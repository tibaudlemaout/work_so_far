/*
** EPITECH PROJECT, 2023
** EPITECH
** File description:
** lib
*/
#include <stdarg.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <sys/wait.h>
#include "./struct.h"

#ifndef LIB_H_
    #define LIB_H_

int my_printf(const char *format, ...);
int cond_printf(const char *format, int i, va_list list);
void my_putchar(char c);
int my_strlen(char const *str);
int my_put_nbr(int nb);
int my_putstr(char const *str);
int my_get_nbr(char *str);
int my_strcmp(char *str1, char *str2);
char *my_strcpy(char *dest, char const *src);

#endif /* !LIB_H_ */
