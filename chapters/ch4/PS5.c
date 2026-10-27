/*
 * How to run this program:
 *   1. Open it in CodeVisionAVR, create a project for ATmega32 @ 8 MHz and build it.
 *   2. Take the generated .hex file and load it into Proteus.
 *   3. Run the simulation in Proteus.
 */

#include <io.h>
#include <delay.h>

unsigned char sec = 0, min = 0;

unsigned char bcd(unsigned char v)
{
    return ((v / 10) << 4) | (v % 10);
}

void tick(void)
{
    sec++;
    if (sec == 60)
    {
        sec = 0;
        min++;
        if (min == 60)
            min = 0;
    }
}

void show(void)
{
    PORTA = bcd(sec);
    PORTB = bcd(min);
}

void main(void)
{
    DDRA = 0xff;
    DDRB = 0xff;

    while (1)
    {
        show();
        delay_ms(1000);
        tick();
    }
}
