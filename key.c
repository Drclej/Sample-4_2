#include <msp430f249.h>
#include "key.h"
#define uchar unsigned char
#define uint unsigned int

extern uchar key;

uchar keylib[4][4] = {0x0F,0x0B,0x07,0x03,0x0E,0x0A,0x06,0x02,0x0D,0x09,0x05,0x01,0x0C,0x08,0x04,0x00};

uchar scanseq[] = {0x0E,0x0D,0x0B,0x07};

uchar keycol[] = {0xE0,0xD0,0xB0,0x70};

void delayus(uint t)
{
  while(t--);
}

void processkey(void)
{
  uchar row;
  uchar col;
  for (row = 0;row < 4;++row)
  {
    P3OUT = scanseq[row];
    if ((P3IN & 0xF0) != 0xF0)
    {
      for (col = 0;col < 4;++col)
      {
        if((P3IN & 0xF0) == keycol[col]) 
        {
          key = keylib[row][col];
        }
      }
    }
  }
}