#include "uD_ST7789_Driver.h"
#include <stdint.h>
#include "../Helpers/uD_Delay.h"

static uDisplayUnderlyingProtocol * spi_protocol;

void st7789_init(uDisplayUnderlyingProtocol *protocol) 
{
    spi_protocol = protocol;
    protocol->configure(0);  // Configure SPI with address 0
    protocol->Init();  // Initialize SPI protocol

    // Below is a basic initialization sequence for ST7789
    uint8_t exit_sleep_mode[] = { 0x11 };
    st7789_send_command(exit_sleep_mode, sizeof(exit_sleep_mode));

    // Delay for 120 ms
    uD_delay_ms(120);
    
    // Pixel Format Set
    uint8_t pixel_format_set[] = { 0x3A, 0x55 }; // 16 bits/pixel
    st7789_send_command(pixel_format_set, sizeof(pixel_format_set));

    // Memory Data Access Control
    uint8_t mem_data_access_control[] = { 0x36, 0x00 };
    st7789_send_command(mem_data_access_control, sizeof(mem_data_access_control));

    // Inversion Control
    uint8_t inversion_control[] = { 0xB4, 0x00 };
    st7789_send_command(inversion_control, sizeof(inversion_control));

    // Porch control
    uint8_t porch_control[] = { 0xB2, 0x0C, 0x0C, 0x00, 0x33, 0x33 };
    st7789_send_command(porch_control, sizeof(porch_control));

    // Gamma Set
    uint8_t gamma_set[] = { 0x26, 0x01 };
    st7789_send_command(gamma_set, sizeof(gamma_set));

    // Display On
    uint8_t display_on[] = { 0x29 };
    st7789_send_command(display_on, sizeof(display_on));

    // Delay for 100 ms
    uD_delay_ms(100);
}


void st7789_send_command(uint8_t* command, uint8_t len)
{
    spi_protocol->write(0x00, command, len);  // Send command over SPI protocol
}

void st7789_send_data(uint8_t* data, uint8_t len)
{
    spi_protocol->write(0x40, data, len);  // Send data over SPI protocol
}

void st7789_dispose(void)
{
    // Add any necessary cleanup here, if necessary
}
