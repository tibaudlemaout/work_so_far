/*
** EPITECH PROJECT, 2023
** B-CPE-210-NAN-2-1-stumper3-dragos.suceveanu
** File description:
** stumper
*/
#include <stdarg.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <sys/wait.h>
#include "./struct.h"

#ifndef STUMPER_H_
    #define STUMPER_H_

int my_printf(const char *format, ...);
int cond_printf(const char *format, int i, va_list list);
void my_putchar(char c);
int my_strlen(char const *str);
int my_put_nbr(int nb);
int my_putstr(char const *str);
int my_get_nbr(char *str);
int my_strcmp(char *str1, char *str2);
char *my_strcpy(char *dest, char const *src);
void init_struct(global_t *global);
int get_argv(int argc, char **argv, global_t *global);
int diff_p_char(global_t *global);
int *get_attack(global_t *global);
char **create_map(global_t *global);
char **display_move(global_t *global, int *pos, char **map);
int win_cond(global_t *global, char **map, int *pos);
int check_left_line(global_t *global, char **map, char p);
int check_right_line(global_t *global, char **map, char p);
int draw_cond(char **map);
void free_map(char **map);

#endif /* !STUMPER_H_ */
