#pragma once

#include <stdbool.h>

// ============================================================
// ForgeUI Hosted WiFi System
// ============================================================
// ESP32-P4 hosted WiFi backend.
//
// Features:
// - hosted WiFi init
// - scan
// - connect/disconnect
// - IP status tracking
// - network forget/reset
//
// Runtime Model:
// - backend owns WiFi state
// - UI sends intent only
//
// Hardware:
//   ESP32-P4 host
//   + onboard ESP32-C6 WiFi
//
// Future Direction:
// - saved networks
// - reconnect manager
// - RSSI reporting
// - cloud sync
// ============================================================


// Initialise hosted WiFi backend
void fg_wifi_init(void);

// Runtime WiFi pump/task helper
void fg_wifi_pump(void);


// Status helpers
bool fg_wifi_is_ready(void);

bool fg_wifi_is_connected(void);

const char *fg_wifi_status_text(void);

const char *fg_wifi_ip_text(void);


// WiFi scan helpers
void fg_wifi_scan_start(void);

int fg_wifi_get_scan_results(char ssids[][33],
                             int max);


// Connection helpers
void fg_wifi_connect(const char *ssid,
                     const char *pass);

void fg_wifi_disconnect(void);

void fg_wifi_forget(void);