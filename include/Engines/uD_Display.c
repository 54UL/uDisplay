#include "uD_Display.h"
#include <avr/pgmspace.h>

// IMPLEMENT RENDERING QUEUE
// THUS TO DISCARD OUT OF TIME FRAMES.
// IF FRAME BUFFER AVAILIBLE, THE RENDER QUEUE HAS TO SAVE ALL RENDERING METHODS TO THE DISPATCH BUFFER, THEN WHEN CALLING COMMIT SEND ALL THIS DATA...
static uDisplayDriver *underlyingDriver;
static uDRect * s_currentOrigin;
static const uint8_t* s_currentFont;

// uDisplay control methods                        ==================================================================================
void uDisplay_Initialize(uDRenderConfig *config)
{
  //TODO: INITIALIZE ALL COMPONENTS FROM HERE:
  
  // Initialize the display driver
  underlyingDriver = config->driver;
  // config->protocol->init(0x78);
  // underlyingDriver->Init(config->protocol);
}

void uDisplay_StartDrawCall(uDBufferDescriptor buffer)
{
  // Send the command to set the display buffer start address
  // uint8_t start_address[] = {0xB0 | (buffer.y / 8), buffer.x & 0x0F, 0x10 | (buffer.x >> 4)};//TODO: MOVE THIS FUNCTION TO THE PROPPER PAGINATION FUNCTION
  // underlyingDriver->SendCommand(start_address, sizeof(start_address));
}

void uDisplay_CommitDrawCall(uDBufferDescriptor buffer)
{
  // Send the data to set the buffer
  underlyingDriver->SendData(buffer.data, buffer.dataLenght);
}

// UDisplay built-in display function interface ==================================================================================
void uDisplay_Clear(void)
{
  static uint16_t rindex = 0;
  uint8_t clearPayload = 0x00;
  
  uDisplay_ResetOrigin();
  for (; rindex < 1024 ; rindex--)//TODO: ADD screen calcualtion
  {
    underlyingDriver->SendData(&clearPayload, 1);
  }
  uDisplay_ResetOrigin();

}

void uDisplay_ClearRegion(uDRect *region)
{
}

void uDisplay_ResetOrigin(void)
{
  s_currentOrigin->x = 0;
  s_currentOrigin->y = 0;
  // s_currentOrigin->height = screen_height;
  // s_currentOrigin->width = screen_width;

  //Send the command to configure page and col settings
  //TODO: IMPLEMENT AT DRIVER LAYER THE FUNCTION void uOLED_ResetCoords(void)
}

void uDisplay_SetOrigin(uDRect *origin)
{
  s_currentOrigin = origin;
  //TODO: IMPLEMENT AT DRIVER LAYER THE FUNCTION void uOLED_gotoxy(void)
}

void uDisplay_SetFont(const uint8_t * fontArray)
{
  s_currentFont = fontArray;
  //TODO: IMPLEMENT AT DRIVER LAYER THE FUNCTION void uOLED_gotoxy(void)
}


// uDisplay rendering methods                                ==================================================================================
void uDisplay_DrawPixel(uint8_t x, uint8_t y, uDColor *color)
{
  // Calculate the buffer offset based on the x, y coordinates
  uint16_t offset = (y/8)*128 + x;

  // Send the command to set the display buffer start address
  uint8_t start_address[] = {0xB0 | (y/8), x & 0x0F, 0x10 | (x >> 4)};
  underlyingDriver->SendCommand(start_address, sizeof(start_address));

  // Send the data to set the pixel color
  uint8_t data[] = {1 << (y % 8)};
  if (color == 0) {
    data[0] = 0;
  }
  underlyingDriver->SendData(data, sizeof(data));
}

void uDisplay_DrawBuffer(uDBufferDescriptor buffer)
{
  // Send the command to set the display buffer start address (TODO REPLACE WITH PAGIANATION FROM THE DRIVER)
  uint8_t start_address[] = {0xB0 | (s_currentOrigin->y/8), s_currentOrigin->x & 0x0F, 0x10 | (s_currentOrigin->x >> 4)};
  underlyingDriver->SendCommand(start_address, sizeof(start_address));

  // Send the data to set the buffer
  underlyingDriver->SendData(buffer.data, buffer.dataLenght);
}

void uDisplay_DrawChar(char character)
{
  static uint16_t charFontStart;
  static uint8_t gylphIndex;

  charFontStart = (((uint8_t)character - 32) * 6) + 1;
  gylphIndex = 0;
  for (gylphIndex = 0; gylphIndex < 6; gylphIndex++)
  { 
      uint8_t readedVal = pgm_read_word (&s_currentFont[charFontStart + gylphIndex]);
      underlyingDriver->SendData(&readedVal, 1);
  }
}

void uDisplay_DrawString(const char *string)
{
  static uint8_t index;

  while (string[index])
  {
      uDisplay_DrawChar(string[index]);
      index++;
  }
}