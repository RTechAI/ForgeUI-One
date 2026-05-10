// ============================================================
// ForgeUI HMI Core
// ============================================================
// Main LVGL HMI construction layer.
//
// Responsibilities:
// - create root tabview
// - apply global styles
// - create header overlay
// - create top-level tabs
// - dispatch tab builders
//
// Rules:
// - no backend ownership here
// - no system truth stored here
// - no hardware init here
//
// Backend modules own truth.
// UI only renders and sends intent.
//
// Current Tabs:
// - Dashboard
// - Pre Op
// - System
// - Admin
// ============================================================


// ============================================================
// Includes
// ============================================================

#include "lvgl.h"

#include "01_FG_HMI.h"

#include "10_UI_Dashboard.h"
#include "11_UI_PreOp.h"
#include "12_UI_System.h"
#include "13_UI_Admin.h"

#include "14_UI_Header.h"
#include "16_UI_Style.h"


// ============================================================
// ForgeUI HMI Init
// ============================================================

void fg_hmi_init(void)
{
    // ========================================================
    // Root Screen
    // ========================================================

    lv_obj_t *scr = lv_screen_active();

    fg_style_apply_screen(scr);


    // ========================================================
    // Main TabView
    // ========================================================

    lv_obj_t *tabview = lv_tabview_create(scr);

    fg_style_apply_screen(tabview);

    lv_tabview_set_tab_bar_position(tabview, LV_DIR_TOP);


    // ========================================================
    // Top Header Bar
    // ========================================================

    lv_obj_t *tab_bar = lv_tabview_get_tab_bar(tabview);

    fg_style_apply_panel(tab_bar);

    lv_obj_set_height(tab_bar, 60);

    lv_obj_set_style_pad_top(tab_bar,    8, 0);
    lv_obj_set_style_pad_bottom(tab_bar, 8, 0);

    lv_obj_set_style_pad_left(tab_bar,  10, 0);
    lv_obj_set_style_pad_right(tab_bar, 10, 0);

    lv_obj_set_style_text_font(tab_bar,
                               &lv_font_montserrat_22,
                               0);

    lv_obj_set_style_text_color(tab_bar,
                                fg_style_text(),
                                0);


    // ========================================================
    // Header Overlay
    // ========================================================
    // Overlay is attached to root screen and positioned
    // visually inside the tab header region.
    //
    // Current use:
    // - clock
    // - future status icons
    // - admin/session indicators

    fg_header_create(scr);


    // ========================================================
    // Tabs
    // ========================================================

    lv_obj_t *tab_dashboard =
        lv_tabview_add_tab(tabview, "Dashboard");

    lv_obj_t *tab_preop =
        lv_tabview_add_tab(tabview, "Pre Op");

    lv_obj_t *tab_system =
        lv_tabview_add_tab(tabview, "System");

    lv_obj_t *tab_admin =
        lv_tabview_add_tab(tabview, "Admin");


    // ========================================================
    // Tab Builders
    // ========================================================

    ui_dashboard_build(tab_dashboard);

    ui_preop_build(tab_preop);

    ui_system_build(tab_system);

    ui_admin_build(tab_admin);
}