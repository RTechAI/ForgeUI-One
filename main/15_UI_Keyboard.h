#pragma once

// ============================================================
// ForgeUI Keyboard Overlay
// ============================================================
//
// ForgeUI
// Created by Scott Forster
// Contact: forgeui.esp32@gmail.com
//
// Purpose:
//
// Shared on-screen LVGL keyboard helper.
//
// Features:
//
// - reusable singleton keyboard
// - textarea attach/detach
// - password entry support
// - READY/CANCEL handling
// - shared overlay behaviour
//
// Used by:
//
// - WiFi password entry
// - future PIN entry
// - text input fields
// - future setup wizards
//
// Rules:
//
// - UI only
// - no backend ownership
// - no hardware ownership
// - no runtime truth storage
//
// ============================================================

#include "lvgl.h"

#ifdef __cplusplus
extern "C" {
#endif


// ============================================================
// Keyboard API
// ============================================================

// Attach keyboard to textarea and show
void fg_keyboard_attach(lv_obj_t *ta);

// Hide keyboard overlay
void fg_keyboard_hide(void);


#ifdef __cplusplus
}
#endif