/*
 * Hello World.c
 *
 * Created: 22-09-2022 12:44:05
 * Author : Daniel Nettelfield
 */ 

#define F_CPU 16000000UL
#include <avr/io.h>
#include <avr/power.h>
#include <util/delay.h>

#define FORSINKELSE 85


int main(void)
{
  uint8_t i;
  uint8_t gentag;
  uint8_t hvilkenLED;
  uint8_t randomNumber = 0x1234;

  DDRD |= 0xFF;

  while (1){
    for (i = 0; i < 8; i++){
      PORTD |= (1 << i);
      _delay_ms(FORSINKELSE);
    }

    for (i = 0; i < 8; i++){
      PORTD &= ~(1 << i);
      _delay_ms(FORSINKELSE);
    }
    _delay_ms(5 * FORSINKELSE);

    for (i = 7; i < 255; i--){
      PORTD |= (1 << i);
      _delay_ms(FORSINKELSE);
    }
    for (i = 7; i < 255; i--){
      PORTD &= (1 << i);
      _delay_ms(FORSINKELSE);
    }
    _delay_ms(5 * FORSINKELSE);

    for (gentag = 0; gentag < 75; gentag++){
      randomNumber = 2053 * randomNumber + 13849;
      hvilkenLED = (randomNumber >> 8) & 0b00000111;
      PORTD ^= (1<<hvilkenLED);
      _delay_ms(FORSINKELSE);
    }
    PORTD = 0;
    _delay_ms(FORSINKELSE);
  }
  return 0;
}

