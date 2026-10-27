/*
 * How to run this program:
 *   1. Open it in CodeVisionAVR, create a project for ATmega32 @ 8 MHz and build it.
 *   2. Take the generated .hex file and load it into Proteus.
 *   3. Run the simulation in Proteus.
 */

#include <io.h>
#include <delay.h>

unsigned char s = 0, i = 0, d[4] = {0x81, 0x42, 0x24, 0x18};

void main(void)
{
    DDRA = 0xff;
    
    while (1)
    {
        if (s == 0)
        {
            PORTA = d[i];
            delay_ms(100);
            i++;
            
            if (i == 3)
            {
                s = 1;
            }
        }
        else
        {
            PORTA = d[i];
            delay_ms(100);
            i--;
            
            if (i == 0)
            {
                s = 0;
            }
        }
    }
}
