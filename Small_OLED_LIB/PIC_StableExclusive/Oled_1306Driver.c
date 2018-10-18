  /*
 * File:   Oled_1306Driver.c
 * Author: Saul
 *
 * Created on 13 de junio de 2018, 09:20 PM
 */


#include "Oled_1306Driver.h"
#include "I2C_SaulLib.h"




//oled display
void OLED_send(uint8_t Data,bool IsCommand)
{
    uint8_t controlbyte  = IsCommand ? 0x00 : 0x40;
    I2C_Master_Start();
    I2C_Master_Write(OledAddr<<1);
    I2C_Master_Write(controlbyte);
    I2C_Master_Write(Data);
    I2C_Master_Stop();
}

void OLED_Initialize()
{
   I2C_Master_Init();
   I2C_Master_Stop();
   __delay_ms(100);
   //Start Sending the comands
  OLED_send ( SSD1306_DISPLAY_OFF,1);
  OLED_send ( SSD1306_SET_DISPLAY_CLOCK_DIV_RATIO,1);
  OLED_send ( 0x80,1);
  OLED_send ( SSD1306_SET_MULTIPLEX_RATIO,1);
  OLED_send (63,1);
  OLED_send ( SSD1306_SET_DISPLAY_OFFSET,1);
  OLED_send (0x00,1);
  OLED_send ( SSD1306_SET_START_LINE|0x00,1);  // Line: 0
  OLED_send ( SSD1306_CHARGE_PUMP ,1);
  // OLED_send (0x10); This will be used with External VCC
  OLED_send (0x14,1);
  OLED_send ( SSD1306_MEMORY_ADDR_MODE ,1);
  OLED_send (0x00,1);  //Horizontal Addressing Mode is Used
  OLED_send ( SSD1306_SET_SEGMENT_REMAP| 0x01,1);
  OLED_send ( SSD1306_COM_SCAN_DIR_DEC,1);
  OLED_send ( SSD1306_SET_COM_PINS,1);
  OLED_send ( 0x12,1);
  OLED_send ( SSD1306_SET_CONTRAST_CONTROL,1);
  // OLED_send (0x9F);  Use with External VCC
  OLED_send (0xCF,1);
  OLED_send ( SSD1306_SET_PRECHARGE_PERIOD,1);
  // OLED_send ( 0x22 ); Use with External VCC
  OLED_send ( 0xF1,1);
  OLED_send ( SSD1306_SET_VCOM_DESELECT,1);
  OLED_send ( 0x40,1);
  OLED_send ( SSD1306_DISPLAY_ALL_ON_RESUME,1);
  OLED_send ( SSD1306_NORMAL_DISPLAY,1);
  OLED_send ( SSD1306_DEACTIVATE_SCROLL,1);
  OLED_send ( SSD1306_DISPLAY_ON,1);
}

void OLED_ResetCoords()
{
     //for ROWS
    OLED_send(SSD1306_SET_PAGE_ADDR,1);
    OLED_send(0,1);
    OLED_send(7,1);
    //for colums
    OLED_send(SSD1306_SET_COLUMN_ADDR,1);
    OLED_send(0,1);
    OLED_send(127,1);
}

void OLED_cls()
{
    OLED_ResetCoords();
    uint16_t rindex=0;
    for(;rindex<1024;rindex++)
        OLED_send(0x00,0);
}

void OLED_gotoxy(uint8_t row,uint8_t colum)
{
    
    //for ROWS
    OLED_send(SSD1306_SET_PAGE_ADDR,1);
    OLED_send(row,1);
    OLED_send(7,1);
  
    //for colums
    OLED_send(SSD1306_SET_COLUMN_ADDR,1);
    OLED_send(colum,1);
    OLED_send(127,1);

}

void OLED_Putchar(char c)
{
    //Requiere de imprimir toda una se
    uint16_t  charFontStart = (((uint8_t)c-32)*6)+1;
    uint8_t gylphIndex = 0;
    for(gylphIndex=0;gylphIndex <6;gylphIndex++)
    {
    OLED_send(DefaultFont[charFontStart+gylphIndex],0);
    }    
}

void OLED_DrawString(const char * string)
{
    uint8_t index=0;
    while(string[index])
    {
        OLED_Putchar(string[index]);
        index++;
    }   
}



void OLED_DrawSprite(uint8_t x,uint8_t y, const uint8_t *sprite,
        unsigned int spriteLenght,
        uint8_t w,uint8_t h,uint8_t Clean)
{
      //almost same as gotoxy
    //for rows of 8 bits
     OLED_send(SSD1306_SET_PAGE_ADDR,1);
     OLED_send(y,1);
     OLED_send(y+h,1);
    //for colums
     OLED_send(SSD1306_SET_COLUMN_ADDR,1);
     OLED_send(x,1);
     OLED_send(x+w,1);
     unsigned int spriteIndex=0;
     //imprimimos
     while(spriteIndex<spriteLenght){
         OLED_send( Clean?0X00:sprite[spriteIndex],0);
         spriteIndex++;
     }
     OLED_ResetCoords();
}


//new code
bool OLED_InitializeRasterizer(){}
void OLED_UpdateRenderer(){}
bool OLED_PushRendererQueue(){}
bool OLED_PopRendererQueue(){}
void OLED_putpixel(){}
void OLED_DrawCircle(){}
void OLED_DrawRect(){}

//3D gemoetric asembly and rendering


void OLED3D_IdentityMatrix(){}

void OLED3d_Clean(){}
void OLED32_CleanColor(){
}


void OLED3D_DrawVertices(){}

