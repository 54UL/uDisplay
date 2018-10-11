

/*
 * File:   I2C_SaulLib.h
 * Author: Saul
 *
 * Created on 13 de junio de 2018, 09:26 PM
 */



#ifndef I2C_DRIVER_H
#define	I2C_DRIVER_H

#if defined(__xc8) 
#include <xc.h>
#endif
#if defined(__C51__)
#include <AT89X52.h>
//8051 only
#define SDA_PIN P1_1
#define SCL_PIN P1_0
#endif

void I2C_Master_Init(const unsigned long c);
void I2C_Master_Wait();
void I2C_Master_Start();
void I2C_Master_RepeatedStart();
void I2C_Master_Stop();
void I2C_Master_Write(unsigned d);


#endif	/* I2C_DRIVERH */

