/*
 * How to run this program:
 *   1. Open it in CodeVisionAVR, create a project for ATmega32 @ 8 MHz and build it.
 *   2. Take the generated .hex file and load it into Proteus.
 *   3. Run the simulation in Proteus.
 */

#include <io.h>
#include <delay.h>

volatile unsigned char paused = 0;
unsigned char a = 0x01;

interrupt [EXT_INT2] void ext_int2_isr(void)
{
    paused = !paused;
}

void main(void)
{
    DDRA = 0xff;
    DDRB &= ~(1 << 2);
    PORTB |= (1 << 2);

    GICR &= ~(1 << INT2);
    MCUCSR &= ~(1 << ISC2);
    GIFR = (1 << INTF2);
    GICR |= (1 << INT2);
    #asm("sei")

    while (1)
    {
        if (paused)
        {
            PORTA = 0xFF;
            delay_ms(100);
            PORTA = 0x00;
            delay_ms(100);
        }
        else
        {
            PORTA = a;
            delay_ms(150);
            a <<= 1;
            if (a == 0)
                a = 0x01;
        }
    }
}
