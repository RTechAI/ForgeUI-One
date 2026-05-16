// ============================================================
// ForgeUI One Style System
// ============================================================
//
// File:
// 16_UI_Style.c
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
// - theme colour ownership
// - shared LVGL style helpers
// - compile-time theme selection
// - consistent ForgeUI visual identity
//
// Current Themes:
// - Atlas Light
// - Nebula Blue
// - Carbon
//
// Rules:
// - style-only responsibilities
// - no backend ownership
// - no hardware ownership
// - no runtime state ownership
// - no workflow ownership
//
// Controlled Through:
//
//   FORGEUI_STYLE_ACTIVE
//
// UI modules should avoid hardcoding:
//
// - colours
// - radii
// - panel styling
// - text styling
//
// Shared visual ownership should flow through this layer.
//
// ============================================================

// ============================================================
// Includes
// ============================================================

#include "16_UI_Style.h"

#include "00_ForgeUI_Config.h"

void fg_style_init(void)
{
    // Reserved for future shared LVGL style objects.
}

// ===============================
// Color Helpers
// ===============================

lv_color_t fg_style_bg(void)
{
#if FORGEUI_STYLE_ACTIVE == FORGEUI_STYLE_NEBULA_BLUE
    return lv_color_hex(0x07111F);
#else
    return lv_color_hex(0xF4F6F8);
#endif
}

lv_color_t fg_style_tile(void)
{
#if FORGEUI_STYLE_ACTIVE == FORGEUI_STYLE_NEBULA_BLUE
    return lv_color_hex(0x10243A);
#else
    return lv_color_hex(0xFFFFFF);
#endif
}

lv_color_t fg_style_panel(void)
{
#if FORGEUI_STYLE_ACTIVE == FORGEUI_STYLE_NEBULA_BLUE
    return lv_color_hex(0x0D1B2E);
#else
    return lv_color_hex(0xEEF2F6);
#endif
}

lv_color_t fg_style_border(void)
{
#if FORGEUI_STYLE_ACTIVE == FORGEUI_STYLE_NEBULA_BLUE
    return lv_color_hex(0x2F80ED);
#else
    return lv_color_hex(0xD7DEE8);
#endif
}

lv_color_t fg_style_text(void)
{
#if FORGEUI_STYLE_ACTIVE == FORGEUI_STYLE_NEBULA_BLUE
    return lv_color_hex(0xEAF2FF);
#else
    return lv_color_hex(0x1C2430);
#endif
}

lv_color_t fg_style_text_dim(void)
{
#if FORGEUI_STYLE_ACTIVE == FORGEUI_STYLE_NEBULA_BLUE
    return lv_color_hex(0x8FA9C7);
#else
    return lv_color_hex(0x5E6B7A);
#endif
}

lv_color_t fg_style_accent(void)
{
#if FORGEUI_STYLE_ACTIVE == FORGEUI_STYLE_NEBULA_BLUE
    return lv_color_hex(0x245C9E);
#else
    return lv_color_hex(0x2563EB);
#endif
}

int fg_style_radius(void)
{
#if FORGEUI_STYLE_ACTIVE == FORGEUI_STYLE_NEBULA_BLUE
    return 6;
#else
    return 18;
#endif
}

// ===============================
// Apply Helpers
// ===============================

void fg_style_apply_screen(lv_obj_t *obj)
{
    if (!obj) return;

    lv_obj_set_style_bg_color(obj, fg_style_bg(), 0);
    lv_obj_set_style_bg_opa(obj, LV_OPA_COVER, 0);
}

void fg_style_apply_tile(lv_obj_t *obj)
{
    if (!obj) return;

    lv_obj_set_style_bg_color(obj, fg_style_tile(), 0);
    lv_obj_set_style_bg_opa(obj, LV_OPA_COVER, 0);
    lv_obj_set_style_border_color(obj, fg_style_border(), 0);
    lv_obj_set_style_border_width(obj, 1, 0);
    lv_obj_set_style_radius(obj, fg_style_radius(), 0);
    lv_obj_set_style_pad_all(obj, 12, 0);
}

void fg_style_apply_panel(lv_obj_t *obj)
{
    if (!obj) return;

    lv_obj_set_style_bg_color(obj, fg_style_panel(), 0);
    lv_obj_set_style_bg_opa(obj, LV_OPA_COVER, 0);
    lv_obj_set_style_border_color(obj, fg_style_border(), 0);
    lv_obj_set_style_border_width(obj, 1, 0);
    lv_obj_set_style_radius(obj, fg_style_radius(), 0);
    lv_obj_set_style_pad_all(obj, 10, 0);
}

void fg_style_apply_button(lv_obj_t *obj)
{
    if (!obj) return;

    lv_obj_set_style_bg_color(obj, fg_style_accent(), 0);
    lv_obj_set_style_bg_opa(obj, LV_OPA_COVER, 0);
    lv_obj_set_style_text_color(obj, lv_color_white(), 0);
    lv_obj_set_style_radius(obj, fg_style_radius(), 0);
    lv_obj_set_style_border_width(obj, 0, 0);
}

void fg_style_apply_dropdown(lv_obj_t *obj)
{
    if (!obj) return;

    lv_obj_set_style_bg_color(obj, fg_style_panel(), 0);
    lv_obj_set_style_bg_opa(obj, LV_OPA_COVER, 0);

    lv_obj_set_style_border_color(obj, fg_style_border(), 0);
    lv_obj_set_style_border_width(obj, 1, 0);

    lv_obj_set_style_radius(obj, fg_style_radius(), 0);

    lv_obj_set_style_text_color(obj, fg_style_text(), 0);

    lv_obj_set_style_pad_all(obj, 10, 0);
}

void fg_style_apply_textarea(lv_obj_t *obj)
{
    if (!obj) return;

    lv_obj_set_style_bg_color(obj, fg_style_panel(), 0);
    lv_obj_set_style_bg_opa(obj, LV_OPA_COVER, 0);

    lv_obj_set_style_border_color(obj, fg_style_border(), 0);
    lv_obj_set_style_border_width(obj, 1, 0);

    lv_obj_set_style_radius(obj, fg_style_radius(), 0);

    lv_obj_set_style_text_color(obj, fg_style_text(), 0);

    lv_obj_set_style_pad_all(obj, 10, 0);
}

void fg_style_apply_label(lv_obj_t *obj)
{
    if (!obj) return;

    lv_obj_set_style_text_color(obj, fg_style_text(), 0);
}

void fg_style_apply_label_dim(lv_obj_t *obj)
{
    if (!obj) return;

    lv_obj_set_style_text_color(obj, fg_style_text_dim(), 0);
}