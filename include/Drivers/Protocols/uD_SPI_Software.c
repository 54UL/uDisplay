#include "uD_SPI_Software.h"
#include <avr/io.h>

//MOVE THIS 
#define SPI_PORT PORTB
#define SPI_DDR  DDRB
#define SPI_PIN  PINB

#define SPI_MOSI PB3
#define SPI_MISO PB4
#define SPI_SCK  PB5
#define SPI_SS   PB2

void sfw_spi_init(uint8_t address)
{
    SPI_DDR |= (1 << SPI_MOSI) | (1 << SPI_SCK) | (1 << SPI_SS); // Set MOSI, SCK, and SS as output
    SPI_DDR &= ~(1 << SPI_MISO); // Set MISO as input
    SPI_PORT |= (1 << SPI_SS); // Set SS high
}

void sfw_spi_start(void)
{
    SPI_PORT &= ~(1 << SPI_SS); // Set SS low to start SPI transaction
}

void sfw_spi_stop(void)
{
    SPI_PORT |= (1 << SPI_SS); // Set SS high to stop SPI transaction
}

void sfw_spi_write(uint8_t data)
{
    for(uint8_t i = 0; i < 8; i++)
    {
        if(data & 0x80) // If the most significant bit is 1
            SPI_PORT |= (1 << SPI_MOSI); // Set MOSI high
        else
            SPI_PORT &= ~(1 << SPI_MOSI); // Set MOSI low

        SPI_PORT |= (1 << SPI_SCK); // Set SCK high
        data <<= 1; // Shift data left by 1
        SPI_PORT &= ~(1 << SPI_SCK); // Set SCK low
    }
}

uint8_t sfw_spi_read(void)
{
    uint8_t data = 0;
    for(uint8_t i = 0; i < 8; i++)
    {
        data <<= 1; // Shift data left by 1
        SPI_PORT |= (1 << SPI_SCK); // Set SCK high

        if(SPI_PIN & (1 << SPI_MISO)) // If MISO is high
            data |= 0x01; // Set the least significant bit of data to 1

        SPI_PORT &= ~(1 << SPI_SCK); // Set SCK low
    }
    return data;
}

void sfw_spi_transfer(uint8_t cmd, uint8_t *data, uint8_t len)
{
    spi_start();
    spi_write(cmd);
    for(uint8_t i = 0; i < len; i++)
    {
        spi_write(data[i]);
    }
    spi_stop();
}

void sfw_spi_receive(uint8_t *data, uint16_t len)
{
    spi_start();
    for(uint16_t i = 0; i < len; i++)
    {
        data[i] = spi_read();
    }
    spi_stop();
}
