ForgeUI P4



Clean LVGL v9 hardware baseline for the Waveshare ESP32-P4-WIFI6-Touch-LCD-7B.



ForgeUI is a product-oriented embedded UI framework focused on stable hardware bring-up, clean architecture, reusable LVGL patterns, and real-world ESP32-P4 integration.



This project intentionally avoids demo-driven runtime architecture and instead provides a clean baseline suitable for real embedded products.



PROJECT STATUS



Current Status:

RC1 Public Release Preparation



Current Save Point:

FORGEUI\_P4\_591\_\_RC1\_PUBLIC\_RELEASE\_PREP\_\_README\_STARTED\_\_2026-05-10



SUPPORTED HARDWARE



Primary Supported Board:

Waveshare ESP32-P4-WIFI6-Touch-LCD-7B



Hardware Proven:



ESP32-P4

ESP32-C6 Hosted WiFi

EK79007 display

GT911 touch

DS3231 RTC

ES8311 audio path

PROVEN RC1 FEATURES



Current proven RC1 baseline includes:



Display alive

Touch alive

LVGL v9 stable

Hosted WiFi alive

WiFi scan/connect/disconnect

RTC persistence working

Audio working

Volume control

SD card support working

Status drawer system

Modular feature config system

Theme foundation

Admin gate foundation

SOFTWARE STACK



Framework:



ESP-IDF v5.5.4



Graphics:



LVGL v9.2.2



Core Components:



esp\_hosted v2.9.7

esp\_wifi\_remote v1.3.0

esp\_lvgl\_port v2.7.2

esp\_codec\_dev v1.2.0

Waveshare BSP v1.0.2



Display Components:



esp\_lcd\_ek79007 v1.0.4

esp\_lcd\_touch\_gt911 v1.2.0\~2

PROJECT GOALS



ForgeUI exists to provide:



stable ESP32-P4 bring-up

reusable LVGL foundations

modular embedded architecture

product-oriented UI structure

hosted WiFi reference implementation

clean ownership boundaries



ForgeUI intentionally avoids:



demo-driven runtime logic

hidden state ownership

tangled UI/backend coupling

unsafe LVGL threading

CORE DESIGN RULES

main.c owns:

board startup

hardware init

LVGL startup

backend startup

runtime loop

UI DOES NOT own system truth

Backends own truth

UI only:

renders state

sends user intent

No LVGL calls from unsafe async contexts

Feature ownership belongs in:

00\_ForgeUI\_Config.h

PROJECT STRUCTURE



Typical structure:



main.c



00\_ForgeUI\_Config.h



01\_FG\_HMI.c

01\_FG\_HMI.h



10\_UI\_Dashboard.c

11\_UI\_PreOp.c

12\_UI\_System.c

13\_UI\_Admin.c

14\_UI\_Header.c

15\_UI\_Keyboard.c

16\_UI\_StatusDrawer.c

17\_UI\_AdminGate.c



20\_RTC.c

21\_RTC\_DS3231.c



30\_Audio.c

30\_WIFI.c



40\_SD.c



50\_SDMMC\_BUS.c

50\_SDMMC\_BUS.h



FEATURE CONFIG SYSTEM



ForgeUI uses compile-time feature switches.



Example:



\#define FORGEUI\_ENABLE\_WIFI 1

\#define FORGEUI\_ENABLE\_SD 1

\#define FORGEUI\_ENABLE\_AUDIO 1

\#define FORGEUI\_ENABLE\_RTC 1



Set:

0 = disabled

1 = enabled



Purpose:



cleaner builds

modular variants

easier product scaling

smaller firmware variants

DISPLAY SYSTEM



Current display baseline:



stable LVGL rendering

touch alive

180-degree rotated orientation

theme-ready UI structure



Current orientation:



bsp\_display\_rotate(disp, LV\_DISPLAY\_ROTATION\_180);



RTC SYSTEM



RTC strategy:



DS3231 provides persistence

ESP system time used during runtime

DS3231 restores time at boot

UI writes back to DS3231 when changed



Current RTC baseline includes:



live clock

header clock

manual time set

power-off retention

AUDIO SYSTEM



Current audio baseline includes:



speaker output

beep testing

runtime volume control

ES8311 codec path alive

HOSTED WIFI



IMPORTANT:

ESP32-P4 itself does NOT contain a native WiFi radio.



ForgeUI RC1 uses:



ESP32-C6

esp\_hosted

esp\_wifi\_remote

SDIO transport



The onboard ESP32-C6 provides WiFi functionality through ESP-Hosted.



Current RC1 setup uses:



SDIO Slot 1

4-bit SDIO bus

40 MHz SDIO clock



Important RC1 notes:



PSRAM XIP disabled

TWT disabled

Hosted WiFi proven stable

WiFi + SD coexistence proven



Known-good menuconfig screenshots are included in:



/docs/setup



SD CARD SYSTEM



Current SD features:



SD detection

folder creation

read/write testing

live rebuild

safe reset path



Important:

Current RC1 baseline avoids live full-formatting due to SDIO/shared-bus ownership constraints with Hosted WiFi.



BUILD ENVIRONMENT



Recommended:



VS Code

ESP-IDF Extension

ESP-IDF v5.5.4



Build:

idf.py build



Flash:

idf.py flash monitor



Full clean:

idf.py fullclean



KNOWN GOOD STARTUP ORDER



Current proven startup order:



Display startup

LVGL startup

UI creation

Hosted WiFi init

SD init

Runtime loop start

MENUCONFIG REFERENCE



Known-good RC1 menuconfig screenshots are included in:



/docs/setup



Included references:



ESP-Hosted

WiFi Remote

SDIO transport

PSRAM XIP

TWT disable

SD configuration

RTC clock config

Power management

SCREENSHOTS



Recommended screenshots for release:



Dashboard

System page

WiFi tile

SD tile

Audio tile

Status drawer

Admin gate

Theme examples

ROADMAP



Planned:



multiple themes

polished transitions

admin authentication

SPIFFS mini database

reusable widget library

overlay system

ESP32-S3 support

starter product editions

LICENSE



ForgeUI source code:

Copyright (c) 2026 Scott Forster



Licensed under the MIT License.



See:

LICENSE



Third-party components retain their own licenses.



See:

THIRD\_PARTY\_LICENSES.md



THIRD PARTY SOFTWARE



This project uses software/components from:



LVGL

Espressif Systems

Waveshare



Please review all third-party licenses before commercial redistribution.



DISCLAIMER



This project is provided as-is without warranty.



Always validate:



electrical safety

thermal safety

hardware stability

production suitability



before commercial deployment.

