ForgeUI P4 RC1

Scott Forster
email forgeui.esp32@gmail.com

Clean LVGL v9 hardware baseline for the
Waveshare ESP32-P4-WIFI6-Touch-LCD-7B.

Production-ready LVGL v9 framework and ESP-IDF baseline for the ESP32-P4 RISC-V MCU.


============================================================
OVERVIEW
============================================================

ForgeUI is a product-oriented embedded UI framework
focused on:

- stable hardware bring-up
- clean architecture
- reusable LVGL patterns
- hosted WiFi integration
- real-world ESP32-P4 integration

ForgeUI intentionally avoids demo-driven runtime
architecture and instead provides a clean baseline
suitable for real embedded products.

ForgeUI intentionally favors clarity and stability
over demo complexity.


============================================================
WHY FORGEUI EXISTS
============================================================

ForgeUI was created to provide a clean,
real-world ESP32-P4 baseline focused on:

- stable hardware bring-up
- production-oriented LVGL architecture
- hosted WiFi integration
- reusable embedded UI patterns
- clean ownership boundaries


============================================================
PROJECT STATUS
============================================================

Current Status:

RC1 Public Release Preparation


Current Save Point:

FORGEUI_P4_591__RC1_PUBLIC_RELEASE_PREP__README_STARTED__2026-05-10


============================================================
QUICK START
============================================================

Set target:

idf.py set-target esp32p4


Build:

idf.py build


Flash:

idf.py flash monitor


Full clean:

idf.py fullclean


============================================================
SUPPORTED HARDWARE
============================================================

Primary Supported Board:

Waveshare ESP32-P4-WIFI6-Touch-LCD-7B


Proven Hardware Integration:

- ESP32-P4
- ESP32-C6 Hosted WiFi
- EK79007 display
- GT911 touch
- DS3231 RTC
- ES8311 audio path


============================================================
PROVEN RC1 FEATURES
============================================================

Current proven RC1 baseline includes:

- Display operational
- Touch operational
- LVGL v9 stable
- Hosted WiFi operational
- WiFi scan/connect/disconnect
- RTC persistence working
- Audio working
- Volume control
- SD card support working
- Status drawer system
- Modular feature config system
- Theme foundation
- Admin gate foundation


============================================================
SOFTWARE STACK
============================================================

Framework:

ESP-IDF v5.5.4


Graphics:

LVGL v9.2.2


Core Components:

- esp_hosted v2.9.7
- esp_wifi_remote v1.3.0
- esp_lvgl_port v2.7.2
- esp_codec_dev v1.2.0
- Waveshare BSP v1.0.2


Display Components:

- esp_lcd_ek79007 v1.0.4
- esp_lcd_touch_gt911 v1.2.0~2


============================================================
PROJECT GOALS
============================================================

ForgeUI exists to provide:

- stable ESP32-P4 bring-up
- reusable LVGL foundations
- modular embedded architecture
- product-oriented UI structure
- hosted WiFi reference implementation
- clean ownership boundaries


ForgeUI intentionally avoids:

- demo-driven runtime logic
- hidden state ownership
- tangled UI/backend coupling
- unsafe LVGL threading


============================================================
CORE DESIGN RULES
============================================================

main.c owns:

- board startup
- hardware init
- LVGL startup
- backend startup
- runtime loop


UI DOES NOT own system truth

Backends own truth


UI only:

- renders state
- sends user intent


No LVGL calls from unsafe async contexts


Feature ownership belongs in:

00_ForgeUI_Config.h


============================================================
SAFE LVGL RULES
============================================================

- LVGL calls must execute from LVGL-safe context
- Backend/event tasks must never directly mutate UI
- Async/event systems should cache state only
- UI timers/pumps apply visual updates safely


============================================================
PROJECT STRUCTURE
============================================================

Typical structure:


main.c


00_ForgeUI_Config.h


01_FG_HMI.c
01_FG_HMI.h


10_UI_Dashboard.c
11_UI_PreOp.c
12_UI_System.c
13_UI_Admin.c
14_UI_Header.c
15_UI_Keyboard.c
16_UI_StatusDrawer.c
17_UI_AdminGate.c


20_RTC.c
21_RTC_DS3231.c


30_Audio.c
30_WIFI.c


40_SD.c


50_SDMMC_BUS.c
50_SDMMC_BUS.h


============================================================
FEATURE CONFIG SYSTEM
============================================================

ForgeUI uses compile-time feature switches.


Example:

#define FORGEUI_ENABLE_WIFI   1
#define FORGEUI_ENABLE_SD     1
#define FORGEUI_ENABLE_AUDIO  1
#define FORGEUI_ENABLE_RTC    1


Set:

0 = disabled
1 = enabled


Purpose:

- cleaner builds
- modular variants
- easier product scaling
- smaller firmware variants


============================================================
DISPLAY SYSTEM
============================================================

Current display baseline:

- stable LVGL rendering
- touch operational
- 180-degree rotated orientation
- theme-ready UI structure


Current orientation:

bsp_display_rotate(disp, LV_DISPLAY_ROTATION_180);


============================================================
RTC SYSTEM
============================================================

RTC strategy:

- DS3231 provides persistence
- ESP system time used during runtime
- DS3231 restores time at boot
- UI writes back to DS3231 when changed


Current RTC baseline includes:

- live clock
- header clock
- manual time set
- power-off retention


============================================================
AUDIO SYSTEM
============================================================

Current audio baseline includes:

- speaker output
- beep testing
- runtime volume control
- ES8311 codec path operational


============================================================
HOSTED WIFI
============================================================

IMPORTANT:

ESP32-P4 itself does NOT contain a native WiFi radio.


ForgeUI RC1 uses:

- ESP32-C6
- esp_hosted
- esp_wifi_remote
- SDIO transport


The onboard ESP32-C6 provides WiFi functionality
through ESP-Hosted.


Current RC1 setup uses:

- SDIO Slot 1
- 4-bit SDIO bus
- 40 MHz SDIO clock


Important RC1 notes:

- PSRAM XIP disabled
- TWT disabled
- Hosted WiFi proven stable
- WiFi + SD coexistence proven


Known-good menuconfig screenshots are included in:

/docs/setup


============================================================
SD CARD SYSTEM
============================================================

Current SD features:

- SD detection
- folder creation
- read/write testing
- live rebuild
- safe reset path


IMPORTANT:

Current RC1 baseline avoids live full-formatting
due to SDIO/shared-bus ownership constraints
with Hosted WiFi.


============================================================
BUILD ENVIRONMENT
============================================================

Recommended:

- VS Code
- ESP-IDF Extension
- ESP-IDF v5.5.4


Build:

idf.py build


Flash:

idf.py flash monitor


Full clean:

idf.py fullclean


============================================================
KNOWN GOOD STARTUP ORDER
============================================================

Current proven startup order:

1. Display startup
2. LVGL startup
3. UI creation
4. Hosted WiFi init
5. SD init
6. Runtime loop start


============================================================
MENUCONFIG REFERENCE
============================================================

Known-good RC1 menuconfig screenshots
are included in:

/docs/setup


Included references:

- ESP-Hosted
- WiFi Remote
- SDIO transport
- PSRAM XIP
- TWT disable
- SD configuration
- RTC clock config
- Power management


============================================================
KNOWN GOTCHAS
============================================================

- Hosted WiFi requires PSRAM XIP disabled
- TWT may require disabling depending on esp_hosted version
- WiFi and SD share SDIO ownership constraints
- Live SD formatting currently not recommended
- Full clean builds recommended after major config changes


============================================================
SCREENSHOTS
============================================================

Recommended screenshots for release:

- Dashboard
- System page
- WiFi tile
- SD tile
- Audio tile
- Status drawer
- Admin gate
- Theme examples


============================================================
ROADMAP
============================================================

Planned:

- multiple themes
- polished transitions
- admin authentication
- SPIFFS mini database
- reusable widget library
- overlay system
- ESP32-S3 support
- starter product editions


============================================================
LICENSE
============================================================

ForgeUI source code:

Copyright (c) 2026 Scott Forster

Licensed under the:

ForgeUI Source Available License


See:

LICENSE


Third-party components retain
their own licenses.


See:

THIRD_PARTY_LICENSES.md


============================================================
THIRD PARTY SOFTWARE
============================================================

- LVGL
- Espressif Systems
- Waveshare


Please review all third-party licenses
before commercial redistribution.


============================================================
DISCLAIMER
============================================================

This project is provided as-is
without warranty.


Always validate:

- electrical safety
- thermal safety
- hardware stability
- production suitability


before commercial deployment.

============================================================
SEARCH KEYWORDS
============================================================

ESP32-P4
LVGL v9
ESP-IDF
Waveshare ESP32-P4
Embedded GUI
Embedded UI
RISC-V MCU
ESP-Hosted
Touchscreen UI
LVGL Framework
ESP32 UI Framework