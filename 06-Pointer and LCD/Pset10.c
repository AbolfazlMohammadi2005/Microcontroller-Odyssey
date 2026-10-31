#include <io.h>
#include <alcd.h>

void main(void)
{
    lcd_init(16);
    lcd_puts("Hello");

    while (1)
    {
    }
}
