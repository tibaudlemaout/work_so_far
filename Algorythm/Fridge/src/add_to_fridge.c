/*
** EPITECH PROJECT, 2023
** stumper
** File description:
** addtofridge option
*/

#include "duo.h"
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

static int add_item_4(fridge_t *fridge, char **input)
{
    if (my_strcmp(input[1], "ham") == 0) {
        if (is_int_modif(input[2]) == 0) {
            fridge->ham += char_in_int_modif(input[2]);
            return (1);
        }
    }
    if (my_strcmp(input[1], "cheese") == 0) {
        if (is_int_modif(input[2]) == 0) {
            fridge->cheese += char_in_int_modif(input[2]);
            return (1);
        }
    }
    return (0);
}

static int add_item_3(fridge_t *fridge, char **input)
{
    if (my_strcmp(input[1], "olive") == 0) {
        if (is_int_modif(input[2]) == 0) {
            fridge->olive += char_in_int_modif(input[2]);
            return (1);
        }
    }
    if (my_strcmp(input[1], "pepper") == 0) {
        if (is_int_modif(input[2]) == 0) {
            fridge->pepper += char_in_int_modif(input[2]);
            return (1);
        }
    }
    if (add_item_4(fridge, input) == 1)
        return (1);
    return (0);
}

static int add_item_2(fridge_t *fridge, char **input)
{
    if (my_strcmp(input[1], "onion") == 0) {
        if (is_int_modif(input[2]) == 0) {
            fridge->onion += char_in_int_modif(input[2]);
            return (1);
        }
    }
    if (my_strcmp(input[1], "pasta") == 0) {
        if (is_int_modif(input[2]) == 0) {
            fridge->pasta += char_in_int_modif(input[2]);
            return (1);
        }
    }
    if (add_item_3(fridge, input) == 1)
        return (1);
    return (0);
}

int add_item(fridge_t *fridge, char *buff, char **input)
{
    if (my_strcmp(input[1], "tomato") == 0) {
        if (is_int_modif(input[2]) == 0) {
            my_put_nbr(fridge->tomato);
            fridge->tomato += char_in_int_modif(input[2]);
            return (0);
        }
    }
    if (my_strcmp(input[1], "dough") == 0) {
        if (is_int_modif(input[2]) == 0) {
            fridge->dough += char_in_int_modif(input[2]);
            return (0);
        }
    }
    if (add_item_2(fridge, input) == 0)
        printf("'%s': Invalid operation\n", buff);
    return (0);
}
