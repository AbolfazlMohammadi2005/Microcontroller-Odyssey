/*
 * How to run this program:
 *   1. Open it in CodeVisionAVR, create a project for ATmega32 @ 8 MHz and build it.
 *   2. Take the generated .hex file and load it into Proteus.
 *   3. Run the simulation in Proteus.
 */

#include <io.h>
#include <delay.h>

flash unsigned char hex[16] = {
    0x3f, 0x06, 0x5b, 0x4f, 0x66, 0x6d, 0x7d, 0x07,
    0x7f, 0x6f, 0x77, 0x7c, 0x39, 0x5e, 0x79, 0x71
};

unsigned char keypad_scan(void)
{
    unsigned char r, c, cols;

    for (r = 0; r < 4; r++)
    {
        PORTC = ~(1 << r);
        delay_us(10);
        cols = (PINC >> 4) & 0x0F;

        if (cols != 0x0F)
        {
            for (c = 0; c < 4; c++)
            {
                if ((cols & (1 << c)) == 0)
                    return (r * 4) + c;
            }
        }
    }
    return 0xFF;
}

unsigned char key;

void main(void)
{
    DDRD = 0xff;
    DDRC = 0x0F;
    PORTC = 0xFF;

    PORTD = 0x40;

    while (1)
    {
        key = keypad_scan();

        if (key != 0xFF)
        {
            delay_ms(20);
            if (keypad_scan() == key)
            {
                PORTD = hex[key];
                while (keypad_scan() != 0xFF);
                delay_ms(20);
            }
        }
    }
}
