# ForgeUI P4

Production-ready LVGL v9 framework and ESP-IDF baseline for the ESP32-P4 RISC-V MCU.

ForgeUI provides a clean, modular, hardware-proven embedded UI foundation for developers building real ESP32-P4 products using LVGL and ESP-IDF.

Pre-configured and tested on the:

Waveshare ESP32-P4-WIFI6-Touch-LCD-7B


---

# OVERVIEW

ForgeUI removes the painful low-level ESP32-P4 bring-up stage by already integrating:

- EK79007 MIPI DSI display support
- GT911 capacitive touch support
- ESP-Hosted WiFi
- ESP32-C6 remote WiFi transport
- DS3231 RTC integration
- SD card support
- LVGL v9 runtime
- modular UI architecture
- keyboard overlays
- configurable feature system
- clean ownership boundaries
- product-oriented runtime structure


---

# DESIGN PHILOSOPHY

ForgeUI intentionally avoids demo-driven runtime architecture and instead focuses on:

- stable hardware bring-up
- clean module ownership
- reusable embedded UI patterns
- safe LVGL runtime rules
- production-oriented structure
- maintainable firmware architecture
- real-world ESP32-P4 integration


---

# CORE ARCHITECTURE RULES

- main.c owns boot order only
- backends own system truth
- UI renders state only
- no unsafe async LVGL calls
- modular compile-time feature control
- no hidden subsystem ownership
- no demo-driven runtime coupling
- safe backend/UI separation


---

# CURRENT PROVEN FEATURES

Current proven ForgeUI P4 baseline includes:

- display operational
- touch operational
- LVGL v9 operational
- hosted WiFi operational
- WiFi scan/connect/disconnect
- RTC persistence
- DS3231 RTC integration
- audio path support
- SD card support
- keyboard overlay system
- modular UI foundation
- theme foundation
- status drawer architecture
- single-page UI baseline
- modular multi-page UI baseline


---

# TARGET USE CASES

ForgeUI is designed as a clean starting point for:

- embedded products
- industrial UI systems
- ESP32-P4 experimentation
- LVGL projects
- touchscreen appliances
- dashboards
- games
- kiosk systems
- hardware prototypes
- commercial firmware platforms
- industrial HMI systems
- product development platforms


---

# SOFTWARE STACK

Built using:

- ESP-IDF v5.5.x
- LVGL v9
- ESP-Hosted
- esp_wifi_remote
- Waveshare BSP ecosystem
- Espressif managed components


---

# HARDWARE SUPPORT

Current proven hardware support includes:

- ESP32-P4 RISC-V MCU
- ESP32-C6 Hosted WiFi
- EK79007 display controller
- GT911 touch controller
- DS3231 RTC
- SD card support
- audio subsystem support


---

# PROJECT DIRECTION

ForgeUI intentionally favors:

- clarity
- stability
- maintainability
- reusable architecture
- hardware-proven workflows
- readable embedded structure

The goal is to provide a reusable, understandable, hardware-proven ESP32-P4 baseline suitable for real embedded products rather than temporary demo-driven firmware.


---

# SEARCH KEYWORDS

ESP32-P4  
ESP32 P4  
LVGL  
LVGL v9  
ESP-IDF  
Embedded UI  
Embedded GUI  
Waveshare ESP32-P4  
ESP32-P4-WIFI6-Touch-LCD-7B  
ESP-Hosted  
esp_wifi_remote  
Touchscreen UI  
RISC-V MCU  
Industrial HMI  
LVGL Framework  
ESP32 UI Framework  
Embedded Display Framework  
Embedded Product Framework  
ESP32 GUI  
Touch Display UI  
MIPI DSI  
GT911  
EK79007  


---

Powered by ForgeUI.