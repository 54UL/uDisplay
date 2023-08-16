#ifndef UD_I2C_SOFTWARE_H
#define UD_I2C_SOFTWARE_H
#include "../../uD_Api.h"

#include <stdint.h>
#include <avr/io.h>
#include <avr/interrupt.h>

//todo move this FCPU AVR IMPL
#ifndef F_CPU
#define F_CPU 8000000UL
#endif

//public
void    sfw_i2c_init(uint8_t address);
void    sfw_i2c_start(void);
void    sfw_i2c_stop(void);
// uint8_t sfw_i2c_read_ack(void);
// uint8_t sfw_i2c_read_nack(void);
void    sfw_i2c_write(uint8_t data);
void    sfw_i2c_transfer(uint8_t cmd, uint8_t *data, uint8_t len);
void    sfw_i2c_receive(uint8_t *data, uint16_t len);

#endif //UD_I2C_SOFTWARE_H




