#include <stdio.h>

void get_val(int *x, int *y)
{
    *x = 10;
    *y = 20;
}

int main(void)
{
    int a, b;
    get_val(&a, &b);
    return 0;
}
