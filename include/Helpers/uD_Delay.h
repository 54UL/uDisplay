#ifndef UD_DELAY_H
#define UD_DELAY_H

#ifdef __AVR__
// #define F_CPU 80000

#include <util/delay.h>
static void uD_delay_ms(uint16_t ms) {
    for(uint16_t t = 0; t < ms; t++)
        _delay_ms(1);
}

static void uD_delay_us(uint16_t us) {
    for(uint16_t t = 0; t < us; t++)
        _delay_us(1);
}

// For xc8 compiler
#elif defined(__XC8)
#include <xc.h>
inline void uD_delay_ms(uint16_t ms) {
    __delay_ms(ms);
}

// For c51 compiler
#elif defined(__C51__)
#include <reg51.h>
inline void uD_delay_ms(uint16_t ms) {
    uint16_t i, j;
    for (i = 0; i < ms; i++) {
        for (j = 0; j < 230; j++) {
            // no-op
        }
    }
}
#endif

#endif