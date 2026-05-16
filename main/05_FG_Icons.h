#pragma once

#include "lvgl.h"

#ifdef __cplusplus
extern "C" {
#endif

// ============================================================
// ForgeUI One Icon Pipeline
// ============================================================
//
// File:
// 05_FG_Icons.h
//
// Purpose:
// Shared icon accessor interface.
//
// UI modules should access icons through
// this layer rather than directly touching
// LVGL image asset symbols.
//
// Responsibilities:
// - centralised icon ownership
// - icon pack abstraction
// - future theme/icon switching
//
// Rules:
// - no UI logic
// - no styling logic
// - no backend ownership
// - no runtime ownership
// - no hardware ownership
//
// ============================================================

// ============================================================
// Shared Icon Accessors
// ============================================================

const void *fg_icon_home(void);

const void *fg_icon_sound(void);
const void *fg_icon_wifi(void);
const void *fg_icon_sdcard(void);
const void *fg_icon_time(void);

#ifdef __cplusplus
}
#endif