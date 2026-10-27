/*
 * How to run this program:
 *   1. Open it in CodeVisionAVR, create a project for ATmega32 @ 8 MHz and build it.
 *   2. Take the generated .hex file and load it into Proteus.
 *   3. Run the simulation in Proteus.
 */

#include <io.h>

volatile unsigned int ms = 0;

interrupt [TIM0_COMP] void timer0_comp_isr(void)
{
    ms++;
}

unsigned int millis(void)
{
    unsigned int m;
    #asm("cli")
    m = ms;
    #asm("sei")
    return m;
}

unsigned int t0 = 0, t1 = 0, t2 = 0, now;

void main(void)
{
    DDRA = 0xff;

    TCCR0 = (1 << WGM01) | (1 << CS01) | (1 << CS00);
    OCR0 = 124;
    TCNT0 = 0;
    TIMSK |= (1 << OCIE0);
    #asm("sei")

    while (1)
    {
        now = millis();

        if ((unsigned int)(now - t0) >= 100)
        {
            t0 = now;
            PORTA ^= (1 << 0);
        }

        if ((unsigned int)(now - t1) >= 350)
        {
            t1 = now;
            PORTA ^= (1 << 1);
        }

        if ((unsigned int)(now - t2) >= 1000)
        {
            t2 = now;
            PORTA ^= (1 << 2);
        }
    }
}
