#include "uD_SSD1306_Driver.h"

#define SSD1306_I2C_CMD 0x00
#define SSD1306_I2C_DATA 0x40

static uDisplayUnderlyingProtocol *underlying_protocol;

void ssd1306_send_command(uint8_t *command, uint16_t len)
{  
  underlying_protocol->write(SSD1306_I2C_CMD, command, len);
}

void ssd1306_send_data(uint8_t *data, uint16_t len)
{
  underlying_protocol->write(SSD1306_I2C_DATA, data, len);
}

void ssd1306_init(uDisplayUnderlyingProtocol *protocol)
{
    underlying_protocol = protocol;
  
    // Turn display off
    uint8_t command1[] = {0xAE};
    ssd1306_send_command(command1, sizeof(command1));
  
    // Set memory addressing mode to horizontal
    uint8_t command2[] = {0x20, 0x00};
    ssd1306_send_command(command2, sizeof(command2));
  
    // Set display start line to 0
    uint8_t command3[] = {0x40};
    ssd1306_send_command(command3, sizeof(command3));
  
    // Set segment re-map to column 127
    uint8_t command4[] = {0xA1};
    ssd1306_send_command(command4, sizeof(command4));
  
    // Set COM output scan direction to normal
    uint8_t command5[] = {0xC0};
    ssd1306_send_command(command5, sizeof(command5));
  
    // Set COM pins hardware configuration to alternative
    uint8_t command6[] = {0xDA, 0x12};
    ssd1306_send_command(command6, sizeof(command6));
  
    // Set display clock divide ratio/oscillator frequency
    uint8_t command7[] = {0xD5, 0xF0};
    ssd1306_send_command(command7, sizeof(command7));
  
    // Set pre-charge period
    uint8_t command8[] = {0xD9, 0x22};
    ssd1306_send_command(command8, sizeof(command8));
  
    // Set VCOMH deselect level
    uint8_t command9[] = {0xDB, 0x20};
    ssd1306_send_command(command9, sizeof(command9));
  
    // Set display mode to normal
    uint8_t command10[] = {0xA6};
    ssd1306_send_command(command10, sizeof(command10));
  
    // Set contrast control
    uint8_t command11[] = {0x81, 0xCF};
    ssd1306_send_command(command11, sizeof(command11));
  
    // Turn display on
    uint8_t command12[] = {0xAF};
    ssd1306_send_command(command12, sizeof(command12));
}

void ssd1306_dispose(void)
{
  // Nothing to do
}



