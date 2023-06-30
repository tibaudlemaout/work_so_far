/*
** EPITECH PROJECT, 2023
** Semester_2
** File description:
** display_gen_map
*/
#include "../include/struct.h"
#include "../include/dante.h"

void display_gen_map(global_t *data)
{
    for (int i = 0; i < data->layers; i ++){
        printf("%s", data->tab[i]);
        if (i < data->layers - 1)
            putchar('\n');
    }
    return;
}