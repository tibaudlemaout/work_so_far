/*
** EPITECH PROJECT, 2023
** stumper
** File description:
** sort strings
*/
#include "../include/struct.h"
#include "../include/stumper.h"
#include <string.h>

static int sort_r(char *letter, int *repeat, int pos)
{
    int i = 0;
    int length = strlen(letter);

    while (i != length) {
        if (repeat[i] == repeat[pos] && i != pos) {
            printf("%c,", letter[pos]);
            letter[pos] = '\0';
            pos = i;
        }
        i++;
    }
    printf("%c:%i\n", letter[pos], repeat[pos]);
    return (0);
}

int display_r(global_t *global, char *letter, int *repeat)
{
    for (int i = 0; letter[i] != '\0'; i++)
        sort_r(letter, repeat, i);
    return (0);
}
