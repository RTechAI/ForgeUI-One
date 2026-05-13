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
#include "05_FG_Icons.h"
#include "01_FG_HMI.h"


// ============================================================
// Dashboard Builder
// ============================================================

static void evt_open_system(lv_event_t *e)
{
    LV_UNUSED(e);
    fg_hmi_go_system();
}

static void evt_open_admin(lv_event_t *e)
{
    LV_UNUSED(e);
    fg_hmi_go_admin();
}

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
    // System Launcher Card
    // ========================================================

    lv_obj_t *btn_system = lv_button_create(panel);

    fg_style_apply_tile(btn_system);

    lv_obj_set_size(btn_system, 220, 180);

    lv_obj_set_layout(btn_system, LV_LAYOUT_FLEX);
    lv_obj_set_flex_flow(btn_system, LV_FLEX_FLOW_COLUMN);

    lv_obj_set_flex_align(btn_system,
                      LV_FLEX_ALIGN_CENTER,
                      LV_FLEX_ALIGN_CENTER,
                      LV_FLEX_ALIGN_CENTER);


    // ========================================================
    // System Launcher Action
    // ========================================================

    lv_obj_add_event_cb(btn_system,
                    evt_open_system,
                    LV_EVENT_CLICKED,
                    NULL);

    lv_obj_t *img = lv_image_create(btn_system);
    lv_image_set_src(img, fg_icon_system());

    lv_obj_t *sys_lbl = lv_label_create(btn_system);
    lv_label_set_text(sys_lbl, "System");
    fg_style_apply_label(sys_lbl);
    lv_obj_set_style_text_font(sys_lbl, &lv_font_montserrat_18, 0);

    // ========================================================
    // Admin Launcher Card
    // ========================================================

    lv_obj_t *btn_admin = lv_button_create(panel);

    fg_style_apply_tile(btn_admin);

    lv_obj_set_size(btn_admin, 220, 180);

    lv_obj_set_layout(btn_admin, LV_LAYOUT_FLEX);
    lv_obj_set_flex_flow(btn_admin, LV_FLEX_FLOW_COLUMN);

    lv_obj_set_flex_align(btn_admin,
                      LV_FLEX_ALIGN_CENTER,
                      LV_FLEX_ALIGN_CENTER,
                      LV_FLEX_ALIGN_CENTER);


    // ========================================================
    // Admin Launcher Action
    // ========================================================

    lv_obj_add_event_cb(btn_admin,
                    evt_open_admin,
                    LV_EVENT_CLICKED,
                    NULL);

    lv_obj_t *admin_img = lv_image_create(btn_admin);
    lv_image_set_src(admin_img, fg_icon_admin());

    lv_obj_t *admin_lbl = lv_label_create(btn_admin);
    lv_label_set_text(admin_lbl, "Admin");
    fg_style_apply_label(admin_lbl);
    lv_obj_set_style_text_font(admin_lbl, &lv_font_montserrat_18, 0);

    // ========================================================
    // Subtitle
    // ========================================================

    lv_obj_t *sub = lv_label_create(panel);

    lv_label_set_text(sub, "ForgeUI Dashboard module ready");

    fg_style_apply_label_dim(sub);
}
