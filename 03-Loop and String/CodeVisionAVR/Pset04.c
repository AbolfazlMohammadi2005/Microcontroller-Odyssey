#include <io.h>
#include <delay.h>

unsigned char i;

void main(void)
{
    DDRA = 0xff;

    while (1)
    {
        for (i = 0; i < 8; i++)
        {
            PORTA = (1 << i);
            delay_ms(200);
        }
    }
}
