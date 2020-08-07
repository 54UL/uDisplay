
#define F_CPU 8000000UL

#include <avr/io.h>
#include <avr/iotn85.h>

#include <util/delay.h>

#define OLED_LOAD_DEFAULT_FONT
#define USE_I2C_SOFTWARE_IMPLEMENTATION
#define USE_DELAY_SOFTWARE_IMPLEMENTATION
#define SDA_PIN PB0
#define SCL_PIN PB1
#define I2C_PORT PORTB
#define I2C_TRIS DDRB

#include <stdio.h>
#include "uOledLib.h"

int main()
{
    uOLED_Initialize();
    uOLED_DrawString("Hola desde AVR :)");
    
   // uOLED_Putchar('F');
    // I2C_MasterStart();
    // I2C_MasterWrite(0XAA);
    // I2C_MasterStop();
    // I2C_MasterStart();
    // I2C_MasterWrite(0XBB);
    // I2C_MasterStop();
    // uint16_t index=0;
    // uint16_t* addressByte;
    // uint8_t byte;
    // for (index = 0; index < 570; index++)
    // {
    //     I2C_MasterStart();
    //     byte = pgm_read_byte( &DefaultFont[index]);
    //     I2C_MasterWrite(byte);
    //     I2C_MasterStop();
    // }
    // // I2C_MasterStart();
    // // I2C_MasterWrite(0XCC);
    // // I2C_MasterStop();

    uint64_t tick;
    DDRB |= 1<<PB2;
    while(1)
    {
        _delay_ms(200);
         PORTB |= 1<< PB2;
        _delay_ms(200);
        PORTB &= ~(1<< PB2);
    };
    return 0;
}