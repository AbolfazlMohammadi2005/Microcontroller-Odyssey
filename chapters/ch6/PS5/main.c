/*
 * How to run this program:
 *   1. Open it in CodeVisionAVR, create a project for ATmega32 @ 8 MHz and build it.
 *   2. Take the generated .hex file and load it into Proteus.
 *   3. Run the simulation in Proteus.
 */

#include <io.h>
#include <delay.h>
#include "lcd.h"

char text[] = "Hello AVR! ";

void print_window(char *t, unsigned char len, unsigned char start)
{
    unsigned char i;
    unsigned char idx = start;

    lcd_gotoxy(0, 0);
    for (i = 0; i < 16; i++)
    {
        lcd_putchar(*(t + idx));
        idx++;
        if (idx == len)
            idx = 0;
    }
}

unsigned char len, s;

void main(void)
{
    char *p = text;

    lcd_init();
    lcd_clear();

    len = 0;
    while (*p != 0)
    {
        len++;
        p++;
    }

    while (1)
    {
        for (s = 0; s < len; s++)
        {
            print_window(text, len, s);
            delay_ms(300);
        }
    }
}
