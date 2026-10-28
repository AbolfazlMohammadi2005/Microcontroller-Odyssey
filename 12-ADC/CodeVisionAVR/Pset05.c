#include <io.h>
#include <delay.h>

unsigned int read_adc(unsigned char ch)
{
    ADMUX = (1 << REFS0) | ch;
    delay_us(10);
    ADCSRA |= (1 << ADSC);
    while (ADCSRA & (1 << ADSC));
    return ADCW;
}

unsigned int t, k;

void main(void)
{
    DDRB = 0xff;
    ADCSRA = (1 << ADEN) | (1 << ADPS2) | (1 << ADPS1);

    while (1)
    {
        t = 10 + read_adc(0);
        PORTB ^= (1 << 0);

        for (k = 0; k < t; k++)
            delay_ms(1);
    }
}
