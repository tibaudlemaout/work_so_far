/*
** EPITECH PROJECT, 2022
** EPITECH
** File description:
** pushswap
*/
#include <stdarg.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include "struct.h"

#ifndef PUSHSWAP_H_
    #define PUSHSWAP_H_
int cond_printf(const char *format, int i, va_list list);
int octal_conv(const char *format, int i, va_list list);
int hexa_conv(const char *format, int i, va_list list);
int hexa_maj_conv(const char *format, int i, va_list list);
int my_printf(const char *format, ...);
void my_putchar(char c);
int my_strlen(char const *str);
int my_put_nbr(int nb);
int my_putstr(char const *str);
int display(global_t *data);
void swap_sa(int *array);
void swap_sb(int *array);
void rotate_left_ra(global_t *data, int disp);
void rotate_left_rb(global_t *data, int disp);
void rotate_right_rra(global_t *data, int disp);
void rotate_right_rrb(global_t *data, int disp);
void bubble_push(global_t *data);
void push_pa(global_t *data, int disp);
void push_pb(global_t *data, int disp);
int my_get_nbr(char *str);

#endif /* !PUSHSWAP_H_ */
