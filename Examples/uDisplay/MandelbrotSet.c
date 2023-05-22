//TODO: FIX EXAMPLE
#include <math.h>
#include "uDisplayApi.h"

#define WIDTH 128
#define HEIGHT 128
#define MAX_ITER 50

uDisplay display;

void mandelbrotSet(uint8_t *buffer)
{
    double x, y, x0, y0, xtemp;
    int iteration;

    for(int row = 0; row < HEIGHT; row++)
    {
        for(int col = 0; col < WIDTH; col++)
        {
            x0 = ((double)col / WIDTH) * 3.5 - 2.5;
            y0 = ((double)row / HEIGHT) * 2.0 - 1.0;
            x = 0.0;
            y = 0.0;
            iteration = 0;

            while(x*x + y*y < 4.0 && iteration < MAX_ITER)
            {
                xtemp = x*x - y*y + x0;
                y = 2*x*y + y0;
                x = xtemp;
                iteration++;
            }

            if(iteration == MAX_ITER)
            {
                *buffer++ = 0;
                *buffer++ = 0;
                *buffer++ = 0;
            }
            else
            {
                *buffer++ = iteration * 5;
                *buffer++ = iteration * 10;
                *buffer++ = iteration * 15;
            }
        }
    }
}

int main()
{
    struct uDRenderConfig config;
    uint8_t buffer[WIDTH * HEIGHT * 3];

    // Initialize the display driver
    config.protocol = /*uDisplayUnderlyingProtocol implementation*/;
    config.driver = /*uDisplayDriver implementation*/;
    display.Initialize(&config);

    // Generate the Mandelbrot set
    mandelbrotSet(buffer);

    // Send the buffer to the display
    struct uDBufferDescriptor bufferDesc = {0, 0, WIDTH, HEIGHT, buffer, sizeof(buffer)};
    display.DrawBuffer(bufferDesc);

    return 0;
}