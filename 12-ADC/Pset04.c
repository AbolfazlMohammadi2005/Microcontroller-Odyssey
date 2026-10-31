#include <io.h>
#include <delay.h>

#define FAN_ON_TEMP   30
#define FAN_OFF_TEMP  28

unsigned int read_adc(unsigned char ch)
{
    ADMUX = (1 << REFS1) | (1 << REFS0) | ch;
    delay_us(10);
    ADCSRA |= (1 << ADSC);
    while (ADCSRA & (1 << ADSC));
    return ADCW;
}

unsigned char temp;

void main(void)
{
    DDRB = 0xff;
    DDRD = 0xff;
    ADCSRA = (1 << ADEN) | (1 << ADPS2) | (1 << ADPS1);

    while (1)
    {
        temp = read_adc(0) / 4;

        if (temp >= FAN_ON_TEMP)
            PORTB |= (1 << 0);
        else if (temp <= FAN_OFF_TEMP)
            PORTB &= ~(1 << 0);

        if (temp > 99)
            PORTD = 0x99;
        else
            PORTD = ((temp / 10) << 4) | (temp % 10);

        delay_ms(300);
    }
}
