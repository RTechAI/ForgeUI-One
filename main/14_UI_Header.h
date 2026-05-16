#pragma once

#include "lvgl.h"

#ifdef __cplusplus
extern "C" {
#endif

// ============================================================
// ForgeUI One Header Layer
// ============================================================
//
// File:
// 14_UI_Header.h
//
// Purpose:
// Lightweight optional top UI layer.
//
// Responsibilities:
// - create persistent foreground header layer
// - render optional top-right RTC clock
// - keep header positioning centralised
//
// Rules:
// - UI only
// - no backend ownership
// - no hardware ownership
// - no runtime truth storage
// - no routing
// - no workflow logic
//
// ============================================================

// ============================================================
// Header API
// ============================================================

void fg_header_create(lv_obj_t *parent);
void fg_header_refresh(void);

#ifdef __cplusplus
}
#endif