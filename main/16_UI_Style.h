#pragma once

// ============================================================
// ForgeUI Shared Style System
// ============================================================
//
// ForgeUI
// Created by Scott Forster
// Contact: forgeui.esp32@gmail.com
//
// Purpose:
//
// Centralized visual styling and theme layer.
//
// Responsibilities:
//
// - theme colors
// - shared widget styling
// - visual consistency
// - compile-time theme selection
// - Reactor visual identity ownership
//
// Current Themes:
//
// - Atlas Light
// - Nebula Blue
// - Reactor UI direction
//
// Controlled through:
//
//   FORGEUI_STYLE_ACTIVE
//
// in:
//
//   00_ForgeUI_Config.h
//
// Rules:
//
// - style-only responsibilities
// - no backend ownership
// - no hardware ownership
// - no runtime truth storage
//
// ============================================================

#include "lvgl.h"


// ============================================================
// Style System Init
// ============================================================

void fg_style_init(void);


// ============================================================
// Style Apply Helpers
// ============================================================

void fg_style_apply_screen(lv_obj_t *obj);
void fg_style_apply_tile(lv_obj_t *obj);
void fg_style_apply_panel(lv_obj_t *obj);
void fg_style_apply_button(lv_obj_t *obj);
void fg_style_apply_dropdown(lv_obj_t *obj);
void fg_style_apply_textarea(lv_obj_t *obj);
void fg_style_apply_label(lv_obj_t *obj);
void fg_style_apply_label_dim(lv_obj_t *obj);


// ============================================================
// Color Helpers
// ============================================================

lv_color_t fg_style_bg(void);
lv_color_t fg_style_tile(void);
lv_color_t fg_style_panel(void);
lv_color_t fg_style_border(void);
lv_color_t fg_style_text(void);
lv_color_t fg_style_text_dim(void);
lv_color_t fg_style_accent(void);


// ============================================================
// Shared Metrics
// ============================================================

int fg_style_radius(void);