cmake_minimum_required(VERSION 3.10)
project(uDisplay C CXX ASM)

# GENERAL UDISPLAY CONFIG
set(MCU  "atmega328p")
set(ARCH "AVR")
file(GLOB_RECURSE UDISPLAY_RUNNING_EXAMPLE "Examples/uDisplay/HelloWorld.c")

# Set the path to the avr-gcc toolchain
set(CMAKE_C_COMPILER "avr-gcc")
set(CMAKE_CXX_COMPILER "avr-g++")
set(CMAKE_ASM_COMPILER "avr-gcc")

# Set compiler flags
set(CMAKE_C_FLAGS "-mmcu=${MCU} -Os")
set(CMAKE_CXX_FLAGS "-mmcu=${MCU} -Os")
set(CMAKE_ASM_FLAGS "-mmcu=${MCU}")

include_directories(
    "/usr/lib/avr/include"
)

# uDisplay library sources
file(GLOB_RECURSE UDISPLAY_SOURCES "include/*.c")
file(GLOB_RECURSE UDISPLAY_TEMPLATE_HEADERS "include/*.h")

# Add the source files to the project
add_executable(uDisplay ${UDISPLAY_SOURCES} ${UDISPLAY_TEMPLATE_HEADERS} ${UDISPLAY_RUNNING_EXAMPLE})

# Set the linker flags
set(CMAKE_EXE_LINKER_FLAGS "-mmcu=${MCU} -Os")

# Specify the output file name
set_target_properties(uDisplay PROPERTIES OUTPUT_NAME "uDisplay.elf")

# # Generate the HEX and BIN files
# add_custom_command(TARGET uDisplay POST_BUILD
#                    COMMAND avr-objcopy -O ihex -R .eeprom uDisplay.elf uDisplay.hex
#                    COMMAND avr-objcopy -O binary -R .eeprom uDisplay.elf uDisplay.bin)

# # Upload the firmware to the microcontroller using avrdude
# add_custom_target(upload
#                   COMMAND avrdude -p ${MCU} -c usbasp -U flash:w:uDisplay.hex:i)