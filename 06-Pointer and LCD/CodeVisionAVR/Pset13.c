#include <io.h>
#include <alcd.h>
#include <delay.h>

signed char x;

void main(void)
{
    lcd_init(16);

    while (1)
    {
        for (x = 0; x <= 11; x++)
        {
            lcd_gotoxy(x, 0);
            lcd_putsf("Hello");
            delay_ms(50);
            lcd_gotoxy(x, 0);
            lcd_putsf(" ");
        }

        lcd_clear();

        for (x = 11; x >= 0; x--)
        {
            lcd_gotoxy(x, 1);
            lcd_putsf("Hello");
            delay_ms(50);
            lcd_gotoxy(x + 4, 1);
            lcd_putsf(" ");
        }
    }
}
