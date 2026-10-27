/*
 * How to run this program:
 *   1. Open it in CodeVisionAVR, create a project for ATmega32 @ 8 MHz and build it.
 *   2. Take the generated .hex file and load it into Proteus.
 *   3. Run the simulation in Proteus.
 */

#include <io.h>
#include <delay.h>

volatile unsigned char ev_up = 0, ev_down = 0;
unsigned char count = 0;

interrupt [EXT_INT0] void ext_int0_isr(void)
{
    ev_up = 1;
}

interrupt [EXT_INT1] void ext_int1_isr(void)
{
    ev_down = 1;
}

void main(void)
{
    DDRA = 0xff;
    DDRD &= ~((1 << 2) | (1 << 3));
    PORTD |= (1 << 2) | (1 << 3);

    MCUCR = (1 << ISC01) | (1 << ISC11);
    GICR |= (1 << INT0) | (1 << INT1);
    #asm("sei")

    while (1)
    {
        if (ev_up)
        {
            delay_ms(30);
            GIFR = (1 << INTF0);
            ev_up = 0;
            count++;
            if (count == 100) count = 0;
        }

        if (ev_down)
        {
            delay_ms(30);
            GIFR = (1 << INTF1);
            ev_down = 0;
            if (count == 0) count = 99;
            else            count--;
        }

        PORTA = ((count / 10) << 4) | (count % 10);
    }
}
