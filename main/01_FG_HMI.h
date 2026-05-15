#pragma once

#ifdef __cplusplus
extern "C" {
#endif

// ============================================================
// ForgeUI HMI Configuration
// ============================================================
//
// ForgeUI
// Created by Scott Forster
// Contact: forgeui.esp32@gmail.com
//
// Purpose:
//
// Small HMI-level feature flags and UI routing helpers.
//
// This layer is intentionally lightweight.
//
// System-wide ownership belongs in:
//
//   00_ForgeUI_Config.h
//
// This file should only contain:
//
// - temporary UI toggles
// - HMI-only behaviour flags
// - development routing helpers
// - lightweight UI config paths
//
// Avoid:
//
// - backend ownership
// - hardware ownership
// - duplicated subsystem config
// - runtime state ownership
//
// ============================================================


// ============================================================
// Admin Access Control
// ============================================================
//
// FG_ADMIN_DEV_UNLOCK
//
// Development helper.
//
// 1 = Admin UI unlocked/open
// 0 = Admin protection enabled
//
// Current purpose:
//
// - development access
// - UI testing
// - routing validation
//
// Future direction:
//
// - PIN gate
// - RFID login
// - role-based access
// - session manager
// - timeout handling
//
// ============================================================

#define FG_ADMIN_DEV_UNLOCK  1


// ============================================================
// HMI Navigation Entry Points
// ============================================================
//
// These helpers route the hidden internal
// LVGL tabview/navigation engine.
//
// Reactor UI uses:
//
// primary navigation:
//   icon/card tap
//
// secondary navigation:
//   swipe gestures
//
// ============================================================

void fg_hmi_init(void);

void fg_hmi_go_dashboard(void);
void fg_hmi_go_preop(void);
void fg_hmi_go_system(void);
void fg_hmi_go_admin(void);

#ifdef __cplusplus
}
#endif