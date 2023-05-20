#ifndef UD_I2C_H
#define UD_I2C_H


#include <stdint.h>

#include "../../uD_Api.h"

#include <avr/io.h>
#include <avr/interrupt.h>

//AVR IMPL


#ifndef F_CPU
#define F_CPU 8000000UL
#endif

void    i2c_init(void);
void    i2c_start(uint8_t address);
void    i2c_stop(void);
uint8_t i2c_read_ack(void);
uint8_t i2c_read_nack(void);
void    i2c_write(uint8_t data);
void    i2c_transfer(uint8_t cmd, uint8_t *data, uint8_t len);
void    i2c_receive(uint8_t *data, uint16_t len);

#endif //UD_I2C_H




