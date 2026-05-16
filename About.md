# ForgeUI P4

Production-ready LVGL v9 framework and ESP-IDF baseline for the ESP32-P4 RISC-V MCU.

ForgeUI provides a clean, modular, hardware-proven embedded UI foundation for developers building real ESP32-P4 products using LVGL and ESP-IDF.

Pre-configured and tested on the:

Waveshare ESP32-P4-WIFI6-Touch-LCD-7B


---

# OVERVIEW

ForgeUI removes the painful low-level bring-up stage by already integrating:

- EK79007 display path
- GT911 touch support
- ESP-Hosted WiFi
- ESP32-C6 remote WiFi transport
- DS3231 RTC support
- SD card integration
- LVGL v9 runtime
- modular UI architecture
- keyboard overlays
- configurable feature system
- clean ownership boundaries


---

# DESIGN PHILOSOPHY

ForgeUI intentionally avoids demo-driven runtime architecture and instead focuses on:

- stable hardware bring-up
- clean module ownership
- reusable embedded UI patterns
- safe LVGL runtime rules
- production-oriented structure
- real-world ESP32-P4 integration


---

# CORE ARCHITECTURE RULES

- main.c owns boot order only
- backends own system truth
- UI renders state only
- no unsafe async LVGL calls
- modular compile-time feature control
- no hidden subsystem ownership


---

# CURRENT PROVEN FEATURES

- display operational
- touch operational
- hosted WiFi operational
- WiFi scan/connect/disconnect
- RTC persistence
- audio path support
- SD card support
- theme foundation
- keyboard overlay system
- status drawer architecture
- single-page and modular UI baselines


---

# TARGET USE CASES

ForgeUI is designed as a clean starting point for:

- embedded products
- industrial UI systems
- ESP32-P4 experimentation
- LVGL projects
- touch-screen appliances
- dashboards
- games
- kiosk systems
- hardware prototypes
- commercial firmware platforms


---

# SOFTWARE STACK

Built using:

- ESP-IDF v5.5.x
- LVGL v9
- ESP-Hosted
- Waveshare BSP ecosystem
- Espressif managed components


---

# PROJECT DIRECTION

ForgeUI intentionally favors clarity, stability, and maintainability over demo complexity.

The goal is to provide a reusable, understandable, hardware-proven ESP32-P4 baseline suitable for real embedded products rather than temporary demo-driven firmware.


---

# SEARCH KEYWORDS

ESP32-P4  
LVGL v9  
ESP-IDF  
Embedded UI  
Embedded GUI  
Waveshare ESP32-P4  
ESP-Hosted  
Touchscreen UI  
RISC-V MCU  
Industrial HMI  
LVGL Framework  
ESP32 UI Framework


---

Powered by ForgeUI.