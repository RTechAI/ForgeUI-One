#pragma once

#include "esp_err.h"

// Init audio system (called automatically on first use)
esp_err_t fg_audio_init(void);

// Set speaker volume (0–100)
esp_err_t fg_audio_set_volume(int volume);

// Play test beep
esp_err_t fg_audio_test_beep(void);