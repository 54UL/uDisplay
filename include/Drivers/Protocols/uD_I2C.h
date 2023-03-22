
#ifndef UD_I2C_H
#define UD_I2C_H

#include "../../uD_Api.h"
#include <avr/io.h>
#include <avr/interrupt.h>
#include <stdint.h>

//AVR IMPL
#define I2C_FREQ 100000UL
#define I2C_PRESCALER (1 << TWPS0)

#ifndef F_CPU
#define F_CPU 8000000UL
#endif

void    i2c_init(void);
void    i2c_start(uint8_t address);
void    i2c_stop(void);
uint8_t i2c_read_ack(void);
uint8_t i2c_read_nack(void);
void    i2c_write(uint8_t data);
void    i2c_transfer(uint8_t *data, uint16_t len);
void    i2c_send(uint8_t *data, uint16_t len);
void    i2c_receive(uint8_t *data, uint16_t len);

uDisplayUnderlyingProtocol uDisplay_UnderlyingProtocol_I2C = {
    .init = i2c_init,
    .read = i2c_receive,
    .write = i2c_send,
    .transfer = i2c_transfer,
    .send = i2c_send,
    .receive = i2c_receive,
};

#endif //UD_I2C_H




