#ifndef U_DISPLAY_API_H
#define U_DISPLAY_API_H

//GENERIC INCLUDES
#include <stdint.h>

typedef struct 
{
  uint8_t x;
  uint8_t y;
  uint8_t w;
  uint8_t h;
  uint8_t *data;
  unsigned int length;
} uDBufferDescriptor;

typedef enum {
    MONOCHROME,
    GRAYSCALE,
    RGB,
    RGBA,
    BGRA,
    ARGB,
    ABGR,
} uDPixelFormat;

struct uDDrawable 
{
  uDPixelFormat format;
  uint8_t  length;
  uint8_t* data;
};

struct uDPoint
{
  struct uDDrawable drawable;
  int x,y;
};

struct uDFont
{
  struct uDDrawable drawable;
  int x,y;
};

//INTERFACES
typedef struct 
{
  void    (*configure)(uint8_t address);
  void    (*init)(void);
  void    (*read)(uint8_t *data,  uint16_t len);
  void    (*write)(uint8_t cmd, uint8_t* data, uint8_t len);
} uDisplayUnderlyingProtocol;

typedef struct 
{
  void (*Init)(uDisplayUnderlyingProtocol *protocol);
  void (*SendCommand)(uint8_t* command, uint16_t len);
  void (*SendData)(uint8_t* data, uint16_t len);
  void (*Dispose)(void);
} uDisplayDriver;

typedef struct
{
  uDisplayUnderlyingProtocol *protocol;
  uDisplayDriver * driver;
} uDRenderConfig;

typedef struct 
{
    void (*Initialize)(uDRenderConfig *config );
    void (*DrawPixel)(uint8_t x, uint8_t y, uint8_t color);
    void (*DrawBuffer)(uDBufferDescriptor buffer);
    void (*StartDrawCall)(uDBufferDescriptor buffer);
    void (*EndDrawCall)(uDBufferDescriptor buffer);
} uDisplay;

//BASE DEFINITION
typedef struct  
{
  void (*initialize)(uDisplay * uDisplayInstance);
  void (*moveTo)(int x, int y);
  void (*Draw)(struct uDDrawable * drawable);
  void (*DrawString)(struct uDFont * font, char * text);
  //refresh rate, text rendering, base color format
} uDisplayEngine;

//USES UDisplayEngine as base
typedef struct uDisplayCanvasEngine {
    void (*initialize)(uDisplay * uDisplayInstance);
    void (*DrawPixel)(const char *canvasId,struct uDDrawable* drawable);
    void (*clear)();
    void (*setFillColor)(struct uDDrawable* drawable);
    void (*setStrokeColor)(struct uDDrawable* drawable);
    void (*drawRect)(int x, int y, int width, int height);
    void (*fillRect)(int x, int y, int width, int height);
    void (*strokeRect)(int x, int y, int width, int height);
    void (*clearRect)(int x, int y, int width, int height);
    void (*beginPath)();
    void (*closePath)();
    void (*moveTo)(int x, int y);
    void (*lineTo)(int x, int y);
    void (*arc)(int x, int y, int radius, double startAngle, double endAngle, int anticlockwise);
    void (*fill)();
    void (*stroke)();
    void (*drawImage)(int x, int y, struct uDDrawable* drawable);
    void (*createLinearGradient)(int x0, int y0, int x1, int y1);
    void (*createRadialGradient)(int x0, int y0, int r0, int x1, int y1, int r1);
} uDisplayCanvasEngine;


#endif //U_DISPLAY_API_H