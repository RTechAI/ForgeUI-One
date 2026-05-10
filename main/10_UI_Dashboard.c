// ============================================================
// ForgeUI Dashboard Tab
// ============================================================
// Dashboard landing page.
//
// Responsibilities:
// - build the Dashboard tab UI
// - provide a clean first-screen placeholder
// - prove tab/theme/layout pipeline is alive
//
// Rules:
// - no backend ownership here
// - no hardware init here
// - no long-running logic here
//
// Future direction:
// - app status cards
// - live system summary
// - quick action tiles
// - product/demo hero widgets
// ============================================================

#include "10_UI_Dashboard.h"
#include "16_UI_Style.h"


// ============================================================
// Dashboard Builder
// ============================================================

void ui_dashboard_build(lv_obj_t *parent)
{
    fg_style_apply_screen(parent);

    lv_obj_set_style_pad_all(parent, 16, 0);


    // ========================================================
    // Main Panel
    // ========================================================

    lv_obj_t *panel = lv_obj_create(parent);

    fg_style_apply_tile(panel);

    lv_obj_set_size(panel, lv_pct(100), lv_pct(100));
    lv_obj_center(panel);

    lv_obj_set_layout(panel, LV_LAYOUT_FLEX);
    lv_obj_set_flex_flow(panel, LV_FLEX_FLOW_COLUMN);

    lv_obj_set_flex_align(panel,
                          LV_FLEX_ALIGN_CENTER,
                          LV_FLEX_ALIGN_CENTER,
                          LV_FLEX_ALIGN_CENTER);


    // ========================================================
    // Title
    // ========================================================

    lv_obj_t *title = lv_label_create(panel);

    lv_label_set_text(title, "Dashboard");

    fg_style_apply_label(title);

    lv_obj_set_style_text_font(title,
                               &lv_font_montserrat_24,
                               0);


    // ========================================================
    // Subtitle
    // ========================================================

    lv_obj_t *sub = lv_label_create(panel);

    lv_label_set_text(sub, "ForgeUI Dashboard module ready");

    fg_style_apply_label_dim(sub);
}