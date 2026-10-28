#include <io.h>
#include <delay.h>

unsigned char duty = 0, dir = 1;

void main(void)
{
    DDRB |= (1 << 3);

    TCCR0 = (1 << WGM00) | (1 << WGM01) | (1 << COM01) | (1 << CS01);

    while (1)
    {
        OCR0 = duty;
        delay_ms(5);

        if (dir)
        {
            duty++;
            if (duty == 255)
                dir = 0;
        }
        else
        {
            duty--;
            if (duty == 0)
                dir = 1;
        }
    }
}
