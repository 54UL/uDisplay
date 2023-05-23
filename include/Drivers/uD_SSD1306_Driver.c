#include "uD_SSD1306_Driver.h"

#define SSD1306_I2C_CMD 0x00
#define SSD1306_I2C_DATA 0x40

#define SSD1306_SET_CONTRAST_CONTROL 0x81
#define SSD1306_DISPLAY_ALL_ON_RESUME 0xA4
#define SSD1306_DISPLAY_ALL_ON 0xA5
#define SSD1306_NORMAL_DISPLAY 0xA6
#define SSD1306_INVERT_DISPLAY 0xA7
#define SSD1306_DISPLAY_OFF 0xAE
#define SSD1306_DISPLAY_ON 0xAF
#define SSD1306_NOP 0xE3
#define SSD1306_HORIZONTAL_SCROLL_RIGHT 0x26
#define SSD1306_HORIZONTAL_SCROLL_LEFT 0x27
#define SSD1306_HORIZONTAL_SCROLL_VERTICAL_AND_RIGHT 0x29
#define SSD1306_HORIZONTAL_SCROLL_VERTICAL_AND_LEFT 0x2A
#define SSD1306_DEACTIVATE_SCROLL 0x2E
#define SSD1306_ACTIVATE_SCROLL 0x2F
#define SSD1306_SET_VERTICAL_SCROLL_AREA 0xA3
#define SSD1306_SET_LOWER_COLUMN 0x00
#define SSD1306_SET_HIGHER_COLUMN 0x10
#define SSD1306_MEMORY_ADDR_MODE 0x20
#define SSD1306_SET_COLUMN_ADDR 0x21
#define SSD1306_SET_PAGE_ADDR 0x22
#define SSD1306_SET_START_LINE 0x40
#define SSD1306_SET_SEGMENT_REMAP 0xA0
#define SSD1306_SET_MULTIPLEX_RATIO 0xA8
#define SSD1306_COM_SCAN_DIR_INC 0xC0
#define SSD1306_COM_SCAN_DIR_DEC 0xC8
#define SSD1306_SET_DISPLAY_OFFSET 0xD3
#define SSD1306_SET_COM_PINS 0xDA
#define SSD1306_CHARGE_PUMP 0x8D
#define SSD1306_SET_DISPLAY_CLOCK_DIV_RATIO 0xD5
#define SSD1306_SET_PRECHARGE_PERIOD 0xD9
#define SSD1306_SET_VCOM_DESELECT 0xDB

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
  //PORT uOledLib ssd1306 initializatrion
  
  // Turn display off
  uint8_t command1[] = {SSD1306_DISPLAY_OFF};
  ssd1306_send_command(command1, sizeof(command1));

  // Set memory addressing mode to horizontal
  uint8_t command2[] = {SSD1306_MEMORY_ADDR_MODE, 0x00};
  ssd1306_send_command(command2, sizeof(command2));

  // Set display start line to 0
  uint8_t command3[] = {SSD1306_SET_START_LINE, 0x00};
  ssd1306_send_command(command3, sizeof(command3));

  // // Set segment re-map to column 127
  // uint8_t command4[] = {};
  // ssd1306_send_command(command4, sizeof(command4));

  // Set COM output scan direction to normal
  uint8_t command5[] = {SSD1306_COM_SCAN_DIR_INC};
  ssd1306_send_command(command5, sizeof(command5));

  // Set COM pins hardware configuration to alternative
  uint8_t command6[] = {SSD1306_SET_COM_PINS, 0x12};
  ssd1306_send_command(command6, sizeof(command6));

  // Set display clock divide ratio/oscillator frequency
  uint8_t command7[] = {SSD1306_SET_DISPLAY_CLOCK_DIV_RATIO, 0xF0};
  ssd1306_send_command(command7, sizeof(command7));

  // Set pre-charge period
  uint8_t command8[] = {SSD1306_SET_PRECHARGE_PERIOD, 0x22};
  ssd1306_send_command(command8, sizeof(command8));

  // Set VCOMH deselect level
  uint8_t command9[] = {SSD1306_SET_VCOM_DESELECT, 0x20};
  ssd1306_send_command(command9, sizeof(command9));

  // Set display mode to normal
  uint8_t command10[] = {SSD1306_NORMAL_DISPLAY};
  ssd1306_send_command(command10, sizeof(command10));

  // Set contrast control
  uint8_t command11[] = {SSD1306_SET_CONTRAST_CONTROL, 0xCF};
  ssd1306_send_command(command11, sizeof(command11));

  // Turn display on
  uint8_t command12[] = {SSD1306_DISPLAY_ON};
  ssd1306_send_command(command12, sizeof(command12));
  
  //THIS IS AFTER INITIALIZATION (ON DISPLAY ON)
  // Reset page addr (0 to 7 page mode)
  uint8_t command13[] = {SSD1306_SET_PAGE_ADDR, 0, 7};
  ssd1306_send_command(command13, sizeof(command13));

  // Reset page colum (0 to 127 colum mode)
  uint8_t command14[] = {SSD1306_SET_COLUMN_ADDR, 0, 127};
  ssd1306_send_command(command14, sizeof(command14));
}

void ssd1306_dispose(void)
{
  // Nothing to do
}
