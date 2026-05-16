// ============================================================
// ForgeUI One Header Layer
// ============================================================
//
// File:
// 14_UI_Header.c
//
// Purpose:
// Lightweight optional top UI layer.
//
// Responsibilities:
// - create optional top-right clock label
// - keep header objects in foreground
// - render display state only
//
// Rules:
// - UI only
// - no backend ownership
// - no hardware ownership
// - no display driver ownership
// - no routing
// - no workflow logic
//
// Ownership:
// - feature gating comes from 00_ForgeUI_Config.h
// - visual styling comes from 16_UI_Style.c
// - RTC formatting comes from 20_RTC.c
//
// ============================================================

#include "14_UI_Header.h"

#include "00_ForgeUI_Config.h"
#include "16_UI_Style.h"

#if FORGEUI_ENABLE_RTC
#include "20_RTC.h"
#endif

// ============================================================
// Static State
// ============================================================

static lv_obj_t *g_blk    = NULL;
static lv_obj_t *g_lbl_dt = NULL;

// ============================================================
// Header Create
// ============================================================

void fg_header_create(lv_obj_t *parent)
{
    if (!parent) {
        return;
    }

    g_blk = lv_obj_create(parent);

    lv_obj_remove_style_all(g_blk);

    lv_obj_set_size(g_blk,
                    LV_SIZE_CONTENT,
                    LV_SIZE_CONTENT);

    lv_obj_set_style_pad_all(g_blk, 0, 0);
    lv_obj_set_style_border_width(g_blk, 0, 0);
    lv_obj_set_style_bg_opa(g_blk, LV_OPA_TRANSP, 0);

    lv_obj_align(g_blk,
                 LV_ALIGN_TOP_RIGHT,
                 -12,
                 10);

#if FORGEUI_SHOW_HEADER_CLOCK && FORGEUI_ENABLE_RTC
    g_lbl_dt = lv_label_create(g_blk);

    lv_obj_set_style_text_align(g_lbl_dt,
                                LV_TEXT_ALIGN_RIGHT,
                                0);

    lv_obj_set_style_text_font(g_lbl_dt,
                               &lv_font_montserrat_14,
                               0);

    fg_style_apply_label_dim(g_lbl_dt);

    lv_label_set_text(g_lbl_dt, "--\n--:--");
#else
    g_lbl_dt = NULL;
#endif

    lv_obj_move_foreground(g_blk);
}

// ============================================================
// Header Refresh
// ============================================================

void fg_header_refresh(void)
{
#if FORGEUI_SHOW_HEADER_CLOCK && FORGEUI_ENABLE_RTC
    if (g_lbl_dt) {
        char buf[32];

        fg_rtc_format_header(buf, sizeof(buf));
        lv_label_set_text(g_lbl_dt, buf);
    }
#endif

    if (g_blk) {
        lv_obj_move_foreground(g_blk);
    }
}