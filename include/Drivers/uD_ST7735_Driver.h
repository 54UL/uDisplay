#ifndef UD_ST7735_DRIVER_H
#define UD_ST7735_DRIVER_H

#include "../uD_Api.h"
#include <stdint.h>

//Driver impl
void st7735_send_command(uint8_t *command, uint8_t len);
void st7735_send_data(uint8_t *data, uint8_t len);
void st7735_init(uDisplayUnderlyingProtocol *protocol);
void st7735_dispose(void);

#endif


