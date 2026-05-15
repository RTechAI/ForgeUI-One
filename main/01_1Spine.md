FORGEUI P4 SPINE

WHAT IS THE SPINE?

The Spine is the master architecture and ownership document for ForgeUI.

The Spine is intended to evolve alongside ForgeUI.

It should be updated whenever:

- architecture changes
- ownership changes
- runtime behaviour changes
- hardware truth changes
- product direction changes
- known-good baselines change

If something becomes important enough to repeatedly explain,
it belongs in the Spine.

The Spine defines:

- hardware truth
- runtime truth
- module ownership
- subsystem responsibilities
- UI direction
- product direction
- known-good boot order
- proven hardware states
- configuration ownership
- Reactor architecture
- future development rules

The Spine exists to prevent:

- project drift
- duplicated ownership
- hidden runtime behaviour
- undocumented fixes
- random architectural changes
- forgotten hardware rules
- unstable feature expansion

The Spine is the single source of truth for the current known-good ForgeUI baseline.

If code, comments, behaviour, or documentation drift away from the Spine,
the Spine must be updated or the implementation corrected.

Everything in ForgeUI should eventually trace back to Spine ownership.

ForgeUI Spine philosophy:

keep it simple
keep it stable
keep it teachable
keep it modular
keep it alive on real hardware first

Everything works
→ then build product on top


SAVE POINT:
FORGEUI_P4_598__THEME_SELECTOR_AND_UI_MODULE_TOGGLES_OK__2026-05-15

Board Model:
WAVESHARE ESP32-P4-WIFI6-TOUCH-LCD-7B

Project:
ForgeUI

Branch:
ForgeUI-Reactor

CREATOR / ATTRIBUTION

ForgeUI
Created by Scott Forster

Contact:
forgeui.esp32@gmail.com

Powered by ForgeUI

ForkGuard retired for this baseline

PURPOSE

This document defines the current ForgeUI P4 hardware baseline, ownership rules, module structure, runtime responsibilities, Reactor launcher direction, icon ownership model, Reactor modal architecture, UI feature-toggle ownership, and modular appliance-style UI direction.

It is the single source of truth for:

module layout
responsibility boundaries
runtime ownership
hardware proof status
ESP32-P4 + ESP32-C6 hosted WiFi strategy
SD card integration strategy
future product handover direction
master feature config ownership
backend ownership strategy
visual style ownership strategy
product UI consistency rules
admin gate ownership
status drawer ownership
Reactor launcher ownership
Reactor modal ownership
hidden routing ownership
icon pipeline ownership
touch-driven launcher ownership
shared overlay ownership
shared keyboard ownership
theme selector ownership
optional UI module ownership

CURRENT MISSION

Build a fully alive, hardware-proven ForgeUI baseline, then evolve Reactor into a modular appliance-style launcher UI suitable for product deployment.

Current next mission:
RTC tile cleanup and improved date/time setting workflow.

RULES

No demos in runtime path
No guessing
No hidden duplicate drivers
No random per-widget styling
No subsystem owning another subsystem
Everything must remain simple enough for someone else to follow later

GOAL

Everything works
→ then build product on top

PRODUCT DIRECTION

ForgeUI is now being shaped as a reusable embedded UI product baseline.

The UI must be:

consistent
clean
teachable
sellable
easy to modify
stable on hardware
not over-engineered

This is no longer a one-off demo screen.

BRANCH STATUS

main branch:

stable traditional ForgeUI baseline

ForgeUI-Reactor branch:

active launcher/appliance UI branch
hidden tabview routing
touch-first navigation
launcher-card direction
shared modal direction
shared overlay direction
modular icon system
future overlay/page split architecture

CURRENT REACTOR COMMIT DIRECTION

Reactor launcher UI, icon pipeline, shared modal architecture, and modular config ownership proven on hardware.

PLATFORM TRUTH — ESP32-P4 WIFI

ESP32-P4 has NO native WiFi radio.

Actual WiFi path:

ESP32-P4 host
→ onboard ESP32-C6 radio
→ ESP-Hosted
→ SDIO transport
→ WiFi Remote
→ ESP-IDF WiFi API

WiFi API appears normal in code.
Radio is remote.

PROVEN WORKING HARDWARE

Display: OK
Touch: OK
LVGL v9 UI: OK
Header clock: OK
NVS: OK
DS3231 RTC: OK
Power-off time retention: OK
BSP shared I2C bus: OK
Audio: OK
Volume slider: OK
Tab UI structure: OK
Hidden tab routing: OK
Launcher routing helpers: OK
Screen rotation: OK
Native BSP panel orientation: OK
Startup 180° flip: FIXED
Hosted WiFi (ESP32-C6 over SDIO): OK
WiFi scan/connect/disconnect: OK
WiFi password entry: OK
WiFi keyboard overlay: OK
WiFi-first / SD-second workaround: OK
SD mount after Hosted WiFi: OK
Safe SD rebuild/reset: OK
Keyboard overlay: OK
Feature modular config system: OK
Theme selector cleanup: OK
Header enable toggle: OK
Dashboard tile enable toggle: OK
Dashboard tile gating: OK
Nebula Blue theme pass: STARTED
Reactor branch: ALIVE
System launcher hub: ALIVE
Dashboard launcher card routing: ALIVE
Admin gate dev switch: OK
Admin PIN keypad path: PROVEN
Status drawer V1: ALIVE
Status drawer side config: PROVEN
Icon pipeline: PROVEN
Touch-driven launcher model: PROVEN
Reactor modal framework: PROVEN
Brightness Reactor modal: OK
Sound Reactor modal: OK
WiFi Reactor modal: OK
Storage Reactor modal: OK
Shared Reactor overlay: OK
Shared modal close path: OK
Async modal deletion: OK
LVGL stale object protection: OK
Modal exit reset bug: FIXED
Tab swipe tuning: ADDED

DISPLAY ROTATION TRUTH

The Waveshare ESP32-P4-WIFI6-Touch-LCD-7B native display orientation is already correct.

REMOVE:

bsp_display_rotate(disp, LV_DISPLAY_ROTATION_180);

This forced rotation caused:

visible startup flip
white/FPS rotate transition
unnecessary redraw overhead

ForgeUI now runs in native BSP orientation.

HOSTED WIFI STATUS

Status:
PROVEN WORKING

Proven:

ESP-Hosted SDIO transport
ESP32-C6 detected
Transport active
MAC read
STA started
Scan pipeline working
SSIDs returned
RSSI returned
UI WiFi status alive
Scan/select/password/connect/IP/forget working
Shared keyboard overlay working
Stable with current boot order

Proof logs:

transport: Identified slave [esp32c6]
H_API: Transport active
FG_WIFI: STA started
FG_WIFI: WiFi hosted init READY
FG_WIFI: SCAN DONE EVENT FIRED

SD CARD STATUS

Status:
PROVEN WORKING

Proven:

SDMMC mount
FAT filesystem
File create
File read
256GB SDHC
4-bit mode
40 MHz
Read/write test pass
Reactor storage modal working
Live rebuild working
List ForgeUI working

Proof logs:

FG_SD: SD mounted OK
FG_SD: SD TEST PASS

CRITICAL WIFI + SD RULE

Correct boot order:

fg_wifi_init()
fg_sd_init()
fg_sd_test()

Do NOT mount SD before WiFi.

Reason:

ESP-Hosted claims SDMMC first.
SD safely attaches afterward.

Golden proof:

sdmmc_host already initialized, skipping init flow

Breaking this causes:

SD failure
timeouts
conflicts
unstable WiFi

SDMMC BUS STRATEGY

50_SDMMC_BUS.* exists.

Status:
UNUSED / PLACEHOLDER

Do NOT build a custom bus layer yet.

Working system relies on:

WiFi first
SD second

WIFI ARCHITECTURE RULE

Never run heavy logic inside event handlers.

Correct:

event → flag
main loop → fg_wifi_pump()

This rule is locked.

ESP-IDF BASELINE

Version:
5.5.4

Do NOT drift casually.

Required:

ESP-Hosted enabled
WiFi Remote enabled
PSRAM XIP FROM PSRAM = OFF

PROJECT STRUCTURE

main/

00_ForgeUI_Config.h
01_1Spine.md

01_FG_HMI.h
02_FG_HMI.c

05_FG_Icons.h
05_FG_Icons.c

10_UI_Dashboard.h
10_UI_Dashboard.c

11_UI_PreOp.h
11_UI_PreOp.c

12_UI_System.h
12_UI_System.c

13_UI_Admin.h
13_UI_Admin.c

14_UI_Header.h
14_UI_Header.c

15_UI_Keyboard.h
15_UI_Keyboard.c

16_UI_AdminGate.h
16_UI_AdminGate.c

16_UI_Style.h
16_UI_Style.c

17_UI_StatusDrawer.h
17_UI_StatusDrawer.c

17_UI_ReactorModal.h
17_UI_ReactorModal.c

20_RTC.h
20_RTC.c

30_Audio.h
30_Audio.c

30_WIFI.h
30_WIFI.c

40_SD.h
40_SD.c

50_SDMMC_BUS.h
50_SDMMC_BUS.c

main.c
CMakeLists.txt
idf_component.yml

REACTOR UI STATUS

Status:
ALIVE / STABILIZED

Reactor is now more than a colour theme.

It changes:

navigation model
interaction flow
launch model
UI hierarchy
module routing direction
icon ownership direction
page ownership direction
overlay ownership direction
modal ownership direction

CURRENT REACTOR BEHAVIOUR

Top tab bar hidden.
LVGL tabview remains alive internally.
Swipe remains available as secondary navigation.
Dashboard acts as launcher.
Dashboard launcher cards can route to pages.
System page is now a modular icon hub.
System hub now launches shared Reactor modals.
Admin can launch from Dashboard or System hub.
System legacy page remains parked but preserved.

IMPORTANT TRUTH

Do NOT delete the internal tabview.

The tabview is now the hidden routing engine.

REACTOR NAVIGATION RULE

Primary navigation:

tap icons/cards

Secondary navigation:

swipe between hidden tabview pages

Do NOT rely on swipe as primary navigation.

REASON

Swipe can feel stiff on the 7-inch panel.
Icon tap feels cleaner for appliance/product UI.
Hidden tab animation can look messy if animated.

CURRENT CONFIG IMPROVEMENT

Theme selector has been simplified for normal users.

Current direction:

theme selection first
instructions first
internal IDs second

Reason:

public projects must optimize for readability and usability, not only developer architecture purity.

CURRENT CONFIG TOGGLES

FORGEUI_ENABLE_HEADER
FORGEUI_ENABLE_DASHBOARD_TILES

Current behaviour:

1 = enabled
0 = disabled

Dashboard launcher cards are now gated correctly through:

FORGEUI_ENABLE_DASHBOARD_TILES

Header visibility is now gated correctly through:

FORGEUI_ENABLE_HEADER

CURRENT DASHBOARD DIRECTION

Dashboard is no longer just a placeholder page.

Dashboard now acts as:

launcher
home screen
future module router
future status entry point

Current dashboard direction:

large touch launcher cards
minimal text
icon-first interaction
clean appliance-style UX
future infotainment-style flow

CURRENT SYSTEM HUB

Brightness
Sound
WiFi
Storage
Time
Admin

SYSTEM PAGE DIRECTION

Old direction:

single giant settings page

New Reactor direction:

System becomes launcher hub only.

Features now launch through:

shared Reactor modals

Future:

dedicated pages/modules

CURRENT REACTOR MODAL SYSTEM

Status:
PROVEN WORKING

Current modal architecture:

shared overlay
shared modal builder
shared close path
shared styling ownership
shared keyboard ownership
shared runtime cleanup

Current modal-backed modules:

Brightness
Sound
WiFi
Storage

MODAL STABILITY RULES

ALL timer-driven refresh paths must validate LVGL objects before access.

Correct:

lv_obj_is_valid(...)

Reason:

modal deletion can occur while timers still exist.

This rule is LOCKED.

MODAL CLOSE RULE

Shared modals must use async delete where possible.

Correct:

lv_obj_delete_async(...)

Reason:

prevents deleting active objects during LVGL event traversal.

SYSTEM TIMER SAFETY RULE

Timer-driven UI refresh code must NEVER assume UI objects still exist.

ALL refresh paths must guard:

NULL pointers
stale LVGL objects

Reason:

prevents green-screen/reset crash during modal close.

ICON PIPELINE STATUS

Status:
PROVEN WORKING

Current ownership:

05_FG_Icons.h
05_FG_Icons.c

Current live icon assets:

fg_icon_system_48px
fg_icon_admin_48px
fg_icon_brightness_48px
fg_icon_sound_48px
fg_icon_wifi_48px
fg_icon_sd_card_48px
fg_icon_time_48px

ICON SIZE DECISION

Current Reactor icon size:

48px

Reason:

64px proved the icon pipeline, but 48px looks better on the 7-inch Reactor launcher.

VISUAL STYLE SYSTEM

Status:
PROVEN WORKING

Current compile-time styles:

FORGEUI_STYLE_ATLAS_LIGHT
FORGEUI_STYLE_NEBULA_BLUE
FORGEUI_STYLE_REACTOR

Current active Reactor direction:

FORGEUI_STYLE_REACTOR

STYLE SYSTEM RULES

Visual styles are controlled centrally.

Rules:

No random per-widget styling
No duplicated hardcoded colors
No hidden style ownership in tabs
No separate tab-specific color systems
No runtime skin editor yet

All visual identity must flow through:

16_UI_Style.c
16_UI_Style.h

RUNTIME OWNERSHIP

main.c
→ boot + loop only

UI
→ display only

Backends:

RTC
→ time

Audio
→ sound

WiFi
→ network

SD
→ storage

MASTER CONFIG
→ subsystem existence

STYLE SYSTEM
→ visual ownership

ADMIN GATE
→ admin access UI state

STATUS DRAWER
→ render-only status view

REACTOR MODAL SYSTEM
→ overlay + modal ownership

RUNTIME ORDER

NVS
Display
Backlight
UI
Header
Status Drawer
RTC

WiFi FIRST
SD SECOND

Main loop:

fg_wifi_pump()

CURRENT REACTOR STATE

Dashboard launcher alive
System launcher hub alive
Shared modal architecture alive
Shared keyboard overlay alive
Admin routing alive
Hidden tab engine alive
Modular icon pipeline alive
Branch isolated safely
Build stable
Flash stable
Touch-first navigation alive

KNOWN LIMITATIONS

Format requires power cycle
Reset rebuilds folders not empty
Boot marker fails post-reset
SDMMC bus not abstracted
Status drawer values static
Status drawer no animation yet
Swipe still slightly stiff on panel
Launcher modules not split into dedicated pages yet
System legacy page still parked internally
Time Reactor modal not built yet

These are accepted truths.

FINAL LOCK

WiFi first
SD second

Reset = delete + rebuild
Format = destructive + power cycle

Tabview stays alive internally
Launcher navigation is primary
Swipe is secondary
System becomes module launcher hub
Shared Reactor modals now stable
Icons remain centralized
Reactor branch now official
ForgeUI evolving toward appliance/product-grade touch launcher UI