/*
 * How to run this program:
 *   1. Open it in CodeVisionAVR, create a project for ATmega32 @ 8 MHz and build it.
 *   2. Take the generated .hex file and load it into Proteus.
 *   3. Run the simulation in Proteus.
 */

#include <io.h>
#include <delay.h>

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
    ADCSRA = (1 << ADEN) | (1 << ADPS2) | (1 << ADPS1);

    while (1)
    {
        temp = read_adc(0) / 4;
        if (temp > 99)
            temp = 99;

        PORTB = ((temp / 10) << 4) | (temp % 10);
        delay_ms(500);
    }
}
