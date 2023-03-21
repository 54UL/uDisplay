#ifndef U_DISPLAY_API_H
#define U_DISPLAY_API_H

struct uDBufferDescriptor 
{
  uint8_t x;
  uint8_t y;
  uint8_t w;
  uint8_t h;
  const uint8_t *data;
  unsigned int length;
};

struct uDDrawable 
{
  PixelFormat format,
  uint8_t* data
};

struct uDPoint
{
  uDDrawable drawable;
  int x,y;
};

struct uDFont
{
  uDDrawable drawable;
  int x,y;
};


//INTERFACES
typedef struct 
{
  void (*init)(void);
  uint8_t (*read)(uint8_t address, uint8_t reg);
  void (*write)(uint8_t address, uint8_t reg, uint8_t value);
  void (*transfer)(uint8_t *data, uint16_t len);
  void (*send)(uint8_t *data, uint16_t len);
  void (*receive)(uint8_t *data, uint16_t len);
} uDisplayUnderlyingProtocol;


typedef struct 
{
  void (*Init)(struct uDisplayUnderlyingProtocol *protocol);
  void (*SendCommand)(uint8_t* command, uint16_t len);
  void (*SendData)(uint8_t* data, uint16_t len);
  void (*Dispose)(void);
} uDisplayDriver;


struct uDRenderConfig 
{
  struct uDisplayUnderlyingProtocol *protocol
  struct uDisplayDriver *protocol
};

typedef struct 
{
    void (*Initialize)(struct uDRenderConfig * config );
    void (*DrawPixel)(void);
    void (*DrawBuffer)(struct uDBufferDescriptor);
    void (*StartDrawCall)(struct uDBufferDescriptor);
    void (*CommitDrawCall)(struct uDBufferDescriptor);
} uDisplay;



//BASE DEFINITION
typedef struct uDisplayEngine 
{
  void (*initialize)(struct uDisplay * uDisplayInstance);
  void (*moveTo)(int x, int y);
  void (*Draw)(struct uDDrawable * drawable);
  void (*DrawString)(struct uDFont * font, char * text);
  //refresh rate, text rendering, base color format
};

//USES UDisplayEngine as base
typedef struct uDisplayCanvasEngine {
    void (*initialize)(struct uDisplay * uDisplayInstance);
    void (*DrawPixel)(const char *canvasId,uDDrawable drawable);
    void (*clear)();
    void (*setFillColor)(uDDrawable* drawable);
    void (*setStrokeColor)(uDDrawable* drawable);
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
    void (*drawImage)(int x, int y,uDDrawable* drawable drawable);
    void (*createLinearGradient)(int x0, int y0, int x1, int y1);
    void (*createRadialGradient)(int x0, int y0, int r0, int x1, int y1, int r1);
} uDisplayCanvasEngine;


#endif //U_DISPLAY_API_H