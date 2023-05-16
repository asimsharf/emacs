#include "main.h"

void _puts(char *str)
{
    while (*str)
        _putchar(*str++);
    _putchar('\n');
}
