#pragma once

// ============================================================
// ForgeUI System UI
// ============================================================
//
// ForgeUI
// Created by Scott Forster
// Contact: forgeui.esp32@gmail.com
//
// Purpose:
//
// Main runtime system/settings UI builder.
//
// Responsibilities:
//
// - build System launcher hub
// - expose system controls
// - launch Reactor modals
// - render backend status
// - send user intent to backend modules
//
// Controlled through:
//
//   00_ForgeUI_Config.h
//
// Rules:
//
// - UI only
// - no backend ownership
// - no hardware ownership
// - no runtime truth storage
//
// Backend modules own system truth.
// This layer renders state and sends intent only.
//
// Current Reactor direction:
//
// System acts as:
//
// - settings hub
// - hardware proof hub
// - modular launcher
// - shared modal entry point
//
// ============================================================

#include "lvgl.h"

#ifdef __cplusplus
extern "C" {
#endif


// ============================================================
// System Builder
// ============================================================

void ui_system_build(lv_obj_t *parent);


#ifdef __cplusplus
}
#endif