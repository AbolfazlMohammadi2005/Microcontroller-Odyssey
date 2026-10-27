/*
 * How to run this program:
 *   1. Open it in CodeVisionAVR, create a project for ATmega32 @ 8 MHz and build it.
 *   2. Take the generated .hex file and load it into Proteus.
 *   3. Run the simulation in Proteus.
 */

#include <io.h>
#include <delay.h>

unsigned char i, v, a;
char data[8] = "Hum:47%";

void main(void)
{
    DDRA = 0xff;

    while (1)
    {
        for (i = 0; data[i] != 0; i++)
        {
            if (data[i] == ':')
                break;
        }

        if (data[i] == 0)
        {
            PORTA = 0xff;
        }
        else
        {
            v = 0;
            i++;
            while ((data[i] >= '0') && (data[i] <= '9'))
            {
                v = (v * 10) + (data[i] - '0');
                i++;
            }

            a = ((v / 10) << 4) | (v % 10);
            PORTA = a;
        }
        delay_ms(500);
    }
}
