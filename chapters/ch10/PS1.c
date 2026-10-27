/*
 * How to run this program:
 *   1. Open it in CodeVisionAVR, create a project for ATmega32 @ 8 MHz and build it.
 *   2. Take the generated .hex file and load it into Proteus.
 *   3. Run the simulation in Proteus.
 */

#include <io.h>
#include <delay.h>

interrupt [EXT_INT0] void ext_int0_isr(void)
{
    PORTA ^= (1 << 0);
}

void main(void)
{
    DDRA = 0xff;

    DDRD &= ~(1 << 2);
    PORTD |= (1 << 2);          // pull-up

    MCUCR = (1 << ISC01);
    GICR |= (1 << INT0);
    GIFR = (1 << INTF0);

    #asm("sei")

    while (1)
    {
        PORTA ^= (1 << 7);
        delay_ms(500);
    }
}
