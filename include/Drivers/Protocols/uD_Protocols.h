#ifndef UD_COMMS_API_H
#define UD_COMMS_API_H

#include "../../uD_Api.h"

#include "uD_I2C.h"
// #include "uD_SPI.h"

uDisplayUnderlyingProtocol uDisplay_UnderlyingProtocol_I2C = {
    .configure = i2c_init,
    .init = i2c_start,
    .read = i2c_receive,
    .write = i2c_transfer,
};

// uDisplayUnderlyingProtocol uDisplay_UnderlyingProtocol_SPI = 
// {
//     .init = spi_init,
//     .read = spi_read,
//     .write = spi_write
// };

#endif