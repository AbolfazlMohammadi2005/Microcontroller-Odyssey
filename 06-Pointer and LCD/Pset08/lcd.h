#ifndef _LCD_H
#define _LCD_H

#include <io.h>
#include <delay.h>

#define DATA_PORT PORTA
#define CTRL_PORT PORTB
#define DATA_DDR  DDRA
#define CTRL_DDR  DDRB

#define RS_PIN_NUMBER 0
#define RW_PIN_NUMBER 1
#define E_PIN_NUMBER  2

#define RS (1 << RS_PIN_NUMBER)
#define RW (1 << RW_PIN_NUMBER)
#define E  (1 << E_PIN_NUMBER)

void lcd_init(void);
void lcd_clear(void);
void lcd_gotoxy(unsigned char x, unsigned char y);
void lcd_putchar(char ch);
void lcd_puts(char *str);

#endif
