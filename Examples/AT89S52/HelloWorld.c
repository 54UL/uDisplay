#include "Oled_1306Driver.h"
#include <AT89X52.h>

void main ()
{
	OLED_Initialize();
	OLED_cls();
	OLED_gotoxy(0,0);
	OLED_DrawString("hello world");
	OLED_gotoxy(1,0);
	OLED_DrawString(":3");
}
