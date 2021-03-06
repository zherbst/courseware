#include "gpio.h"
#include "timer.h"

//int pin = 14; 
int pin = 20; 

#define BAUD 9600
#define DELAY (1000000/BAUD)

void bit(int val)
{
    pinWrite(pin,val);
    delay_us(DELAY);
}

void putc(int c)
{
    int i;

    bit(0); // start bit
    for( i=0; i<8; i++ ) { // output 8-bits, lsb first
        bit(c & 0x1);
        c >>= 1;
    }
    bit(1); // stop bit
    delay_us(2*DELAY);
}

void puts(char *s)
{
    while(*s)
        putc(*s++);
}

void notmain(void)
{
    pinMode(pin,OUTPUT);
    while(1) {
        puts("hello, world\n\r");
        delay_us(8*DELAY);
    }
}

