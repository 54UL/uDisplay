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

void ssd1306_send_command(uint8_t *command, uint8_t len)
{
  underlying_protocol->write(SSD1306_I2C_CMD, command, len);
}

void ssd1306_send_data(uint8_t *data, uint8_t len)
{
  underlying_protocol->write(SSD1306_I2C_DATA, data, len);
}

void ssd1306_init(uDisplayUnderlyingProtocol *protocol)
{
  underlying_protocol = protocol;
  
  uint8_t displayOffCommand[] = {SSD1306_DISPLAY_OFF, 0x00};
  ssd1306_send_command(displayOffCommand, sizeof(displayOffCommand));

  uint8_t displayClockDivRatioCommand[] = {SSD1306_SET_DISPLAY_CLOCK_DIV_RATIO, 0x80};
  ssd1306_send_command(displayClockDivRatioCommand, sizeof(displayClockDivRatioCommand));

  uint8_t multiplexRatioCommand[] = {SSD1306_SET_MULTIPLEX_RATIO, 0x3F};
  ssd1306_send_command(multiplexRatioCommand, sizeof(multiplexRatioCommand));

  uint8_t displayOffsetCommand[] = {SSD1306_SET_DISPLAY_OFFSET, 0x00};
  ssd1306_send_command(displayOffsetCommand, sizeof(displayOffsetCommand));

  uint8_t startLineCommand[] = {SSD1306_SET_START_LINE | 0x00, 0x00};
  ssd1306_send_command(startLineCommand, sizeof(startLineCommand));

  uint8_t chargePumpCommand[] = {SSD1306_CHARGE_PUMP, 0x14};
  ssd1306_send_command(chargePumpCommand, sizeof(chargePumpCommand));

  uint8_t addrModeCommand[] = {SSD1306_MEMORY_ADDR_MODE, 0x00};
  ssd1306_send_command(addrModeCommand, sizeof(addrModeCommand));

  uint8_t segmentRemapCommand[] = {SSD1306_SET_SEGMENT_REMAP | 0x01, 0x00};
  ssd1306_send_command(segmentRemapCommand, sizeof(segmentRemapCommand));

  uint8_t comScanDirCommand[] = {SSD1306_COM_SCAN_DIR_DEC, 0x00};
  ssd1306_send_command(comScanDirCommand, sizeof(comScanDirCommand));

  uint8_t comPinsCommand[] = {SSD1306_SET_COM_PINS, 0x12};
  ssd1306_send_command(comPinsCommand, sizeof(comPinsCommand));

  uint8_t contrastControlCommand[] = {SSD1306_SET_CONTRAST_CONTROL, 0xCF};
  ssd1306_send_command(contrastControlCommand, sizeof(contrastControlCommand));

  uint8_t prechargePeriodCommand[] = {SSD1306_SET_PRECHARGE_PERIOD, 0xF1};
  ssd1306_send_command(prechargePeriodCommand, sizeof(prechargePeriodCommand));

  uint8_t vcomDeselectCommand[] = {SSD1306_SET_VCOM_DESELECT, 0x40};
  ssd1306_send_command(vcomDeselectCommand, sizeof(vcomDeselectCommand));

  uint8_t displayAllOnResumeCommand[] = {SSD1306_DISPLAY_ALL_ON_RESUME, 0x00};
  ssd1306_send_command(displayAllOnResumeCommand, sizeof(displayAllOnResumeCommand));

  uint8_t normalDisplayCommand[] = {SSD1306_NORMAL_DISPLAY, 0x00};
  ssd1306_send_command(normalDisplayCommand, sizeof(normalDisplayCommand));

  uint8_t deactivateScrollCommand[] = {SSD1306_DEACTIVATE_SCROLL, 0x00};
  ssd1306_send_command(deactivateScrollCommand, sizeof(deactivateScrollCommand));

  uint8_t displayOnCommand[] = {SSD1306_DISPLAY_ON, 0x00};
  ssd1306_send_command(displayOnCommand, sizeof(displayOnCommand));
}

void ssd1306_dispose(void)
{
  // Nothing to do
}
