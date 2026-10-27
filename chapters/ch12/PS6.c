/*
 * How to run this program:
 *   1. Open it in CodeVisionAVR, create a project for ATmega32 @ 8 MHz and build it.
 *   2. Take the generated .hex file and load it into Proteus.
 *   3. Run the simulation in Proteus.
 */

#include <io.h>
#include <delay.h>

#define SAMPLES 16

unsigned int read_adc(unsigned char ch)
{
    ADMUX = (1 << REFS0) | ch;
    delay_us(10);
    ADCSRA |= (1 << ADSC);
    while (ADCSRA & (1 << ADSC));
    return ADCW;
}

unsigned int read_adc_avg(unsigned char ch)
{
    unsigned int sum = 0;
    unsigned char i;

    for (i = 0; i < SAMPLES; i++)
        sum += read_adc(ch);

    return sum >> 4;
}

void main(void)
{
    DDRB = 0xff;
    ADCSRA = (1 << ADEN) | (1 << ADPS2) | (1 << ADPS1);

    while (1)
    {
        PORTB = read_adc_avg(0) >> 2;
        delay_ms(100);
    }
}
