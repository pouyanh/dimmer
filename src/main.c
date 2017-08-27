// Processor Frequency 8MHz
#define F_CPU 8000000UL

// Processor type to include appropriate i/o header
#define __AVR_ATmega162__
#include <avr/io.h>
#include <util/delay.h>

#include "addr_space.h"

void main(void) {
	MCUCR = 0xC0;
	DDRC |= 1 << PC2;
	
	while (1) {
		PORTC &= ~(1 << PC2);
		_delay_ms(100);

		PORTC |=(1 << PC2);
		_delay_ms(100);
	}
}
