#CMAKE TODO'S:
#ADD LIBRARY PREFIXES
#ADD CONFGIGURATIONS (TO MAKE THIS EZ TO HANDLE)
#ADD ONLY HEADER LIBRARY GENERATION
#CONFIGURE UPLOAD STEPS AND AVR DUDE CONFIGURATION AT THE TOP OF THE FILE
#ADD MULTI COMPILER CONFIGURATION

cmake_minimum_required(VERSION 3.10)
project(uDisplay C CXX ASM)

# GENERAL UDISPLAY CONFIG
set(MCU  "attiny85")
set(ARCH "AVR")
set(FIRMWARE_NAME "build/uDisplay.hex")

# Compile entry point
# file(GLOB_RECURSE UDISPLAY_ENTRY_POINT "Examples/protos/uart_echo.c")
# file(GLOB_RECURSE UDISPLAY_ENTRY_POINT "Examples/uDisplayTests/DriverTest.c")
file(GLOB_RECURSE UDISPLAY_ENTRY_POINT "Examples/uDisplayTests/ProtocolsTests.c")

# Set the path to the avr-gcc toolchain
set(CMAKE_C_COMPILER "avr-gcc")
set(CMAKE_CXX_COMPILER "avr-g++")
set(CMAKE_ASM_COMPILER "avr-gcc")

# Set compiler flags
set(CMAKE_C_FLAGS "-mmcu=${MCU} -Os")
set(CMAKE_CXX_FLAGS "-mmcu=${MCU} -Os")
set(CMAKE_ASM_FLAGS "-mmcu=${MCU}")

# # Add the AVR include directories
include_directories(
/usr/lib/gcc/avr/5.4.0
)

# uDisplay library sources
file(GLOB_RECURSE UDISPLAY_SOURCES "include/*.c")
file(GLOB_RECURSE UDISPLAY_HEADERS "include/*.h")

# Add the source files to the project
add_executable(uDisplay ${UDISPLAY_SOURCES} ${UDISPLAY_HEADERS} ${UDISPLAY_ENTRY_POINT})

# Set the linker flags
set(CMAKE_EXE_LINKER_FLAGS "-mmcu=${MCU} -Os")

# # Add a custom target to run AVR-GDB on your firmware
# add_custom_target(Debug
#   COMMAND avr-gdb -ex "target remote localhost:1234" ${FIRMWARE_NAME}
#   DEPENDS ${FIRMWARE_NAME}
#   WORKING_DIRECTORY ${CMAKE_BINARY_DIR}
# )

# Specify the output file name
set_target_properties(uDisplay PROPERTIES OUTPUT_NAME "uDisplay.elf")

# Generate the HEX and BIN files
add_custom_command(TARGET uDisplay POST_BUILD
                   COMMAND avr-objcopy -O ihex -R .eeprom uDisplay.elf uDisplay.hex
                   COMMAND avr-objcopy -O binary -R .eeprom uDisplay.elf uDisplay.bin)

# #Upload the firmware to the microcontroller using avrdude
add_custom_target(upload
                  COMMAND avrdude -c usbasp -p attiny85 -U hfuse:w:0xD7:m
                  COMMAND avrdude -p ${MCU} -c usbasp -U flash:w:uDisplay.hex:i)
