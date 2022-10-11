#define F_CPU 16000000UL
#include <avr/io.h>
#include <util/delay.h>
int main(void){
	DDRB |= (1 << PINB5);
	PORTB &= ~(1 << PINB5);
	while (1){
		_delay_ms(2000);
		PORTB ^= (1 << PINB5);
	}
}
