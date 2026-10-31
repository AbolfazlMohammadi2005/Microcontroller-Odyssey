#include <io.h>
#include "two_digit.h"

unsigned char i;

void main(void)
{
    DDRA = 0xff;

    while (1)
    {
        PORTA = show(i);
        DELAY_MS(500);
        i++;
        if (i == 100)
            i = 0;
    }
}
