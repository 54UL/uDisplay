#include <AT89X52.H>
#define SCL_PIN P3_0
#define SDA_PIN P3_1
#define OLED_LOAD_DEFAULT_FONT

#include <uOledLib.h>

void main()
{
	uOLED_Initialize();
	uOLED_gotoxy(0, 0);
	uOLED_DrawString("HelloWorld from 8051");
	uOLED_gotoxy(6, 0);
	uOLED_DrawString("Viva mexico :3");
	while (1);
	return;
}
