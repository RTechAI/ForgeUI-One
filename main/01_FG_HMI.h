#pragma once

#ifdef __cplusplus
extern "C" {
#endif

// ============================================================
// ForgeUI HMI Configuration
// ============================================================
// Small HMI-level feature flags.
//
// Keep this lightweight.
// System-wide feature ownership belongs in:
//   00_ForgeUI_Config.h
//
// This file is intended for temporary or
// UI-specific behaviour toggles only.
// ============================================================


// ============================================================
// Admin Access Control
// ============================================================
// V1 Development Mode
//
// 1 = Admin tab unlocked/open
// 0 = Admin protection enabled
//
// Future direction:
// - PIN gate
// - RFID login
// - role-based access
// - session manager

#define FG_ADMIN_DEV_UNLOCK  1


// ============================================================
// HMI Entry
// ============================================================

void fg_hmi_init(void);
void fg_hmi_go_dashboard(void);
void fg_hmi_go_preop(void);
void fg_hmi_go_system(void);
void fg_hmi_go_admin(void);

#ifdef __cplusplus
}
#endif