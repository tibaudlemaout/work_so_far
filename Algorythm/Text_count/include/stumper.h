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

int count_letters(global_t *global);
int display(global_t *global, char *letter, int *repeat, int length);
int check_for_spaces(char *str);
void display_remaining_char(global_t *global, char *letter);
void bubble_sort_array(int *array, int size, char *letter);
int display_r(global_t *global, char *letter, int *repeat);

#endif /* !STUMPER_H_ */
