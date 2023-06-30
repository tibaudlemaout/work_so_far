/*
** EPITECH PROJECT, 2023
** stumper
** File description:
** to make pasta
*/

#include "duo.h"
#include <unistd.h>
#include <stdio.h>

static int rmv_pasta(fridge_t *fridge)
{
    fridge->tomato -= 5;
    fridge->pasta -= 2;
    fridge->olive -= 6;
    fridge->ham -= 3;
    fridge->cheese -= 4;
    return (0);
}

static int make_pasta_2(fridge_t *fridge, char *buff, int cook)
{
    if (fridge->olive < 6) {
        printf("'%s': not enough olive\n", buff);
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

int make_pasta(fridge_t *fridge, char *buff)
{
    int cook = 1;

    if (fridge->tomato < 5) {
        printf("'%s': not enough tomato\n", buff);
        cook = 0;
    }
    if (fridge->pasta < 2) {
        printf("'%s': not enough pasta\n", buff);
        cook = 0;
    }
    cook = make_pasta_2(fridge, buff, cook);
    if (cook == 1)
        rmv_pasta(fridge);
    return (0);
}
