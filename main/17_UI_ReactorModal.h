#pragma once

// ============================================================
// ForgeUI Reactor Modal
// ============================================================
//
// ForgeUI
// Created by Scott Forster
// Contact: forgeui.esp32@gmail.com
//
// Purpose:
//
// Shared Reactor modal / overlay system.
//
// Responsibilities:
//
// - create shared modal overlays
// - provide reusable modal containers
// - support shared close handling
// - manage modal lifecycle ownership
//
// Current Features:
//
// - singleton modal system
// - reusable overlay layer
// - shared close callback support
// - Reactor-compatible modal styling
//
// Rules:
//
// - UI only
// - no backend ownership
// - no hardware ownership
// - no runtime truth storage
//
// Current ownership:
//
// Feature modules own:
//
// - modal content
// - feature logic
// - runtime state
//
// Reactor modal owns:
//
// - overlay lifecycle
// - modal container
// - close callback handling
//
// ============================================================

#include "lvgl.h"

#ifdef __cplusplus
extern "C" {
#endif


// ============================================================
// Close Callback
// ============================================================

typedef void (*fg_reactor_modal_close_cb_t)(void);


// ============================================================
// Modal API
// ============================================================

// Open Reactor modal and return content container
lv_obj_t *fg_reactor_modal_open(const char *title,
                                const void *icon);

// Register optional modal close callback
void fg_reactor_modal_set_close_cb(
    fg_reactor_modal_close_cb_t cb);

// Close active Reactor modal
void fg_reactor_modal_close(lv_obj_t *modal);


#ifdef __cplusplus
}
#endif