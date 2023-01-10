/******************************************
* "LED.H":                                *
* Header file for Arduino LED driver.     *
* LED'er er forbundet til PORT D.         *
*******************************************/ 
void initLEDport();
void writeAllLEDs(unsigned char pattern);
void turnOnLED(unsigned char led_nr);
void turnOffLED(unsigned char led_nr);
void toggleLED(unsigned char led_nr);
/******************************************/
