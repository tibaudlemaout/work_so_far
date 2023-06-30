/*
** EPITECH PROJECT, 2022
** my_putchar
** File description:
** write
*/

#include <unistd.h>
#include "duo.h"

int my_putchar(char c)
{
    write(1, &c, 1);
}
