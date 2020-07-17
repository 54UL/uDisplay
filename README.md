# SSD1306_OLED_LIB (uOLED)
## What is this?
lightweight implementation of ssd1306 128x64 monochrome display controller for XC8 and C51 compilers, coming soon agnostic device and avr hardware capabilities.

***

## Implementation details
Does not use a frame buffer to draw things in the screen neither uses the internal ram of the display to achive the rendering, when you have to draw something you have to clear all the area you had drawn into it, for example you draw an 16x16 sprite and this thing is moving in the screen you have to clear all that area before you draw the new object position (see the pong game example for pic)

***

## Instructions
Is pretty easy to get this lib working in xc8 or c51, you only have to let know where is the include folder of the lib in your compiler options, or even easier one: copy and paste the 1 header lib into your workspace, to get the lib working you must define some symbols before the uOled includes.

## SYMBOLS TO BE DEFINED

```c
#define OLED_LOAD_DEFAULT_FONT
```
#### LOADS THE DEFAULT FONT GYLPHS IN PROGRAM MEMORY (if not defined the font is not loaded)
***

```c
#define USE_I2C_SOFTWARE_IMPLEMENTATION
```
#### (EXPERIMENTAL) instead of using hardware implementation uses software implementation
***

```c
#define USE_DELAY_SOFTWARE_IMPLEMENTATION
```
#### this is only for C51 and its calibrated to run in 12mhz xtal (WIP FOR AGNOSTIC DELAYS)
***

```c
#define SDA_PIN <int value>
```
#### this for I2C sda pin spec for software implementation (IS ONLY WORKING IN C51)
***

```c
#define SCL_PIN <int value>
```
#### this for I2C scl pin spec for software implementation (IS ONLY WORKING IN C51)
***

## C API

```c
void uOLED_Send(uint8_t Data, uint8_t IsCommand);
```
#### Sends data/commands through I2C
***

```c
void uOLED_Initialize()
```
#### Initialize the oled display comunication
***

```c
void uOLED_ResetCoords(void)
```
#### Reset row and colum cursor position
***

```c
void uOLED_ClearDisplay()
```
#### Clear the display buffer sending 0's in a loop of 1024 steps 
***

```c
void uOLED_Putchar(char c)
```
#### Draws an single char in the current row and colum position
***

```c
void uOLED_CleanChar(uint8_t row, uint8_t col)
```
#### Clean the area to the dimensions of a char gylph.
***

```c
void uOLED_DrawString(const char *string)
```
#### Draws and string in the current cursor position
***

```c
void uOLED_DrawSprite(uint8_t x, uint8_t y, const uint8_t *sprite, unsigned int spriteLenght, uint8_t w, uint8_t h, uint8_t Clean)
```
#### Draws a sprite in position x and y, if clean is 1 will set to 0's the sprite area (no pixel shown)
***

## Video example
coming soon...
***

## PCB Circuit for pong game
coming soon...
***

# ALL CONTRIBUTIONS ARE WELL ACCEPTED, MAKE YOUR PULL REQUEST :)



