/*
** EPITECH PROJECT, 2022
** bsq h
** File description:
** bsq
*/
#include <stdarg.h>
#include "struct.h"

#ifndef BSQ_H
    #define BSQ_H

int cond_printf(const char *format, int i, va_list list);
int octal_conv(const char *format, int i, va_list list);
int hexa_conv(const char *format, int i, va_list list);
int hexa_maj_conv(const char *format, int i, va_list list);
int my_printf(const char *format, ...);
void my_putchar(char c);
int my_strlen(char const *str);
int bsq_strlen(char const *str);
int my_put_nbr(int nb);
int my_putstr(char const *str);
int my_get_nbr(char *str);
int op_rd_file(const char *filepath, GLOBAL_T *data);
int count_cols(const char *buff);
int count_lines(const char *buff);
void square_search(GLOBAL_T *data);
void search_cont(GLOBAL_T *data);
void check_square(GLOBAL_T *data);
void drawing_square(GLOBAL_T *data);
void create_template(GLOBAL_T *data, int size, char *template);
void generated_search(GLOBAL_T *data, int size);
void generated_drawing_square(GLOBAL_T *data);

#endif /* !BSQ_H_ */
