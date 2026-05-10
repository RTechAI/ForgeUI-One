#pragma once

#include "lvgl.h"

#ifdef __cplusplus
extern "C" {
#endif

// ============================================================
// ForgeUI Admin Tab
// ============================================================
// Optional protected administration UI.
//
// Controlled through:
//   00_ForgeUI_Config.h
//
// Optional Features:
// - admin gate
// - PIN access
// - RFID access
// - maintenance tools
//
// This is UI-only.
// No backend ownership.
// ============================================================

void ui_admin_build(lv_obj_t *parent);

#ifdef __cplusplus
}
#endif