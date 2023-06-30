/*
** EPITECH PROJECT, 2023
** duo
** File description:
** my_save
*/

#include "duo.h"

static int my_save_2(fridge_t *fridge, int fd)
{
    write(fd, "\npepper = ", 10);
    write(fd, fridge->pepper, sizeof(fridge->pepper));
    write(fd, "\nham = ", 7);
    write(fd, fridge->ham, sizeof(fridge->ham));
    write(fd, "\ncheese = ", 10);
    write(fd, fridge->cheese, sizeof(fridge->cheese));    
    return (0);
}

int my_save(fridge_t *fridge)
{
    FILE *fd = fopen(".save", "w");

    if (!fd)
        return 84;
    write(fd, "tomato = ", 9);
    write(fd, fridge->tomato, sizeof(fridge->tomato));
    write(fd, "\ndough = ", 9);
    write(fd, fridge->dough, sizeof(fridge->dough));
    write(fd, "\nonion = ", 9);
    write(fd, fridge->onion, sizeof(fridge->onion));
    write(fd, "\npasta = ", 9);
    write(fd, fridge->pasta, sizeof(fridge->pasta));
    write(fd, "\nolive = ", 9);
    write(fd, fridge->olive, sizeof(fridge->olive));
    my_save_2(fridge, fd);
    return (0);
}
