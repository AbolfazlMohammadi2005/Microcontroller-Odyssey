#include "two_digit.h"

unsigned char show(unsigned char v)
{
    unsigned char a, b;
    a = v / 10;
    b = v % 10;
    a <<= 4;
    a |= b;
    return a;
}

void DELAY_MS(unsigned int x)
{
    unsigned int i, j;
    for (i = 0; i < x; i++)
        for (j = 0; j < 1000; j++);
}
