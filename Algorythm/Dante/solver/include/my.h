/*
** EPITECH PROJECT, 2023
** B-CPE-200-NAN-2-1-dante-tibaud.le-maout
** File description:
** my
*/
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "struct.h"

#ifndef MY_H_
    #define MY_H_
void my_putchar(char c);
int my_putstr(char const *str);
int my_strlen(char *str);
char *my_strcpy(char *str);
int get_lines(char **tab);
void find_dead_end(struct_t *data, int y);
void best_path(struct_t *data, int y, int x);

#endif /* !MY_H_ */
