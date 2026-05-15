#pragma once

// ============================================================
// ForgeUI Audio System
// ============================================================
//
// ForgeUI
// Created by Scott Forster
// Contact: forgeui.esp32@gmail.com
//
// Purpose:
//
// Shared ForgeUI audio backend.
//
// Responsibilities:
//
// - initialise speaker/audio path
// - manage output volume
// - provide simple audio test playback
//
// Current Features:
//
// - BSP audio initialisation
// - speaker codec support
// - runtime volume control
// - sine-wave speaker test beep
//
// Rules:
//
// - backend only
// - no LVGL ownership
// - no UI styling
// - UI sends intent only
//
// Controlled through:
//
//   FORGEUI_ENABLE_AUDIO
//
// ============================================================

#include "esp_err.h"


// ============================================================
// Audio API
// ============================================================

// Init audio system (called automatically on first use)
esp_err_t fg_audio_init(void);

// Set speaker volume (0–100)
esp_err_t fg_audio_set_volume(int volume);

// Play test beep
esp_err_t fg_audio_test_beep(void);