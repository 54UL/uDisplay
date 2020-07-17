# SSD1306_OLED_LIB A.K.A; uOLED
## What is this?
lightweight implementation of ssd1306 128x64 monochrome display controller for XC8 and C51 compilers, coming soon agnostic device and avr hardware capabilities.

## Implementation details
Does not use a frame buffer to draw things in the screen neither uses the internal ram of the display to achive the rendering, when you have to draw something you have to clear all the area you had drawn into it, for example you draw an 16x16 sprite and this thing is moving in the screen you have to clear all that area before you draw the new object position (see the pong game example for pic)

## Instructions
Is pretty easy to get this lib working in xc8 or c51, you only have to let know where is the include folder of the lib in your compiler options, or even easier one: copy and paste the 1 header lib into your workspace.


## C API

### Sends data/commands through I2C
```c
void uOLED_Send(uint8_t Data, uint8_t IsCommand);
```

### Initialize the oled display comunication
```c
void uOLED_Initialize()
```

### Initialize the oled display comunication
```c
void uOLED_Initialize()
```

### Reset row and colum cursor position
```c
void uOLED_ResetCoords(void)
```

### Clears the display
```c
void uOLED_ClearDisplay()
```

### Draws an single char in the current row and colum position
```c
void uOLED_Putchar(char c)
```

### Clean the area to the dimensions of a char gylph.
```c
void uOLED_CleanChar(uint8_t row, uint8_t col)
```

### Draws and string in the current cursor position
```c
void uOLED_DrawString(const char *string)
```
### Draws a sprite in position x and y, the dimensions of the sprite must be passed and the last argument "clean", if is 1, is gonna clean all the area of the sprite ignoring the data in 'sprite' argument and writing 0's to the scren (no pixel drawn)
```c
void uOLED_DrawSprite(uint8_t x, uint8_t y, const uint8_t *sprite, unsigned int spriteLenght, uint8_t w, uint8_t h, uint8_t Clean)
```

## Video example
coming soon...
