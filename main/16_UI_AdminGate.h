#pragma once

#include <stdbool.h>

#include "lvgl.h"

#ifdef __cplusplus
extern "C" {
#endif

// ============================================================
// ForgeUI Admin Gate
// ============================================================
// Optional PIN-based admin access layer.
//
// Features:
// - Admin tab protection
// - unlock state handling
// - PIN entry UI
// - relock support
//
// Controlled through:
//   FORGEUI_ENABLE_ADMIN_GATE
//
// Future Direction:
// - RFID unlock
// - role/session system
// - timeout support
// - persistent PIN storage
//
// This layer is UI-only.
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