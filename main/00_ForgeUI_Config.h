// ============================================================
// ForgeUI One
// ============================================================
//
// Created by Scott Forster
// Contact: forgeui.esp32@gmail.com
//
// Clean ESP32-P4 LVGL starter framework.
//
// Purpose:
// - single-page alive baseline
// - display + touch proof
// - header + styling baseline
// - hosted WiFi support
// - SD card support
// - RTC support
// - optional audio support
//
// Designed to help ESP32-P4 developers get a stable UI baseline
// alive faster.
//
// Please retain ForgeUI attribution in public, commercial,
// educational, or redistributed builds.
//
// Powered by ForgeUI
//
// ============================================================

// ============================================================
// Studio Export Test
// ============================================================
//
// Enables temporary ForgeUI Studio -> LVGL export testing.
//
// Purpose:
// - validate generated LVGL code
// - validate Studio coordinate export
// - validate physical ESP32-P4 rendering
//
// When enabled:
// - 90_Studio_Export.c may inject generated LVGL objects
// - generated screens may appear on top of ForgeUI One UI
//
// This is a temporary experimental bridge layer.
//
// ============================================================

#define FORGEUI_ENABLE_STUDIO_EXPORT_TEST  1


#pragma once

#include "driver/i2c_master.h"

// ============================================================
// ForgeUI Version
// ============================================================

#define FORGEUI_VERSION_MAJOR              1
#define FORGEUI_VERSION_MINOR              0
#define FORGEUI_VERSION_PATCH              0

// ============================================================
// Core Feature Switches
// ============================================================
//
// These switches control which ForgeUI One modules are compiled
// into the live runtime.
//
// Keep the single-page base light.
// Turn optional hardware features on only when needed.
//
// ============================================================

#define FORGEUI_ENABLE_RTC                 1
#define FORGEUI_ENABLE_WIFI                1
#define FORGEUI_ENABLE_SD                  1
#define FORGEUI_ENABLE_AUDIO               0

// ============================================================
// Header Options
// ============================================================

#define FORGEUI_ENABLE_HEADER              1
#define FORGEUI_SHOW_HEADER_CLOCK          1

// ============================================================
// Display Options
// ============================================================

#define FORGEUI_ROTATION_0                 0
#define FORGEUI_ROTATION_180               1

#define FORGEUI_DISPLAY_ROTATION           FORGEUI_ROTATION_180

// ============================================================
// Theme IDs
// ============================================================

#define FORGEUI_STYLE_ATLAS_LIGHT          0
#define FORGEUI_STYLE_NEBULA_BLUE          1
#define FORGEUI_STYLE_CARBON               2

// ============================================================
// Active Theme
// ============================================================
//
// Select ONE active style.
//
// ============================================================

//#define FORGEUI_STYLE_ACTIVE             FORGEUI_STYLE_ATLAS_LIGHT
#define FORGEUI_STYLE_ACTIVE             FORGEUI_STYLE_NEBULA_BLUE


// ============================================================
// Icon Set IDs
// ============================================================

#define FORGEUI_ICON_SET_LIGHT_32          0
#define FORGEUI_ICON_SET_DARK_32           1
#define FORGEUI_ICON_SET_LIGHT_48          2
#define FORGEUI_ICON_SET_DARK_48           3
#define FORGEUI_ICON_SET_DARK_64           4

// ============================================================
// Active Icon Set
// ============================================================

#define FORGEUI_ICON_SET_ACTIVE            FORGEUI_ICON_SET_DARK_48

// ============================================================
// WiFi Backend Options
// ============================================================
//
// ESP32-P4 has no native WiFi radio.
//
// ForgeUI One WiFi path:
//
// ESP32-P4
// -> ESP-Hosted
// -> SDIO
// -> ESP32-C6
// -> WiFi Remote
//
// ============================================================

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
//
// DS3231 is the preferred retained-time backend.
// ESP_NVS is a fallback/software-only option.
//
// ============================================================

#if FORGEUI_ENABLE_RTC
#define FORGEUI_RTC_BACKEND                FORGEUI_RTC_BACKEND_DS3231
#else
#define FORGEUI_RTC_BACKEND                FORGEUI_RTC_BACKEND_NONE
#endif

// ============================================================
// DS3231 Settings
// ============================================================
//
// Board path:
// - DS3231 on BSP I2C bus
// - address 0x68
// - ESP32-P4 I2C_NUM_0
//
// ============================================================

#define FORGEUI_DS3231_ADDR                0x68
#define FORGEUI_DS3231_I2C_PORT            I2C_NUM_0

#define FORGEUI_DS3231_SDA_IO              7
#define FORGEUI_DS3231_SCL_IO              8

// ============================================================
// SD / WiFi Boot Order Truth
// ============================================================
//
// Current proven stable Hosted WiFi + SD order:
//
//   WiFi init first
//   -> SD mount second
//
// Do not mount SD before Hosted WiFi on this ESP32-P4 board
// unless this has been retested and proven again.
//
// ============================================================

// ============================================================
// Runtime Ownership Rules
// ============================================================
//
// main.c:
// - boot order only
// - board bring-up only
// - LVGL startup only
//
// backend modules:
// - own hardware state
// - own system truth
//
// UI modules:
// - render only
// - send intent only
// - no hardware ownership
//
// ============================================================

// ============================================================
// ForgeUI One Identity
// ============================================================
//
// This project is ForgeUI One.
//
// Do not reintroduce old runtime names:
// - ForkGuard
// - Reactor UI
// - LVGL demo widgets
// - vendor demo runtime ownership
//
// Old names may only appear in historical notes,
// never in active module ownership.
//
// ============================================================
//
// Powered by ForgeUI
//
// Build cool stuff.
// Enjoy.
// Let me know how your project goes.
//
// ============================================================