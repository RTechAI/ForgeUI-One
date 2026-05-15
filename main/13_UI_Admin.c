// ============================================================
// ForgeUI Admin UI
// ============================================================
//
// ForgeUI
// Created by Scott Forster
// Contact: forgeui.esp32@gmail.com
//
// Purpose:
//
// Optional protected administration area.
//
// Responsibilities:
//
// - build Admin page content
// - enforce Admin gate entry point
// - host protected settings/workflows
// - provide future service/maintenance area
//
// Current V1 Features:
//
// - optional admin gate
// - compile-time unlock support
// - PIN keypad path
// - placeholder admin panel
//
// Rules:
//
// - UI only
// - no backend ownership
// - no hardware ownership
// - no runtime truth storage
//
// Controlled through:
//
//   00_ForgeUI_Config.h
//
// Future Direction:
//
// - PIN authentication
// - RFID login
// - role/session management
// - diagnostics
// - maintenance tools
// - firmware update tools
//
// ============================================================

// ============================================================
// Includes
// ============================================================

#include "lvgl.h"

#include "01_FG_HMI.h"

#include "13_UI_Admin.h"

#include "16_UI_Style.h"
#include "16_UI_AdminGate.h"

#include "00_ForgeUI_Config.h"


// ============================================================
// Admin Builder
// ============================================================

void ui_admin_build(lv_obj_t *parent)
{
    fg_style_apply_screen(parent);

    lv_obj_set_style_pad_all(parent, 16, 0);


    // ========================================================
    // Optional Admin Gate
    // ========================================================

#if FORGEUI_ENABLE_ADMIN_GATE

    if (!fg_admin_is_unlocked())
    {
        fg_admin_gate_build(parent);
        return;
    }

#endif


    // ========================================================
    // Main Panel
    // ========================================================

    lv_obj_t *panel = lv_obj_create(parent);

    fg_style_apply_tile(panel);

    lv_obj_set_size(panel, lv_pct(100), lv_pct(100));

    lv_obj_center(panel);

    lv_obj_set_layout(panel, LV_LAYOUT_FLEX);

    lv_obj_set_flex_flow(panel,
                         LV_FLEX_FLOW_COLUMN);

    lv_obj_set_flex_align(panel,
                          LV_FLEX_ALIGN_CENTER,
                          LV_FLEX_ALIGN_CENTER,
                          LV_FLEX_ALIGN_CENTER);


    // ========================================================
    // Title
    // ========================================================

    lv_obj_t *title = lv_label_create(panel);

    lv_label_set_text(title, "Admin");

    fg_style_apply_label(title);

    lv_obj_set_style_text_font(title,
                               &lv_font_montserrat_24,
                               0);


    // ========================================================
    // Subtitle
    // ========================================================

    lv_obj_t *sub = lv_label_create(panel);

    lv_label_set_text(sub,
                      "ForgeUI Admin module ready");

    fg_style_apply_label_dim(sub);
}