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


// Initializes a ssd1306 (i2c_software) uDisplay base renderer
static inline void uDisplay_DrawStringRenderTest()
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
   uDisplayRenderer.SetFont(uD_DefaultFont);

   //Renders an string 
   uDisplayRenderer.DrawString("uDisplay:");

   //Renders all font characters
   uint8_t charIndex = 32;
   const uint8_t fontLenght = sizeof(uD_DefaultFont) / 6;
   for (; charIndex < fontLenght; charIndex++)
   {
      uDisplayRenderer.DrawChar(charIndex);
   }
}


void main()
{
   uDisplay_DrawStringRenderTest();
   //infinite loop to prevent reboots
   while(1);
}