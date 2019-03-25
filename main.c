#include <msp430f249.h>
#include "key.h"
#define uchar unsigned char
#define uint unsigned int

uchar key;

uchar const LED_Lib[16] = {0x3F,0x06,0x5B,0x4F,0x66,0x6D,0x7D,0x07,0x7F,0x6F,0x77,0x7C,0x39,0x5E,0x79,0x71};

void initialize(void)
{
  P1SEL = 0x00;
  P1DIR = 0xFF;
  P1OUT = 0x00;
  
  P3DIR = 0x0F;
  P3OUT = 0x00;
}



void display(void)
{
  P1OUT = LED_Lib[key];
}


void main( void )
{
  // Stop watchdog timer to prevent time out reset
  WDTCTL = WDTPW + WDTHOLD;
  initialize();
  while (1)
  {
    if (P3IN != 0xF0)
    {
      delayus(100);
      if (P3IN != 0xF0) 
      {
        processkey();
        display();
      }
    }
  }
}
