/*
 * Hello World.c
 *
 * Created: 22-09-2022 12:44:05
 * Author : Daniel Nettelfield
 */ 

#define F_CPU 16000000UL
#include <avr/io.h>
#include <util/delay.h>

#define FORSINKELSE 85


int main(void)
{
	uint8_t i=0;
	DDRD |= 0xFF;

    while (1){
		while (i<7){
			PORTD = (1 << i);
			_delay_ms(FORSINKELSE);
			i++;
		}
		while (i>0){
			PORTD = (1<<i);
			_delay_ms(FORSINKELSE);
			i--;
		}
    }
	return 0;
}

