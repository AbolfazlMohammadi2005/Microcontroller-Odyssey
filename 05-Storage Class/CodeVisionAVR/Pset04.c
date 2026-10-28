#include <io.h>
#include <delay.h>

void chase_left(void)
{
    static unsigned char pos = 0x01;
    PORTA = pos;
    pos <<= 1;
    if (pos == 0)
        pos = 0x01;
}

void chase_right(void)
{
    static unsigned char pos = 0x80;
    PORTB = pos;
    pos >>= 1;
    if (pos == 0)
        pos = 0x80;
}

unsigned char t;

void main(void)
{
    DDRA = 0xff;
    DDRB = 0xff;

    while (1)
    {
        t++;
        delay_ms(50);

        chase_left();
        if ((t % 3) == 0)
            chase_right();
    }
}
