#include "uD_I2C.h"
#include <avr/io.h>
#include <avr/interrupt.h>

// THIS IS ATtiny85 IMPL
static uint8_t current_i2c_address;

#define I2C_FREQ 400000

void i2c_init()
{
    USICR = (1 << USIWM1) | (1 << USICS1) | (1 << USICS0); // Two-wire mode, external positive edge clock source
    USIDR = 0xFF; // Preload data register with 0xFF to release SDA line
    USISR = (1 << USISIF) | (1 << USIOIF) | (1 << USIPF) | (1 << USIDC) | (0x0 << USICNT0); // Clear flags and reset counter
    DDRB |= (1 << DDB0); // Set SDA (PB0) as output
    PORTB |= (1 << PORTB0); // Set SDA (PB0) high
    DDRB &= ~(1 << DDB2); // Set SCL (PB2) as input
    PORTB |= (1 << PORTB2); // Enable pull-up on SCL (PB2)
}

void i2c_start(uint8_t address)
{
    // i2c_init();
    USISR = (1 << USISIF) | (1 << USIOIF) | (1 << USIPF) | (1 << USIDC) | (0x0 << USICNT0); // Clear flags and reset counter
    USIDR = (address << 1) | 0x00; // Set address with write bit
    DDRB |= (1 << DDB0); // Set SDA (PB0) as output
    USICR |= (1 << USICLK) | (1 << USITC); // Toggle clock to generate start condition
    while (!(USISR & (1 << USIOIF))); // Wait for start condition to be transmitted
    DDRB &= ~(1 << DDB0); // Set SDA (PB0) as input
}

void i2c_stop(void)
{
    USIDR = 0xFF; // Preload data register with 0xFF to release SDA line
    DDRB |= (1 << DDB0); // Set SDA (PB0) as output
    USICR |= (1 << USICLK) | (1 << USITC); // Toggle clock to generate stop condition
    while (!(USISR & (1 << USIPF))); // Wait for stop condition to be transmitted
    DDRB &= ~(1 << DDB0); // Set SDA (PB0) as input
}

uint8_t i2c_read_ack(void)
{
    DDRB &= ~(1 << DDB0); // Set SDA (PB0) as input
    USIDR = 0x00; // Preload data register with 0x00 to ACK next byte
    USICR |= (1 << USICLK) | (1 << USITC); // Toggle clock to read byte and generate ACK
    while (!(USISR & (1 << USIOIF))); // Wait for byte to be received
    return USIDR;
}

uint8_t i2c_read_nack(void)
{
    DDRB &= ~(1 << DDB0); // Set SDA (PB0) as input
    USIDR = 0xFF; // Preload data register with 0xFF to NACK next byte
    USICR |= (1 << USICLK) | (1 << USITC); // Toggle clock to read byte and generate NACK
    while (!(USISR & (1 << USIOIF))); // Wait for byte to be received
    return USIDR;
}

void i2c_write(uint8_t data)
{
    DDRB |= (1 << DDB0); // Set SDA (PB0) as output
    USIDR = data; // Load data into the data register
    USICR |= (1 << USICLK) | (1 << USITC); // Toggle clock to send byte
    while (!(USISR & (1 << USIOIF))); // Wait for byte to be sent
}

void i2c_transfer(uint8_t cmd, uint8_t *data, uint8_t len)
{
    i2c_start(current_i2c_address);
    for (uint8_t i = 0; i < len; i++)
    {
        i2c_write(data[i]);
    }
    i2c_stop();
}

void i2c_receive(uint8_t *data, uint16_t len)
{
    i2c_start((data[0] << 1) | 1);
    for (uint16_t i = 0; i < len - 1; i++)
    {
        data[i] = i2c_read_ack();
    }
    data[len - 1] = i2c_read_nack();
    i2c_stop();
}
