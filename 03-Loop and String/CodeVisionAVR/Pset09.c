#include <io.h>
#include <delay.h>

flash unsigned char digit[10] = {0x3f, 0x06, 0x5b, 0x4f, 0x66, 0x6d, 0x7d, 0x07, 0x7f, 0x6f};
unsigned char i, k;

void main(void)
{
    DDRA = 0xff;
    DDRD = 0xff;

    while (1)
    {
        i = 1;
        do
        {
            PORTD = digit[i];
            delay_ms(400);
            i++;
        } while (i < 10);

        k = 0;
        do
        {
            PORTA ^= 0x01;
            delay_ms(150);
            k++;
        } while (k < 10);
    }
}
