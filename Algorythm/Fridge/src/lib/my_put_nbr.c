/*
** EPITECH PROJECT, 2022
** my_put_nbr
** File description:
** task07
*/

#include "duo.h"

static int transform_positif(int number)
{
    int modulo = 10;
    int compteur = 1;
    int compt;
    int charactere;

    while (number % modulo != number) {
        compteur++;
        modulo = modulo * 10;
    }
    modulo = modulo / 10;
    for (compt = compteur ; compt > 0 ; compt--) {
        charactere = number / modulo;
        my_putchar(charactere + 48);
        number = number - modulo * charactere;
        modulo = modulo / 10;
    }
    return (0);
}

static int transform_negatif(int number)
{
    int modulo = -10;
    int compteur = 1;
    int compt;
    int charactere;

    while (number % modulo != number) {
        compteur++;
        modulo = modulo * 10;
    }
    modulo = modulo / 10;
    for (compt = compteur ; compt > 0 ; compt--) {
        charactere = number / modulo;
        my_putchar(charactere + 48);
        number = number - modulo * charactere;
        modulo = modulo / 10;
    }
    return (0);
}

int my_put_nbr(int number)
{
    if (number >= 0) {
        transform_positif(number);
    } else {
        my_putchar('-');
        transform_negatif(number);
    }
    return (0);
}
