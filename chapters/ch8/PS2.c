/*
 * How to run this program:
 *   1. Open it in CodeVisionAVR, create a project for ATmega32 @ 8 MHz and build it.
 *   2. Take the generated .hex file and load it into Proteus.
 *   3. Run the simulation in Proteus.
 */

#include <io.h>
#include <delay.h>

typedef struct {
    unsigned char h;
    unsigned char m;
    unsigned char s;
} CLOCK;

unsigned char bcd(unsigned char v)
{
    return ((v / 10) << 4) | (v % 10);
}

void clock_tick(CLOCK *c)
{
    c->s++;
    if (c->s == 60)
    {
        c->s = 0;
        c->m++;
        if (c->m == 60)
        {
            c->m = 0;
            c->h++;
            if (c->h == 24)
                c->h = 0;
        }
    }
}

CLOCK now = {23, 59, 50};

void main(void)
{
    DDRA = 0xff;
    DDRB = 0xff;
    DDRC = 0xff;

    while (1)
    {
        PORTA = bcd(now.h);
        PORTB = bcd(now.m);
        PORTC = bcd(now.s);
        delay_ms(1000);
        clock_tick(&now);
    }
}
