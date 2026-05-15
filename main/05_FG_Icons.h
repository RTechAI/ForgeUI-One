#pragma once

// ============================================================
// ForgeUI Icon Pipeline
// ============================================================
//
// ForgeUI
// Created by Scott Forster
// Contact: forgeui.esp32@gmail.com
//
// Purpose:
//
// Shared icon accessor interface.
//
// UI modules should access icons through
// this layer rather than directly touching
// LVGL image asset symbols.
//
// This allows:
//
// - centralized icon ownership
// - future icon pack switching
// - theme-aware icon systems
// - cleaner module separation
//
// Rules:
//
// - no UI logic
// - no styling logic
// - no backend ownership
// - no runtime state ownership
//
// Current Reactor baseline:
//
// - shared centralized icons
// - 48px icon pipeline
// - touch-first launcher support
//
// Future direction:
//
// - dark/light icon packs
// - runtime icon scaling
// - appliance-specific icon sets
// - customer branding packs
//
// ============================================================

#include "lvgl.h"

#ifdef __cplusplus
extern "C" {
#endif


// ============================================================
// Shared Icon Accessors
// ============================================================

const void *fg_icon_system(void);
const void *fg_icon_admin(void);
const void *fg_icon_sdcard(void);
const void *fg_icon_sound(void);
const void *fg_icon_wifi(void);
const void *fg_icon_brightness(void);
const void *fg_icon_time(void);


#ifdef __cplusplus
}
#endif