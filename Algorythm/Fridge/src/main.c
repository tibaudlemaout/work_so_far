/*
** EPITECH PROJECT, 2023
** duo
** File description:
** main
*/

#include "duo.h"

int main(int ac, char **av)
{
    fridge_t fridge = {0, 0, 0, 0, 0, 0, 0, 0};

    if (ac != 1)
        return 84;
    if (parse_file(&fridge) == 84)
        return 84;
    fridge_loop(&fridge);
    return 0;
}
