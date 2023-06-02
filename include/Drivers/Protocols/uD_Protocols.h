#ifndef UD_COMMS_API_H
#define UD_COMMS_API_H

#include "../../uD_Api.h"

#include "uD_I2C.h"
#include "uD_I2C_Software.h"
#include "uD_SPI_Software.h""

uDisplayUnderlyingProtocol uDisplay_UnderlyingProtocol_I2C = {
    .configure = i2c_init,
    .Init = i2c_start,
    .read = i2c_receive,
    .write = i2c_transfer,
};

uDisplayUnderlyingProtocol uDisplay_UnderlyingProtocol_I2C_Software = {
    .configure = sfw_i2c_init,
    .Init = sfw_i2c_start,
    .read = sfw_i2c_receive,
    .write = sfw_i2c_transfer,
};

uDisplayUnderlyingProtocol uDisplay_UnderlyingProtocol_SPI_Software = {
    .configure = spi_init,
    .Init = spi_start,
    .read = spi_receive,
    .write = spi_transfer
};

#endif