#pragma once

#include "lvgl.h"

#ifdef __cplusplus
extern "C" {
#endif

// ============================================================
// ForgeUI One Home Screen
// ============================================================
//
// File:
// 02_UI_Home.h
//
// Purpose:
// Main single-page Home screen.
//
// Responsibilities:
// - build primary Home screen
// - render alive/runtime proof UI
// - host future launcher widgets
//
// Rules:
// - UI only
// - no backend ownership
// - no hardware ownership
// - no runtime workflow logic
//
// ============================================================

// ============================================================
// Home Screen Builder
// ============================================================

void ui_home_build(lv_obj_t *parent);

#ifdef __cplusplus
}
#endif