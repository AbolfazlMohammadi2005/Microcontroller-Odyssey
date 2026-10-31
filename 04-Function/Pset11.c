#include <io.h>
#include <delay.h>

unsigned char bin2gray(unsigned char b)
{
    return b ^ (b >> 1);
}

unsigned char n;

void main(void)
{
    DDRA = 0xff;
    DDRB = 0xff;

    while (1)
    {
        PORTA = n;
        PORTB = bin2gray(n);
        delay_ms(300);
        n++;
    }
}
