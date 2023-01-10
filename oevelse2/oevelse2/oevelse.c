/*********************************************
* Testprogram for Arduino kontakter          *
*                                            *
* Arduino Setup:                             *
* Forbind 8 LED'er til PORT D 0-7.           *
* Forbind 2 kontakter til PIN B 0-1.         *
*                                            *
**********************************************/
#define F_CPU 16000000UL
#include <util/delay.h>
#include <avr/io.h>
#include "Switch/switch.h"
#include "LED/led.h"

int main()
{
  unsigned char i;
  unsigned int currentLED;

  // Klargøring af SWITCH-porten
  initSwitchPort();
  // Klargøring af LED-porten
  initLEDport();

  // Test af switchStatus():
  // Resultatet skrives til hele lysdiodeporten
  // Testen afsluttes, når man samtidigt
  // trykket på SW0 og SW1
  i = 0;
  while (i != 0b00000011) {
    i = switchStatus();
    writeAllLEDs(i);
  }

  // Tænd alle lysdioder i 2 sekunder
  // og sluk så alle lysdioder
  // Så kan vi se, at næste test starter
  writeAllLEDs(0xFF);
  _delay_ms(2000);
  writeAllLEDs(0);

  // Test af switchOn():
  // Læs på skift de 2 kontakter
  // Trykkes knappen på PINB0, skal LED0 tænde
  // For hver gang samme knap påvirkes, skal den tændte diode
  // rykke 1 mod venstre. Trykkes knappen på PINB1, skal den
  // tændte diode rykke 1 mod højre.
  currentLED = 0;
  while (1) {
    currentLED %= 8;
    if (switchOn(0)){
      currentLED--;
    }
    else if (switchOn(1)){
      currentLED++;
    }
    writeAllLEDs(1 << currentLED);
    _delay_ms(150);
  }
  return 0;
}
