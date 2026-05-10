#pragma once

// ============================================================
// ForgeUI RTC System
// ============================================================
// Shared runtime RTC/timekeeping layer.
//
// Responsibilities:
// - runtime clock ownership
// - RTC backend abstraction
// - DS3231 integration
// - NVS fallback persistence
// - date/time formatting helpers
//
// Controlled through:
//   FORGEUI_RTC_BACKEND
//
// Current Runtime Model:
// - ESP system time = active runtime clock
// - DS3231 = persistent hardware source
// - NVS = fallback persistence
// ============================================================


// Initialise runtime RTC system
void fg_rtc_init(void);


// Set runtime/system time
void fg_rtc_set(int year,
                int month,
                int day,
                int hour,
                int min);


// Get runtime/system time
void fg_rtc_get(int *year,
                int *month,
                int *day,
                int *hour,
                int *min,
                int *sec);


// Format helpers
void fg_rtc_format_day(char *out, int max);

void fg_rtc_format_time(char *out, int max);

void fg_rtc_format_header(char *out, int max);