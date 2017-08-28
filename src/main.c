// Processor Frequency 8MHz
#define F_CPU 8000000UL

// Processor type to include appropriate i/o header
// #define __AVR_ATmega8__
#include <avr/io.h>
#include <util/delay.h>

#include "addrs.h"

void main(void) {
	DDRD |= 0xFF;
	
	while (1) {
		PORTD |= 1 << PD7; // Disable Selector
//		_delay_ms(10);
		PORTD = 0x0B; // PUT 0b1011 on Data, Device 0
//		_delay_ms(25);

		PORTD |= 1 << PD7; // Disable Selector
//		_delay_ms(10);
		PORTD = 0x1A; // PUT 0b1010 on Data, Device 1
//		_delay_ms(25);

		PORTD |= 1 << PD7; // Disable Selector
//		_delay_ms(10);
		PORTD = 0x29; // PUT 0b1001 on Data, Device 2
//		_delay_ms(25);

		PORTD |= 1 << PD7; // Disable Selector
//		_delay_ms(10);
		PORTD = 0x35; // PUT 0b0101 on Data, Device 3
//		_delay_ms(25);
	}
}
