#include <io.h>
#include <delay.h>

void main(void)
{
    DDRA = 0xff;
    DDRB = 0x00;
    PORTB = 0xff;

    while (1)
    {
        if ((PINB & (1 << 0)) == 0)
            PORTA |= (1 << 0);
        else
            PORTA &= ~(1 << 0);
    }
}
