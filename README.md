# uDisplay

2D Display controller library for low spec MCU'S
________________________________________________

### Key features

* Intented to run on many embbed c compilers
* Lightweight/Portable implementation using only C and CMake
* Buffer-less rendering (main library goal)
* Generated header only library 
* I2C and SPI hardware/software implementations

## Example

* Initialze uDisplay
```c
//Configures uDisplay renderer with software 
uDRenderConfig config = { &uDisplay_UnderlyingProtocol_I2C_Software, &uDisplay_SSD1306Driver };

//Configures the underlying comunication ports and address (0x78) in this case
uDisplay_UnderlyingProtocol_I2C_Software.configure(0x78);

//Configures uDisplay rendering
uDisplayRenderer.Initialize(&config);
```

* Text rendering example

```c
//Set font data
uDBufferDescriptor testFont;
testFont.data = uD_DefaultFont;
testFont.dataLenght = sizeof(uD_DefaultFont);
fontMeta.height = 8; // 8 bits tall font
testFont.width = 5; //  5 bits wide font

//Set as current font
uDisplayRenderer.SetFont(&testFont);

//Draws an string
uDisplayRenderer.DrawString("uDisplay:");

//Draws all font characters
uint8_t charIndex = 32;
const uint8_t fontLenght = sizeof(uD_DefaultFont) / testFont.width;
for (; charIndex < fontLenght; charIndex++)
{
  uDisplayRenderer.DrawChar(charIndex);
}
```

#### Running example on attiny85
![running_example](images/fonts_v0.5-wip.png)
* Check uDisplayTest.c for more detailed examples

## Getting Started

* Configure the [CMakeLists.txt]() to compile as an example or lib (genererates a .o or a only header version)
```cmake
set(MCU  "attiny85")
set(ARCH "AVR")
```

## Dependencies
* CMake
* avr-gnu toolchain
* avrdude

#### Ubuntu:

```bash
sudo apt-get install gcc-avr binutils-avr gdb-avr avr-libc avrdude
```
## Installing

* [See installation guide for avr]() 
* [See installation guide for pic]() 


## Library development states
* TODO
  - Needs to be done lol

* WIP
  - work in progress...

* FUNCTIONAL
  - Has minimal functionality
  - Barely functional

* WOP: WORKING ON PLATFORM
  - Stable code from some specific platform

* RELEASE
  - Stable code
  - Works on all devices and architectures...

## uDisplay drivers

| DISPLAY CONTROLLER| PROTOCOL  | STATUS       |
|-------------------|-----------|--------------|
| SSD1306           | I2C       | FUNCTIONAL   |
| ST7789            | SPI       | TODO         |
| ST7735R           | SPI       | TODO         |

## uDisplay MCU compatibility

| MCU             | ARCH  | STATUS       |
|-----------------|-------|--------------|
| ATmega328P      | AVR   | TODO         |
| ATTiny85        | AVR   | FUNCTIONAL   |
| AT89S52         | 8051  | TODO         |
| PIC16F877A      | PIC   | TODO         |
| STM32F103C8T6   | ARM   | TODO         |

## uDisplay road map

* 1.0 (WIP)
    * Basic batch rendering
    * Dedicated frame buffer or bufferles rendering 
    * Helper  rendering functions (generic display built-ins)
      - Clear display
      - Rendering regions (colum and pages configuration)
      - Content scrolling
    * Basic in-memory font rendering
    * Device compatibility
      - ATTINY85
      - ATMEGA328P
    * Display drivers
      - SSD1306
      - SST7789
    *  uDisplay benchmarking module
      - FPS indicator
      - Latency indicator
    * Header only library (Generated)

* 1.1 (FUTURE-RELEASE)
    *  AVR C code optimizations
    *  Display drivers
        - ILI9341
    * Touch drivers module
        -  ILI9341 touch screen driver
    * Device compatibility
        - STM32 (ARM CORTEX M0)
    * Multiple Screens running on the same library instance (uDisplay factory)

#### OPTIONAL FEATURES

* 1.X (FUTURE-RELEASE)
  * Video rendering
     - too complex??? idk, let's find out...
  * Pseudo threads for uDisplay (uThreads library)
    - Software implementation
    - Harware implementation using timmers and interrupts

## Authors and 
* Repo owner
* Add you if are an author...

## Resources used to implement uDisplay (REFERENCES)
- [AVR Optimization tips and tricks] (https://ww1.microchip.com/downloads/en/AppNotes/doc8453.pdf)
- [Open GL pixmap fonts rendering] (https://courses.cs.washington.edu/courses/cse457/98a/tech/OpenGL/font.c)
