#ifndef UD_I2C_H
#define UD_I2C_H
#include "../../uD_Api.h"

#include <stdint.h>
#include <avr/io.h>
#include <avr/interrupt.h>

void    sfw_spi_init(uint8_t address);
void    sfw_spi_start(void);
void    sfw_spi_stop(void);
void    sfw_spi_write(uint8_t data);
void    sfw_spi_transfer(uint8_t cmd, uint8_t *data, uint8_t len);
void    sfw_spi_receive(uint8_t *data, uint16_t len);

#endif //UD_I2C_H




