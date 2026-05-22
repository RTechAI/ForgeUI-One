// ============================================================
// ForgeUI One HMI Core
// ============================================================
// 01_FG_HMI.c
//
// Single-page LVGL runtime shell.
//
// Responsibilities:
// - root screen ownership
// - global screen styling
// - optional header layer
// - launch home/alive screen
//
// No tabs.
// No routing.
// No workflow logic.
//
// ============================================================

#include "lvgl.h"

#include "00_ForgeUI_Config.h"
#include "01_FG_HMI.h"
#include "02_UI_Home.h"
#include "16_UI_Style.h"

#if FORGEUI_ENABLE_HEADER
#include "14_UI_Header.h"
#endif

void fg_hmi_init(void)
{
    lv_obj_t* scr = lv_screen_active();

    fg_style_apply_screen(scr);

#if FORGEUI_ENABLE_HEADER
    fg_header_create(scr);
#endif

    ui_home_build(scr);

}