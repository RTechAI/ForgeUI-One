// ============================================================
// ForgeUI HMI Core
// ============================================================
//
// ForgeUI
// Created by Scott Forster
// Contact: forgeui.esp32@gmail.com
//
// Purpose:
//
// Main LVGL HMI construction and navigation layer.
//
// Responsibilities:
//
// - create root tabview
// - apply global visual styles
// - create shared header overlay
// - create top-level UI pages
// - dispatch page builders
// - provide central navigation helpers
//
// Rules:
//
// - no backend ownership
// - no hardware ownership
// - no persistent runtime truth
// - no subsystem state storage
//
// Backend modules own truth.
// UI only renders state and sends intent.
//
// Current UI Pages:
//
// - Dashboard
// - Pre Op
// - System
// - Admin
//
// Reactor Direction:
//
// Reactor uses hidden internal LVGL tab routing.
//
// Primary navigation:
// - launcher cards
// - icon taps
//
// Secondary navigation:
// - swipe gestures
//
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
#include "00_ForgeUI_Config.h"


// ============================================================
// Local State
// ============================================================

static lv_obj_t *g_tabview = NULL;

#define FG_TAB_DASHBOARD  0
#define FG_TAB_PREOP      1
#define FG_TAB_SYSTEM     2
#define FG_TAB_ADMIN      3


// ============================================================
// Swipe Tuning
// ============================================================

static void fg_hmi_tune_tab_swipe(lv_obj_t *tabview)
{
    if (!tabview) return;

    lv_obj_t *content = lv_tabview_get_content(tabview);
    if (!content) return;

    lv_obj_set_scroll_dir(content, LV_DIR_HOR);

    lv_obj_set_scroll_snap_x(content,
                             LV_SCROLL_SNAP_CENTER);

    lv_obj_set_scrollbar_mode(content,
                              LV_SCROLLBAR_MODE_OFF);

    lv_obj_add_flag(content,
                    LV_OBJ_FLAG_SCROLL_ONE);

    lv_obj_add_flag(content,
                    LV_OBJ_FLAG_SCROLL_MOMENTUM);
}


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

    g_tabview = lv_tabview_create(scr);
    lv_obj_t *tabview = g_tabview;

    fg_style_apply_screen(tabview);

    lv_tabview_set_tab_bar_position(tabview, LV_DIR_TOP);

    fg_hmi_tune_tab_swipe(tabview);


    // ========================================================
// Top Header Bar
// ========================================================

lv_obj_t *tab_bar = lv_tabview_get_tab_bar(tabview);

#if !FORGEUI_ENABLE_HEADER

    lv_obj_add_flag(tab_bar, LV_OBJ_FLAG_HIDDEN);
    lv_obj_set_height(tab_bar, 0);

#elif FORGEUI_STYLE_ACTIVE == FORGEUI_STYLE_REACTOR

    lv_obj_add_flag(tab_bar, LV_OBJ_FLAG_HIDDEN);
    lv_obj_set_height(tab_bar, 0);

#else

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

#endif


    // ========================================================
    // Header Overlay
    // ========================================================

#if FORGEUI_ENABLE_HEADER
    fg_header_create(scr);
#endif


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


// ============================================================
// HMI Navigation Helpers
// ============================================================

void fg_hmi_go_dashboard(void)
{
    if (g_tabview) {
        lv_tabview_set_active(g_tabview,
                              FG_TAB_DASHBOARD,
                              LV_ANIM_OFF);
    }
}

void fg_hmi_go_preop(void)
{
    if (g_tabview) {
        lv_tabview_set_active(g_tabview,
                              FG_TAB_PREOP,
                              LV_ANIM_OFF);
    }
}

void fg_hmi_go_system(void)
{
    if (g_tabview) {
        lv_tabview_set_active(g_tabview,
                              FG_TAB_SYSTEM,
                              LV_ANIM_OFF);
    }
}

void fg_hmi_go_admin(void)
{
    if (g_tabview) {
        lv_tabview_set_active(g_tabview,
                              FG_TAB_ADMIN,
                              LV_ANIM_OFF);
    }
}