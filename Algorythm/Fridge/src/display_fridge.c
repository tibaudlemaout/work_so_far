/*
** EPITECH PROJECT, 2023
** stumper
** File description:
** to display fridge
*/
#include "duo.h"
#include <stdio.h>

int display_fridge(fridge_t *fridge, char **input, char *buff)
{
    if (my_strcmp(input[1], "fridge") == 0) {
        printf("tomato = %i\ndough = %i\n", fridge->tomato, fridge->dough);
        printf("onion = %i\npasta = %i\n", fridge->onion, fridge->pasta);
        printf("olive = %i\npepper = %i\n", fridge->olive, fridge->pepper);
        printf("ham = %i\ncheese = %i\n", fridge->ham, fridge->cheese);
    } else {
        printf("'%s': Invalid operation\n", buff);
    return (0);
}
