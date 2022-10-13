#define LED_COUNT 12
#define DDR_CHAR 0
#define PORT_CHAR 1
#define FORSINKELSE 500

#define F_CPU 16000000UL
#include <avr/io.h>
#include <avr/power.h>
#include <util/delay.h>


char charlie[LED_COUNT][2] = {
  // DDR_CHAR PORT_CHAR
  // ABCDE ABCDE
  { 0b00000011, 0b00000001 }, // AB 0
  { 0b00000011, 0b00000010 }, // BA 1
  { 0b00000110, 0b00000010 }, // BC 2
  { 0b00000110, 0b00000100 }, // CB 3
  { 0b00001100, 0b00000100 }, // CD 4
  { 0b00001100, 0b00001000 }, // DC 5
  { 0b00000101, 0b00000001 }, // AC 6
  { 0b00000101, 0b00000010 }, // CA 7
  { 0b00001010, 0b00000100 }, // BD 8
  { 0b00001010, 0b00001000 }, // BD 9
  { 0b00001001, 0b00000001 }, // AD 10
  { 0b00001001, 0b00001000 }, // AD 11
};

void taend( char led ) {
  DDRD = charlie[led][DDR_CHAR];
  PORTD = charlie[led][PORT_CHAR];
}

int main(void) {
  while(1)
  {
    for( char ld = 0; ld < LED_COUNT; ld++ ) {
    taend( ld );
    _delay_ms(FORSINKELSE);
  }
    for( char ld = LED_COUNT-1; ld > 0; ld-- ) {
      taend( ld );
      _delay_ms(FORSINKELSE);
    }
  }
}
