
#ifndef STD_INT_8051_OLED_LIB_H
#define STD_INT_8051_OLED_LIB_H

//Keli c51 does not have std int suport
#ifndef _XC8   
typedef signed char             int8_t;
typedef short int               int16_t;
typedef long int                int32_t;

typedef unsigned char           uint8_t;
typedef unsigned int      		uint16_t;
typedef unsigned long int       uint32_t;
#endif


#endif //STD_INT_8051_OLED_LIB_H