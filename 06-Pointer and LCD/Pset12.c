#include <io.h>
#include <alcd.h>
#include <delay.h>

void main(void)
{
    lcd_init(16);
    lcd_putsf("Hello");
    delay_ms(100);
    lcd_clear();
    lcd_gotoxy(7, 1);
    lcd_putsf("Bye");

    while (1)
    {
    }
}
