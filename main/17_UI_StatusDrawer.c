// ============================================================
// ForgeUI Status Drawer
// ============================================================
// Global slide-out status drawer.
//
// Responsibilities:
// - provide quick system status visibility
// - expose lightweight runtime state
// - stay available above normal tab content
//
// Current V1 Features:
// - edge handle
// - show/hide drawer toggle
// - static status labels
//
// Rules:
// - UI-only overlay
// - no backend ownership
// - no hardware init
//
// Controlled through:
//   00_ForgeUI_Config.h
//
// Future Direction:
// - live WiFi status
// - live SD status
// - RTC state
// - admin/session state
// - alert/notification list
// ============================================================


// ============================================================
// Includes
// ============================================================

#include "17_UI_StatusDrawer.h"

#include "00_ForgeUI_Config.h"
#include "16_UI_Style.h"

#include "lvgl.h"

static lv_obj_t *g_drawer = NULL;
static lv_obj_t *g_handle = NULL;

static bool g_drawer_open = false;

// ===============================
// Toggle
// ===============================

void fg_status_drawer_toggle(void)
{
    if (!g_drawer) {
        return;
    }

    g_drawer_open = !g_drawer_open;

    if (g_drawer_open)
    {
        lv_obj_clear_flag(g_drawer, LV_OBJ_FLAG_HIDDEN);
    }
    else
    {
        lv_obj_add_flag(g_drawer, LV_OBJ_FLAG_HIDDEN);
    }
}

// ===============================
// Handle Event
// ===============================

static void evt_drawer_toggle(lv_event_t *e)
{
    LV_UNUSED(e);

    fg_status_drawer_toggle();
}

// ===============================
// Create
// ===============================

void fg_status_drawer_create(void)
{
    lv_obj_t *parent = lv_layer_top();

    // ===========================
    // Drawer Panel
    // ===========================

    g_drawer = lv_obj_create(parent);

    lv_obj_set_size(
    g_drawer,
    FORGEUI_STATUS_DRAWER_WIDTH,
    lv_disp_get_ver_res(NULL)
        - FORGEUI_STATUS_DRAWER_Y
        - FORGEUI_STATUS_DRAWER_BOTTOM_GAP);

#if FORGEUI_STATUS_DRAWER_RIGHT

lv_obj_align(
    g_drawer,
    LV_ALIGN_TOP_RIGHT,
    0,
    FORGEUI_STATUS_DRAWER_Y);

#else

lv_obj_align(
    g_drawer,
    LV_ALIGN_TOP_LEFT,
    0,
    FORGEUI_STATUS_DRAWER_Y);

#endif

    fg_style_apply_panel(g_drawer);

    lv_obj_set_style_pad_all(g_drawer, 16, 0);

    lv_obj_set_layout(g_drawer, LV_LAYOUT_FLEX);

    lv_obj_set_flex_flow(g_drawer, LV_FLEX_FLOW_COLUMN);

    lv_obj_set_style_pad_row(g_drawer, 12, 0);

    lv_obj_add_flag(g_drawer, LV_OBJ_FLAG_HIDDEN);

    // ===========================
    // Pills / Labels
    // ===========================

    lv_obj_t *lbl_wifi = lv_label_create(g_drawer);
    lv_label_set_text(lbl_wifi, "WiFi: READY");
    fg_style_apply_label(lbl_wifi);

    lv_obj_t *lbl_sd = lv_label_create(g_drawer);
    lv_label_set_text(lbl_sd, "SD: READY");
    fg_style_apply_label(lbl_sd);

    lv_obj_t *lbl_rtc = lv_label_create(g_drawer);
    lv_label_set_text(lbl_rtc, "RTC: OK");
    fg_style_apply_label(lbl_rtc);

    lv_obj_t *lbl_audio = lv_label_create(g_drawer);
    lv_label_set_text(lbl_audio, "Audio: ON");
    fg_style_apply_label(lbl_audio);

    lv_obj_t *lbl_admin = lv_label_create(g_drawer);
    lv_label_set_text(lbl_admin, "Admin: DEV");
    fg_style_apply_label(lbl_admin);

    // ===========================
    // Edge Handle
    // ===========================

    g_handle = lv_button_create(parent);

    lv_obj_set_size(
    g_handle,
    FORGEUI_STATUS_DRAWER_HANDLE_W,
    FORGEUI_STATUS_DRAWER_HANDLE_H);

#if FORGEUI_STATUS_DRAWER_RIGHT

lv_obj_align(
    g_handle,
    LV_ALIGN_RIGHT_MID,
    0,
    0);

#else

lv_obj_align(
    g_handle,
    LV_ALIGN_LEFT_MID,
    0,
    0);

#endif

lv_obj_set_y(
    g_handle,
    FORGEUI_STATUS_DRAWER_Y / 2);
    fg_style_apply_button(g_handle);

    lv_obj_add_event_cb(
        g_handle,
        evt_drawer_toggle,
        LV_EVENT_CLICKED,
        NULL);

    lv_obj_t *lbl = lv_label_create(g_handle);

    lv_label_set_text(lbl, "<");

    lv_obj_center(lbl);
}