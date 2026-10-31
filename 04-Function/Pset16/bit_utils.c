#include "bit_utils.h"

unsigned char bit_set(unsigned char v, unsigned char n)
{
    return v | (1 << n);
}

unsigned char bit_clear(unsigned char v, unsigned char n)
{
    return v & ~(1 << n);
}

unsigned char bit_toggle(unsigned char v, unsigned char n)
{
    return v ^ (1 << n);
}

unsigned char bit_read(unsigned char v, unsigned char n)
{
    return (v >> n) & 1;
}

unsigned char count_ones(unsigned char v)
{
    unsigned char i, c = 0;
    for (i = 0; i < 8; i++)
    {
        c += bit_read(v, i);
    }
    return c;
}
