/*************************************
* Testprogram for Arduino LED driver *
*                                    *
* Lysdioder forbundet til PORT D     *
*                                    *
**************************************/
#define F_CPU 16000000UL
#include <util/delay.h>
#include <avr/io.h>
#include "led.h"

#define KORT_PAUSE _delay_ms(500)
#define PAUSE _delay_ms(2000)

int main()
{
unsigned char i;

  // Test af "initLEDport"
  initLEDport();
  PAUSE;

  // Test af "writeAllLEDs"
  writeAllLEDs(0b01010101);
  PAUSE;
  writeAllLEDs(0);
  PAUSE; 
       
  // Test af "turnOnLED"
  for (i=0; i<8; i++)
  {
    turnOnLED(i);
    KORT_PAUSE;
  }  
  turnOnLED(17);
  KORT_PAUSE;
 
  // Test af "turnOffLED"
  for (i=0; i<8; i++)
  {
    turnOffLED(i);
    KORT_PAUSE;
  }  
  turnOffLED(117);
  KORT_PAUSE;
            
  // Test af "toggleLED"
  writeAllLEDs(0b01010101);
  KORT_PAUSE;
  for (i=0; i<8; i++)
  {
    toggleLED(i);
    KORT_PAUSE;
  }  
  toggleLED(117);
    
  // Bliv her
  while (1)
  {}
  return 0;      
}
