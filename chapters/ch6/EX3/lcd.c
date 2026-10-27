#include "lcd.h"

void send_command(unsigned char comm)
{
    delay_ms(2);
    CTRL_PORT &= ~RS;
    CTRL_PORT &= ~RW;
    CTRL_PORT &= ~E;
    DATA_PORT = comm;
    CTRL_PORT |= E;
    CTRL_PORT &= ~E;
}

void lcd_putchar(char ch)
{
    delay_ms(2);
    CTRL_PORT |= RS;
    CTRL_PORT &= ~RW;
    CTRL_PORT &= ~E;
    DATA_PORT = ch;
    CTRL_PORT |= E;
    CTRL_PORT &= ~E;
}

void lcd_init(void)
{
    delay_ms(2);
    DATA_DDR = 0xff;
    CTRL_DDR = 0xff;
    
    send_command(0x38);
    send_command(0x06);
    send_command(0x0C);
}

void lcd_gotoxy(unsigned char x, unsigned char y)
{
    delay_ms(2);
    switch (y)
    {
        case 0:
            send_command(0x80 + x);
            break;
        case 1:
            send_command(0xC0 + x);
            break;
    }
}

void lcd_clear(void)
{
    delay_ms(2);
    send_command(0x01);
    send_command(0x02);
}

void lcd_puts(char *str)
{
    delay_ms(2);
    while (*str != 0)
    {
        lcd_putchar(*str);
        str++;
    }
}
