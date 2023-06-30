/*
** EPITECH PROJECT, 2022
** my_ls
** File description:
** h file
*/
#include <stdarg.h>

#ifndef LS_H
    #define LS_H

void my_putchar(char c);
int my_strlen(char const *str);
int my_put_nbr(int nb);
int my_putstr(char const *str);
char *my_revstr(char *str);
int my_printf(const char *format, ...);
int cond_printf(const char *format, int i, va_list list);
int octal_conv(const char *format, int i, va_list list);
int hexa_conv(const char *format, int i, va_list list);
int hexa_maj_conv(const char *format, int i, va_list list);
int ls_a(const char *pathname);
int ls_l(const char *pathname);
int my_ls(const char *pathname);
int manage_flags(int argc, char **argv);
int ls_r_maj(const char *pathname);

#endif /* !LS_H */
