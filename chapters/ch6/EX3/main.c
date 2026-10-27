/*
 * How to run this program:
 *   1. Open it in CodeVisionAVR, create a project for ATmega32 @ 8 MHz and build it.
 *   2. Take the generated .hex file and load it into Proteus.
 *   3. Run the simulation in Proteus.
 */

#include <io.h>
#include <delay.h>
#include <stdio.h>
#include "lcd.h"

int i;
char str[20];

void main(void)
{
    lcd_init();
    lcd_clear();
    lcd_gotoxy(0, 0);
    lcd_puts(" LCD TEST! ");
    delay_ms(1000);
    lcd_clear();
    
    while (1)
    {
        sprintf(str, "Value=%d", i);
        lcd_gotoxy(0, 0);
        lcd_puts(str);
        delay_ms(500);
        
        i++;
        if (i == 100)
            i = 0;
    }
}
