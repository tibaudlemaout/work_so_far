/*
** EPITECH PROJECT, 2022
** modified strlen
** File description:
** for bsq
*/
#include "../bsq.h"

int bsq_strlen(char const *str)
{
    int length = 0;

    while (str[length] != '\n'){
        length ++;
    }
    return (length);
}
