# uDisplay

2D driver and rendering framework for AVR, PIC, 8051 AND STM32

## Overview
uDisplay has 5 modules: Timing, Comunications, Drivers and Rendering engines

### Timing 
  - Software delays
  - MCU Specific Implementation
  - Open API

### Comunication protocols
  - MCU Specific Implementation
    - SPI and I2C hardware implementation
      - AVR
      - PIC
  - Software implementations
    - Bit banging in most of the plataforms
  - Open API
  
### Drivers
  - Uses a comunication protocol
  - Display controller
    - SSD1306
    - ST7789
  - Open API

### Rendering engines layer
- Uses a driver
- 2D Rendering
  - uDisplay         (base and built-in engine with basic rendering functions)
    - uDisplayCanvas (HTML like canvas)
    - uDisplayShell  (Terminal shell)
    - uDisplayPlot   (Plot renderer)
  - Open API (all engines must be based on the uDisplay base rendering engine.)

## Getting Started

* Configure the [CMakeLists.txt]() to compile as an example or lib (genererates a .o or a only header version)
```cmake
set(MCU  "attiny85")
set(ARCH "AVR")
```

### Dependencies

* Cmake
* avr-gnu toolchain
* avrdude
* C51 (Arm keli)
* XC8 (Microchip)
```bash
sudo apt-get install avr-libc avrdude gcc-avr binutils-avr gdb-avr
```
#### Ubuntu:
```bash
sudo apt-get install gcc-avr binutils-avr gdb-avr avr-libc avrdude
```

### Installing

* [See installation guide for avr]() 
* [See installation guide for pic]() 

### Executing program

* How to run the program
* Step-by-step bullets
```
code blocks for commands
```
## uDisplay device compatibility

| MCU             | ARCH  | STATUS       |
|-----------------|-------|--------------|
| ATmega328P      | AVR   | DEVELOPMENT  |
| ATmega32U4      | AVR   | DEVELOPMENT  |
| ATtiny85        | AVR   | DEVELOPMENT  |
| AT89S52         | 8051  | DEVELOPMENT  |
| PIC16F877A      | PIC   | DEVELOPMENT  |
| STM32F103C8T6   | STM32 | DEVELOPMENT  |
| STM32F407VG     | STM32 | DEVELOPMENT  |
| STM32L053C8T6   | STM32 | DEVELOPMENT  |


## Version History

* 0.1
    * Initial Release

## Authors

Contributors names and contact info