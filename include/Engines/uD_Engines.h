#ifndef UD_ENGINES_H
#define UD_ENGINES_H

#include "../uD_Api.h"
#include "uD_Renderer.h"

uDisplay uDisplayBaseEngine = {
  .Initialize = uDisplay_Initialize,
  .DrawPixel = uDisplay_DrawPixel,
  .DrawBuffer = uDisplay_DrawBuffer,
  .StartDrawCall = uDisplay_StartDrawCall,
  .EndDrawCall = uDisplay_CommitDrawCall
};
                   
#endif