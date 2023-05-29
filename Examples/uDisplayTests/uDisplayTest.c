//MAIN PROJECT TEST CODE (START HERE...)

//uDisplay config
#define F_CPU 8000000UL
#define SCREEN_WIDTH 128
#define SCREEN_HEIGHT 64

#include <math.h>
#include <avr/io.h>
#include <stdio.h>

#include "../../include/uD_Font.h"
#include "../../include/Drivers/Protocols/uD_Protocols.h"
#include "../../include/Drivers/uD_Drivers.h"
#include "../../include/Engines/uD_Engines.h"
#include "../../include/Helpers/uD_Delay.h"


//Minimal code to initalize the library with software impl
static inline void InitializeSystem()
{
   //Configures uDisplay renderer
   uDRenderConfig config = { &uDisplay_UnderlyingProtocol_I2C_Software, &uDisplay_SSD1306Driver, 0x78};

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
   
   //Renders all font characters
   uint8_t charIndex = 32;
   const uint8_t fontLenght = sizeof(uD_DefaultFont) / uD_DefaultFont.width;
   for (; charIndex < fontLenght; charIndex++)
   {
      uDisplayRenderer.DrawChar(charIndex);
   }
}

//Draw pixel test
static inline void DrawPixelTest()
{
   //Renders an string 
   uDColor color;
   uDisplayRenderer.DrawPixel(8, 8, &color);
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
   //DrawPixelTest(); //todo WORKS BUT STRANGE (fixme)...

   //infinite loop to prevent reboots
   while(1);
}