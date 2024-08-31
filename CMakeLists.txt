cmake_minimum_required(VERSION 3.13)

include(pico_sdk_import.cmake)

set(CMAKE_C STANDARD 11)
set(CMAKE_CXX_STANDARD 17)
set(PICO_BOARD pico_w)

project(alarm C CXX ASM)

pico_sdk_init()

add_executable(alarm
        main.c
        )

target_link_libraries(alarm pico_stdlib pico_cyw43_arch_none)

#configura a saída padrão como sendo uma 'Serial-Over USB'
pico_enable_stdio_usb(alarm 1)
pico_enable_stdio_uart(alarm 0)


# create map/bin/hex file etc.
pico_add_extra_outputs(alarm)