#ifndef UOLEDLIB_H
#define UOLEDLIB_H

/*
BSD 2-Clause License

Copyright (c) 2018, Saul Aceves
All rights reserved.

Redistribution and use in source and binary forms, with or without
modification, are permitted provided that the following conditions are met:

* Redistributions of source code must retain the above copyright notice, this
  list of conditions and the following disclaimer.

* Redistributions in binary form must reproduce the above copyright notice,
  this list of conditions and the following disclaimer in the documentation
  and/or other materials provided with the distribution.

THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE
FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR
SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER
CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY,
OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.

---------- IMPORTANT INVISIBLE MACROS (NEED TO BE DEFINED BY THE USER IN HIS CODE) ----------
OLED_LOAD_DEFAULT_FONT : LOADS THE DEFAULT FONT GYLPHS IN PROGRAM MEMORY
USE_I2C_SOFTWARE_IMPLEMENTATION
USE_SOFTWARE_TIMING: ENABLES THE USE OF SOFTWARE DELAY BY PROVIDING EXTRA INFO ABOUT THE INSTRUCTION CYCLE TIMES
SDA_PIN : const int of the bit of sda 
SCL_PIN: const int of the bit of sda
*/

/*
TODOS:
    IMPLEMENT PRECISE TIMING CONTROL IN SOFTWARE( FORMULA TO DETERMINE HOW MANY LOOPS MUST NEED TO COMPLETE THAT DELAY)
    IMPLEMENT I2C FULL PROTOCOL IN SOFTWARE AND HARDWARE FOR PIC 16F877A
    IMPLEMENT OLED READING AND WRITTING IN INTERNAL DRAM 
    IMPLEMENT RASTER BUFFER FOR LARGE DRAM DEVICES
 */

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
#if defined (__XC8)
#include <xc.h>
#include <stdint.h>
#define _XTAL_FREQ 4000000 // this define is for pic timing
#define MEMORY_KEYWORD
#elif defined(__C51__) // 8052 microcontroller
#define uint8_t unsigned char
#define uint16_t unsigned short int
#define MEMORY_KEYWORD code
#endif

//COMAND TABLE FOR 1306
#define SSD1306_SET_CONTRAST_CONTROL 0x81
#define SSD1306_DISPLAY_ALL_ON_RESUME 0xA4
#define SSD1306_DISPLAY_ALL_ON 0xA5
#define SSD1306_NORMAL_DISPLAY 0xA6
#define SSD1306_INVERT_DISPLAY 0xA7
#define SSD1306_DISPLAY_OFF 0xAE
#define SSD1306_DISPLAY_ON 0xAF
#define SSD1306_NOP 0xE3
#define SSD1306_HORIZONTAL_SCROLL_RIGHT 0x26
#define SSD1306_HORIZONTAL_SCROLL_LEFT 0x27
#define SSD1306_HORIZONTAL_SCROLL_VERTICAL_AND_RIGHT 0x29
#define SSD1306_HORIZONTAL_SCROLL_VERTICAL_AND_LEFT 0x2A
#define SSD1306_DEACTIVATE_SCROLL 0x2E
#define SSD1306_ACTIVATE_SCROLL 0x2F
#define SSD1306_SET_VERTICAL_SCROLL_AREA 0xA3
#define SSD1306_SET_LOWER_COLUMN 0x00
#define SSD1306_SET_HIGHER_COLUMN 0x10
#define SSD1306_MEMORY_ADDR_MODE 0x20
#define SSD1306_SET_COLUMN_ADDR 0x21
#define SSD1306_SET_PAGE_ADDR 0x22
#define SSD1306_SET_START_LINE 0x40
#define SSD1306_SET_SEGMENT_REMAP 0xA0
#define SSD1306_SET_MULTIPLEX_RATIO 0xA8
#define SSD1306_COM_SCAN_DIR_INC 0xC0
#define SSD1306_COM_SCAN_DIR_DEC 0xC8
#define SSD1306_SET_DISPLAY_OFFSET 0xD3
#define SSD1306_SET_COM_PINS 0xDA
#define SSD1306_CHARGE_PUMP 0x8D
#define SSD1306_SET_DISPLAY_CLOCK_DIV_RATIO 0xD5
#define SSD1306_SET_PRECHARGE_PERIOD 0xD9
#define SSD1306_SET_VCOM_DESELECT 0xDB

#if defined(OLED_LOAD_DEFAULT_FONT)
 const  uint8_t MEMORY_KEYWORD DefaultFont[] = {
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, // sp
    0x00, 0x00, 0x00, 0x2f, 0x00, 0x00, // !
    0x00, 0x00, 0x07, 0x00, 0x07, 0x00, // "
    0x00, 0x14, 0x7f, 0x14, 0x7f, 0x14, // #
    0x00, 0x24, 0x2a, 0x7f, 0x2a, 0x12, // $
    0x00, 0x23, 0x13, 0x08, 0x64, 0x62, // %
    0x00, 0x36, 0x49, 0x55, 0x22, 0x50, // &
    0x00, 0x00, 0x05, 0x03, 0x00, 0x00, // '
    0x00, 0x00, 0x1c, 0x22, 0x41, 0x00, // (
    0x00, 0x00, 0x41, 0x22, 0x1c, 0x00, // )
    0x00, 0x14, 0x08, 0x3E, 0x08, 0x14, // *
    0x00, 0x08, 0x08, 0x3E, 0x08, 0x08, // +
    0x00, 0x00, 0x00, 0xA0, 0x60, 0x00, // ,
    0x00, 0x08, 0x08, 0x08, 0x08, 0x08, // -
    0x00, 0x00, 0x60, 0x60, 0x00, 0x00, // .
    0x00, 0x20, 0x10, 0x08, 0x04, 0x02, // /
    0x00, 0x3E, 0x51, 0x49, 0x45, 0x3E, // 0
    0x00, 0x00, 0x42, 0x7F, 0x40, 0x00, // 1
    0x00, 0x42, 0x61, 0x51, 0x49, 0x46, // 2
    0x00, 0x21, 0x41, 0x45, 0x4B, 0x31, // 3
    0x00, 0x18, 0x14, 0x12, 0x7F, 0x10, // 4
    0x00, 0x27, 0x45, 0x45, 0x45, 0x39, // 5
    0x00, 0x3C, 0x4A, 0x49, 0x49, 0x30, // 6
    0x00, 0x01, 0x71, 0x09, 0x05, 0x03, // 7
    0x00, 0x36, 0x49, 0x49, 0x49, 0x36, // 8
    0x00, 0x06, 0x49, 0x49, 0x29, 0x1E, // 9
    0x00, 0x00, 0x36, 0x36, 0x00, 0x00, // :
    0x00, 0x00, 0x56, 0x36, 0x00, 0x00, // ;
    0x00, 0x08, 0x14, 0x22, 0x41, 0x00, // <
    0x00, 0x14, 0x14, 0x14, 0x14, 0x14, // =
    0x00, 0x00, 0x41, 0x22, 0x14, 0x08, // >
    0x00, 0x02, 0x01, 0x51, 0x09, 0x06, // ?
    0x00, 0x32, 0x49, 0x59, 0x51, 0x3E, // @
    0x00, 0x7C, 0x12, 0x11, 0x12, 0x7C, // A
    0x00, 0x7F, 0x49, 0x49, 0x49, 0x36, // B
    0x00, 0x3E, 0x41, 0x41, 0x41, 0x22, // C
    0x00, 0x7F, 0x41, 0x41, 0x22, 0x1C, // D
    0x00, 0x7F, 0x49, 0x49, 0x49, 0x41, // E
    0x00, 0x7F, 0x09, 0x09, 0x09, 0x01, // F
    0x00, 0x3E, 0x41, 0x49, 0x49, 0x7A, // G
    0x00, 0x7F, 0x08, 0x08, 0x08, 0x7F, // H
    0x00, 0x00, 0x41, 0x7F, 0x41, 0x00, // I
    0x00, 0x20, 0x40, 0x41, 0x3F, 0x01, // J
    0x00, 0x7F, 0x08, 0x14, 0x22, 0x41, // K
    0x00, 0x7F, 0x40, 0x40, 0x40, 0x40, // L
    0x00, 0x7F, 0x02, 0x0C, 0x02, 0x7F, // M
    0x00, 0x7F, 0x04, 0x08, 0x10, 0x7F, // N
    0x00, 0x3E, 0x41, 0x41, 0x41, 0x3E, // O
    0x00, 0x7F, 0x09, 0x09, 0x09, 0x06, // P
    0x00, 0x3E, 0x41, 0x51, 0x21, 0x5E, // Q
    0x00, 0x7F, 0x09, 0x19, 0x29, 0x46, // R
    0x00, 0x46, 0x49, 0x49, 0x49, 0x31, // S
    0x00, 0x01, 0x01, 0x7F, 0x01, 0x01, // T
    0x00, 0x3F, 0x40, 0x40, 0x40, 0x3F, // U
    0x00, 0x1F, 0x20, 0x40, 0x20, 0x1F, // V
    0x00, 0x3F, 0x40, 0x38, 0x40, 0x3F, // W
    0x00, 0x63, 0x14, 0x08, 0x14, 0x63, // X
    0x00, 0x07, 0x08, 0x70, 0x08, 0x07, // Y
    0x00, 0x61, 0x51, 0x49, 0x45, 0x43, // Z
    0x00, 0x00, 0x7F, 0x41, 0x41, 0x00, // [
    0xAA, 0x55, 0xAA, 0x55, 0xAA, 0x55, // Backslash (Checker pattern)
    0x00, 0x00, 0x41, 0x41, 0x7F, 0x00, // ]
    0x00, 0x04, 0x02, 0x01, 0x02, 0x04, // ^
    0x00, 0x40, 0x40, 0x40, 0x40, 0x40, // _
    0x00, 0x00, 0x03, 0x05, 0x00, 0x00, // `
    0x00, 0x20, 0x54, 0x54, 0x54, 0x78, // a
    0x00, 0x7F, 0x48, 0x44, 0x44, 0x38, // b
    0x00, 0x38, 0x44, 0x44, 0x44, 0x20, // c
    0x00, 0x38, 0x44, 0x44, 0x48, 0x7F, // d
    0x00, 0x38, 0x54, 0x54, 0x54, 0x18, // e
    0x00, 0x08, 0x7E, 0x09, 0x01, 0x02, // f
    0x00, 0x18, 0xA4, 0xA4, 0xA4, 0x7C, // g
    0x00, 0x7F, 0x08, 0x04, 0x04, 0x78, // h
    0x00, 0x00, 0x44, 0x7D, 0x40, 0x00, // i
    0x00, 0x40, 0x80, 0x84, 0x7D, 0x00, // j
    0x00, 0x7F, 0x10, 0x28, 0x44, 0x00, // k
    0x00, 0x00, 0x41, 0x7F, 0x40, 0x00, // l
    0x00, 0x7C, 0x04, 0x18, 0x04, 0x78, // m
    0x00, 0x7C, 0x08, 0x04, 0x04, 0x78, // n
    0x00, 0x38, 0x44, 0x44, 0x44, 0x38, // o
    0x00, 0xFC, 0x24, 0x24, 0x24, 0x18, // p
    0x00, 0x18, 0x24, 0x24, 0x18, 0xFC, // q
    0x00, 0x7C, 0x08, 0x04, 0x04, 0x08, // r
    0x00, 0x48, 0x54, 0x54, 0x54, 0x20, // s
    0x00, 0x04, 0x3F, 0x44, 0x40, 0x20, // t
    0x00, 0x3C, 0x40, 0x40, 0x20, 0x7C, // u
    0x00, 0x1C, 0x20, 0x40, 0x20, 0x1C, // v
    0x00, 0x3C, 0x40, 0x30, 0x40, 0x3C, // w
    0x00, 0x44, 0x28, 0x10, 0x28, 0x44, // x
    0x00, 0x1C, 0xA0, 0xA0, 0xA0, 0x7C, // y
    0x00, 0x44, 0x64, 0x54, 0x4C, 0x44, // z
    0x00, 0x00, 0x10, 0x7C, 0x82, 0x00, // {
    0x00, 0x00, 0x00, 0xFF, 0x00, 0x00, // |
    0x00, 0x00, 0x82, 0x7C, 0x10, 0x00, // }
    0x00, 0x00, 0x06, 0x09, 0x09, 0x06  // ~
};
#else
 static uint8_t * DefaultFont;
#endif

//LIB GLOBAL VARS
static uint8_t OledAddr = 0x3C;
//I2C PORT BITS

void Timing_BlockingDelay_ms(uint16_t ms)
{
#if defined(__XC8) && !defined(USE_SOFTWARE_IMPLEMENTATION)
    __delay_ms(ms);
#elif (__C51__) || defined(USE_I2C_SOFTWARE_IMPLEMENTATION)
    //imaginando que funciona igual que los retrasos en asm
    //cada repeticion son 2 micro segundos, tiempo deseado * ninstrucciones
    uint16_t AuxCounter1;
    uint16_t AuxCounter2;
    for (AuxCounter2 = 0; AuxCounter2 < ms; AuxCounter2++)
    {
        for (AuxCounter1 = 0; AuxCounter1 < 500; AuxCounter1++); //UNICAMENTE PARA 12 MHZ DE CRISTAL 1 ms 500 *2 u
    }
#endif
}

void I2C_MasterInit()
{
#if defined(__XC8) && !defined(USE_I2C_SOFTWARE_IMPLEMENTATION)
    SSPCON = 0b00101000; //SSP Module as Master
    SSPCON2 = 0;
    SSPADD = I2C_PIC_HARDWARE_SPEED(); //Setting Clock Speed para 12 mhz, hacerla const esta expreciony
    SSPSTAT = 0;
    TRISC3 = 1; //Setting as input as given in datasheet
    TRISC4 = 1;
#elif (__C51__) || defined(USE_I2C_SOFTWARE_IMPLEMENTATION)
    // SOFTWARE IMPLEMENTATION
    SCL_PIN = 1;
    SDA_PIN = 1;
#endif
}

void I2C_MasterWait()
{
#if defined(__XC8) && !defined(USE_I2C_SOFTWARE_IMPLEMENTATION)
    while ((SSPSTAT & 0x04) || (SSPCON2 & 0x1F));
#elif __C51__ || defined(USE_I2C_SOFTWARE_IMPLEMENTATION)
    SCL_PIN = 1;
    Timing_BlockingDelay_ms(1);
    while (!SCL_PIN);
#endif
}

void I2C_MasterStart()
{
#if defined(__XC8) && !defined(USE_I2C_SOFTWARE_IMPLEMENTATION)
    I2C_MasterWait();
    SEN = 1; //Initiate start condition
#elif (__C51__) || defined(USE_I2C_SOFTWARE_IMPLEMENTATION)
    // SOFTWARE IMPLEMENTATION
    SCL_PIN = 1;
    SDA_PIN = 1;
   Timing_BlockingDelay_ms(1);
    SDA_PIN = 0;
#endif
}

void I2C_MasterRepeatedStart()
{
#if defined(__XC8) && !defined(USE_I2C_SOFTWARE_IMPLEMENTATION)
    I2C_MasterWait();
    RSEN = 1;
#elif (__C51__) || defined(USE_I2C_SOFTWARE_IMPLEMENTATION)
    //not implemented
#endif
}

void I2C_MasterStop()
{
#if defined(__XC8) && !defined(USE_I2C_SOFTWARE_IMPLEMENTATION)
    I2C_MasterWait();
    PEN = 1;
#elif (__C51__) || defined(USE_I2C_SOFTWARE_IMPLEMENTATION)
    SCL_PIN = 0;
    SDA_PIN = 0;
    SCL_PIN = 1;
    SDA_PIN = 1;
#endif
}

uint8_t serial_buff_oled;
uint8_t shiftedvalue;
uint8_t timeout;
uint8_t BUS_READY;

void I2C_MasterWrite(unsigned d)
{
#if defined(__XC8) && !defined(USE_I2C_SOFTWARE_IMPLEMENTATION)
    I2C_MasterWait();
    SSPBUF = d;
#elif (__C51__) && defined(USE_I2C_SOFTWARE_IMPLEMENTATION)
    timeout = 0;
    for (serial_buff_oled = 0; serial_buff_oled < 8; serial_buff_oled++)
    {
        SCL_PIN = 0;
        if (d & (0x80 >> serial_buff_oled))
            SDA_PIN = 1;
        else
            SDA_PIN = 0;
        SCL_PIN = 1;
    }
    //Aknowledge
    SCL_PIN = 0;
    SCL_PIN = 1;
    while (timeout < 254)
    {
        if (!SCL_PIN)
            while (SCL_PIN) //perame men estoy ocpado(bussy)

                if (!SDA_PIN)
                    break;
        timeout++;
    }
    if (SDA_PIN)
    {
        Master_Stop(); //not ack
    }
#endif
}

//oled display
void uOLED_Send(uint8_t Data, uint8_t IsCommand)
{
    uint8_t controlbyte = IsCommand ? 0x00 : 0x40;
    I2C_MasterStart();
    I2C_MasterWrite(OledAddr << 1);
    I2C_MasterWrite(controlbyte);
    I2C_MasterWrite(Data);
    I2C_MasterStop();
}

void uOLED_Initialize()
{
    I2C_MasterInit();
    I2C_MasterStop();
    Timing_BlockingDelay_ms(100);
    //comand startup
    uOLED_Send(SSD1306_DISPLAY_OFF, 1);
    uOLED_Send(SSD1306_SET_DISPLAY_CLOCK_DIV_RATIO, 1);
    uOLED_Send(0x80, 1);
    uOLED_Send(SSD1306_SET_MULTIPLEX_RATIO, 1);
    uOLED_Send(63, 1);
    uOLED_Send(SSD1306_SET_DISPLAY_OFFSET, 1);
    uOLED_Send(0x00, 1);
    uOLED_Send(SSD1306_SET_START_LINE | 0x00, 1);
    uOLED_Send(SSD1306_CHARGE_PUMP, 1);
    uOLED_Send(0x14, 1);
    uOLED_Send(SSD1306_MEMORY_ADDR_MODE, 1);
    uOLED_Send(0x00, 1);
    uOLED_Send(SSD1306_SET_SEGMENT_REMAP | 0x01, 1);
    uOLED_Send(SSD1306_COM_SCAN_DIR_DEC, 1);
    uOLED_Send(SSD1306_SET_COM_PINS, 1);
    uOLED_Send(0x12, 1);
    uOLED_Send(SSD1306_SET_CONTRAST_CONTROL, 1);
    uOLED_Send(0xCF, 1);
    uOLED_Send(SSD1306_SET_PRECHARGE_PERIOD, 1);
    uOLED_Send(0xF1, 1);
    uOLED_Send(SSD1306_SET_VCOM_DESELECT, 1);
    uOLED_Send(0x40, 1);
    uOLED_Send(SSD1306_DISPLAY_ALL_ON_RESUME, 1);
    uOLED_Send(SSD1306_NORMAL_DISPLAY, 1);
    uOLED_Send(SSD1306_DEACTIVATE_SCROLL, 1);
    uOLED_Send(SSD1306_DISPLAY_ON, 1);
}

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
    index = 0;
    while (string[index])
    {
        uOLED_Putchar(string[index]);
        index++;
    }
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
#endif
