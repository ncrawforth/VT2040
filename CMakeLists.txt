cmake_minimum_required(VERSION 3.13)

include(../pico-sdk/pico_sdk_init.cmake)

project(vt2040)

pico_sdk_init()

# Compile C code
add_executable(vt2040 serial.c lcd.c term.c keyb.c unicodetocodepage.c vt2040.c)

# Assemble PIO programs
pico_generate_pio_header(vt2040 ${CMAKE_CURRENT_LIST_DIR}/lcd.pio)
pico_generate_pio_header(vt2040 ${CMAKE_CURRENT_LIST_DIR}/serial.pio)

# Pull in common dependencies
target_link_libraries(vt2040 pico_stdlib pico_multicore pico_mem_ops hardware_pwm hardware_pio)

# Fix intermittent boot failure on Waveshare RP2040 Zero
target_compile_definitions(vt2040 PRIVATE PICO_XOSC_STARTUP_DELAY_MULTIPLIER=64)

# Disable uart output
pico_enable_stdio_uart(vt2040 0)

# Create map/bin/hex/uf2 file etc.
pico_add_extra_outputs(vt2040)
