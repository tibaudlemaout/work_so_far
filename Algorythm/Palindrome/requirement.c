/*
** EPITECH PROJECT, 2023
** B-SYN-200-NAN-2-1-palindrome-tibaud.le-maout
** File description:
** requirement
*/
#include <stdio.h>

int my_factrec_synthesis(int nb)
{
    int result = 0;

    if (nb < 0 || nb > 12 || nb > 2147483647) {
        return (0);
    }
    if (nb == 1 || nb == 0) {
        return (1);
    }
    result = my_factrec_synthesis(nb - 1) * nb;
    return (result);
}

int my_squareroot_synthesis(int nb)
{
    float sum = 1;
    int i = 1;

    if (nb < 0 || nb > 2147483647)
        return (-1);
    if (nb == 0 || nb == 1)
        return (nb);
    while (sum < nb) {
        i++;
        sum = i * i;
    }
    if ((i * i) != nb)
        return (-1);
    return (i);
}
