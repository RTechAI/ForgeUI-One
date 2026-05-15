#pragma once

// ============================================================
// ForgeUI Pre Operation UI
// ============================================================
//
// ForgeUI
// Created by Scott Forster
// Contact: forgeui.esp32@gmail.com
//
// Purpose:
//
// Optional workflow / application module.
//
// Current direction:
//
// - workflow placeholder
// - industrial workflow area
// - ForkGuard-compatible expansion point
//
// Rules:
//
// - UI only
// - no backend ownership
// - no hardware ownership
// - no runtime truth storage
//
// Controlled by:
//
//   FORGEUI_ENABLE_PREOP
//
// in:
//
//   00_ForgeUI_Config.h
//
// Future direction:
//
// - digital forms
// - checklist systems
// - inspection workflows
// - operator workflows
// - telemetry-linked actions
//
// This module is intended to remain:
//
// - optional
// - removable
// - product configurable
//
// ============================================================

#include "lvgl.h"

#ifdef __cplusplus
extern "C" {
#endif


// ============================================================
// Pre Operation Builder
// ============================================================

void ui_preop_build(lv_obj_t *parent);


#ifdef __cplusplus
}
#endif