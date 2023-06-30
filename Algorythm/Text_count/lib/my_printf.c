/*
** EPITECH PROJECT, 2022
** printf
** File description:
** my_printf
*/
#include <stdarg.h>
#include "../include/lib.h"

int my_printf(const char *format, ...)
{
    va_list list;
    va_start (list, format);
    int i = 0;

    while (format[i] != '\0') {
        if (format[i] == '%') {
            cond_printf (format, i, list);
            i = i + 2;
        } else {
            my_putchar (format[i]);
            i++;
            }
        }
    va_end(list);
    return (i);
}
