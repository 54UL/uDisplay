#ifndef UD_ST7789_DRIVER_H
#define UD_ST7789_DRIVER_H

#include "../uD_Api.h"
#include <stdint.h>

//Driver impl
void st7789_send_command(uint8_t *command, uint8_t len);
void st7789_send_data(uint8_t *data, uint8_t len);
void st7789_init(uDisplayUnderlyingProtocol *protocol);
void st7789_dispose(void);

#endif


