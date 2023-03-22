#ifndef UD_RENDERER_H
#define UD_RENDERER_H

#include "../uD_Api.h"


void uDisplay_Initialize(uDRenderConfig* config);
void uDisplay_DrawPixel(uint8_t x, uint8_t y, uint8_t color);
void uDisplay_DrawBuffer(uDBufferDescriptor buffer);
void uDisplay_StartDrawCall(uDBufferDescriptor buffer);
void uDisplay_CommitDrawCall(uDBufferDescriptor buffer);

// typedef struct uDisplay display = {
//   uDisplay_Initialize,
//   uDisplay_DrawPixel,
//   uDisplay_DrawBuffer,
//   uDisplay_StartDrawCall,
//   uDisplay_CommitDrawCall
// };

#endif