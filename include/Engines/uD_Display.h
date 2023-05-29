#ifndef UD_DISPLAY_H
#define UD_DISPLAY_H

#include "../uD_Api.h"

//Base functionality functions
void uDisplay_Initialize(uDRenderConfig* config);
void uDisplay_StartDrawCall(uDBufferDescriptor buffer);
void uDisplay_CommitDrawCall(uDBufferDescriptor buffer);
//Rendering logic functions
void uDisplay_Clear (void);
void uDisplay_ClearRegion(uDRect* region);
void uDisplay_ResetOrigin(void);
void uDisplay_SetOrigin(uDRect* origin);
void uDisplay_SetFont(const uDFontDescriptor * data);
//Draw functions
void uDisplay_DrawPixel(uint8_t x, uint8_t y, uDColor * color);
void uDisplay_DrawBuffer(uDBufferDescriptor buffer);
void uDisplay_DrawChar(char character);
void uDisplay_DrawString(const char * string);

#endif