/*
 * lightShowOff.c
 *
 * Created: 11-10-2022 09:38:11
 * Author : Daniel Nettelfield
 */ 

#define F_CPU 16000000UL
#define DELAY 100 // Master delay thing
#include <avr/io.h>
#include <avr/power.h>
#include <util/delay.h>

int main(void)
{
  DDRB = 0x00;
  DDRD = 0xFF;
  run1();
  PORTD = 0x00;
  while (1){
    if (PINB & 0b00000001)
      PORTD = 0xFF;
    }
}

void run1(){
  for (int i = 0; i < 2; i++) {
    part1();
  }
  for (int i = 0; i < 3; i++) {
    part2();
  }
  for (int i = 0; i < 4; i++) {
    part3();
  }
  for (int i = 0; i < 5; i++) {
    part4();
  }
}

void run2(){
  for (int i = 0; i < 2; i++) {
    part4();
  }
  for (int i = 0; i < 3; i++) {
    part3();
  }
  for (int i = 0; i < 4; i++) {
    part2();
  }
  for (int i = 0; i < 5; i++) {
    part1();
  }
}

void part1(){
  PORTD = 0x00;
  for (int i = 0; i < 8; i++) {
    PORTD = (1<<i);
    _delay_ms(DELAY);
  }
}

void part2(){
  PORTD = 0x00;
  for (int i = 0; i < 7; i+=1) {
    PORTD = 0x00;
    PORTD |= (3 << i);
    _delay_ms(DELAY);
  }
  for (int i = 5; i > 0; i-=1) {
    PORTD = 0x00;
    PORTD |= (3 << i);
    _delay_ms(DELAY);
  }
}

void part3(){
  PORTD = 0x00;
  for (int i = 0; i < 50; i++) {
    PORTD = i;
    _delay_ms(DELAY);
  }
}

void part4(){
  PORTD = 0x00;
  for (int i = 0; i < 4; i++) {
    PORTD = (1 << i) | (128 >> i);
    _delay_ms(DELAY);
  }
  for (int i = 1; i < 3; i++) {
    PORTD = (8 >> i) | (16 << i);
    _delay_ms(DELAY);
  }
}
