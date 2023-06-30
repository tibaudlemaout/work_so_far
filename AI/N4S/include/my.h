/*
** EPITECH PROJECT, 2023
** B-AIA-200-NAN-2-1-n4s-tibaud.le-maout
** File description:
** my
*/
#include "struct.h"

#ifndef MY_H_
    #define MY_H_

char *get_next_line(int fd, int start);
char **str_to_tab(char *str);
int change_direction(struct_t *info, char **tab);

#endif /* !MY_H_ */
