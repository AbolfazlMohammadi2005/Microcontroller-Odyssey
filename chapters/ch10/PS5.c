/*
 * How to run this program:
 *   1. Open it in CodeVisionAVR, create a project for ATmega32 @ 8 MHz and build it.
 *   2. Take the generated .hex file and load it into Proteus.
 *   3. Run the simulation in Proteus.
 */

/*
 *     ISC01 ISC00
 */
#include <io.h>
#include <delay.h>

interrupt [EXT_INT0] void ext_int0_isr(void)
{
    if ((PIND & (1 << 2)) == 0)
        PORTA |= (1 << 0);
    else
        PORTA &= ~(1 << 0);
}

void main(void)
{
    DDRA = 0xff;
    DDRD &= ~(1 << 2);
    PORTD |= (1 << 2);

    MCUCR = (1 << ISC00);
    GICR |= (1 << INT0);
    GIFR = (1 << INTF0);
    #asm("sei")

    while (1)
    {
        PORTA ^= (1 << 7);
        delay_ms(250);
    }
}
