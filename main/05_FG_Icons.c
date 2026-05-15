// ============================================================
// ForgeUI Icon Pipeline
// ============================================================
//
// ForgeUI
// Created by Scott Forster
// Contact: forgeui.esp32@gmail.com
//
// Purpose:
//
// Central icon asset ownership layer.
//
// Responsibilities:
//
// - expose shared UI icon accessors
// - isolate LVGL image asset symbols
// - centralize icon ownership
// - allow future icon pack switching
//
// Rules:
//
// - no direct UI logic
// - no styling logic
// - no runtime ownership
// - no hardware ownership
//
// Current Reactor baseline uses:
//
// 48px icon assets
//
// Future direction:
//
// - multiple icon packs
// - theme-aware icon sets
// - runtime icon scaling
// - dark/light variants
// - appliance/product icon packs
//
// ============================================================

#include "05_FG_Icons.h"
#include "00_ForgeUI_Config.h"

// ============================================================
// External LVGL Image Assets
// ============================================================

LV_IMAGE_DECLARE(fg_icon_admin_48px);
LV_IMAGE_DECLARE(fg_icon_brightness_48px);
LV_IMAGE_DECLARE(fg_icon_sound_48px);
LV_IMAGE_DECLARE(fg_icon_system_48px);
LV_IMAGE_DECLARE(fg_icon_time_48px);
LV_IMAGE_DECLARE(fg_icon_wifi_48px);
LV_IMAGE_DECLARE(fg_icon_sd_card_48px);
LV_IMAGE_DECLARE(fg_icon_home_28px);

// ============================================================
// Icons
// ============================================================

const void *fg_icon_system(void)
{
    return &fg_icon_system_48px;
}

const void *fg_icon_admin(void)
{
    return &fg_icon_admin_48px;
}

const void *fg_icon_brightness(void)
{
    return &fg_icon_brightness_48px;
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

const void *fg_icon_home(void)
{
    return &fg_icon_home_28px;
}
