#include <io.h>
#include <delay.h>

flash unsigned char pattern[8] = {0x18, 0x3C, 0x7E, 0xFF, 0x7E, 0x3C, 0x18, 0x00};
unsigned char i = 0;

void main(void)
{
    DDRA = 0xff;

    while (1)
    {
        PORTA = pattern[i];
        delay_ms(200);
        i++;

        if (i == 8)
        {
            i = 0;
        }
    }
}
