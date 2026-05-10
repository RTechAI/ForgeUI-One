#pragma once

#include "lvgl.h"

// ============================================================
// ForgeUI Header Overlay
// ============================================================
// Global overlay/header layer.
//
// Current Features:
// - top-right RTC clock
//
// Future Direction:
// - status icons
// - notifications
// - admin/session indicators
// - telemetry indicators
//
// This layer is UI-only.
// ============================================================


// Create persistent overlay/header objects
void fg_header_create(lv_obj_t *parent);

// Refresh runtime header values
void fg_header_refresh(void);