//SYMBOLS TO BE IMPORTED ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

//AGNOSTIC SYMBOLS BETWEN XC8 AND OTHERS
#ifndef __XTAL
#define XTAL_HERTZ 12000000
#else
#define XTAL_HERTZ __XTAL
#endif

#ifndef I2C_BAUD_RATE
#define I2C_BAUD_RATE 400000
#endif

#define I2C_PIC_HARDWARE_SPEED() (XTAL_HERTZ / (4 * I2C_BAUD_RATE)) - 1

//ANSI C INCLUDES

//SPECIFIC SYMBOLS FOR XC8, C51 AND SDDC
#if defined(__XC8)
#include <xc.h>
#include <stdint.h>
#define _XTAL_FREQ 4000000 // this define is for pic timing
#define MEMORY_KEYWORD
#elif defined(__C51__) // 8052 microcontroller
#define uint8_t unsigned char
#define uint16_t unsigned short int
#define MEMORY_KEYWORD code
#endif


//LIST OF FUNCTIONS TO BE PORTED ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
void uOLED_ResetCoords(void)
{
    //for ROWS
    uOLED_Send(SSD1306_SET_PAGE_ADDR, 1);
    uOLED_Send(0, 1);
    uOLED_Send(7, 1);
    //for colums
    uOLED_Send(SSD1306_SET_COLUMN_ADDR, 1);
    uOLED_Send(0, 1);
    uOLED_Send(127, 1);
}

uint16_t rindex = 0;

void uOLED_ClearDisplay()
{
    uOLED_ResetCoords();
    for (; rindex < 1024; rindex++)
        uOLED_Send(0x00, 0);
    uOLED_ResetCoords();
}

void uOLED_gotoxy(uint8_t row, uint8_t colum)
{
    //for ROWS
    uOLED_Send(SSD1306_SET_PAGE_ADDR, 1);
    uOLED_Send(row, 1);
    uOLED_Send(7, 1);
    //for colums
    uOLED_Send(SSD1306_SET_COLUMN_ADDR, 1);
    uOLED_Send(colum, 1);
    uOLED_Send(127, 1);
}

uint16_t charFontStart;
uint8_t gylphIndex;

void uOLED_Putchar(char c)
{
    charFontStart = (((uint8_t)c - 32) * 6) + 1;
    gylphIndex = 0;
    for (gylphIndex = 0; gylphIndex < 6; gylphIndex++)
    {
        uOLED_Send(DefaultFont[charFontStart + gylphIndex], 0);
    }
}

void uOLED_CleanChar(uint8_t x, uint8_t y)
{
	  uint8_t index;
    uOLED_gotoxy(y, x);
    //en vez de usar putchar, son 6 por que los caracteres son 6 de largo
    for(index = 0; index < 6 ; index++)
    uOLED_Send(0x00, 0);
    uOLED_ResetCoords();
}


uint8_t index;

void uOLED_DrawString(const char *string)
{
   
}

unsigned int spriteIndex;
void uOLED_DrawSprite(uint8_t x, uint8_t y, const uint8_t *sprite, unsigned int spriteLenght, uint8_t w, uint8_t h, uint8_t Clean)
{
    //almost same as uOLED_gotoxy(optimize moving this to uOLED_gotoxy function).
    //for rows of 8 bits
    uOLED_Send(SSD1306_SET_PAGE_ADDR, 1);
    uOLED_Send(y, 1);
    uOLED_Send(y + h, 1);
    //for colums
    uOLED_Send(SSD1306_SET_COLUMN_ADDR, 1);
    uOLED_Send(x, 1);
    uOLED_Send(x + w, 1);
    spriteIndex = 0;
    //if clean is set , we set to 0 all the sprite zone("cleaning")
    //this is used when we dont have a framebuffer in this case 1024 bytes of ram
    //8051 external mode could handle this
    while (spriteIndex < spriteLenght)
    {
        uOLED_Send(Clean ? 0X00 : sprite[spriteIndex], 0);
        spriteIndex++;
    }
    uOLED_ResetCoords();
}