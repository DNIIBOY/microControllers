#include <avr/io.h> // Standard AVR headerfil
int main(void)
{
  DDRB = 0xFF; // Alle pinne på PORTB er Output
  DDRD = 0xFF; // Alle pinne på PORTD er Output
  ADCSRA = 0b10000111; // Aktiver ADC og del systemclock med 128
  ADMUX = 0b01000000; // 5V Vref valgt. ADC arbejder ifht. 0V
  while(1)
  {
    ADCSRA |= (1 << ADSC); // Start analog konvertering
    while((ADCSRA & ( 1<<ADIF)) == 0); // Vent på at konverteringen er afsluttet
    if ((ADCW > 0) & (ADCW < 10)) // Læser HELE indholdet af ADC konverteringen
    PORTD = 0;
    if (ADCW >= 102) // over 0,5V
      PORTD = 0x01;
    if (ADCW >= 204) // over 1,0V
      PORTD = 0x03;
    if (ADCW >= 306) // over 1,5V
      PORTD = 0x07;
    if (ADCW >= 408) // over 2,0V
      PORTD = 0x0F;
    if (ADCW >= 510) // over 2,5V
      PORTD = 0x1F;
    if (ADCW >= 612) // over 3,0V
      PORTD = 0x3F;
    if (ADCW >= 714) // over 3,5V
      PORTD = 0x7F;
    if (ADCW >= 816) // over 4,0V
    {
      PORTD = 0xFF;
      PORTB = 0;
    }
    if (ADCW >= 918) // over 4,5V
    {
      PORTD = 0xFF;
      PORTB = 0x01;
    }
    if (ADCW >= 1020) // over 4,98V
    {
      PORTD = 0xFF;
      PORTB = 0x03;
    }
  }
  return 0;
}
