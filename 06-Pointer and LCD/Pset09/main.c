#include <io.h>
#include <delay.h>
#include <stdio.h>
#include "lcd.h"

char str[17];
unsigned char sec = 0;

void draw_bar(unsigned char n)
{
    unsigned char i;
    lcd_gotoxy(0, 1);
    for (i = 0; i < 16; i++)
    {
        if (i < n)
            lcd_putchar('#');
        else
            lcd_putchar(' ');
    }
}

void main(void)
{
    lcd_init();
    lcd_clear();

    while (1)
    {
        sprintf(str, "Time 00:%02d", sec);
        lcd_gotoxy(0, 0);
        lcd_puts(str);

        draw_bar((sec * 16) / 60);

        delay_ms(1000);
        sec++;
        if (sec == 60)
        {
            sec = 0;
            lcd_clear();
        }
    }
}
