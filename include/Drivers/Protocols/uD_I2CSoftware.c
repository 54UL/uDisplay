#include "uD_I2CSoftware.h"
#include <avr/io.h>
#include "../../Helpers/uD_Delay.h"

//TODO: MOVE THIS Pin Definitions
#define SDA_PIN PB0
#define SCL_PIN PB2

// Global Variables
static uint8_t current_i2c_address;
uint8_t serial_buff_oled;
uint16_t timeout;

void sfw_i2c_init(uint8_t address)
{
    current_i2c_address = address;
    DDRB  |= (1 << SCL_PIN) | (1 << SDA_PIN);
    PORTB |= (1 << SCL_PIN) | (1 << SDA_PIN);
}

void sfw_i2c_start() //ADDRESS NOT USED !!!
{    
    PORTB |= (1 << SCL_PIN);
    PORTB |= (1 << SDA_PIN);
    uD_delay_ms(1); // Add a delay of 1 ms
    PORTB &= ~(1 << SDA_PIN);
}

void sfw_i2c_stop()
{
    PORTB &= ~(1 << SCL_PIN);
    PORTB &= ~(1 << SDA_PIN);
    uD_delay_ms(1); // Add a delay of 1 ms
    PORTB |= (1 << SCL_PIN);
    PORTB |= (1 << SDA_PIN);
}

int sfw_i2c_check_ack()
{
    PORTB &= ~(1 << SCL_PIN);  // Ensure SCL is low
    DDRB &= ~(1 << SDA_PIN);    // Set SDA as input to check for ACK
    PORTB |= (1 << SCL_PIN);    // Generate clock pulse
    int ack = !(PINB & (1 << SDA_PIN));  // Check if SDA is pulled low (ACK received)
    PORTB &= ~(1 << SCL_PIN);    // Clear SCL
    DDRB |= (1 << SDA_PIN);      // Set SDA as output again
    return ack;
}

void sfw_i2c_write(uint8_t data)
{
    PORTB &= ~(1 << SCL_PIN); // Ensure SCL is low
    
    for (serial_buff_oled = 0; serial_buff_oled < 8; serial_buff_oled++)
    {
        if (data & (0x80 >> serial_buff_oled))
            PORTB |= (1 << SDA_PIN);
        else
            PORTB &= ~(1 << SDA_PIN);
        
        PORTB |= (1 << SCL_PIN); // Generate clock pulse
        PORTB &= ~(1 << SCL_PIN);
    }
    
    // Check for ACK
    if (!sfw_i2c_check_ack())
    {
        // Handle NACK condition
        // Here, we will just exit the function without taking any action
        return;
    }
}

void sfw_i2c_transfer(uint8_t cmd, uint8_t *data, uint8_t len)
{
    sfw_i2c_start();
    sfw_i2c_write(current_i2c_address);
    sfw_i2c_write(cmd);

    for (uint8_t i = 0; i < len; i++)
    {
        sfw_i2c_write(data[i]);
    }
    sfw_i2c_stop();
}

void sfw_i2c_receive(uint8_t *data, uint16_t len)
{
    // NOT IMPLEMENTED
    for (uint8_t i = 0; i < len; i++)
    {
        data[i] = 0xCC;
    }
}

