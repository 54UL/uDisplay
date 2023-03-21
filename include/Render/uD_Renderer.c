#include <uDisplay.h>
#include <uDisplayDriver.h>

static struct uDisplayDriver* driver;

void uDisplay_Initialize(struct uDRenderConfig* config)
{
  // Initialize the display driver
  driver = config->protocol;
  driver->Init(config->protocol);
}

void uDisplay_DrawPixel(uint8_t x, uint8_t y, uint8_t color)
{
  // Calculate the buffer offset based on the x, y coordinates
  uint16_t offset = (y/8)*128 + x;

  // Send the command to set the display buffer start address
  uint8_t start_address[] = {0xB0 | (y/8), x & 0x0F, 0x10 | (x >> 4)};
  driver->SendCommand(start_address, sizeof(start_address));

  // Send the data to set the pixel color
  uint8_t data[] = {1 << (y % 8)};
  if (color == 0) {
    data[0] = 0;
  }
  driver->SendData(data, sizeof(data));
}

void uDisplay_DrawBuffer(struct uDBufferDescriptor buffer)
{
  // Send the command to set the display buffer start address
  uint8_t start_address[] = {0xB0 | (buffer.y/8), buffer.x & 0x0F, 0x10 | (buffer.x >> 4)};
  driver->SendCommand(start_address, sizeof(start_address));

  // Send the data to set the buffer
  driver->SendData(buffer.data, buffer.length);
}

void uDisplay_StartDrawCall(struct uDBufferDescriptor buffer)
{
  // Send the command to set the display buffer start address
  uint8_t start_address[] = {0xB0 | (buffer.y/8), buffer.x & 0x0F, 0x10 | (buffer.x >> 4)};
  driver->SendCommand(start_address, sizeof(start_address));
}

void uDisplay_CommitDrawCall(struct uDBufferDescriptor buffer)
{
  // Send the data to set the buffer
  driver->SendData(buffer.data, buffer.length);
}

static struct uDisplay display = {
  uDisplay_Initialize,
  uDisplay_DrawPixel,
  uDisplay_DrawBuffer,
  uDisplay_StartDrawCall,
  uDisplay_CommitDrawCall
};

struct uDisplay* uDisplay_GetInstance(void)
{
  return &display;
}