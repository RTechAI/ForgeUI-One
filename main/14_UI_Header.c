// ============================================================
// ForgeUI Header Overlay
// ============================================================
// Global header/status overlay layer.
//
// Responsibilities:
// - top-right clock display
// - persistent overlay elements
// - lightweight runtime status display
//
// Current Features:
// - RTC date/time display
//
// Rules:
// - overlay only
// - no backend ownership
// - no hardware init
// - lightweight refresh path only
//
// Future Direction:
// - WiFi status icon
// - SD status icon
// - admin/session state
// - notifications
// - telemetry indicators
// ============================================================


// ============================================================
// Includes
// ============================================================

#include "14_UI_Header.h"

#include "20_RTC.h"

#include "16_UI_Style.h"


// ============================================================
// Local State
// ============================================================

static lv_obj_t *g_blk    = NULL;
static lv_obj_t *g_lbl_dt = NULL;


// ============================================================
// Header Create
// ============================================================

void fg_header_create(lv_obj_t *parent)
{
    g_blk = lv_obj_create(parent);

    lv_obj_remove_style_all(g_blk);

    lv_obj_set_size(g_blk,
                    LV_SIZE_CONTENT,
                    LV_SIZE_CONTENT);

    lv_obj_set_style_pad_all(g_blk, 0, 0);

    lv_obj_set_style_border_width(g_blk, 0, 0);

    lv_obj_set_style_bg_opa(g_blk,
                            LV_OPA_TRANSP,
                            0);


    // ========================================================
    // Position
    // ========================================================

    lv_obj_align(g_blk,
                 LV_ALIGN_TOP_RIGHT,
                 -12,
                 10);


    // ========================================================
    // Date/Time Label
    // ========================================================

    g_lbl_dt = lv_label_create(g_blk);

    lv_obj_set_style_text_align(g_lbl_dt,
                                LV_TEXT_ALIGN_RIGHT,
                                0);

    lv_obj_set_style_text_font(g_lbl_dt,
                               &lv_font_montserrat_14,
                               0);

    fg_style_apply_label_dim(g_lbl_dt);

    lv_label_set_text(g_lbl_dt,
                      "Fri 17\n14:32");


    // ========================================================
    // Overlay Priority
    // ========================================================

    lv_obj_move_foreground(g_blk);
}


// ============================================================
// Header Refresh
// ============================================================

void fg_header_refresh(void)
{
    char buf[32];

    fg_rtc_format_header(buf, sizeof(buf));

    if (g_lbl_dt) {
        lv_label_set_text(g_lbl_dt, buf);
    }

    if (g_blk) {
        lv_obj_move_foreground(g_blk);
    }
}