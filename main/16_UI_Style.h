#pragma once

#include "lvgl.h"

#ifdef __cplusplus
extern "C" {
#endif

// ============================================================
// ForgeUI One Style System
// ============================================================
//
// File:
// 16_UI_Style.h
//
// Created by:
// Scott Forster
//
// Contact:
// forgeui.esp32@gmail.com
//
// Purpose:
// Central visual styling layer for ForgeUI One.
//
// Responsibilities:
// - theme colours
// - shared widget styling
// - visual consistency
// - compile-time theme selection
// - shared ForgeUI visual ownership
//
// Current Themes:
// - Atlas Light
// - Nebula Blue
// - Carbon
//
// Controlled Through:
//
//   FORGEUI_STYLE_ACTIVE
//
// In:
//
//   00_ForgeUI_Config.h
//
// Rules:
// - style-only responsibilities
// - no backend ownership
// - no hardware ownership
// - no runtime truth storage
// - no workflow ownership
//
// ============================================================

// ============================================================
// Style Apply Helpers
// ============================================================

void fg_style_apply_screen(lv_obj_t *obj);
void fg_style_apply_card(lv_obj_t *obj);
void fg_style_apply_panel(lv_obj_t *obj);
void fg_style_apply_button(lv_obj_t *obj);
void fg_style_apply_dropdown(lv_obj_t *obj);
void fg_style_apply_textarea(lv_obj_t *obj);
void fg_style_apply_label(lv_obj_t *obj);
void fg_style_apply_label_dim(lv_obj_t *obj);

// ============================================================
// Colour Helpers
// ============================================================

lv_color_t fg_style_bg(void);
lv_color_t fg_style_card(void);
lv_color_t fg_style_panel(void);
lv_color_t fg_style_border(void);
lv_color_t fg_style_text(void);
lv_color_t fg_style_text_dim(void);
lv_color_t fg_style_accent(void);

// ============================================================
// Shared Metrics
// ============================================================

int fg_style_radius(void);

#ifdef __cplusplus
}
#endif