#include "uD_I2C.h"

//THIS IS AVR IMPL

void i2c_init(void) {
    TWSR |= I2C_PRESCALER;
    TWBR = ((F_CPU / I2C_FREQ) - 16) / (2 * (1 << TWPS0));
    TWCR = (1 << TWEN);
}

void i2c_start(uint8_t address) {
    TWCR = (1 << TWINT) | (1 << TWSTA) | (1 << TWEN);
    while (!(TWCR & (1 << TWINT)));
    TWDR = (address << 1);
    TWCR = (1 << TWINT) | (1 << TWEN);
    while (!(TWCR & (1 << TWINT)));
}

void i2c_stop(void) {
    TWCR = (1 << TWINT) | (1 << TWSTO) | (1 << TWEN);
}

uint8_t i2c_read_ack(void) {
    TWCR = (1 << TWINT) | (1 << TWEN) | (1 << TWEA);
    while (!(TWCR & (1 << TWINT)));
    return TWDR;
}

uint8_t i2c_read_nack(void) {
    TWCR = (1 << TWINT) | (1 << TWEN);
    while (!(TWCR & (1 << TWINT)));
    return TWDR;
}

void i2c_write(uint8_t data) {
    TWDR = data;
    TWCR = (1 << TWINT) | (1 << TWEN);
    while (!(TWCR & (1 << TWINT)));
}

void i2c_transfer(uint8_t *data, uint16_t len) {
    uint16_t i;
    for (i = 0; i < len; i++) {
        i2c_write(data[i]);
    }
}

void i2c_send(uint8_t *data, uint16_t len) {
    i2c_start(data[0]);
    i2c_transfer(&data[1], len - 1);
    i2c_stop();
}

void i2c_receive(uint8_t *data, uint16_t len) {
    i2c_start((data[0] << 1) | 1);
    uint16_t i;
    for (i = 0; i < len - 1; i++) {
        data[i] = i2c_read_ack();
    }
    data[len - 1] = i2c_read_nack();
    i2c_stop();
}