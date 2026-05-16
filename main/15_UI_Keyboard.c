// ============================================================
// ForgeUI One Keyboard Helper
// ============================================================
//
// File:
// 15_UI_Keyboard.c
//
// Purpose:
// Shared LVGL on-screen keyboard helper.
//
// Responsibilities:
// - create reusable singleton keyboard
// - attach keyboard to text areas
// - manage show/hide lifecycle
// - provide shared text-entry path
//
// Rules:
// - UI only
// - no backend ownership
// - no hardware ownership
// - no runtime truth ownership
// - no workflow logic
//
// Styling:
// - base styling comes from 16_UI_Style.c
// - theme-specific polish is allowed here only for the keyboard
//
// ============================================================

#include "15_UI_Keyboard.h"

#include "00_ForgeUI_Config.h"
#include "16_UI_Style.h"

// ============================================================
// Local State
// ============================================================

static lv_obj_t *g_kb = NULL;

// ============================================================
// Local Helpers
// ============================================================

static void fg_keyboard_apply_theme(lv_obj_t *kb)
{
    if (!kb) {
        return;
    }

    fg_style_apply_panel(kb);

#if FORGEUI_STYLE_ACTIVE == FORGEUI_STYLE_NEBULA_BLUE

    lv_obj_set_style_bg_color(kb,
                              lv_color_hex(0x0B1220),
                              LV_PART_MAIN);

    lv_obj_set_style_bg_opa(kb,
                            LV_OPA_COVER,
                            LV_PART_MAIN);

    lv_obj_set_style_border_color(kb,
                                  lv_color_hex(0x1E3A5F),
                                  LV_PART_MAIN);

    lv_obj_set_style_border_width(kb,
                                  2,
                                  LV_PART_MAIN);

    lv_obj_set_style_radius(kb,
                            14,
                            LV_PART_MAIN);

    lv_obj_set_style_pad_all(kb,
                             8,
                             LV_PART_MAIN);

    lv_obj_set_style_bg_color(kb,
                              lv_color_hex(0x14213A),
                              LV_PART_ITEMS | LV_STATE_DEFAULT);

    lv_obj_set_style_bg_opa(kb,
                            LV_OPA_COVER,
                            LV_PART_ITEMS | LV_STATE_DEFAULT);

    lv_obj_set_style_text_color(kb,
                                lv_color_hex(0xEAF2FF),
                                LV_PART_ITEMS | LV_STATE_DEFAULT);

    lv_obj_set_style_border_color(kb,
                                  lv_color_hex(0x2F80ED),
                                  LV_PART_ITEMS | LV_STATE_DEFAULT);

    lv_obj_set_style_border_width(kb,
                                  1,
                                  LV_PART_ITEMS | LV_STATE_DEFAULT);

    lv_obj_set_style_radius(kb,
                            8,
                            LV_PART_ITEMS | LV_STATE_DEFAULT);

    lv_obj_set_style_bg_color(kb,
                              lv_color_hex(0x2563EB),
                              LV_PART_ITEMS | LV_STATE_PRESSED);

    lv_obj_set_style_text_color(kb,
                                lv_color_hex(0xFFFFFF),
                                LV_PART_ITEMS | LV_STATE_PRESSED);

    lv_obj_set_style_bg_color(kb,
                              lv_color_hex(0x1D4ED8),
                              LV_PART_ITEMS | LV_STATE_CHECKED);

    lv_obj_set_style_text_color(kb,
                                lv_color_hex(0xFFFFFF),
                                LV_PART_ITEMS | LV_STATE_CHECKED);

    lv_obj_set_style_bg_color(kb,
                              lv_color_hex(0x1E293B),
                              LV_PART_ITEMS | LV_STATE_FOCUSED);

    lv_obj_set_style_text_color(kb,
                                lv_color_hex(0xFFFFFF),
                                LV_PART_ITEMS | LV_STATE_FOCUSED);

#endif
}

// ============================================================
// Keyboard Event Handler
// ============================================================

static void fg_keyboard_event_cb(lv_event_t *e)
{
    lv_event_code_t code = lv_event_get_code(e);

    if (code == LV_EVENT_READY ||
        code == LV_EVENT_CANCEL)
    {
        fg_keyboard_hide();
    }
}

// ============================================================
// Keyboard Create
// ============================================================

static void fg_keyboard_create_if_needed(void)
{
    if (g_kb) {
        return;
    }

    lv_obj_t *scr = lv_screen_active();

    if (!scr) {
        return;
    }

    g_kb = lv_keyboard_create(scr);

    fg_keyboard_apply_theme(g_kb);

    lv_obj_set_size(g_kb,
                    lv_pct(100),
                    220);

    lv_obj_align(g_kb,
                 LV_ALIGN_BOTTOM_MID,
                 0,
                 0);

    lv_obj_add_event_cb(g_kb,
                        fg_keyboard_event_cb,
                        LV_EVENT_ALL,
                        NULL);

    lv_obj_add_flag(g_kb,
                    LV_OBJ_FLAG_HIDDEN);
}

// ============================================================
// Attach Keyboard
// ============================================================

void fg_keyboard_attach(lv_obj_t *ta)
{
    if (!ta) {
        return;
    }

    fg_keyboard_create_if_needed();

    if (!g_kb) {
        return;
    }

    lv_keyboard_set_textarea(g_kb, ta);

    lv_obj_move_foreground(g_kb);

    lv_obj_clear_flag(g_kb,
                      LV_OBJ_FLAG_HIDDEN);
}

// ============================================================
// Hide Keyboard
// ============================================================

void fg_keyboard_hide(void)
{
    if (!g_kb) {
        return;
    }

    lv_keyboard_set_textarea(g_kb, NULL);

    lv_obj_add_flag(g_kb,
                    LV_OBJ_FLAG_HIDDEN);
}