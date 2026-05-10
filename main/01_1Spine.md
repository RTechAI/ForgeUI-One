FORGEUI P4 SPINE
SAVE POINT: FORGEUI_P4_586__STATUS_DRAWER_V1_ALIVE__CONFIG_SIDE_ALIGN_PROVEN__2026-05-10

Board Model: WAVESHARE ESP32-P4-WIFI6-TOUCH-LCD-7B
Project: ForgeUI
ForkGuard retired for this baseline

PURPOSE

This document defines the current ForgeUI P4 hardware-baseline structure, rules, ownership boundaries, known-good boot order, visual style direction, admin gate direction, and status drawer direction.

It is the single source of truth for:

module layout
responsibility boundaries
runtime ownership
hardware proof status
ESP32-P4 + ESP32-C6 hosted Wi-Fi strategy
SD card integration strategy
future product handover direction
master feature config ownership
backend ownership strategy
visual style ownership strategy
product UI consistency rules
admin gate ownership
status drawer ownership

CURRENT MISSION

Build a fully alive, hardware-proven ForgeUI baseline.

Rules:

No demos in runtime path
No guessing
No hidden duplicate drivers
No random per-widget styling
No subsystem owning another subsystem
Everything must be simple enough for someone else to follow later

Goal:

Everything works → then build product on top

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

This is not a one-off demo screen anymore.

PLATFORM TRUTH — ESP32-P4 WIFI

ESP32-P4 has NO native Wi-Fi radio

Actual Wi-Fi path:

ESP32-P4 host
→ onboard ESP32-C6 radio
→ ESP-Hosted
→ SDIO transport
→ Wi-Fi Remote
→ ESP-IDF Wi-Fi API

Wi-Fi API appears normal in code
Radio is remote

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
Screen rotation: OK
Native BSP panel orientation: OK
Startup 180° flip: FIXED
Hosted WiFi (ESP32-C6 over SDIO): OK
WiFi scan/connect/disconnect: OK
WiFi-first / SD-second workaround: OK
SD mount after Hosted WiFi: OK
Safe SD rebuild/reset: OK
Keyboard overlay: OK
Feature modular config system: OK
Nebula Blue theme pass: STARTED
Admin gate dev switch: OK
Admin PIN keypad path: PROVEN
Status drawer V1: ALIVE
Status drawer side config: PROVEN

DISPLAY ROTATION TRUTH

The Waveshare ESP32-P4-WIFI6-Touch-LCD-7B native display orientation is already correct.

REMOVE:
    bsp_display_rotate(disp, LV_DISPLAY_ROTATION_180);

This forced rotation caused:
- visible startup flip
- white/FPS rotate transition
- unnecessary redraw overhead

ForgeUI now runs in native BSP orientation.

HOSTED WIFI STATUS

Status: PROVEN WORKING

Proven:

ESP-Hosted SDIO transport
ESP32-C6 detected
Transport active
MAC read
STA started
Scan pipeline working
SSIDs returned
RSSI returned
UI Wi-Fi status alive
Scan/select/password/connect/IP/forget working
Stable with current boot order

Proof logs:

transport: Identified slave [esp32c6]
H_API: Transport active
FG_WIFI: STA started
FG_WIFI: WiFi hosted init READY
FG_WIFI: SCAN DONE EVENT FIRED

SD CARD STATUS

Status: PROVEN WORKING

Proven:

SDMMC mount
FAT filesystem
File create
File read
256GB SDHC
4-bit mode
40 MHz
Read/write test pass

Proof log:

FG_SD: SD mounted OK
FG_SD: SD TEST PASS

CRITICAL WIFI + SD RULE

Correct boot order:

fg_wifi_init()
fg_sd_init()
fg_sd_test()

Do NOT mount SD before Wi-Fi

Reason:

ESP-Hosted claims SDMMC first
SD mount safely attaches after

Golden proof:

sdmmc_host already initialized, skipping init flow

Breaking this causes:

SD failure
timeouts
conflicts
unstable Wi-Fi

SDMMC BUS STRATEGY

50_SDMMC_BUS.* exists

Status: UNUSED / PLACEHOLDER

Do not build custom bus layer yet

Working system relies on:

Wi-Fi first
SD second

WIFI ARCHITECTURE RULE

Never run heavy logic in event handler

Correct:

event → flag
main loop → fg_wifi_pump()

This is locked

ESP-IDF BASELINE

Version: 5.5.4

Do NOT drift casually

Required:

ESP-Hosted enabled
Wi-Fi Remote enabled
PSRAM XIP FROM PSRAM = OFF

PROJECT STRUCTURE

main/

00_ForgeUI_Config
01_Spine.md

01_FG_HMI
02_FG_HMI

10_UI_Dashboard
11_UI_PreOp
12_UI_System
13_UI_Admin
14_UI_Header
15_UI_Keyboard
16_UI_Style
16_UI_AdminGate
17_UI_StatusDrawer

20_RTC

30_Audio
30_WIFI
40_SD

50_SDMMC_BUS unused / placeholder

main.c
CMakeLists.txt

MASTER CONFIG CONTROL LAYER

Status: PROVEN WORKING

ForgeUI has central feature ownership through:

00_ForgeUI_Config.h

MASTER FEATURE SWITCHES

FORGEUI_ENABLE_RTC
FORGEUI_ENABLE_AUDIO
FORGEUI_ENABLE_WIFI
FORGEUI_ENABLE_SD

Architecture rule:

Config owns existence

Meaning:

Disabled feature =

no backend init
no runtime pump
no tile creation
no event handlers
no hidden subsystem state

This is the official ForgeUI modular architecture baseline.

CONFIG FILE OWNERSHIP

00_ForgeUI_Config.h is the SINGLE source of truth for:

feature existence
backend selection
hardware backend routing
compile-time subsystem ownership
visual style selection
admin gate behaviour
status drawer side and sizing

Rules:

No subsystem should decide its own backend internally.

All backend selection must originate from:

00_ForgeUI_Config.h

Current backend ownership:

Wi-Fi:
FORGEUI_WIFI_BACKEND

RTC:
FORGEUI_RTC_BACKEND

Visual Style:
FORGEUI_STYLE_ACTIVE

Admin Gate:
FORGEUI_ENABLE_ADMIN_GATE
FORGEUI_ADMIN_DEFAULT_PIN
FORGEUI_ADMIN_SESSION_TIMEOUT_MIN

Status Drawer:
FORGEUI_STATUS_DRAWER_LEFT
FORGEUI_STATUS_DRAWER_RIGHT
FORGEUI_STATUS_DRAWER_WIDTH
FORGEUI_STATUS_DRAWER_HANDLE_W
FORGEUI_STATUS_DRAWER_HANDLE_H
FORGEUI_STATUS_DRAWER_Y
FORGEUI_STATUS_DRAWER_BOTTOM_GAP

Future systems should follow same model:

GPS
SIM
Storage
Authentication
Cloud sync
Extra visual styles
Extra status drawer fields

WIFI BACKEND MODEL

Current backend options:

FORGEUI_WIFI_BACKEND_NONE
FORGEUI_WIFI_BACKEND_HOSTED

Current active backend:

FORGEUI_WIFI_BACKEND_HOSTED

Current status:

Hosted Wi-Fi fully proven working
Scan/select/password/connect/IP/forget alive

RTC BACKEND MODEL

Current backend options:

FORGEUI_RTC_BACKEND_NONE
FORGEUI_RTC_BACKEND_ESP_NVS
FORGEUI_RTC_BACKEND_DS3231

Current active backend:

FORGEUI_RTC_BACKEND_DS3231

ADMIN GATE STATUS

Status: PROVEN WORKING

Current design:

Admin gate is controlled by config.

FORGEUI_ENABLE_ADMIN_GATE = 0

Admin area opens in dev mode.

FORGEUI_ENABLE_ADMIN_GATE = 1

Admin area uses PIN keypad gate.

Current default PIN:

FORGEUI_ADMIN_DEFAULT_PIN = "1234"

Current timeout:

FORGEUI_ADMIN_SESSION_TIMEOUT_MIN = 0

Meaning:

No timeout yet.

Admin gate V1 truth:

dev/open mode works
PIN keypad appears when gate enabled
PIN verification path proven
correct PIN unlocks admin
wrong PIN stays locked
admin gate styling follows shared style system
NVS/changeable PIN can come later

ADMIN GATE RULE

Admin gate owns only admin access UI state.

It must NOT:

own Wi-Fi
own SD
own RTC
own Audio
start backend logic
change global app state outside admin access

STATUS DRAWER STATUS

Status: V1 ALIVE / CONFIG SIDE ALIGN PROVEN

Module:

17_UI_StatusDrawer.c
17_UI_StatusDrawer.h

Current behaviour:

right or left side drawer controlled by config
small edge handle shown on selected side
tap handle opens drawer
tap handle again hides drawer
drawer renders on lv_layer_top()
drawer uses shared style helpers
drawer does not permanently occupy tab header
drawer no longer uses full screen top overlay approach

Current V1 content:

WiFi: READY
SD: READY
RTC: OK
Audio: ON
Admin: DEV

Current config:

FORGEUI_STATUS_DRAWER_LEFT = 1
FORGEUI_STATUS_DRAWER_RIGHT = 0

FORGEUI_STATUS_DRAWER_WIDTH = 240

FORGEUI_STATUS_DRAWER_HANDLE_W = 28
FORGEUI_STATUS_DRAWER_HANDLE_H = 120

FORGEUI_STATUS_DRAWER_Y = 64
FORGEUI_STATUS_DRAWER_BOTTOM_GAP = 27

STATUS DRAWER RULE

Status drawer is render-only.

It may read status later from:

Wi-Fi backend
SD backend
RTC backend
Audio enabled state
Admin gate state

It must NOT:

start Wi-Fi
mount SD
set RTC
play audio
change Admin state
own backend logic

STATUS DRAWER DESIGN DECISION

Top status overlay was tested and rejected.

Reason:

Permanent top overlay sat over tab/header area
visual conflict with tab bar
bad fit for current UI structure

Replacement design:

slide-out side drawer

Why:

does not fight tab/header layout
keeps main UI clean
can hold more detail later
better product feel
easier to add icons/images later
config can place left or right

STATUS DRAWER NEXT POLISH

Future improvements only after V1 is stable:

handle arrow changes direction open/closed
optional slide animation
status values become live instead of static
small icon support
per-pill enable flags
drawer opacity config
drawer width tuning
green/amber/red state colours
left/right handle arrow correctness

Do not overbuild yet.

VISUAL STYLE SYSTEM

Status: PROVEN WORKING

ForgeUI now has centralized visual style ownership.

Current compile-time styles:

FORGEUI_STYLE_ATLAS_LIGHT
FORGEUI_STYLE_NEBULA_BLUE

Current active style:

FORGEUI_STYLE_NEBULA_BLUE

STYLE SYSTEM RULES

Visual styles are controlled centrally.

Rules:

No random per-widget styling
No duplicated hardcoded colors
No hidden style ownership in tabs
No separate tab-specific color systems
No runtime skin editor yet

All visual identity should flow through:

16_UI_Style.c
16_UI_Style.h

Current style helpers:

fg_style_apply_screen()
fg_style_apply_tile()
fg_style_apply_panel()
fg_style_apply_button()
fg_style_apply_dropdown()
fg_style_apply_textarea()
fg_style_apply_label()
fg_style_apply_label_dim()

Current color helpers:

fg_style_bg()
fg_style_tile()
fg_style_panel()
fg_style_border()
fg_style_text()
fg_style_text_dim()
fg_style_accent()

Current metric helper:

fg_style_radius()

STYLE CONTRACT FOR ALL TABS

Every tab must follow the same pattern:

apply screen style
create main panel or tile
apply tile or panel style
use shared layout rules
use style helpers for labels
use style helpers for buttons
use style helpers for inputs

Correct pattern:

fg_style_apply_screen(parent)
main panel/tile
fg_style_apply_tile(panel)
labels use fg_style_apply_label or fg_style_apply_label_dim
buttons use fg_style_apply_button
dropdowns use fg_style_apply_dropdown
textareas use fg_style_apply_textarea

Avoid:

custom tab colours
custom tab radius values
random LVGL defaults
hardcoded dark hacks
different layout language per tab

NEBULA BLUE STATUS

Status: PROVEN WORKING

Current visual direction:

dark navy background
industrial sharp corners
blue accent buttons
cyan/blue borders
clean modern embedded look

Current system integration:

System page background styled
System tiles styled
RTC buttons styled
WiFi buttons styled
WiFi dropdown styled
WiFi password textarea styled
WiFi labels styled
SD labels styled
SD buttons styled
Audio labels styled
Audio buttons styled
Brightness labels styled
Apply button styled
Header clock styled
Tab bar styling started
Keyboard panel styling started
Admin gate styled
Status drawer styled through shared panel/button/label helpers

Architecture proven:

single config switch changes UI personality

UI STYLE NOTE

The bright blue buttons currently work but may be slightly too light / arcade-looking.

Possible later button accent options:

0x1D6FD6
0x245C9E

Do not change this until the full tab style pass is stable.

CURRENT TAB STYLE STATUS

System:

Status: MOSTLY STYLED / WORKING

Includes:

screen background
tiles
buttons
labels
WiFi dropdown
WiFi password field
SD labels
RTC controls
header clock visible
dark style proven on hardware

Dashboard:

Status: STYLE PASS STARTED

Current direction:

use same ForgeUI tab contract
screen background styled
main full-size panel/tile
title label
dim subtitle

PreOp:

Status: STYLE PASS STARTED

Current direction:

use same ForgeUI tab contract
screen background styled
main full-size panel/tile
title label
dim subtitle

Admin:

Status: STYLE PASS STARTED / GATE PROVEN

Current direction:

use same ForgeUI tab contract
screen background styled
main full-size panel/tile
Admin Locked state styled
PIN keypad path proven
Dev unlock path preserved

Header / Tab Bar:

Status: STYLE PASS STARTED

Current direction:

style active screen
style tabview background
style tab bar panel
style header clock dim text
keep header overlay top-right

Known issue fixed:

14_UI_Header.c had duplicate fg_header_refresh()
Fix was to replace file with single clean fg_header_refresh() definition.

Keyboard:

Status: STYLE PASS STARTED

Current direction:

keyboard remains global overlay
keyboard created once
keyboard styled with fg_style_apply_panel()
keyboard remains moved to foreground on attach

SYSTEM WIFI TILE LAYOUT

Current issue:

Tiny scroll remained in WiFi tile.

Fix direction:

Move Forget WiFi beside Disconnect on the same row.

Current intended WiFi button layout:

Scan WiFi
Dropdown
Password
Connect
Disconnect | Forget WiFi

Reason:

removes small scroll
improves product layout
keeps WiFi tile compact
makes action grouping cleaner

RTC CURRENT DESIGN

Current active RTC path:

DS3231
→ sets ESP runtime/system time
→ runtime uses ESP time only
→ DS3231 provides power-loss retention

This is the official ForgeUI RTC architecture baseline.

DS3231 HARD RULE

DS3231 driver MUST NOT:

create I2C bus
reconfigure BSP bus
change bus speed
own bus lifetime

DS3231 only ATTACHES to existing BSP-owned bus.

Current DS3231 settings:

FORGEUI_DS3231_ADDR = 0x68
FORGEUI_DS3231_I2C_PORT = I2C_NUM_0
FORGEUI_DS3231_SDA_IO = GPIO7
FORGEUI_DS3231_SCL_IO = GPIO8

RTC FILE STATUS

20_RTC.c is currently clean and product-grade.

Good design:

DS3231 owns persistence
ESP system time owns runtime
NVS fallback exists
validation layer exists
formatting isolated
BSP owns I2C
DS3231 only attaches to bus

Do not touch RTC unless broken.

Possible future cleanup only:

split DS3231 internals into 21_RTC_DS3231.c
add fg_rtc_is_valid()
add seconds apply option later

AUDIO STATUS

30_Audio.c is clean.

Good design:

BSP audio path
speaker codec init
volume clamp
lazy init
busy guard
simple sine beep
no UI/style coupling

Do not add theme or UI logic to audio backend.

PROVEN CONFIG TESTS

Wi-Fi OFF:

no Wi-Fi init
no Wi-Fi pump
no Wi-Fi System tile

SD OFF:

no SD System tile

Audio OFF:

no Audio tile
no Audio handlers

RTC OFF:

no RTC tile
no RTC handlers
no RTC helper logic

Admin Gate OFF:

admin opens in dev mode
no PIN required

Admin Gate ON:

PIN keypad gate appears
correct PIN unlocks admin

Status Drawer LEFT:

handle and drawer appear left

Status Drawer RIGHT:

handle and drawer appear right

UI FEATURE RULE

FORGEUI_ENABLE_* flags are BUILD-TIME ownership only.

Current system does NOT support:

runtime feature enable
hidden tile enable
dynamic subsystem loading

Disabled means:

not compiled
not initialized
not rendered
not pumped

Brightness remains ALWAYS ON.

Brightness is treated as:

core UI/display infrastructure

NOT optional hardware.

RUNTIME OWNERSHIP

main.c → boot + loop only

UI → display only

Backends:

RTC → time
Audio → sound
Wi-Fi → network
SD → storage

MASTER CONFIG → subsystem existence
STYLE SYSTEM → visual ownership
ADMIN GATE → admin access UI state
STATUS DRAWER → render-only status view

RUNTIME ORDER

NVS
Display
Backlight
UI
Header
Status Drawer
RTC

Wi-Fi FIRST
SD SECOND

Main loop:

fg_wifi_pump()

CURRENT SD SYSTEM DESIGN

SD path:

/sdcard

ForgeUI path:

/sdcard/ForgeUI

FORGEUI FILE STRUCTURE

/ForgeUI
/config
/logs
/users
/preop
/export
/backups
/system

SD TILE — CURRENT BEHAVIOUR

There are THREE distinct operations:

FORMAT SD LOW LEVEL

Full FAT format
Deletes everything
Rebuilds folders
Triggers restart

REAL BEHAVIOUR:

Format completes
System needs settle time
Manual power cycle required

Rule:

Do NOT remount immediately

RESET FORGEUI STORAGE SOFT RESET

Deletes contents of /ForgeUI
Deletes subfolders
Rebuilds folder structure immediately

IMPORTANT:

Folders WILL still exist after reset

This is correct behaviour

Reset = clean rebuild
NOT empty SD

CREATE / INITIALISE FOLDERS

Creates ForgeUI structure only

Does not delete anything

Used for:

First boot
Repair
Manual init

CRITICAL USER CONFUSION FIX

Reset does:

delete → rebuild

So folders showing after reset is EXPECTED

BOOT MARKER STATUS

Path:

/ForgeUI/system/boot_marker.txt

Current behaviour:

Fails after reset errno=22

Decision:

Do NOT write during reset

Keep as:

separate button
or delayed action

CURRENT SYSTEM UI STATE

Current layout direction:

top row:

Display Brightness
Sound

middle row:

WiFi
SD Card

bottom row:

RTC Time Set full-width tile

RTC TILE STATUS

Status: CLEAN GRID LAYOUT PROVEN

RTC tile converted from:

old vertical 6-row stack

to:

balanced 3-row dual-column layout

Current structure:

Left side:

Year
Month
Day

Right side:

Hour
Min
Sec

Design goals achieved:

full-width lower tile
no internal scrolling
balanced spacing
larger touch targets
cleaner visual alignment
consistent typography
Apply button no longer clipped

RTC BUTTON SIZING

Old size:

26 x 22

New standard size:

34 x 28

Reason:

Better usability on 7-inch touch panel
Cleaner visual balance
More product-grade appearance

RTC FONT STANDARD

RTC labels now use:

lv_font_montserrat_16

This matches the rest of the System page typography.

RTC GRID RULE

RTC now uses LVGL grid layout rather than stacked flex rows.

Reason:

Better alignment
Cleaner spacing
Future-safe scaling
More professional settings-page appearance

CURRENT SYSTEM PAGE DIRECTION

Goals:

aligned tiles
balanced spacing
no clipped controls
consistent font sizing
touch-friendly controls
reduced visual clutter
cleaner white-space usage
more polished product feel

Current visual direction:

dark industrial embedded UI
clean navy backgrounds
sharp modern panels
reusable product-grade style layer

CURRENT SYSTEM STATE

Wi-Fi READY
SD READY
RTC READY
Audio READY
SD TEST PASS
Admin gate dev mode active
Status drawer V1 alive
NEBULA BLUE STYLE PASS
System stable

KNOWN LIMITATIONS

Format requires power cycle
Reset rebuilds folders not empty
Boot marker fails post-reset
SDMMC bus not abstracted
Slider accent still needs cleanup
Top tab/header style is started but may need polish
Dashboard/PreOp/Admin are simple styled placeholders for now
Status drawer values are static V1 labels
Status drawer has no animation yet
Status drawer handle arrow does not yet change with side/open state

These are accepted truths

NEXT STEP

Finish status drawer V1 polish:

align drawer exactly to main content panel
make handle arrow correct for left/right and open/closed
optionally add live refresh values
keep drawer render-only

Then finish style engine application across:

Dashboard
PreOp
Admin
Header/tab bar
Keyboard

Then:

slider accent cleanup
button colour tuning
dropdown popup styling if needed
small layout polish only

DO NOT OVERBUILD

Only keep a few visual styles.

Accepted style set direction:

ATLAS_LIGHT
NEBULA_BLUE

Possible future only:

FORGE_ORANGE
MIDNIGHT_STEEL

Avoid:

runtime theme editor
20 colour pickers
per-widget style menus
gamer RGB effects
complex animation system
permanent top status overlay

FINAL LOCK

Wi-Fi first
SD second

Reset = delete + rebuild
Format = destructive + power cycle

RTC grid layout proven
Master config layer proven
Style engine proven
Admin gate dev/PIN path proven
Status drawer V1 alive
Nebula Blue proven
System stable and modular-product ready

Updated from current spine source