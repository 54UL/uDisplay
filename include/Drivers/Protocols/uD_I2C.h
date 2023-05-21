#ifndef UD_I2C_H
#define UD_I2C_H
#include "../../uD_Api.h"

#include <stdint.h>
#include <avr/io.h>
#include <avr/interrupt.h>

void    i2c_init(uint8_t address);
void    i2c_start(void);
void    i2c_stop(void);
uint8_t i2c_read_ack(void);
uint8_t i2c_read_nack(void);
void    i2c_write(uint8_t data);
void    i2c_transfer(uint8_t cmd, uint8_t *data, uint8_t len);
void    i2c_receive(uint8_t *data, uint16_t len);

#endif //UD_I2C_H




