//uDisplay config + my program defines (top most define)
#define F_CPU 8000000UL
#define SCREEN_WIDTH 128
#define SCREEN_HEIGHT 64

#include <math.h>
#include <avr/io.h>
#include "../../include/Drivers/Protocols/uD_Protocols.h"
#include "../../include/Drivers/uD_Drivers.h"
#include "../../include/Helpers/uD_Delay.h"

// SSD1306 AND I2C_TEST BED CHECKERS BIT()
static inline uint8_t SSD1306_I2C_HARDWARE_AVR_TEST()
{
    //Populates rendering config for uDisplay lib
    uDRenderConfig config = {&uDisplay_UnderlyingProtocol_I2C, &uDisplay_SSD1306Driver};
    uint8_t drawCount = 0;
    uint8_t buff[128];

    //Configures i2c underlying impl
    uDisplay_UnderlyingProtocol_I2C.configure(0x3C);
    uD_delay_ms(500);
    //Initialize driver with 0x3c i2c address
    uDisplay_UnderlyingProtocol_I2C.init();
    // uDisplay_SSD1306Driver.Init(&uDisplay_UnderlyingProtocol_I2C); //TODO: FIX THIS!!!( FIXING SSD1306 DRIVER)
    
    //I2C DRIVER TEST BED
    while (drawCount < 128)
    {
        buff[drawCount] = 0xAA;
        drawCount++;
    }

    uDisplay_UnderlyingProtocol_I2C.write(0xFF, buff, sizeof(buff));

    //TODO: ALSO FIX THIS (FIXING SSD1306 DRIVER)
    // //sends dumy data to draw vertically 10101010 and visually represented as horizontal lines
    // while (drawCount < 128)
    // {
    //     uint8_t buff[1] = {0XAA};
    //     uDisplay_SSD1306Driver.SendData(buff, sizeof(buff));
    //     drawCount++;
    // }

    return 0;
}

// SSD1306 AND I2C_TEST BED CHECKERS BIT()
static inline uint8_t SSD1306_I2C_SOFTWARE_AVR_TEST()
{
    //Configure the display render
    uint8_t drawCount = 0;
    uint8_t buff[3] = { 0XAA, 0XBB, 0XCC};
    uDRenderConfig config = {&uDisplay_UnderlyingProtocol_I2C_Software, &uDisplay_SSD1306Driver};
    
    //Call configure before doing anythig else (only call once if selecteed pins does not do anything more)
    uDisplay_UnderlyingProtocol_I2C_Software.configure(0x78);

    //Initialize the I2C protocol and the ssd1306 driver with the initialized protocol
    uDisplay_UnderlyingProtocol_I2C_Software.init();
    uDisplay_SSD1306Driver.Init(&uDisplay_UnderlyingProtocol_I2C_Software);
 
    //SSD1306 DRIVER WITH I2C SOFTWARE TEST (renders a pseduo random pattern all over the screen)
    while (drawCount++ < 0XFF )
    {
        uDisplay_SSD1306Driver.SendData(buff, sizeof(buff));
    }

    return 0;
}


//TODO:
//ADD TO THE COMPILING CHAIN (TO CHECK IF SOMETHING IS BROKEN AS IS)
//ADD STT7789 DRIVER TEST...

void main()
{
   //SOFTWARE I2C/SSD1306
   SSD1306_I2C_SOFTWARE_AVR_TEST();
   
   //infinite loop to prevent reboots
   while(1);
}