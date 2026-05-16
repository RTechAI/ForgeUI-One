#pragma once

#include "lvgl.h"

#ifdef __cplusplus
extern "C" {
#endif

// ============================================================
// ForgeUI One Keyboard Helper
// ============================================================
//
// File:
// 15_UI_Keyboard.h
//
// Created by:
// Scott Forster
//
// Contact:
// forgeui.esp32@gmail.com
//
// Purpose:
// Shared LVGL on-screen keyboard helper.
//
// Responsibilities:
// - reusable singleton keyboard
// - textarea attach/detach
// - shared text-entry path
// - keyboard show/hide lifecycle
//
// Current Features:
// - password entry support
// - READY/CANCEL handling
// - shared overlay behaviour
// - theme-aware keyboard styling
//
// Used By:
// - WiFi password entry
// - future PIN entry
// - text input fields
// - future setup/config screens
//
// Rules:
// - UI only
// - no backend ownership
// - no hardware ownership
// - no runtime truth storage
// - no workflow ownership
//
// ============================================================

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