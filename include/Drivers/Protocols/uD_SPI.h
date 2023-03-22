#ifndef UD_SPI_H
#define UD_SPI_H

#include <avr/io.h>
#include <stdint.h>
#include "../../uD_Api.h"

//THIS IS FOR AVR IMPL

void spi_init(void);
uint8_t spi_read(uint8_t address, uint8_t reg);
void spi_write(uint8_t address, uint8_t reg, uint8_t value);
void spi_transfer(uint8_t *data, uint16_t len);
void spi_send(uint8_t *data, uint16_t len);
void spi_receive(uint8_t *data, uint16_t len);

uDisplayUnderlyingProtocol uDisplay_UnderlyingProtocol_SPI = 
{
    .init = spi_init,
    .read = spi_read,
    .write = spi_write,
    .transfer = spi_transfer,
    .send = spi_send,
    .receive = spi_receive,
};

#endif

