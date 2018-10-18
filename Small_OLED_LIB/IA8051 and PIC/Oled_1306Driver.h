/*
 * File:   Oled_1306Driver.h
 * Author: Saul
 *
 * 
 */
#ifndef OLED_DRIVER_H
#define	OLED_DRIVER_H

// common XC8 AND C51 preprocessor  includes  
#define OLED_LOAD_DEFAULT_FONT 
// exclusive XC8 AND C51 preprocessor  includes  
// xc8 compiler; works only for  PIC 14 and pic 16
#if defined __xc8  
#include <xc.h>
#include <stdint.h>
#define _XTAL_FREQ 4000000 // this define is for pic timing
#define MEMORY_KEYWORD 
#elif defined (__C51__) // 8052 microcontroller
#include <8052.h>
#include "stdint.h"
#define MEMORY_KEYWORD code
//INSERT TIMING INCLUDES FOR 8051 HERE
#endif


#define SSD1306_SET_CONTRAST_CONTROL                    0x81
#define SSD1306_DISPLAY_ALL_ON_RESUME                   0xA4
#define SSD1306_DISPLAY_ALL_ON                          0xA5
#define SSD1306_NORMAL_DISPLAY                          0xA6
#define SSD1306_INVERT_DISPLAY                          0xA7
#define SSD1306_DISPLAY_OFF                             0xAE
#define SSD1306_DISPLAY_ON                              0xAF
#define SSD1306_NOP                                     0xE3
#define SSD1306_HORIZONTAL_SCROLL_RIGHT                 0x26
#define SSD1306_HORIZONTAL_SCROLL_LEFT                  0x27
#define SSD1306_HORIZONTAL_SCROLL_VERTICAL_AND_RIGHT    0x29
#define SSD1306_HORIZONTAL_SCROLL_VERTICAL_AND_LEFT     0x2A
#define SSD1306_DEACTIVATE_SCROLL                       0x2E
#define SSD1306_ACTIVATE_SCROLL                         0x2F
#define SSD1306_SET_VERTICAL_SCROLL_AREA                0xA3
#define SSD1306_SET_LOWER_COLUMN                        0x00
#define SSD1306_SET_HIGHER_COLUMN                       0x10
#define SSD1306_MEMORY_ADDR_MODE                        0x20
#define SSD1306_SET_COLUMN_ADDR                         0x21
#define SSD1306_SET_PAGE_ADDR                           0x22
#define SSD1306_SET_START_LINE                          0x40
#define SSD1306_SET_SEGMENT_REMAP                       0xA0
#define SSD1306_SET_MULTIPLEX_RATIO                     0xA8
#define SSD1306_COM_SCAN_DIR_INC                        0xC0
#define SSD1306_COM_SCAN_DIR_DEC                        0xC8
#define SSD1306_SET_DISPLAY_OFFSET                      0xD3
#define SSD1306_SET_COM_PINS                            0xDA
#define SSD1306_CHARGE_PUMP                             0x8D
#define SSD1306_SET_DISPLAY_CLOCK_DIV_RATIO             0xD5
#define SSD1306_SET_PRECHARGE_PERIOD                    0xD9
#define SSD1306_SET_VCOM_DESELECT                       0xDB



//OLED LIB DEFINES

//i2c oled addres
#define  OledAddr 0x3C



//Oled display functions
void OLED_Initialize();
void OLED_send(uint8_t Data,uint8_t IsCommand);
void OLED_gotoxy(uint8_t row,uint8_t colum);
void OLED_Putchar(char c);
void OLED_DrawString(const char * string);
void OLED_DrawSprite(uint8_t x,uint8_t y, const uint8_t *sprite,
        unsigned int spriteLenght,
        uint8_t w,uint8_t h,uint8_t Clean);
void OLED_cls();
void OLED_ResetCoords();

//to implement
void OLED_DrawPixel( uint8_t x, uint8_t y);
void OLED_DrawPixel( uint8_t x,uint8_t y,const uint8_t color);
void OLED_DrawLine(unit8_t x_start, uint8_t y_start,uint8_t x_end,uint8_t y_end);


#endif	//OLED_DRIVER_H

