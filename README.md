# Minimalist 2D rendering system for MCU'S and such 
* Communication protocols
    - I2C (AVR, PIC, SOFTWARE)
    - SPI (AVR, PIC, SOFTWARE)
* Display drivers
    - SSD1306
    - ST7789 
* Rendering
    - Basic drawing operations engine
    - 2D Canvas engine (Based on HTML Canvas)

# Example code
* (WARNING THIS IS DRAFT CODE, SUBJECT TO CHANGES...)

```c
#include <math.h>
#include "uDisplayAPI.h"

#define SCREEN_WIDTH 128
#define SCREEN_HEIGHT 64

// Sine wave properties
#define WAVE_AMPLITUDE 32
#define WAVE_PERIOD 64
#define WAVE_STEP 0.1

// Buffer to hold sine wave data
uint8_t waveBuffer[SCREEN_WIDTH];

// Function to generate sine wave data
void generateWaveData() {
  for (int x = 0; x < SCREEN_WIDTH; x++) {
    double y = WAVE_AMPLITUDE * sin((2 * M_PI * x) / WAVE_PERIOD);
    waveBuffer[x] = (uint8_t) round(y + SCREEN_HEIGHT / 2);
  }
}

int main() {

  // Initialize underlying protocol and driver for SSD1306 display
  uDisplayUnderlyingProtocol protocol;
  uDisplayDriver driver;
  uDRenderConfig config = { &protocol, &driver };
  uDisplay display;

  protocol.init();
  driver.Init(&protocol);

  // Generate sine wave data
  generateWaveData();

  // Initialize display using configuration
  display.Initialize(&config);

  // Create buffer descriptor for sine wave data
  struct uDBufferDescriptor waveDesc = {
    .x = 0,
    .y = 0,
    .w = SCREEN_WIDTH,
    .h = 1,
    .data = waveBuffer,
    .length = SCREEN_WIDTH
  };

  // Start draw call and draw sine wave data
  display.StartDrawCall(&waveDesc);
  display.DrawBuffer(waveDesc);

  // Commit draw call to display sine wave
  display.CommitDrawCall(waveDesc);

  // Clean up
  driver.Dispose();

  return 0;
}
```

### Dependencies

```
avr-gnu toolchain
avrdude
C51 (Arm keli)
XC8 (Microchip)
```
#### AVR
```bash
sudo apt-get install gcc-avr binutils-avr gdb-avr avr-libc avrdude
```

### Compilation configs
```cmake
set(MCU  "attiny85")
set(ARCH "AVR")
```

# uDisplay supported devices
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
