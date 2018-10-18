
/* 
 * File:   
 * Author: 
 * Comments:
 * Revision history: 
 */

#ifndef i2c_driver_H
#define	i2c_driver_H
#include <xc.h>
//I2C LIB
void I2C_Master_Init();
void I2C_Master_Wait();
void I2C_Master_Start();
void I2C_Master_RepeatedStart();
void I2C_Master_Stop();
void I2C_Master_Write(unsigned d);


#endif	/* XC_HEADER_TEMPLATE_H */

