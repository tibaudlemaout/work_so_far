/*
** EPITECH PROJECT, 2022
** resource for miniprintf
** File description:
** for compilation
*/
#include <unistd.h>
#include "../include/lib.h"

void my_putchar(char c)
{
    write(1, &c, 1 );
}

int my_strlen(char const *str)
{
    int length = 0;

    while (str[length] != '\0') {
        length++;
    }
    return (length);
}

int my_put_nbr(int nb)
{
    int div = 1;

    if (nb < 0){
        my_putchar ('-');
        nb = (nb * -1);
    }
    while (nb / div >= 10) {
        div = div * 10;
    }
    while (nb != 0 || div > 0) {
        my_putchar (nb / div + 48);
        nb = (nb % div);
        div = (div / 10);
        }
    return (0);
}

int my_putstr(char const *str)
{
    int i = 0;

        while (str[i] != '\0' ) {
            my_putchar(str[i]);
            i++;
        }
        return (0);
}

int my_get_nbr(char *str)
{
    int nb = 0;
    int neg = 1;
    int index = 0;

    while (str[index] != '\0') {
        if (str[index] >= '0' && str[index] <= '9') {
            nb *= 10;
            nb += str[index] - 48;
        }
        index++;
    }
    index = 0;
    while (str[index] == '-' || str[index] == '+') {
        if (str[index] == '-') {
            neg = (neg * -1);
        }
    }
    nb = (nb * neg);
    return (nb);
}
