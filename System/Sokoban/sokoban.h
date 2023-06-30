/*
** EPITECH PROJECT, 2022
** sokoban
** File description:
** h file
*/
#include <stdarg.h>
#include "struct.h"

#ifndef SOKOBAN_H
    #define SOKOBAN_H
int sokoban_strlen(char const *str);
int cond_printf(const char *format, int i, va_list list);
int octal_conv(const char *format, int i, va_list list);
int hexa_conv(const char *format, int i, va_list list);
int hexa_maj_conv(const char *format, int i, va_list list);
int my_printf(const char *format, ...);
char *my_strcpy(char *dest, char const *src);
void my_putchar(char c);
int my_strlen(char const *str);
int my_put_nbr(int nb);
int my_putstr(char const *str);
char *my_revstr(char *str);
int op_rd_file(const char *filepath);
int help_manual(char **av, INIT_S *data);
int error(int argc, INIT_S *data);
int check_map(const char *buff, INIT_S *data);
int count_lines(const char *buff);
int count_collums(const char *buff);
void cpy(const char *buff, INIT_S *data);
void rd_file(INIT_S *data);
void move_input(INIT_S *data);
void game (INIT_S *data);
void display_game (INIT_S *data);
void empty_cpy(const char *buff, INIT_S *data);
void move_up(INIT_S *data);
void move_down(INIT_S *data);
void move_left(INIT_S *data);
void move_right(INIT_S *data);
void count_boxes(const char *buff, INIT_S *data);
void count_storage(const char *buff, INIT_S *data);
void possible_end(const char *buff, INIT_S *data);
void get_win(INIT_S *data);
void get_lose(INIT_S *data);
void get_lose_cont(INIT_S *data, int i, int j);
void check_end_cond(INIT_S *data);
void free_all(INIT_S *data);

#endif /* !SOKOBAN_H */
