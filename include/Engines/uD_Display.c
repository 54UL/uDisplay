#include "uD_Display.h"

// IMPLEMENT RENDERING QUEUE
// THUS TO DISCARD OUT OF TIME FRAMES.
// IF FRAME BUFFER AVAILIBLE, THE RENDER QUEUE HAS TO SAVE ALL RENDERING METHODS TO THE DISPATCH BUFFER, THEN WHEN CALLING COMMIT SEND ALL THIS DATA...
static uDisplayDriver *underlyingDriver;
static uDRect origin* s_currentOrigin;

// uDisplay control methods                        ==================================================================================
void uDisplay_Initialize(uDRenderConfig *config)
{
  // Initialize the display driver
  underlyingDriver = config->driver;
  // config->protocol->init(0x78);
  underlyingDriver->Init(config->protocol);
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
}

void uDisplay_ClearRegion(uDRect *region)
{
}

void uDisplay_ResetOrigin(void)
{
  
}

void uDisplay_Origin(uDRect *origin)
{
  s_currentOrigin = origin;
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
  uint8_t start_address[] = {0xB0 | (s_currentOrigin.y/8), s_currentOrigin.x & 0x0F, 0x10 | (s_currentOrigin.x >> 4)};
  underlyingDriver->SendCommand(start_address, sizeof(start_address));

  // Send the data to set the buffer
  underlyingDriver->SendData(buffer.data, buffer.dataLenght);
}

void uDisplay_DrawChar(char character)
{

}

void uDisplay_DrawString(const char *string)
{
}