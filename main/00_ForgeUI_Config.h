#pragma once

#include "driver/i2c_master.h"

// ============================================================
// ForgeUI Global Configuration
// ============================================================
// Central compile-time feature ownership.
//
// 1 = enabled / compiled in
// 0 = disabled / removed from build + UI
//
// Goal:
// - predictable builds
// - reproducible demos
// - easy feature stripping
// - no hidden runtime ownership
//
// ForgeUI V1 intentionally keeps configuration simple.
// Runtime settings/profile systems can come later.
//
// Target Board:
//   Waveshare ESP32-P4-WIFI6-Touch-LCD-7B
//
// Framework:
//   ForgeUI Framework V1
// ============================================================


// ============================================================
// ForgeUI Master Feature Switches
// ============================================================

#define FORGEUI_ENABLE_RTC                 1
#define FORGEUI_ENABLE_AUDIO               1
#define FORGEUI_ENABLE_WIFI                1
#define FORGEUI_ENABLE_SD                  1

// Optional application/workflow modules
#define FORGEUI_ENABLE_PREOP               1


// ============================================================
// ForgeUI UI Options
// ============================================================

#define FORGEUI_SHOW_HEADER_CLOCK          1


// ============================================================
// ForgeUI Admin Gate Options
// ============================================================
// V1 uses compile-time default PIN.
//
// Future direction:
// - NVS-stored PIN
// - role levels
// - user/session manager
// - timeout handling

#define FORGEUI_ENABLE_ADMIN_GATE          0
#define FORGEUI_ADMIN_DEFAULT_PIN          "1234"

// 0 = disabled
#define FORGEUI_ADMIN_SESSION_TIMEOUT_MIN  0


// ============================================================
// ForgeUI Visual Styles
// ============================================================
// Compile-time active visual style.
//
// Runtime style switching can come later once
// the shared style helper layer is stable.
//
// Style 0:
//   Atlas Light
//   Clean/light professional UI
//
// Style 1:
//   Nebula Blue
//   Dark sharper industrial UI

#define FORGEUI_STYLE_ATLAS_LIGHT          0
#define FORGEUI_STYLE_NEBULA_BLUE          1

// Active Style
//#define FORGEUI_STYLE_ACTIVE             FORGEUI_STYLE_ATLAS_LIGHT
#define FORGEUI_STYLE_ACTIVE               FORGEUI_STYLE_NEBULA_BLUE


// ============================================================
// Wi-Fi Backend Options
// ============================================================
// ESP32-P4 has NO native Wi-Fi radio.
//
// Wi-Fi is provided by onboard ESP32-C6
// using ESP-Hosted / Wi-Fi Remote.
//
// Required project setup:
//
//   idf.py add-dependency "espressif/esp_wifi_remote"
//   idf.py add-dependency "espressif/esp_hosted"
//
// Required menuconfig:
//
//   Component config -> Wi-Fi
//       Host WiFi Enable = ON
//
//   Wi-Fi Remote component = ON
//
//   PSRAM XIP FROM PSRAM = OFF
//
// Critical:
//
//   CONFIG_SPIRAM_XIP_FROM_PSRAM must be OFF.
//
// Leaving it ON causes:
//   sections.ld linker failures
// on ESP32-P4 Hosted Wi-Fi builds.
//
// Current Status:
//
//   Hosted Wi-Fi fully proven working.
//
// Proven:
// - scan
// - select
// - password entry
// - connect
// - IP acquisition
// - disconnect
// - forget network

#define FORGEUI_WIFI_BACKEND_NONE          0
#define FORGEUI_WIFI_BACKEND_HOSTED        1

#if FORGEUI_ENABLE_WIFI
#define FORGEUI_WIFI_BACKEND               FORGEUI_WIFI_BACKEND_HOSTED
#else
#define FORGEUI_WIFI_BACKEND               FORGEUI_WIFI_BACKEND_NONE
#endif


// ============================================================
// RTC Backend Options
// ============================================================

#define FORGEUI_RTC_BACKEND_NONE           0
#define FORGEUI_RTC_BACKEND_ESP_NVS        1
#define FORGEUI_RTC_BACKEND_DS3231         2


// ============================================================
// Active RTC Backend
// ============================================================
// DS3231 uses existing BSP-owned I2C bus.
//
// Driver rules:
// - must NOT initialise I2C
// - must NOT reconfigure bus
// - only attach to existing BSP bus
//
// Final V1 architecture:
//
// DS3231
//   -> persistent source of truth
//
// ESP system time
//   -> runtime active clock
//
// On boot:
//   DS3231 restores system time.
//
// On user set/apply:
//   system time updates + DS3231 write.

#if FORGEUI_ENABLE_RTC
#define FORGEUI_RTC_BACKEND                FORGEUI_RTC_BACKEND_DS3231
#else
#define FORGEUI_RTC_BACKEND                FORGEUI_RTC_BACKEND_NONE
#endif


// ============================================================
// DS3231 Settings
// ============================================================

#define FORGEUI_DS3231_ADDR                0x68
#define FORGEUI_DS3231_I2C_PORT            I2C_NUM_0

// Board shared BSP I2C bus
#define FORGEUI_DS3231_SDA_IO              7
#define FORGEUI_DS3231_SCL_IO              8


// ============================================================
// ForgeUI Status Drawer Options
// ============================================================

#define FORGEUI_STATUS_DRAWER_LEFT         0
#define FORGEUI_STATUS_DRAWER_RIGHT        1

#define FORGEUI_STATUS_DRAWER_WIDTH        240

#define FORGEUI_STATUS_DRAWER_HANDLE_W     28
#define FORGEUI_STATUS_DRAWER_HANDLE_H     120

// Drawer alignment
#define FORGEUI_STATUS_DRAWER_Y            80
#define FORGEUI_STATUS_DRAWER_BOTTOM_GAP   20