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
