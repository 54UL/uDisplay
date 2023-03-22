#ifndef UD_ST8799_DRIVER_H
#define UD_ST8799_DRIVER_H

#include "../uD_Api.h"

#define ST7789_CMD_SWRESET     0x01
#define ST7789_CMD_SLPOUT      0x11
#define ST7789_CMD_MADCTL      0x36
#define ST7789_CMD_COLMOD      0x3A
#define ST7789_CMD_DISPON      0x29
#define ST7789_CMD_CASET       0x2A
#define ST7789_CMD_RASET       0x2B
#define ST7789_CMD_RAMWR       0x2C

void ST7789_Init(uDisplayUnderlyingProtocol *protocol);
void ST7789_SendCommand(uint8_t* command, uint16_t len);
void ST7789_SendData(uint8_t* data, uint16_t len);
void ST7789_Dispose();

#endif UD_ST8799_DRIVER_H
