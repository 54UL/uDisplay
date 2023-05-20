#include <math.h>

// #include "../../include/uD_Api.h" NOT USED YET?
#include "../../include/Drivers/Protocols/uD_Protocols.h"
#include "../../include/Drivers/uD_Drivers.h"
// #include "../../include/Engines/uD_Engines.h" NOT USED YET

#define SCREEN_WIDTH 128
#define SCREEN_HEIGHT 64

// SSD1306 AND I2C_TEST BED CHECKERS BIT()
inline uint8_t SSD1306_I2C_AVR_TEST()
{
    //Populates rendering config for uDisplay lib
    uDRenderConfig config = {&uDisplay_UnderlyingProtocol_I2C, &uDisplay_SSD1306Driver};
    uint8_t drawCount = 0;
    uint8_t buff[128];

    //Configures i2c underlying impl
    // uDisplay_UnderlyingProtocol_I2C.configure();
    
    //Initialize driver with 0x3c i2c address
    uDisplay_UnderlyingProtocol_I2C.init(0x3C);
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


//TODO:
//ADD TO THE COMPILING CHAIN (TO CHECK IF SOMETHING IS BROKEN AS IS)
//ADD STT7789 DRIVER TEST...

void main()
{
    SSD1306_I2C_AVR_TEST();
   
    while(1);//block the execution
}