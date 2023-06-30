/*
** EPITECH PROJECT, 2023
** duo
** File description:
** parse_file
*/

#include "duo.h"
#include "sys/stat.h"

int parse_file(fridge_t *fridge)
{
    struct stat s;

    if (stat(".save", &s) == -1) {
        init_default(fridge);
        return 0;
    }
    return 0;
}
