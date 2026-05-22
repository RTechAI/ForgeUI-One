// ============================================================
// ForgeUI One Home Screen
// ============================================================
//
// File:
// 02_UI_Home.c
//
// Purpose:
// Main single-page Home screen.
//
// Responsibilities:
// - build the default Home layout
// - create starter UI objects
// - demonstrate clean LVGL structure
//
// Rules:
// - no hardware ownership
// - no backend ownership
// - no runtime business logic
// - styling should flow through style layer
//
// ============================================================

#include "02_UI_Home.h"

#include "lvgl.h"

#include "16_UI_Style.h"
#include "90_Studio_Export.h"

void ui_home_build(lv_obj_t *parent)
{
    if (!parent) {
        return;
    }

    // ========================================================
    // Root Layout
    // ========================================================

    lv_obj_set_layout(parent, LV_LAYOUT_FLEX);

    lv_obj_set_flex_flow(parent,
                         LV_FLEX_FLOW_COLUMN);

    lv_obj_set_flex_align(parent,
                          LV_FLEX_ALIGN_CENTER,
                          LV_FLEX_ALIGN_CENTER,
                          LV_FLEX_ALIGN_CENTER);

    // ========================================================
    // Title
    // ========================================================

    lv_obj_t *title = lv_label_create(parent);

    lv_label_set_text(title, "ForgeUI One");

    fg_style_apply_label(title);

    lv_obj_set_style_text_font(title,
                               &lv_font_montserrat_22,
                               0);

    // ========================================================
    // Studio Export Test
    // ========================================================

    fg_studio_export_create(parent);
}
