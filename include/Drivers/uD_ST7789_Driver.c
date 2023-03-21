#include "u_display_api.h"

#define ST7789_CMD_SWRESET     0x01
#define ST7789_CMD_SLPOUT      0x11
#define ST7789_CMD_MADCTL      0x36
#define ST7789_CMD_COLMOD      0x3A
#define ST7789_CMD_DISPON      0x29
#define ST7789_CMD_CASET       0x2A
#define ST7789_CMD_RASET       0x2B
#define ST7789_CMD_RAMWR       0x2C

typedef struct 
{
    struct uDisplayUnderlyingProtocol *protocol;
} ST7789Driver;

static void ST7789_Init(struct uDisplayUnderlyingProtocol *protocol)
{
    // Initialization sequence based on ST7789 datasheet
    protocol->write(0x00, ST7789_CMD_SWRESET, 0x00);
    delay(5);
    protocol->write(0x00, ST7789_CMD_SLPOUT, 0x00);
    delay(120);
    protocol->write(0x00, ST7789_CMD_MADCTL, 0x08);
    protocol->write(0x00, ST7789_CMD_COLMOD, 0x55);
    protocol->write(0x00, ST7789_CMD_DISPON, 0x00);
}

static void ST7789_SendCommand(uint8_t* command, uint16_t len)
{
    struct uDisplayUnderlyingProtocol *protocol = ((ST7789Driver*)this)->protocol;
    protocol->send(command, len);
}

static void ST7789_SendData(uint8_t* data, uint16_t len)
{
    struct uDisplayUnderlyingProtocol *protocol = ((ST7789Driver*)this)->protocol;
    protocol->send(data, len);
}

static void ST7789_Dispose()
{
    // No cleanup needed for I2C
}

void ST7789Driver_Create(ST7789Driver *this, struct uDisplayUnderlyingProtocol *protocol)
{
    this->protocol = protocol;
}

uDisplayDriver ST7789_Driver = {
    .Init = &ST7789_Init,
    .SendCommand = &ST7789_SendCommand,
    .SendData = &ST7789_SendData,
    .Dispose = &ST7789_Dispose
};