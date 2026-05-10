// ============================================================
// ForgeUI Keyboard Overlay
// ============================================================
// Shared LVGL on-screen keyboard helper.
//
// Responsibilities:
// - create reusable keyboard overlay
// - attach keyboard to text areas
// - manage show/hide lifecycle
//
// Current Features:
// - shared singleton keyboard
// - password/text entry support
// - READY/CANCEL handling
//
// Rules:
// - UI only
// - no backend ownership
// - no hardware init
//
// Future Direction:
// - theme variants
// - numeric keypad mode
// - PIN entry mode
// - animation/transitions
// - auto-layout shifting
// ============================================================


// ============================================================
// Includes
// ============================================================

#include "15_UI_Keyboard.h"

#include "16_UI_Style.h"

#include "lvgl.h"


// ============================================================
// Local State
// ============================================================

static lv_obj_t *g_kb = NULL;


// ============================================================
// Keyboard Event Handler
// ============================================================
// Handles:
// - READY (✔)
// - CANCEL (✖)

static void kb_event_cb(lv_event_t *e)
{
    lv_event_code_t code = lv_event_get_code(e);

    if (code == LV_EVENT_READY ||
        code == LV_EVENT_CANCEL)
    {
        fg_keyboard_hide();
    }
}


// ============================================================
// Attach Keyboard
// ============================================================

void fg_keyboard_attach(lv_obj_t *ta)
{
    if (!ta) {
        return;
    }

    lv_obj_t *scr = lv_screen_active();


    // ========================================================
    // Create Shared Keyboard
    // ========================================================

    if (!g_kb)
    {
        g_kb = lv_keyboard_create(scr);

        fg_style_apply_panel(g_kb);

        lv_obj_set_size(g_kb,
                        lv_pct(100),
                        300);

        lv_obj_align(g_kb,
                     LV_ALIGN_BOTTOM_MID,
                     0,
                     0);

        // Handle ✔ and ✖ events
        lv_obj_add_event_cb(g_kb,
                            kb_event_cb,
                            LV_EVENT_ALL,
                            NULL);
    }


    // ========================================================
    // Attach To Text Area
    // ========================================================

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
    if (g_kb)
    {
        lv_keyboard_set_textarea(g_kb, NULL);

        lv_obj_add_flag(g_kb,
                        LV_OBJ_FLAG_HIDDEN);
    }
}