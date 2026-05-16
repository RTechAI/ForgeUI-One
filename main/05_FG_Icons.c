// ============================================================
// ForgeUI One Icon Pipeline
// ============================================================
//
// File:
// 05_FG_Icons.c
//
// Purpose:
// Central icon asset ownership layer.
//
// Responsibilities:
// - expose shared icon accessors
// - isolate LVGL image symbols
// - centralise icon ownership
// - allow future icon pack switching
//
// Rules:
// - no UI ownership
// - no styling ownership
// - no runtime ownership
// - no hardware ownership
//
// ============================================================

#include "05_FG_Icons.h"

#include "00_ForgeUI_Config.h"

// ============================================================
// External LVGL Image Assets
// ============================================================

LV_IMAGE_DECLARE(fg_icon_home_28px);

LV_IMAGE_DECLARE(fg_icon_sound_48px);
LV_IMAGE_DECLARE(fg_icon_time_48px);
LV_IMAGE_DECLARE(fg_icon_wifi_48px);
LV_IMAGE_DECLARE(fg_icon_sd_card_48px);

// ============================================================
// Icon Accessors
// ============================================================

const void *fg_icon_home(void)
{
    return &fg_icon_home_28px;
}

const void *fg_icon_sound(void)
{
    return &fg_icon_sound_48px;
}

const void *fg_icon_wifi(void)
{
    return &fg_icon_wifi_48px;
}

const void *fg_icon_sdcard(void)
{
    return &fg_icon_sd_card_48px;
}

const void *fg_icon_time(void)
{
    return &fg_icon_time_48px;
}