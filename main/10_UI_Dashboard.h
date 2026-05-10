#pragma once

#include "lvgl.h"

#ifdef __cplusplus
extern "C" {
#endif

// ============================================================
// ForgeUI Dashboard Tab
// ============================================================
// Builds the Dashboard tab content.
//
// This is UI-only.
// No backend ownership.
// No hardware init.
// ============================================================

void ui_dashboard_build(lv_obj_t *parent);

#ifdef __cplusplus
}
#endif