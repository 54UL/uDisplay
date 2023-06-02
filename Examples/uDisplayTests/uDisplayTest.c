//MAIN PROJECT TEST CODE (START HERE...)

//uDisplay config (AVR)
#define F_CPU 8000000UL

#include <math.h>
#include <avr/io.h>
#include <stdio.h>

#include "../../include/uD_Font.h"
#include "../../include/Drivers/Protocols/uD_Protocols.h"
#include "../../include/Drivers/uD_Drivers.h"
#include "../../include/Engines/uD_Engines.h"
#include "../../include/Helpers/uD_Delay.h"

//TODO: ADD THIS FLAGS ON CMAKE
// #define SSD1306_SFTW_TEST
#define ST7789_SFTW_TEST

//Minimal code to initalize the library with software impl
static inline void InitializeSystem()
{
   //Configures uDisplay renderer in this order: protocol/display_driver/address
   
#ifdef SSD1306_SFTW_TEST
   // I2C Software config, and 128x64 ssd1306 oled display at address 0x78
   uDRenderConfig config = { &uDisplay_UnderlyingProtocol_I2C_Software, &uDisplay_SSD1306Driver, 0x78};
#elif defined(ST7789_SFTW_TEST)  
   // SPI Software config, ST7789 and address is not used because spi protocol.
   uDRenderConfig config = { &uDisplay_UnderlyingProtocol_SPI_Software, &uDisplay_st7789_driver, 0X00}; 
#endif

   //Configures uDisplay rendering
   uDisplayRenderer.Initialize(&config);
}

//Basic font rendering 
static inline void FontRenderingTest()
{
   //uD_DefaultFont is the built-in font descriptor
   uDisplayRenderer.SetFont(&uD_DefaultFont);

   //This method draws an string at the current origin
   uDisplayRenderer.DrawString("uDisplay:");
   
   //Tries to render 96 characters only
   uint8_t charIndex = 32;
  for (; charIndex < 96 * uD_DefaultFont.width; charIndex++)
   {
      uDisplayRenderer.DrawChar(charIndex);
   }
   
   uDisplayRenderer.Clear();
   uD_delay_ms(1500);
}

//Draw pixel test
static inline void DrawPixelTest()
{
   //Renders an string 
   uDColor color = {uDPixelFormat::MONOCHROME, 0x1};
   uDisplayRenderer.DrawPixel(8, 8, &color);

   uDisplayRenderer.Clear();
   uD_delay_ms(1500);
}

//Animation test
static inline void AnimationTest()
{
   //Rendering with pre-clean draw, page and colums addresing aka buffer less rendering???
   //Add bouncing ball rendering code...
}

void main()
{
   InitializeSystem();
   FontRenderingTest(); 
   DrawPixelTest();

   //infinite loop to prevent reboots
   while(1);
}