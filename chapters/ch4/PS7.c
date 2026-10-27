/*
 * How to run this program:
 *   1. Open it in CodeVisionAVR, create a project for ATmega32 @ 8 MHz and build it.
 *   2. Take the generated .hex file and load it into Proteus.
 *   3. Run the simulation in Proteus.
 */

/*
 *        n= 3 sq=   9 cube=   27
 *
 */
#include <io.h>
#include <delay.h>
#include <stdio.h>

char str[32];
unsigned int n, sq, cube;

void usart_init(void)
{
    UCSRA = 0x00;
    UCSRB = (1 << TXEN) | (1 << RXEN);
    UCSRC = (1 << URSEL) | (1 << UCSZ1) | (1 << UCSZ0);
    UBRRH = 0;
    UBRRL = 51;                                            // 9600 baud @ 8MHz
}

void main(void)
{
    usart_init();

    while (1)
    {
        for (n = 1; n <= 10; n++)
        {
            sq   = n * n;
            cube = n * n * n;
            sprintf(str, "n=%2d sq=%4d cube=%5d", n, sq, cube);
            puts(str);
            delay_ms(300);
        }
        puts("-----------------");
        delay_ms(2000);
    }
}
