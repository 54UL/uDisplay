#include "../uD_Api.h"
#include "./Protocols/uD_I2C.h"

#define SSD1306_I2C_ADDR 0x3C

static uDisplayUnderlyingProtocol *underlying_protocol;

static void ssd1306_send_command(uint8_t *command, uint16_t len)
{
  // struct uDisplayUnderlyingProtocol *protocol = ((ST7789Driver*)this)->protocol;
  
  underlying_protocol->write(SSD1306_I2C_ADDR, 0x00, *command);
}

static void ssd1306_send_data(uint8_t *data, uint16_t len)
{
  underlying_protocol->write(SSD1306_I2C_ADDR, 0x40, *data);
}

static void ssd1306_init(uDisplayUnderlyingProtocol *protocol)
{
  underlying_protocol = protocol;

  // Turn display off
  uint8_t command[] = {0xAE};
  ssd1306_send_command(command, sizeof(command));

  // Set memory addressing mode to horizontal
  uint8_t set_memory_addressing_mode[] = {0x20, 0x00};
  ssd1306_send_command(set_memory_addressing_mode, sizeof(set_memory_addressing_mode));

  // Set display start line to 0
  uint8_t set_display_start_line[] = {0x40};
  ssd1306_send_command(set_display_start_line, sizeof(set_display_start_line));

  // Set segment re-map to column 127
  uint8_t set_segment_remap[] = {0xA1};
  ssd1306_send_command(set_segment_remap, sizeof(set_segment_remap));

  // Set COM output scan direction to normal
  uint8_t set_com_output_scan_direction[] = {0xC0};
  ssd1306_send_command(set_com_output_scan_direction, sizeof(set_com_output_scan_direction));

  // Set COM pins hardware configuration to alternative
  uint8_t set_com_pins_hardware_configuration[] = {0xDA, 0x12};
  ssd1306_send_command(set_com_pins_hardware_configuration, sizeof(set_com_pins_hardware_configuration));

  // Set display clock divide ratio/oscillator frequency
  uint8_t set_display_clock_divide_ratio[] = {0xD5, 0xF0};
  ssd1306_send_command(set_display_clock_divide_ratio, sizeof(set_display_clock_divide_ratio));

  // Set pre-charge period
  uint8_t set_pre_charge_period[] = {0xD9, 0x22};
  ssd1306_send_command(set_pre_charge_period, sizeof(set_pre_charge_period));

  // Set VCOMH deselect level
  uint8_t set_vcomh_deselect_level[] = {0xDB, 0x20};
  ssd1306_send_command(set_vcomh_deselect_level, sizeof(set_vcomh_deselect_level));

  // Set display mode to normal
  uint8_t set_display_mode[] = {0xA6};
  ssd1306_send_command(set_display_mode, sizeof(set_display_mode));

  // Set contrast control
  uint8_t set_contrast_control[] = {0x81, 0xCF};
  ssd1306_send_command(set_contrast_control, sizeof(set_contrast_control));

  // Turn display on
  uint8_t set_display_on[] = {0xAF};
  ssd1306_send_command(set_display_on, sizeof(set_display_on));
}

static void ssd1306_dispose(void)
{
  // Nothing to do
}



