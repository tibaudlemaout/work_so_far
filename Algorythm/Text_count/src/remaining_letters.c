/*
** EPITECH PROJECT, 2023
** remaining_letters.c
** File description:
** remaining letters
*/

#include <string.h>
#include "../include/stumper.h"
#include "../include/struct.h"

static int check_if_not_same_letter(char a, char b)
{
    int nb = 0;

    if (a != b)
        nb++;
    return (nb);
}

void display_remaining_char(global_t *global, char *letter)
{
    int nb = 0;

    for (int k = 0; global->searched_char[k] != '\0'; k++) {
        nb = 0;
        for (int j = 0; letter[j] != '\0'; j++)
            nb = nb + check_if_not_same_letter(global->searched_char[k],
                        letter[j]);
        if (nb == strlen(letter))
            printf("%c:0\n", global->searched_char[k]);
    }
}
