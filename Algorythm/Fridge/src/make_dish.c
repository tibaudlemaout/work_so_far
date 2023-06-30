/*
** EPITECH PROJECT, 2023
** stumper
** File description:
** when make option
*/

#include "duo.h"
#include <stdio.h>
#include <unistd.h>

static int rmv_pizza(fridge_t *fridge)
{
    fridge->tomato -= 5;
    fridge->dough -= 1;
    fridge->onion -= 3;
    fridge->olive -= 8;
    fridge->pepper -= 8;
    fridge->ham -= 4;
    fridge->cheese -= 3;
    return (0);
}

static int make_pizza_2(fridge_t *fridge, char *buff, int cook)
{
    if (fridge->olive < 8) {
        printf("'%s': not enough olive\n", buff);
        cook = 0;
    }
    if (fridge->pepper < 8) {
        printf("'%s': not enough pepper\n", buff);
        cook = 0;
    }
    if (fridge->ham < 4) {
        printf("'%s': not enough ham\n", buff);
        cook = 0;
    }
    if (fridge->cheese < 3) {
        printf("'%s': not enough cheese\n", buff);
        cook = 0;
    }
    return (cook);
}

static int make_pizza(fridge_t *fridge, char *buff)
{
    int cook = 1;

    if (fridge->tomato < 5) {
        printf("'%s': not enough tomato\n", buff);
        cook = 0;
    }
    if (fridge->dough < 1) {
        printf("'%s': not enough dough\n", buff);
        cook = 0;
    }
    if (fridge->onion < 3) {
        printf("%s: not enough onion\n", buff);
        cook = 0;
    }
    cook = make_pizza_2(fridge, buff, cook);
    if (cook == 1)
        rmv_pizza(fridge);
    return (0);
}

int make_meal(char **input, fridge_t *fridge, char *buff)
{
    if (my_strcmp(input[1], "pasta") == 0) {
        make_pasta(fridge, buff);
        return (0);
    }
    if (my_strcmp(input[1], "pizza") == 0) {
        make_pizza(fridge, buff);
        return (0);
    }
    printf("'%s': meal unknown\n", input[1]);
    return (0);
}
