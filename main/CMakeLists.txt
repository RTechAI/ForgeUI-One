idf_component_register(
    SRCS
        "main.c"
        "02_FG_HMI.c"
        "05_FG_Icons.c"
        "10_UI_Dashboard.c"
        "11_UI_PreOp.c"
        "12_UI_System.c"
        "13_UI_Admin.c"
        "14_UI_Header.c"
        "15_UI_Keyboard.c"
        "16_UI_Style.c"
        "16_UI_AdminGate.c"
        "17_UI_StatusDrawer.c"
        "20_RTC.c"
        "30_Audio.c"
        "30_WIFI.c"
        "40_SD.c"

        "assets/icons/fg_icon_admin_48px.c"
	"assets/icons/fg_icon_brightness_48px.c"
	"assets/icons/fg_icon_sound_48px.c"
	"assets/icons/fg_icon_system_48px.c"
	"assets/icons/fg_icon_time_48px.c"
	"assets/icons/fg_icon_wifi_48px.c"
	"assets/icons/fg_icon_sd_card_48px.c"
	"17_UI_ReactorModal.c"

    INCLUDE_DIRS
        "."

    REQUIRES
        nvs_flash
        driver
        esp_event
        esp_netif
        esp_wifi
        esp_wifi_remote
        esp_hosted
        fatfs
        sdmmc
        waveshare__esp32_p4_wifi6_touch_lcd_7b

    PRIV_REQUIRES
        bsp_extra
)