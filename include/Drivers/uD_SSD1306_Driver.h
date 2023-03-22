#ifndef UD_SSD1306_DRIVER_H
#define UD_SSD1306_DRIVER_H

#include "../uD_Api.h"
#include <stdint.h>

#define SSD1306_I2C_ADDR 0x3C

static void ssd1306_send_command(uint8_t *command, uint16_t len);
static void ssd1306_send_data(uint8_t *data, uint16_t len);
static void ssd1306_init(uDisplayUnderlyingProtocol *protocol);
static void ssd1306_dispose(void);

#endif


