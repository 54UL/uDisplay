#ifndef UD_ENGINES_H
#define UD_ENGINES_H

#include "../uD_Api.h"
#include "uD_Display.h"

uDisplay uDisplayRenderer = {
  //Base functionality functions
  .Initialize = uDisplay_Initialize,
  .StartDrawCall = uDisplay_StartDrawCall,
  .EndDrawCall = uDisplay_CommitDrawCall,
  //Rendering logic functions
  .Clear = uDisplay_Clear,
  .ClearRegion = uDisplay_ClearRegion,
  .ResetOrigin = uDisplay_ResetOrigin,
  .Origin = uDisplay_SetOrigin,
  .SetFont = uDisplay_SetFont,
  //Draw functions
  .DrawPixel = uDisplay_DrawPixel,
  .DrawBuffer = uDisplay_DrawBuffer,
  .DrawChar = uDisplay_DrawChar,
  .DrawString = uDisplay_DrawString
};
                   
#endif