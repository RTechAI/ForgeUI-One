#pragma once

#include "lvgl.h"

#ifdef __cplusplus
extern "C" {
#endif

// ============================================================
// ForgeUI System Tab
// ============================================================
// Main runtime system/settings UI.
//
// Controlled through:
//   00_ForgeUI_Config.h
//
// This is UI-only.
// Backend modules own system state/truth.
// ============================================================

void ui_system_build(lv_obj_t *parent);

#ifdef __cplusplus
}
#endif