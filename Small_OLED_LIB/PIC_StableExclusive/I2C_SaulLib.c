/*
 * File:   I2C_SaulLib.c
 * Author: Saul
 *
 * Created on 13 de junio de 2018, 09:26 PM
 */


#include "I2C_SaulLib.h"
#include <xc.h>
#include <pic16f877a.h>

#ifndef __XTAL
#define XTAL_HERTZ 12000000
#else
#define XTAL_HERTZ __XTAL 
#endif

#ifndef BAUD_RATE
#define BAUD_RATE 400000

#else
#define BAUD_RATE OLED_BAUDRATE
#endif

#define CALIBRATION_FORMULA(freq,speed) (freq/(4*speed))-1

//I2C LIB
void I2C_Master_Init()
{
  SSPCON = 0b00101000;            //SSP Module as Master
  SSPCON2 = 0;
  SSPADD = CALIBRATION_FORMULA(12000000,400000); //Setting Clock Speed para 12 mhz //full speed for 12 mhz clock
  SSPSTAT = 0;
  TRISC3 = 1;                     //Setting as input as given in datasheet
  TRISC4 = 1;    
}

void I2C_Master_Wait()
{
  while ((SSPSTAT & 0x04) || (SSPCON2 & 0x1F)); //Transmit is in progress
}

void I2C_Master_Start()
{
  I2C_Master_Wait();    
  SEN = 1;             //Initiate start condition
}

void I2C_Master_RepeatedStart()
{
  I2C_Master_Wait();
  RSEN = 1;           //Initiate repeated start condition
}

void I2C_Master_Stop()
{
  I2C_Master_Wait();
  PEN = 1;           //Initiate stop condition
}

void I2C_Master_Write(unsigned d)
{
  I2C_Master_Wait();
  SSPBUF = d;         //Write data to SSPBUF
}
