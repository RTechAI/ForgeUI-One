#pragma once

// ============================================================
// ForgeUI Admin Gate
// ============================================================
//
// ForgeUI
// Created by Scott Forster
// Contact: forgeui.esp32@gmail.com
//
// Purpose:
//
// Optional PIN-based admin access layer.
//
// Features:
//
// - Admin UI protection
// - unlock state handling
// - PIN entry UI
// - relock support
// - optional compile-time bypass
//
// Controlled through:
//
//   FORGEUI_ENABLE_ADMIN_GATE
//
// Rules:
//
// - UI only
// - no backend ownership
// - no hardware ownership
// - no persistent runtime storage
//
// Current Reactor direction:
//
// Admin gate acts as:
//
// - protected UI boundary
// - session entry point
// - appliance-style protected access layer
//
// Future Direction:
//
// - RFID unlock
// - role/session system
// - timeout support
// - persistent PIN storage
// - service/user roles
// - customer access levels
//
// ============================================================

#include <stdbool.h>

#include "lvgl.h"

#ifdef __cplusplus
extern "C" {
#endif


// ============================================================
// Admin Gate API
// ============================================================

// Build locked/admin gate UI
void fg_admin_gate_build(lv_obj_t *parent);

// Returns current unlock state
bool fg_admin_is_unlocked(void);

// Force admin relock
void fg_admin_lock(void);


#ifdef __cplusplus
}
#endif