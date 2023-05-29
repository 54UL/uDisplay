#ifndef UD_DRIVERS_H
#define UD_DRIVERS_H

//TODO: ADD A FUNCTION TO CALL ALMOST EVERY BUILT IN COMMAND FROM HERE
//PROPOSAL: Call(BUILT_IN_ENUM_TYPE type, uint8_t payload, payloadLen);

#include "../uD_Api.h"
#include "uD_SSD1306_Driver.h"
// #include "uD_ST7789_Driver.h"

uDisplayDriver uDisplay_SSD1306Driver = {
  .Init = ssd1306_init,
  .SendCommand = ssd1306_send_command,
  .SendData = ssd1306_send_data,
  .Dispose = ssd1306_dispose
};

// uDisplayDriver uDisplay_ST7789Driver = {
//     .Init = ST7789_Init,
//     .SendCommand = ST7789_SendCommand,
//     .SendData = ST7789_SendData,
//     .Dispose = ST7789_Dispose
// };

#endif