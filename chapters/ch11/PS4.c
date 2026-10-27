/*
 * How to run this program:
 *   1. Open it in CodeVisionAVR, create a project for ATmega32 @ 8 MHz and build it.
 *   2. Take the generated .hex file and load it into Proteus.
 *   3. Run the simulation in Proteus.
 */

/*
 *   WGM01=1, WGM00=1  => Fast PWM
 *   Duty cycle = OCR0 / 256
 */
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
