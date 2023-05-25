#define F_CPU 8000000UL

// Define the character to trigger the message
#define TRIGGER_CHAR 0

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

// Receive a byte from UART
uint8_t uart_read() {
  // Wait for start bit
  while (PINB & (1 << UART_RX_PIN));

  _delay_us(BIT_DELAY / 2);

  uint8_t data = 0;

  // Read 8 data bits
  for (uint8_t i = 0; i < 8; i++) {
    _delay_us(BIT_DELAY);
    if (PINB & (1 << UART_RX_PIN))
      data |= (1 << i);
  }

  // Wait for stop bit
  _delay_us(BIT_DELAY);

  return data;
}

char* read_serial() {
    static char received_message[256]; // Assuming maximum message length of 255 characters
    
    while (1) {
     
        // Read the received message
        uint8_t index = 0;
        char received_char;
        do {
           
            received_char = uart_read();
            // Wait for trigger character
       
            if (received_char == TRIGGER_CHAR) 
            {
              continue;
            }
            
            received_message[index++] = received_char;
        } while (received_char != '\n' && index < sizeof(received_message) - 1);
        
        received_message[index] = '\0'; // Null-terminate the received message
        
        return received_message;
    }
}


int main()
{
  // Initialize UART
  uart_init();

  // Loop forever
  while (1)
  {
    // Send back recived text
    char * message = read_serial();
    for (uint8_t i = 0; message[i] != '\0'; i++)
    {
      uart_write(message[i]);
    }
  }

  return 0;
}