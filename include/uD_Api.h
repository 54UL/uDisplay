#ifndef U_DISPLAY_API_H
#define U_DISPLAY_API_H

//GENERIC INCLUDES
#include <stdint.h>

typedef enum {
    MONOCHROME,
    GRAYSCALE,
    RGB,
    RGBA,
    BGRA,
    ARGB,
    ABGR,
} uDPixelFormat;

typedef struct 
{
  uint8_t x;
  uint8_t y;
  uint8_t width;
  uint8_t height;
} uDRect;

typedef struct 
{
  uint8_t width;
  uint8_t height;
  uint8_t dataLenght;
  uint8_t *data;
  uDPixelFormat format;
} uDBufferDescriptor;

typedef struct 
{
  uDPixelFormat colorFormat;
  uint8_t * pallete; // EJ  pallete = [BYTE1,BYTE2,BYTE3,BYTE4], the format determines how is it interpreted the aray
} uDColor;

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
  void (*SendData)(uint8_t* data, uint8_t len);
  void (*Dispose)(void);
} uDisplayDriver;

typedef struct
{
  uDisplayUnderlyingProtocol *protocol;
  uDisplayDriver * driver;
} uDRenderConfig;

typedef struct 
{
  //uDisplay interface base functions
  void (*Initialize)(uDRenderConfig *config );
  void (*StartDrawCall)(uDBufferDescriptor buffer);
  void (*EndDrawCall)(uDBufferDescriptor buffer);
  //UDisplay "engine" interface
  void (*Clear) (void);
  void (*ClearRegion)(uDRect* region);
  void (*ResetOrigin)(void);
  void (*Origin)(uDRect* origin);
  //UDisplay base interface and "engine" drawing functions
  void (*DrawPixel)(uint8_t x, uint8_t y, uDColor * color);
  void (*DrawBuffer)(uDBufferDescriptor buffer);
  void (*DrawChar)(char character);
  void (*DrawString)(const char * string);
} uDisplay;

/*
//Html canvas like API (EXPERIMENTAL)
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
*/

#endif //U_DISPLAY_API_H