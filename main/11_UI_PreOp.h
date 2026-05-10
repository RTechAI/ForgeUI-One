#pragma once

#include "lvgl.h"

#ifdef __cplusplus
extern "C" {
#endif

// ============================================================
// ForgeUI Pre Operation Tab
// ============================================================
// Optional workflow/application module.
//
// This is UI-only.
// No backend ownership.
// No hardware init.
//
// Controlled by:
//   FORGEUI_ENABLE_PREOP
// in:
//   00_ForgeUI_Config.h
// ============================================================

void ui_preop_build(lv_obj_t *parent);

#ifdef __cplusplus
}
#endif