
#include <avr/io.h>
#include <stdint.h>
#include "spi.h"

//THIS IS FOR AVR IMPL

void spi_init(void) {
    // Set MOSI and SCK pins as outputs
    DDRB |= (1 << DDB0) | (1 << DDB2);

    // Enable SPI, Master mode, and set clock rate to F_CPU/16
    SPCR |= (1 << SPE) | (1 << MSTR) | (1 << SPR0);
}

uint8_t spi_read(uint8_t address, uint8_t reg) {
    uint8_t data;

    // Set SS pin low to select device
    PORTB &= ~(1 << PORTB1);

    // Send address and register values
    SPDR = (address << 1) | 0x01;
    while (!(SPSR & (1 << SPIF)));
    SPDR = reg;
    while (!(SPSR & (1 << SPIF)));

    // Receive data
    SPDR = 0x00;
    while (!(SPSR & (1 << SPIF)));
    data = SPDR;

    // Set SS pin high to deselect device
    PORTB |= (1 << PORTB1);

    return data;
}

void spi_write(uint8_t address, uint8_t reg, uint8_t value) {
    // Set SS pin low to select device
    PORTB &= ~(1 << PORTB1);

    // Send address, register, and value
    SPDR = (address << 1);
    while (!(SPSR & (1 << SPIF)));
    SPDR = reg;
    while (!(SPSR & (1 << SPIF)));
    SPDR = value;
    while (!(SPSR & (1 << SPIF)));

    // Set SS pin high to deselect device
    PORTB |= (1 << PORTB1);
}

void spi_transfer(uint8_t *data, uint16_t len) {
    uint16_t i;

    // Set SS pin low to select device
    PORTB &= ~(1 << PORTB1);

    for (i = 0; i < len; i++) {
        // Send data
        SPDR = data[i];
        while (!(SPSR & (1 << SPIF)));

        // Receive data
        data[i] = SPDR;
    }

    // Set SS pin high to deselect device
    PORTB |= (1 << PORTB1);
}

void spi_send(uint8_t *data, uint16_t len) {
    uint16_t i;

    // Set SS pin low to select device
    PORTB &= ~(1 << PORTB1);

    for (i = 0; i < len; i++) {
        // Send data
        SPDR = data[i];
        while (!(SPSR & (1 << SPIF)));
    }

    // Set SS pin high to deselect device
    PORTB |= (1 << PORTB1);
}

void spi_receive(uint8_t *data, uint16_t len) {
    uint16_t i;

    // Set SS pin low to select device
    PORTB &= ~(1 << PORTB1);

    for (i = 0; i < len; i++) {
        // Send dummy data to receive data
        SPDR = 0x00;
        while (!(SPSR & (1 << SPIF)));
        data[i] = SPDR;
    }

    // Set SS pin high to deselect device
    PORTB |= (1 << PORTB1);
}

uDisplayUnderlyingProtocol uDisplay_UnderlyingProtocol_SPI= 
{
    .init = spi_init,
    .read = spi_read,
    .write = spi_write,
    .transfer = spi_transfer,
    .send = spi_send,
    .receive = spi_receive,
};


