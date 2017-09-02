// Processor Frequency 8MHz
#define F_CPU 8000000UL

// Processor type to include appropriate i/o header
// #define __AVR_ATmega8__
#include <avr/io.h>
#include <util/delay.h>

#include "addrs.h"

void main(void) {
	DDRD |= 0xFF;

	unsigned char v[4][10] = {
		{0x00, 0x01, 0x02, 0x03, 0x04, 0x05, 0x06, 0x07, 0x08, 0x09},
		{0x06, 0x07, 0x08, 0x09, 0x0A, 0x0B, 0x0C, 0x0D, 0x0E, 0x0F},
		{0x00, 0x0F, 0x01, 0x0E, 0x02, 0x0D, 0x03, 0x0C, 0x04, 0x0B},
		{0x01, 0x0A, 0x05, 0x0D, 0x06, 0x09, 0x08, 0x0E, 0x00, 0x05},
	};
	
	while (1) {
		unsigned char i = 0;
		for (i = 0; i < 10; i++) {
			PORTD |= 1 << PD7; // Disable Selector
			PORTD = 0x00 | v[0][i]; // PUT v[0][i] on Data, Device 0

			PORTD |= 1 << PD7; // Disable Selector
			PORTD = 0x10 | v[1][i]; // PUT v[1][i] on Data, Device 1

			PORTD |= 1 << PD7; // Disable Selector
			PORTD = 0x20 | v[2][i]; // PUT v[2][i] on Data, Device 2

			PORTD |= 1 << PD7; // Disable Selector
			PORTD = 0x30 | v[3][i]; // PUT v[3][i] on Data, Device 3

			_delay_ms(100);
		}
	}
}
