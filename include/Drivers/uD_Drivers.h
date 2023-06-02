#ifndef UD_DRIVERS_H
#define UD_DRIVERS_H

//TODO: ADD A FUNCTION TO CALL ALMOST EVERY BUILT IN COMMAND FROM HERE
//PROPOSAL: Call(BUILT_IN_ENUM_TYPE type, uint8_t payload, payloadLen);
//REFACTOR DRIVER INTERFACE

#include "../uD_Api.h"
#include "uD_SSD1306_Driver.h"
#include "uD_ST7789_Driver.h"

uDisplayDriver uDisplay_SSD1306Driver = {
  .Init = ssd1306_init,
  .SendCommand = ssd1306_send_command,
  .SendData = ssd1306_send_data,
  .Dispose = ssd1306_dispose
};

uDisplayDriver uDisplay_st7789_driver = {
    .Init = st7789_init,
    .SendCommand = st7789_SendCommand,
    .SendData = st7789_send_data,
    .Dispose = st7789_dispose
};

#endif