//TODO: FIX EXAMPLE

#include <math.h>

#include "../../include/uD_Api.h"
#include "../../include/Drivers/Protocols/uD_Protocols.h"
#include "../../include/Drivers/uD_Drivers.h"
#include "../../include/Engines/uD_Engines.h"

#define SCREEN_WIDTH 128
#define SCREEN_HEIGHT 64

// Sine wave properties
#define WAVE_AMPLITUDE 32
#define WAVE_PERIOD 64
#define WAVE_STEP 0.1

// Buffer to hold sine wave data
uint8_t waveBuffer[SCREEN_WIDTH];

// Function to generate sine wave data
void generateWaveData() 
{
  for (int x = 0; x < SCREEN_WIDTH; x++) 
  {
    double y = WAVE_AMPLITUDE * sin((2 * M_PI * x) / WAVE_PERIOD);
    waveBuffer[x] = (uint8_t) round(y + SCREEN_HEIGHT / 2);
  }
}

//unit testing
//todo fix the actual example... (discard all this changes)
int main() 
{
  uDRenderConfig config = { &uDisplay_UnderlyingProtocol_I2C, &uDisplay_SSD1306Driver };
  uDisplay_UnderlyingProtocol_I2C.init(0x3C);
  uDisplay_SSD1306Driver.Init(&uDisplay_UnderlyingProtocol_I2C);
  //perform rendering

  while(1);
  return 0;
}