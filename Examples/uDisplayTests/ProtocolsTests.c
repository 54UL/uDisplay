//uDisplay config
#define F_CPU 8000000UL
#define SCREEN_WIDTH 128
#define SCREEN_HEIGHT 64
#define I2C_SOFTWARE_TEST //TODO: define symbols in cmake config for selecting the running example

#include <math.h>
#include <avr/io.h>
#include "../../include/Drivers/Protocols/uD_Protocols.h"
#include "../../include/Helpers/uD_Delay.h"

const static uint8_t example_buffer[] = {0XAA, 0XBB, 0XCC};    

// SSD1306 AND I2C_TEST BED CHECKERS BIT()
static inline void SSD1306_I2C_HARDWARE_AVR_TEST()
{
    //Configures the underlying comunication ports and address (0x3c) in this case
    uDisplay_UnderlyingProtocol_I2C.configure(0x78);
    //Initialize the driver (internal initialization)
    uDisplay_UnderlyingProtocol_I2C.init();
    //Send the buffer via hardware I2C and you must recive this sequence {0XFF, 0XAA, 0XBB, 0XCC}
    uDisplay_UnderlyingProtocol_I2C.write(0xFF, example_buffer, sizeof(example_buffer));
}

// SSD1306 AND I2C_TEST BED CHECKERS BIT()
static inline void SSD1306_I2C_SOFTWARE_AVR_TEST()
{
    //Configures the underlying comunication ports and address (0x3c) in this case
    uDisplay_UnderlyingProtocol_I2C_Software.configure(0x78);
    //Initialize the driver (internal initialization)
    uDisplay_UnderlyingProtocol_I2C_Software.init();
    //Send data via software I2C and you must recive this sequence {0XFF, 0XAA, 0XBB, 0XCC}
    uDisplay_UnderlyingProtocol_I2C.write(0xFF, example_buffer, sizeof(example_buffer));
}

void main()
{
#ifdef I2C_HARDWARE_TEST
   SSD1306_I2C_HARDWARE_AVR_TEST
#elif defined(I2C_SOFTWARE_TEST)
   SSD1306_I2C_SOFTWARE_AVR_TEST();
#endif
   //infinite loop to prevent reboots
   while(1);
}