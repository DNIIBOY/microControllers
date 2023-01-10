/********************************************************
* "SWITCH.C":                                           *
* Implementation file for l�sning af 2 knapper          *
* Knapperne forbindes til PIN B 0 og 1                  *
*********************************************************/
#include <avr/io.h>

#define MAX_SWITCH_NR 2

// Klarg�r switch-porten
void initSwitchPort()
{
	DDRB = 0x00;
}

// L�ser alle switches samtidigt
unsigned char switchStatus()
{
	return PINB & 0b00000011;
}

// Returnerer TRUE, hvis switchen med nummeret
// "switch_nr" er aktiveret - ellers returneres FALSE
unsigned char switchOn(unsigned char switch_nr)
{
	return (1 << switch_nr) & PINB;
} 
