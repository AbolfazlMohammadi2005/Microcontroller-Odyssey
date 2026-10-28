#ifndef _BIT_UTILS_H
#define _BIT_UTILS_H

unsigned char bit_set(unsigned char v, unsigned char n);
unsigned char bit_clear(unsigned char v, unsigned char n);
unsigned char bit_toggle(unsigned char v, unsigned char n);
unsigned char bit_read(unsigned char v, unsigned char n);
unsigned char count_ones(unsigned char v);

#endif
