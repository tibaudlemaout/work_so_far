/*
** EPITECH PROJECT, 2022
** resource for miniprintf
** File description:
** for compilation
*/
#include <unistd.h>
#include "../pushswap.h"

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
    while (nb != 0 || div > 1){
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

char *my_revstr(char *str)
{
    int length = my_strlen(str);
    int middle = length / 2;
    char temp;

    for (int i = 0; i < middle; i++){
        temp = str[i];
        str[i] = str[length - i - 1];
        str[length - i -1] = temp;
    }
    my_putstr(str);
    return (0);
}
