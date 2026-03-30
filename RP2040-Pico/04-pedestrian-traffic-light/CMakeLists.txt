cmake_minimum_required(VERSION 3.13)
include(pico_sdk_import.cmake)
project(pedestrian_traffic_light C CXX ASM)
pico_sdk_init()

add_executable(pedestrian_traffic_light main.c)

pico_enable_stdio_usb(pedestrian_traffic_light 1)
pico_enable_stdio_uart(pedestrian_traffic_light 0)

target_link_libraries(pedestrian_traffic_light pico_stdlib hardware_timer)
pico_add_extra_outputs(pedestrian_traffic_light)