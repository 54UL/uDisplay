
// Define cpu freq
#define F_CPU 8000000UL

// Define the baud rate
#define BAUDRATE 1200

// Calculate the bit delay in microseconds
#define BIT_DELAY (1000000 / BAUDRATE)

// Define UART TX and RX pins
#define UART_TX_PIN PB0
#define UART_RX_PIN PB1

#include <avr/io.h>
#include <util/delay.h>

// Initialize UART
void uart_init() {
  // Set TX pin as output
  DDRB |= (1 << UART_TX_PIN);

  // Set RX pin as input
  DDRB &= ~(1 << UART_RX_PIN);

  // Enable pull-up resistor on RX pin
  PORTB |= (1 << UART_RX_PIN);
}

// Send a byte over UART
void uart_write(uint8_t data) {
  // Start bit
  PORTB &= ~(1 << UART_TX_PIN);
  _delay_us(BIT_DELAY);

  // Send 8 data bits
  for (uint8_t i = 0; i < 8; i++) {
    if (data & (1 << i))
      PORTB |= (1 << UART_TX_PIN);
    else
      PORTB &= ~(1 << UART_TX_PIN);

    _delay_us(BIT_DELAY);
  }

  // Stop bit
  PORTB |= (1 << UART_TX_PIN);
  _delay_us(BIT_DELAY);
}

int main() {
  // Initialize UART
  uart_init();

  // Send data continuously
  while (1) {
    // Send a byte
    uart_write('x');
    uart_write('d');
    uart_write('\r');
    uart_write('\n');
    // Delay before sending the next byte
    _delay_ms(16);
  }

  return 0;
}