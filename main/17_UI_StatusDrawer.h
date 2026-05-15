#pragma once

// ============================================================
// ForgeUI Status Drawer
// ============================================================
//
// ForgeUI
// Created by Scott Forster
// Contact: forgeui.esp32@gmail.com
//
// Purpose:
//
// Global slide-out runtime status drawer.
//
// Features:
//
// - edge toggle handle
// - overlay drawer panel
// - runtime status display
// - config-controlled left/right side
//
// Rules:
//
// - UI only
// - no backend ownership
// - no hardware ownership
// - no runtime truth storage
//
// Backend modules own truth.
// Drawer only renders display state.
//
// Future Direction:
//
// - live backend state
// - notifications
// - alerts
// - telemetry indicators
// - quick settings
// - product status badges
//
// ============================================================


// ============================================================
// Status Drawer API
// ============================================================

// Create global status drawer
void fg_status_drawer_create(void);

// Toggle drawer open/closed
void fg_status_drawer_toggle(void);