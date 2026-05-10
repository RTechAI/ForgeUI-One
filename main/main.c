/*
 * ============================================================
 * ForgeUI Framework V1
 * ============================================================
 * Main application entry point.
 *
 * Responsibilities:
 * - system boot sequencing
 * - NVS init
 * - display bring-up
 * - LVGL startup
 * - feature backend startup
 * - runtime service loop
 *
 * Runtime Ownership Rules:
 * - main.c owns boot order only
 * - backend modules own system state
 * - UI modules render only
 * - no business logic in app_main
 *
 * Important Hardware Rule:
 *
 * ESP32-P4 Hosted WiFi and SDMMC
 * share critical hardware paths.
 *
 * Current proven stable boot order:
 *
 *   Hosted WiFi first
 *   -> SD mount second
 *
 * This ordering is REQUIRED for the
 * current stable ForgeUI baseline.
 *
 * Framework:
 *   ForgeUI Framework V1
 *
 * Target Board:
 *   Waveshare ESP32-P4-WIFI6-Touch-LCD-7B
 * ============================================================
 */

#include "nvs_flash.h"
#include "nvs.h"
#include "esp_log.h"
#include "esp_err.h"
#include "esp_check.h"
#include "esp_memory_utils.h"
#include "lvgl.h"
#include "bsp/esp-bsp.h"
#include "bsp/display.h"
#include "bsp_board_extra.h"
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "30_Audio.h"
#include "30_WIFI.h"
#include "01_FG_HMI.h"
#include "14_UI_Header.h"
#include "20_RTC.h"
#include "40_SD.h"
#include "esp_vfs_fat.h"
#include "esp_task_wdt.h"
#include "00_ForgeUI_Config.h"
#include "17_UI_StatusDrawer.h"

static const char *TAG = "APP_MAIN";

static bool fg_sd_check_prepare_flag(void)
{
    nvs_handle_t nvs;
    uint8_t flag = 0;

    if (nvs_open("forgeui", NVS_READWRITE, &nvs) != ESP_OK) {
        return false;
    }

    nvs_get_u8(nvs, "sd_prep", &flag);

    if (flag == 1)
    {
        // clear flag immediately
        nvs_set_u8(nvs, "sd_prep", 0);
        nvs_commit(nvs);
        nvs_close(nvs);

        return true;
    }

    nvs_close(nvs);
    return false;
}

static void fg_sd_prepare_card_maintenance(void)
{
    ESP_LOGW(TAG, "========================================");
    ESP_LOGW(TAG, "SD MAINTENANCE MODE START");
    ESP_LOGW(TAG, "NO UI / NO WIFI");
    ESP_LOGW(TAG, "========================================");

    if (!fg_sd_init())
    {
        ESP_LOGE(TAG, "SD init failed in maintenance mode");
        vTaskDelay(pdMS_TO_TICKS(3000));
        esp_restart();
    }

    ESP_LOGW(TAG, "Preparing ForgeUI file system...");

    // 🔧 (can leave WDT relax or remove — not needed anymore)
    esp_task_wdt_config_t twdt_cfg = {
        .timeout_ms = 300000,
        .idle_core_mask = 0,
        .trigger_panic = false
    };

    esp_err_t wdt_ret = esp_task_wdt_reconfigure(&twdt_cfg);
    ESP_LOGW(TAG, "Maintenance WDT relaxed: %s", esp_err_to_name(wdt_ret));

    // ✅ NEW: FAST RESET (NO FULL FORMAT)
    if (!fg_sd_reset_storage_blocking())
    {
        ESP_LOGE(TAG, "ForgeUI storage reset failed in maintenance mode");
    }

    ESP_LOGW(TAG, "SD PREP COMPLETE - REBOOTING");

    vTaskDelay(pdMS_TO_TICKS(1500));
    esp_restart();
}


void app_main(void)
{
    // ---- NVS INIT ----
    esp_err_t ret = nvs_flash_init();
    if (ret == ESP_ERR_NVS_NO_FREE_PAGES || ret == ESP_ERR_NVS_NEW_VERSION_FOUND)
    {
        ESP_ERROR_CHECK(nvs_flash_erase());
        ret = nvs_flash_init();
    }
    ESP_ERROR_CHECK(ret);

#if FORGEUI_ENABLE_SD
    // ---- CHECK SD MAINTENANCE MODE ----
    if (fg_sd_check_prepare_flag())
    {
        fg_sd_prepare_card_maintenance();
        return; // never run normal boot
    }
#endif

    // ---- DISPLAY INIT ----
    bsp_display_cfg_t cfg = {
        .lvgl_port_cfg = ESP_LVGL_PORT_INIT_CONFIG(),
        .buffer_size = BSP_LCD_DRAW_BUFF_SIZE,
        .double_buffer = BSP_LCD_DRAW_BUFF_DOUBLE,
        .flags = {
            .buff_dma = true,
            .buff_spiram = false,
            .sw_rotate = true,
        }
    };

    (void)bsp_display_start_with_config(&cfg);

    bsp_display_backlight_on();

    //if (disp != NULL)
    //{
    //    bsp_display_rotate(disp, LV_DISPLAY_ROTATION_180);
    //}

    // ---- UI INIT ----
    bsp_display_lock(0);
    fg_hmi_init();
    fg_header_refresh();
    fg_status_drawer_create();
    bsp_display_unlock();

#if FORGEUI_ENABLE_RTC
    // ---- RTC INIT ----
    fg_rtc_init();
#endif

#if FORGEUI_ENABLE_WIFI
    bool wifi_ready = false;
#endif

#if FORGEUI_ENABLE_SD
    bool sd_ready = false;
#endif

    ESP_LOGI(TAG, "========================================");
    ESP_LOGI(TAG, "FORGEUI MASTER CONFIG BOOT");
    ESP_LOGI(TAG, "WiFi feature: %s", FORGEUI_ENABLE_WIFI ? "ON" : "OFF");
    ESP_LOGI(TAG, "SD feature: %s", FORGEUI_ENABLE_SD ? "ON" : "OFF");
    ESP_LOGI(TAG, "RTC feature: %s", FORGEUI_ENABLE_RTC ? "ON" : "OFF");
    ESP_LOGI(TAG, "========================================");

#if FORGEUI_ENABLE_WIFI
    // ---- START HOSTED WIFI FIRST ----
    ESP_LOGI(TAG, "========================================");
    ESP_LOGI(TAG, "HOSTED WIFI FIRST");
    ESP_LOGI(TAG, "========================================");

    fg_wifi_init();

    vTaskDelay(pdMS_TO_TICKS(2500));

    wifi_ready = fg_wifi_is_ready();

    ESP_LOGI(TAG, "WiFi after init: %s | IP: %s",
             fg_wifi_status_text(),
             fg_wifi_ip_text());
#endif

#if FORGEUI_ENABLE_SD
    // ---- NOW MOUNT SD AFTER HOSTED WIFI ----
    ESP_LOGI(TAG, "========================================");
    ESP_LOGI(TAG, "MOUNT SD AFTER WIFI");
    ESP_LOGI(TAG, "========================================");

    if (fg_sd_init())
    {
        sd_ready = true;
        ESP_LOGI(TAG, "SD AFTER WIFI-FIRST INIT: READY");
        fg_sd_test();
    }
    else
    {
        sd_ready = false;
        ESP_LOGE(TAG, "SD AFTER WIFI-FIRST INIT: FAILED");
    }
#endif

    ESP_LOGI(TAG, "========================================");
    ESP_LOGI(TAG, "BOOT TEST RESULT");

#if FORGEUI_ENABLE_WIFI
    ESP_LOGI(TAG, "WiFi ready: %s", wifi_ready ? "READY" : "FAIL");
    ESP_LOGI(TAG, "WiFi status: %s | IP: %s",
             fg_wifi_status_text(),
             fg_wifi_ip_text());
#else
    ESP_LOGI(TAG, "WiFi: DISABLED");
#endif

#if FORGEUI_ENABLE_SD
    ESP_LOGI(TAG, "SD ready: %s", sd_ready ? "READY" : "FAIL");
#else
    ESP_LOGI(TAG, "SD: DISABLED");
#endif

    ESP_LOGI(TAG, "========================================");

    // ---- MAIN LOOP ----
    uint32_t last_1hz = lv_tick_get();

    while (1)
    {
        vTaskDelay(pdMS_TO_TICKS(50));

#if FORGEUI_ENABLE_WIFI
        // ---- WIFI SERVICE PUMP ----
        fg_wifi_pump();
#endif

        uint32_t now = lv_tick_get();

        if ((now - last_1hz) >= 1000)
        {
            last_1hz = now;

            bsp_display_lock(0);
            fg_header_refresh();
            bsp_display_unlock();

#if FORGEUI_ENABLE_WIFI
            const char *wifi_status = fg_wifi_status_text();
            const char *wifi_ip = fg_wifi_ip_text();
#else
            const char *wifi_status = "DISABLED";
            const char *wifi_ip = "-";
#endif

#if FORGEUI_ENABLE_SD
            const char *sd_status = sd_ready ? "READY" : "FAIL";
#else
            const char *sd_status = "DISABLED";
#endif

            ESP_LOGI(TAG, "WiFi: %s | IP: %s | SD: %s",
                     wifi_status,
                     wifi_ip,
                     sd_status);
        }
    }
}