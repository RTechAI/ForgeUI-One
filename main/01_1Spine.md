FORGEUI ONE P4 SPINE

============================================================
WHAT IS THE SPINE?
============================================================

The Spine is the master architecture and ownership document for
ForgeUI One.

It defines:

- hardware truth
- runtime truth
- module ownership
- subsystem responsibilities
- UI direction
- known-good boot order
- proven hardware states
- configuration ownership
- current baseline rules

The Spine exists to prevent:

- project drift
- duplicated ownership
- hidden runtime behaviour
- undocumented fixes
- stale comments
- old feature creep returning
- random architectural changes

If code, comments, behaviour, or documentation drift away from this
Spine, either the Spine must be updated or the implementation must be
corrected.

ForgeUI One philosophy:

keep it simple
keep it stable
keep it teachable
keep it modular
keep it alive on real hardware first

Everything works
→ then build product on top


============================================================
SAVE POINT
============================================================

FORGEUI_ONE_P4_004__SINGLE_PAGE_FLASH_OK__CLEANOUT_PASS_STARTED__2026-05-16


============================================================
PROJECT IDENTITY
============================================================

Project:
ForgeUI One

Board:
Waveshare ESP32-P4-WIFI6-Touch-LCD-7B

Created by:
Scott Forster

Contact:
forgeui.esp32@gmail.com

Powered by ForgeUI


============================================================
CURRENT MISSION
============================================================

ForgeUI One is now a clean single-page ESP32-P4 LVGL starter baseline.

The mission is:

- boot cleanly
- prove display
- prove touch
- prove LVGL path
- prove one-page UI ownership
- keep hardware modules available but optional
- remove old multi-page weight
- remove old Reactor/ForkGuard runtime naming
- keep the project clean enough to fork into new ideas


============================================================
CURRENT BASELINE TRUTH
============================================================

ForgeUI One now flashes and boots.

Current live UI direction:

- single Home page
- optional header
- optional header clock
- central style system
- clean module layout
- no tabview runtime requirement
- no dashboard/pre-op/admin/system page stack
- no Reactor launcher runtime
- no LVGL demo widgets runtime ownership


============================================================
HARD RULES
============================================================

No demos in runtime path.

No hidden duplicate drivers.

No old Reactor runtime ownership.

No ForkGuard runtime naming.

No random per-widget styling.

No subsystem owns another subsystem.

main.c owns boot order only.

Backends own system truth.

UI renders only and sends intent only.

Everything must stay simple enough for someone else to follow later.


============================================================
PROVEN WORKING HARDWARE
============================================================

Display:
OK

Touch:
OK

LVGL v9:
OK

Single-page Home UI:
OK

Header:
OK

Header clock path:
OK

NVS:
OK

RTC module:
OK

DS3231 RTC path:
Previously proven

Hosted WiFi:
Previously proven

SD mount after Hosted WiFi:
Previously proven

Audio:
Previously proven, optional in ForgeUI One

Keyboard helper:
Retained

ESP32-P4 flash path:
UART flashing proven

OpenOCD/JTAG:
Not required for normal flash


============================================================
PLATFORM TRUTH
============================================================

The ESP32-P4 has no native WiFi radio.

Hosted WiFi path:

ESP32-P4
-> ESP-Hosted
-> SDIO
-> onboard ESP32-C6
-> WiFi Remote
-> ESP-IDF WiFi API

The WiFi API may look normal in code, but the radio is remote.


============================================================
ESP-IDF BASELINE
============================================================

Current baseline:
ESP-IDF 5.5.x family

Known important requirements:

- ESP-Hosted enabled when WiFi is used
- WiFi Remote enabled when WiFi is used
- PSRAM XIP from PSRAM should remain OFF if linker issues appear
- WiFi must initialise before SD on this board when both are enabled


============================================================
CURRENT ACTIVE PROJECT STRUCTURE
============================================================

main/

00_ForgeUI_Config.h

01_1Spine.md

01_FG_HMI.c
01_FG_HMI.h

02_UI_Home.c
02_UI_Home.h

05_FG_Icons.c
05_FG_Icons.h

14_UI_Header.c
14_UI_Header.h

15_UI_Keyboard.c
15_UI_Keyboard.h

16_UI_Style.c
16_UI_Style.h

20_RTC.c
20_RTC.h

30_Audio.c
30_Audio.h

30_WIFI.c
30_WIFI.h

40_SD.c
40_SD.h

main.c

CMakeLists.txt
idf_component.yml


============================================================
FILES TO REMOVE OR CHECK
============================================================

Duplicate Home files must not remain active.

Remove or park:

main02_UI_Home.c
main02_UI_Home.h

Keep only:

02_UI_Home.c
02_UI_Home.h

Reason:

Duplicate module naming creates confusion and future build drift.


============================================================
CONFIG OWNERSHIP
============================================================

00_ForgeUI_Config.h owns compile-time feature selection.

It controls:

- RTC enable
- WiFi enable
- SD enable
- Audio enable
- header enable
- header clock enable
- display rotation setting
- active theme
- active icon set
- WiFi backend
- RTC backend
- DS3231 settings

Config must stay readable for normal users.


============================================================
FEATURE SWITCHES
============================================================

Current intended ForgeUI One default:

FORGEUI_ENABLE_RTC      1
FORGEUI_ENABLE_WIFI     1
FORGEUI_ENABLE_SD       1
FORGEUI_ENABLE_AUDIO    0

Reason:

Audio works, but it is optional for a clean starter baseline.


============================================================
RTC TRUTH
============================================================

RTC is optional but supported.

Preferred retained-time backend:

DS3231

Fallback/software-only backend:

ESP_NVS

DS3231 settings:

address:
0x68

I2C port:
I2C_NUM_0

SDA:
GPIO7

SCL:
GPIO8

Rule:

If retained time matters, use DS3231.


============================================================
WIFI TRUTH
============================================================

WiFi is optional but supported.

Backend options:

FORGEUI_WIFI_BACKEND_NONE
FORGEUI_WIFI_BACKEND_HOSTED

When WiFi is enabled on ESP32-P4, the backend should be Hosted WiFi.

Do not treat ESP32-P4 as having native WiFi.


============================================================
SD TRUTH
============================================================

SD is optional but supported.

Known-good boot order when WiFi and SD are both enabled:

WiFi first
SD second

Do not mount SD before Hosted WiFi unless retested and proven again.


============================================================
AUDIO TRUTH
============================================================

Audio is optional in ForgeUI One.

Audio was previously proven through the BSP/codec path.

For the clean single-page starter, audio should stay disabled by default
unless the current product build needs it.

Audio should not block the clean UI baseline.


============================================================
DISPLAY TRUTH
============================================================

Display and touch are core.

ForgeUI One exists first to prove:

- board boot
- display alive
- touch alive
- LVGL alive
- single-page UI alive

Rotation must be controlled clearly from config or board bring-up.

Do not hide display rotation behaviour inside random UI files.


============================================================
UI OWNERSHIP
============================================================

01_FG_HMI owns top-level UI creation.

02_UI_Home owns the single Home page.

14_UI_Header owns the optional header.

15_UI_Keyboard owns shared keyboard helper behaviour.

16_UI_Style owns visual styling.

UI modules must not own hardware state.


============================================================
STYLE OWNERSHIP
============================================================

16_UI_Style.c and 16_UI_Style.h own the visual identity.

Rules:

No random per-widget styling.

No duplicated hardcoded colour systems.

No old Reactor style ownership.

No hidden theme logic in Home page.

All styling should flow through the style layer where practical.


============================================================
ICON OWNERSHIP
============================================================

05_FG_Icons.c and 05_FG_Icons.h own icons.

Icons should remain centralised.

Do not scatter icon declarations through page files.


============================================================
MAIN.C OWNERSHIP
============================================================

main.c owns:

- NVS init
- board bring-up
- display start
- LVGL start
- backend init order
- UI boot call
- runtime pump loop

main.c does not own:

- UI layout details
- page business logic
- hardware state formatting
- module-specific behaviour


============================================================
BACKEND OWNERSHIP
============================================================

RTC module:
owns time

WiFi module:
owns network state

SD module:
owns storage state

Audio module:
owns sound output

UI:
renders backend state only


============================================================
RUNTIME ORDER
============================================================

Preferred boot order:

NVS init
Display init
LVGL init
Style init
UI create
Header create if enabled
RTC init if enabled
WiFi init if enabled
SD init if enabled
Audio init if enabled

Important:

When Hosted WiFi and SD are both enabled:

WiFi first
SD second


============================================================
CURRENT CLEANOUT TARGET
============================================================

The current cleanup pass must check:

- every active file header
- every comment block
- every include name
- every stale module reference
- every CMake source entry
- every old Reactor reference
- every old ForkGuard reference
- every old multi-tab reference
- every duplicate Home file
- every unused module still in build path

Goal:

ForgeUI One wording everywhere.


============================================================
REMOVED OR PARKED OLD SYSTEMS
============================================================

The following old systems are not part of the active ForgeUI One runtime:

- Dashboard page stack
- Pre-Op page
- Admin page
- System settings page
- Reactor launcher
- Reactor modal system
- status drawer
- multi-tab navigation
- hidden tabview routing
- old ForkGuard runtime naming
- LVGL demo widgets runtime path

They may exist in older branches or backups, but they must not drift back
into this clean baseline by accident.


============================================================
KNOWN CURRENT CHECKS
============================================================

Check CMakeLists.txt for duplicate or stale source entries.

Check for:

main02_UI_Home.c
main02_UI_Home.h

These should not remain active.

Check config naming.

Check active theme name.

Check RTC backend default.

Check audio default.

Check headers for stale Reactor/ForkGuard references.


============================================================
CURRENT ACCEPTED LIMITATIONS
============================================================

ForgeUI One is intentionally minimal.

It is not currently trying to be:

- full dashboard system
- admin system
- pre-op system
- product settings hub
- Reactor launcher
- full appliance UI
- ForkGuard runtime

Those can be built later on top of this baseline.


============================================================
PRODUCT DIRECTION
============================================================

ForgeUI One should be a clean starting point for:

- new single-page apps
- games
- hardware demos
- LVGL starter products
- ESP32-P4 experiments
- future ForgeUI variants

It should be easy to understand, easy to flash, and easy to extend.


============================================================
FINAL LOCK
============================================================

ForgeUI One is the clean single-page baseline.

Display first.
Touch first.
LVGL first.
Single page first.

Keep the hardware alive.
Keep the code readable.
Keep ownership clean.

No demo runtime.
No old Reactor drift.
No ForkGuard runtime drift.
No duplicate Home modules.

Build cool stuff.

Powered by ForgeUI.

Additional project details:

See ABOUT.md