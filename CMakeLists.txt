# ============================================================
# ForgeUI Framework V1
# ============================================================
# ESP-IDF Project Root
#
# Target:
#   ESP32-P4-WIFI6-Touch-LCD-7B
#
# Framework:
#   ForgeUI_P4
#
# Notes:
# - Hosted WiFi via onboard ESP32-C6
# - LVGL v9
# - ESP-IDF 5.5.x baseline
# ============================================================

cmake_minimum_required(VERSION 3.5)

include($ENV{IDF_PATH}/tools/cmake/project.cmake)

add_compile_options(-Wno-format)
add_compile_options(-Wno-ignored-qualifiers)
add_compile_options(-Wno-attributes)
add_compile_options(-Wno-unused-function)

project(ForgeUI_P4)