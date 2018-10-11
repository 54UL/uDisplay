
#include "delay.h"


//DELAY BY SOFTWARE
uint16_t AuxCounter1;
uint16_t AuxCounter2;
void __delay_ms(uint16_t ms)
{
     //imaginando que funciona igual que los retrasos en asm
		 //cada repeticion son 2 micro segundos, tiempo deseado * ninstrucciones
    for(AuxCounter2=0;AuxCounter2<ms;AuxCounter2++)
    {
		for(AuxCounter1 =0;AuxCounter1<500;AuxCounter1++); //UNICAMENTE PARA 12 MHZ DE CRISTAL 1 ms 500 *2 u 
    }
}