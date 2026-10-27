/*
 * How to run this program:
 *   1. Open it in CodeVisionAVR, create a project for ATmega32 @ 8 MHz and build it.
 *   2. Take the generated .hex file and load it into Proteus.
 *   3. Run the simulation in Proteus.
 */

#include <io.h>
#include <delay.h>

typedef struct {
    unsigned char pattern;
    unsigned int  time_ms;
} STEP;

#define STEPS 8

STEP seq[STEPS] = {
    {0x01, 200},
    {0x03, 200},
    {0x07, 200},
    {0x0F, 600},
    {0xF0, 200},
    {0xE0, 200},
    {0xC0, 200},
    {0x00, 800}
};

unsigned char i;

void main(void)
{
    DDRA = 0xff;

    while (1)
    {
        for (i = 0; i < STEPS; i++)
        {
            PORTA = seq[i].pattern;
            delay_ms(seq[i].time_ms);
        }
    }
}
