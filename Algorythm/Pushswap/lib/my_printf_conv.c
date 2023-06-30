/*
** EPITECH PROJECT, 2022
** my_printf
** File description:
** printf
*/
#include <stdarg.h>
#include "../pushswap.h"

int cond_printf(const char *format, int i, va_list list)
{
    switch (format[i + 1]) {
    case 'c': my_putchar(va_arg(list, int)); break;
    case 's': my_putstr(va_arg(list, char *)); break;
    case '%': my_putchar('%'); break;
    case 'i': case 'd': my_put_nbr(va_arg(list, int)); break;
    case 'o': octal_conv(format, i, list); break;
    case 'x': hexa_conv(format, i, list); break;
    case 'X': hexa_maj_conv(format, i, list); break;
    default: ; break;
    }
    return (0);
}

int octal_conv(const char *format, int i, va_list list)
{
    int arg = va_arg(list, int);
    char oct[10] = "\0";
    int length = 0;

    while (arg != 0){
        oct[length] = (arg % 8);
        arg = arg / 8;
        length ++;
    }
    while (length >= 0){
        my_putchar (oct[length] + 48);
        length --;
    }
    return (0);
}

int hexa_conv(const char *format, int i, va_list list)
{
    char hexatab[] = "0123456789abcdef";
    int arg = va_arg(list, int);
    int hexa[10];
    int length = 0;
    int look;

    while (arg != 0){
        look = arg % 16;
        hexa[length] = hexatab[look];
        length ++;
        arg = arg / 16;
    }
    while (length >= 0){
        my_putchar (hexa[length]);
        length --;
    }
    return (0);
}

int hexa_maj_conv(const char *format, int i, va_list list)
{
    char hexaXtab[] = "0123456789ABCDEF";
    int arg = va_arg(list, int);
    int hexaX[10];
    int length = 0;
    int look;

    while (arg != 0){
        look = arg % 16;
        hexaX[length] = hexaXtab[look];
        length ++;
        arg = arg / 16;
    }
    while (length >= 0){
        my_putchar (hexaX[length]);
        length --;
    }
    return (0);
}
