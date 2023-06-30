/*
** EPITECH PROJECT, 2023
** EPITECH
** File description:
** minishell_1
*/
#include <stdarg.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <strings.h>
#include <string.h>
#include "./struct.h"

#ifndef MINISHELL_1_H_
    #define MINISHELL_1_H_

int error_handling(int argc, char **argv);
int error_handling_gen(int argc, char **argv);
char **cpy(const char *buff, global_t *data, char **tab);
void set_dead_end_map(global_t *data);
int detect_dead_end(global_t *data, int y, int x);
int detect_crossroads(global_t *data, int y, int x);
int manage_movement(global_t *data);
void display_tab(global_t *data);
void display_gen_map(global_t *data);

#endif /* !MINISHELL_1_H_ */
