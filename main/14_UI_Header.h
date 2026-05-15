#pragma once

// ============================================================
// ForgeUI Header Overlay
// ============================================================
//
// ForgeUI
// Created by Scott Forster
// Contact: forgeui.esp32@gmail.com
//
// Purpose:
//
// Global overlay/header UI layer.
//
// Responsibilities:
//
// - persistent overlay rendering
// - top-right RTC clock display
// - lightweight runtime status display
// - shared overlay positioning
//
// Current Features:
//
// - top-right RTC clock
// - persistent foreground overlay
//
// Rules:
//
// - UI only
// - no backend ownership
// - no hardware ownership
// - no runtime truth storage
//
// Backend modules own truth.
// This layer renders display state only.
//
// Future Direction:
//
// - status icons
// - notifications
// - admin/session indicators
// - telemetry indicators
// - product badges
// - live connection indicators
//
// ============================================================

#include "lvgl.h"


// ============================================================
// Header Overlay
// ============================================================

// Create persistent overlay/header objects
void fg_header_create(lv_obj_t *parent);

// Refresh runtime header values
void fg_header_refresh(void);