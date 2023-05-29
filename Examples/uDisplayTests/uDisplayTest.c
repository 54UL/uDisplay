//MAIN PROJECT TEST CODE (START HERE...)

//uDisplay config
#define F_CPU 8000000UL
#define SCREEN_WIDTH 128
#define SCREEN_HEIGHT 64

#include <math.h>
#include <avr/io.h>
#include <stdio.h>

#include "../../include/Drivers/Protocols/uD_Protocols.h"
#include "../../include/uD_Font.h"

#include "../../include/Drivers/uD_Drivers.h"
#include "../../include/Engines/uD_Engines.h"
#include "../../include/Helpers/uD_Delay.h"


//Minimal code to initalize the library with software impl
static inline void InitializeSystem()
{
   //Configures uDisplay renderer
   uDRenderConfig config = { &uDisplay_UnderlyingProtocol_I2C_Software, &uDisplay_SSD1306Driver };

   //Configures the underlying comunication ports and address (0x78) in this case
   uDisplay_UnderlyingProtocol_I2C_Software.configure(0x78);

   //Initialize the driver (internal initialization)
   uDisplay_UnderlyingProtocol_I2C_Software.init();
   uDisplay_SSD1306Driver.Init(&uDisplay_UnderlyingProtocol_I2C_Software);

   //Configures uDisplay rendering
   uDisplayRenderer.Initialize(&config);
}

//Basic font rendering 
static inline void FontRenderingTest()
{
   //Set font data
   uDBufferDescriptor testFont;
   testFont.data = uD_DefaultFont;
   testFont.dataLenght = sizeof(uD_DefaultFont);

   // fontMeta.height = 8;   //this is assume to be 8 bits
   testFont.width = 5; // 5 or 6 deppends on the selected font
   uDisplayRenderer.SetFont(&testFont);

   uDisplayRenderer.DrawString("uDisplay:");
   //Renders all font characters
   uint8_t charIndex = 32;
   const uint8_t fontLenght = sizeof(uD_DefaultFont) / testFont.width;
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
   uDisplayRenderer.DrawPixel(128,64, &color);
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
   //DrawPixelTest();//todo WORKS BUT STRANGE...

   //infinite loop to prevent reboots
   while(1);
}