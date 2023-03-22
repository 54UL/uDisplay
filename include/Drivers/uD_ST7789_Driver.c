#include "../uD_Api.h"

#include "../Helpers/uD_Delay.h"

#define ST7789_CMD_SWRESET     0x01
#define ST7789_CMD_SLPOUT      0x11
#define ST7789_CMD_MADCTL      0x36
#define ST7789_CMD_COLMOD      0x3A
#define ST7789_CMD_DISPON      0x29
#define ST7789_CMD_CASET       0x2A
#define ST7789_CMD_RASET       0x2B
#define ST7789_CMD_RAMWR       0x2C

static uDisplayUnderlyingProtocol *underlying_protocol;

void ST7789_Init(uDisplayUnderlyingProtocol *protocol)
{
    underlying_protocol = protocol;
    // Initialization sequence based on ST7789 datasheet
    protocol->write(0x00, ST7789_CMD_SWRESET, 0x00);
    uD_delay_ms(5);
    protocol->write(0x00, ST7789_CMD_SLPOUT, 0x00);
    uD_delay_ms(120);
    protocol->write(0x00, ST7789_CMD_MADCTL, 0x08);
    protocol->write(0x00, ST7789_CMD_COLMOD, 0x55);
    protocol->write(0x00, ST7789_CMD_DISPON, 0x00);
}

void ST7789_SendCommand(uint8_t* command, uint16_t len)
{
    underlying_protocol->send(command, len);
}

void ST7789_SendData(uint8_t* data, uint16_t len)
{
    underlying_protocol->send(data, len);
}

void ST7789_Dispose()
{
    // No cleanup needed for I2C
}