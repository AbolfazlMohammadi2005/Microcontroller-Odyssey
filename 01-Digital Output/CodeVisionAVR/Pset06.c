#include <io.h>
#include <delay.h>

void main(void)
{
    DDRA = 0xff;
    PORTA = 0x01;

    while (1)
    {
        delay_ms(400);
        PORTA ^= 0x03;
    }
}
