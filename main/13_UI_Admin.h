#pragma once

// ============================================================
// ForgeUI Admin UI
// ============================================================
//
// ForgeUI
// Created by Scott Forster
// Contact: forgeui.esp32@gmail.com
//
// Purpose:
//
// Optional protected administration UI.
//
// Responsibilities:
//
// - build Admin page content
// - host protected UI/workflows
// - provide service/maintenance area
// - support future protected tooling
//
// Controlled through:
//
//   00_ForgeUI_Config.h
//
// Optional Features:
//
// - admin gate
// - PIN access
// - RFID access
// - maintenance tools
// - diagnostics
// - firmware/service tools
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
// Admin may be launched through:
//
// - Dashboard launcher cards
// - System launcher hub
//
// ============================================================

#include "lvgl.h"

#ifdef __cplusplus
extern "C" {
#endif


// ============================================================
// Admin Builder
// ============================================================

void ui_admin_build(lv_obj_t *parent);


#ifdef __cplusplus
}
#endif