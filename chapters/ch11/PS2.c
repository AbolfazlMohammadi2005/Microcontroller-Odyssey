/*
 * How to run this program:
 *   1. Open it in CodeVisionAVR, create a project for ATmega32 @ 8 MHz and build it.
 *   2. Take the generated .hex file and load it into Proteus.
 *   3. Run the simulation in Proteus.
 */

#include <io.h>

#define PRELOAD 178

volatile unsigned char ticks = 0;
volatile unsigned char sec = 0;

interrupt [TIM0_OVF] void timer0_ovf_isr(void)
{
    TCNT0 = PRELOAD;
    ticks++;
    if (ticks == 100)
    {
        ticks = 0;
        sec++;
        if (sec == 100)
            sec = 0;
    }
}

void main(void)
{
    DDRA = 0xff;

    TCNT0 = PRELOAD;
    TCCR0 = (1 << CS02) | (1 << CS00);
    TIMSK |= (1 << TOIE0);
    #asm("sei")

    while (1)
    {
        PORTA = ((sec / 10) << 4) | (sec % 10);
    }
}
