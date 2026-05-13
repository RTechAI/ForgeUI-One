#include "05_FG_Icons.h"
#include "00_ForgeUI_Config.h"

// ============================================================
// External LVGL Image Assets
// ============================================================

LV_IMAGE_DECLARE(fg_icon_system_64_dark);
LV_IMAGE_DECLARE(ffg_icon_admin_64_dark);

LV_IMAGE_DECLARE(fg_icon_brightness_64_dark);
LV_IMAGE_DECLARE(fg_icon_sound_64_dark);
LV_IMAGE_DECLARE(fg_icon_wifi_64_dark);
LV_IMAGE_DECLARE(fg_icon_sdcard_64_dark);
LV_IMAGE_DECLARE(fg_icon_time_64_dark);
LV_IMAGE_DECLARE(fg_icon_datetime_64_dark);

// ============================================================
// Icons
// ============================================================

const void *fg_icon_system(void)
{
    return &fg_icon_system_64_dark;
}

const void *fg_icon_admin(void)
{
    return &ffg_icon_admin_64_dark;
}

const void *fg_icon_brightness(void)
{
    return &fg_icon_brightness_64_dark;
}

const void *fg_icon_sound(void)
{
    return &fg_icon_sound_64_dark;
}

const void *fg_icon_wifi(void)
{
    return &fg_icon_wifi_64_dark;
}

const void *fg_icon_sdcard(void)
{
    return &fg_icon_sdcard_64_dark;
}

const void *fg_icon_time(void)
{
    return &fg_icon_time_64_dark;
}

