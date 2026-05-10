#pragma once

#include "lvgl.h"

#ifdef __cplusplus
extern "C" {
#endif

// ============================================================
// ForgeUI Keyboard Overlay
// ============================================================
// Shared on-screen LVGL keyboard helper.
//
// Features:
// - reusable singleton keyboard
// - textarea attach/detach
// - password entry support
// - READY/CANCEL handling
//
// Used by:
// - WiFi password entry
// - future PIN entry
// - text input fields
//
// This is UI-only.
// ============================================================


// Attach keyboard to textarea and show
void fg_keyboard_attach(lv_obj_t *ta);

// Hide keyboard overlay
void fg_keyboard_hide(void);

#ifdef __cplusplus
}
#endif