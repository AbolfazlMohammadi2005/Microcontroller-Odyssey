/*
 * How to run this program:
 *   1. Open it in CodeVisionAVR, create a project for ATmega32 @ 8 MHz and build it.
 *   2. Take the generated .hex file and load it into Proteus.
 *   3. Run the simulation in Proteus.
 */

#include <io.h>
#include <delay.h>

unsigned char str_len(char *s)
{
    char *p = s;
    while (*p != 0)
        p++;
    return (unsigned char)(p - s);
}

void str_rev(char *s)
{
    char *e = s + str_len(s) - 1;
    char t;

    while (s < e)
    {
        t = *s;
        *s = *e;
        *e = t;
        s++;
        e--;
    }
}

char text[16] = "micro";

void main(void)
{
    DDRA = 0xff;
    DDRB = 0xff;

    PORTA = str_len(text);     // 5
    delay_ms(1000);

    str_rev(text);             // "orcim"
    PORTB = text[0];           // 'o' = 0x6F

    while (1)
    {
    }
}
