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

unsigned char level;

void main(void)
{
    DDRB = 0xff;
    ADCSRA = (1 << ADEN) | (1 << ADPS2) | (1 << ADPS1);

    while (1)
    {
        level = read_adc(0) / 128;
        PORTB = (1 << (level + 1)) - 1;
        delay_ms(50);
    }
}
