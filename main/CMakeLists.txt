idf_component_register(
    SRCS
        "main.c"
        "01_FG_HMI.c"
        "02_UI_Home.c"
        "05_FG_Icons.c"
        "14_UI_Header.c"
        "15_UI_Keyboard.c"
        "16_UI_Style.c"
        "20_RTC.c"
        "30_Audio.c"
        "30_WIFI.c"
        "40_SD.c"
	"90_Studio_Export.c"



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