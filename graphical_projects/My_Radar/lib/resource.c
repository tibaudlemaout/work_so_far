/*
** EPITECH PROJECT, 2022
** resource for miniprintf
** File description:
** for compilation
*/
#include <unistd.h>
#include "../include/radar.h"

void my_putchar(char c)
{
    write(1, &c, 1 );
}

int my_strlen(char const *str)
{
    int length = 0;

    while (str[length] != '\0'){
        length ++;
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
    if (nb == 0)
        my_putchar('0');
    while (nb / div >= 10){
        div = div * 10;
    }
    while (nb != 0){
        my_putchar (nb / div + 48);
        nb = (nb % div);
        div = (div / 10);
        }
    return (0);
}

int my_putstr(char const *str)
{
    int i = 0;

        while (str[i] != '\0' ){
            my_putchar(str[i]);
            i ++;
        }
        return (0);
}

int my_get_nbr(global_t *data)
{
    int nb = 0;

    while (data->tab[data->tab_y][data->tab_x] != '\0' &&
        data->tab[data->tab_y][data->tab_x] != ' ' &&
        data->tab[data->tab_y][data->tab_x] != '\n'){
        if (data->tab[data->tab_y][data->tab_x] == '-'){
            nb = (nb * -1);
        }
        if (data->tab[data->tab_y][data->tab_x] >= '0' &&
            data->tab[data->tab_y][data->tab_x] <= '9'){
            nb = nb * 10;
            nb = nb + (data->tab[data->tab_y][data->tab_x] - 48);
        }
        data->tab_x ++;
    }
    return (nb);
}
