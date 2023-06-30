/*
** EPITECH PROJECT, 2022
** EPITECH
** File description:
** my_get_nbr
*/
#include "../pushswap.h"

int my_get_nbr(char *str)
{
    int nb = 0;
    int neg = 1;
    int index = 0;

    while (str[index] != '\0') {
        if (str[index] >= '0' && str[index] <= '9') {
            nb = nb + (str[index] - 48);
            nb = nb * 10;
        }
        index ++;
    }
    index = 0;
    while (str[index] == '-' || str[index] == '+') {
        if (str[index] == '-') {
            neg = neg * -1;
        }
    }

    nb = nb * neg;
    return (nb);
}
