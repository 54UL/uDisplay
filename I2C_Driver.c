/*
 * File:   I2C_SaulLib.c
 * Author: Saul
 *
 * Created on 13 de junio de 2018, 09:26 PM
 */


#include "I2C_Driver.h"
#include "delay.h"


#define I2C_PIC_HARDWARE_SPEED(c) (4000000/(4*c))-1

void I2C_Master_Init(const unsigned long c)
{
  #if defined (__xc8)  && !defined(USE_I2C_SOFTWARE_IMPLEMENTATION)
  SSPCON = 0b00101000;            //SSP Module as Master
  SSPCON2 = 0;
  SSPADD = I2C_PIC_HARDWARE_SPEED(9600);    //Setting Clock Speed para 12 mhz, hacerla const esta exprecion
  SSPSTAT = 0;
  TRISC3 = 1;                   //Setting as input as given in datasheet
  TRISC4 = 1;    
  #elif (__C51__) || (USE_I2C_SOFTWARE_IMPLEMENTATION)
  // SOFTWARE IMPLEMENTATION
   SCL_PIN = 1;
   SDA_PIN = 1; 
  #endif
}




void I2C_Master_Wait()
{
 #if defined (__xc8)  && !defined(USE_I2C_SOFTWARE_IMPLEMENTATION)
 while ((SSPSTAT & 0x04) || (SSPCON2 & 0x1F));
 #elif (__C51__) || (USE_I2C_SOFTWARE_IMPLEMENTATION)
  
  SCL_PIN =1;
  __delay_ms(1);
  while(!SCL_PIN);

 #endif
}
void I2C_Master_Start()
{
  #if defined (__xc8) && !defined(USE_I2C_SOFTWARE_IMPLEMENTATION)
  I2C_Master_Wait();    
  SEN = 1;             //Initiate start condition
  #elif (__C51__) || (USE_I2C_SOFTWARE_IMPLEMENTATION)
  // SOFTWARE IMPLEMENTATION
     SCL_PIN = 1;
     SDA_PIN = 1; 
     __delay_ms(1);
     SDA_PIN =0;
  #endif
}
void I2C_Master_RepeatedStart()
{
      #if defined (__xc8) && !defined(USE_I2C_SOFTWARE_IMPLEMENTATION)
      I2C_Master_Wait();
      RSEN = 1;         
      #elif (__C51__) || (USE_I2C_SOFTWARE_IMPLEMENTATION)
         //not implemented


      #endif
}
void I2C_Master_Stop()
{

  #if defined (__xc8) && !defined(USE_I2C_SOFTWARE_IMPLEMENTATION)
  I2C_Master_Wait();
  PEN = 1;          
  #elif (__C51__) || (USE_I2C_SOFTWARE_IMPLEMENTATION)
  SCL_PIN = 0;
  SDA_PIN = 0;
  SCL_PIN = 1;
  SDA_PIN = 1;
  #endif
}

uint8_t serial_buff_oled;
uint8_t shiftedvalue;
uint8_t timeout;
uint8_t BUS_READY;

void I2C_Master_Write(unsigned d)
{
   #if defined (__xc8) && !defined(USE_I2C_SOFTWARE_IMPLEMENTATION)
    I2C_Master_Wait();
    SSPBUF = d;         
   #elif (__C51__) (USE_I2C_SOFTWARE_IMPLEMENTATION)
    timeout=0;
    for(serial_buff_oled=0;serial_buff_oled<8;serial_buff_oled++)
    {
    SCL_PIN = 0;
    if( d&(0x80>>serial_buff_oled) )
      SDA_PIN = 1;
    else
      SDA_PIN = 0;
    SCL_PIN =1;
    }
    //Aknowledge
    SCL_PIN =0;
    SCL_PIN = 1;
     while(timeout<254)
     {
      if(!SCL_PIN)
          while(SCL_PIN) //perame men estoy ocpado(bussy)

        if(!SDA_PIN)
          break;
       timeout++;
     }
      if(SDA_PIN)
      {
       I2C_Master_Stop();//not ack
      }
  #endif
}