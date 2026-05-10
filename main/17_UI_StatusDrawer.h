#pragma once

// ============================================================
// ForgeUI Status Drawer
// ============================================================
// Global slide-out system status drawer.
//
// Features:
// - edge toggle handle
// - overlay drawer panel
// - runtime status display
//
// Future Direction:
// - live backend state
// - notifications
// - alerts
// - telemetry indicators
//
// This layer is UI-only.
// ============================================================


// Create global status drawer
void fg_status_drawer_create(void);

// Toggle drawer open/closed
void fg_status_drawer_toggle(void);