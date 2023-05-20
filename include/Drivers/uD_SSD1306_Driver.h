#ifndef UD_SSD1306_DRIVER_H
#define UD_SSD1306_DRIVER_H

#include "../uD_Api.h"
#include <stdint.h>

void ssd1306_send_command(uint8_t *command, uint16_t len);
void ssd1306_send_data(uint8_t *data, uint16_t len);
void ssd1306_init(uDisplayUnderlyingProtocol *protocol);
void ssd1306_dispose(void);

#endif


