#define F_CPU 16000000UL

#include <avr/io.h>
#include <avr/power.h>
#include <util/delay.h> // Standard AVR headerfil

int led;
int pinNr = 0;

#define LED_COUNT 14 // Antal tilsluttede LEDs
#define DDR_BYTE 0
#define PORT_BYTE 1

  char charlie[LED_COUNT][2] = {
  // DDR_BYTE PORT_BYTE
  // ABCDE ABCDE
  { 0b00000000, 0b00000000 }, // Alt slukket
  { 0b00000011, 0b00000001 }, // AB 0
  { 0b00000011, 0b00000010 }, // BA 1
  { 0b00000110, 0b00000010 }, // BC 2
  { 0b00000110, 0b00000100 }, // CB 3
  { 0b00001100, 0b00000100 }, // CD 4
  { 0b00001100, 0b00001000 }, // DC 5
  { 0b00000101, 0b00000001 }, // AC 6
  { 0b00000101, 0b00000100 }, // CA 7
  { 0b00001010, 0b00000010 }, // BD 8
  { 0b00001010, 0b00001000 }, // DB 9
  { 0b00001001, 0b00000001 }, // AD 10
  { 0b00001001, 0b00001000 }, // DA 11
  { 0b00011000, 0b00001000 }, // DE 12
  { 0b00011000, 0b00010000 } // ED 13
};

void turnOn( char led ) { //Styring af Charlieplexing LEDs
  DDRB = charlie[led][DDR_BYTE];
  PORTB = charlie[led][PORT_BYTE];
}

int laesKnapper()
{
  if(ADCW < 20)
    pinNr = 1;
  else if(ADCW >= 50 && ADCW < 180)
    pinNr = 2;
  else if(ADCW >= 180 && ADCW < 280)
    pinNr = 3;
  else if(ADCW >= 280 && ADCW < 330)
    pinNr = 4;
  else if(ADCW >= 330 && ADCW < 400)
    pinNr = 5;
  else if(ADCW >= 400 && ADCW < 440)
    pinNr = 6;
  else if(ADCW >= 440 && ADCW < 500)
    pinNr = 7;
  else if(ADCW >= 520 && ADCW < 570)
    pinNr = 8;
  else if(ADCW >= 570 && ADCW < 610)
    pinNr = 9;
  else if(ADCW >= 610 && ADCW < 680)
    pinNr = 10;
  else if(ADCW >= 680 && ADCW < 750)
    pinNr = 11;
  else if(ADCW >= 750 && ADCW < 850)
    pinNr = 12;
  else if(ADCW >= 850 && ADCW < 950)
    pinNr = 13;
  else if(ADCW >= 950)
    pinNr = 14;
  else
    pinNr = 0;
  return(pinNr);
}

int main(void)
{
  ADCSRA = 0b10000111;// Aktiver ADC og del systemclock med 128
  ADMUX = 0b01000000;// 5V Vref valgt. ADC arbejder ifht. 0V

  while(1)
  {
    ADCSRA |= (1 << ADSC); // Start analog konvertering
    while((ADCSRA & ( 1<<ADIF)) == 0); // Vent på at konverteringen er afsluttet
    if(ADCW < 500 || ADCW > 530)
    {
      pinNr = laesKnapper();
      turnOn(pinNr);
    }
    else{
        turnOn(0);  // Turn off all
    }
  }

  return 0;
}
