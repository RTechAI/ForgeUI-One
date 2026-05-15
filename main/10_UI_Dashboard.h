#pragma once

// ============================================================
// ForgeUI Dashboard UI
// ============================================================
//
// ForgeUI
// Created by Scott Forster
// Contact: forgeui.esp32@gmail.com
//
// Purpose:
//
// Dashboard / home screen UI builder.
//
// Responsibilities:
//
// - build Dashboard page content
// - create launcher cards
// - provide top-level UI entry points
// - route user navigation intent
//
// Rules:
//
// - UI only
// - no backend ownership
// - no hardware ownership
// - no runtime truth storage
//
// Current Reactor direction:
//
// Dashboard acts as:
//
// - home screen
// - launcher hub
// - appliance-style entry point
//
// Primary navigation:
//
// - launcher cards
// - icon taps
//
// Secondary navigation:
//
// - hidden tabview swipe routing
//
// ============================================================

#include "lvgl.h"

#ifdef __cplusplus
extern "C" {
#endif


// ============================================================
// Dashboard Builder
// ============================================================

void ui_dashboard_build(lv_obj_t *parent);


#ifdef __cplusplus
}
#endif