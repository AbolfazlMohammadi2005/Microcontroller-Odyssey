#include <io.h>
#include <alcd.h>
#include <delay.h>
#include <stdio.h>

int h, m, s;
char c[16];

void main(void)
{
    lcd_init(16);
    lcd_putsf("Time:");

    while (1)
    {
        for (h = 0; h <= 23; h++)
        {
            for (m = 0; m <= 59; m++)
            {
                for (s = 0; s <= 59; s++)
                {
                    sprintf(c, "%02d:%02d:%02d", h, m, s);
                    lcd_gotoxy(0, 1);
                    lcd_puts(c);
                    delay_ms(20);
                }
            }
        }
    }
}
