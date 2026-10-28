#include <io.h>
#include <delay.h>

volatile unsigned char count = 0;

interrupt [EXT_INT0] void ext_int0_isr(void)
{
    count++;
    if (count == 100)
        count = 0;
}

void main(void)
{
    DDRA = 0xff;
    DDRD &= ~(1 << 2);
    PORTD |= (1 << 2);

    MCUCR = (1 << ISC01);
    GICR |= (1 << INT0);
    #asm("sei")

    while (1)
    {
        PORTA = ((count / 10) << 4) | (count % 10);
    }
}
