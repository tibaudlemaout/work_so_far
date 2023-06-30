/*
** EPITECH PROJECT, 2023
** B-SYN-200-NAN-2-1-palindrome-tibaud.le-maout
** File description:
** base_calc
*/
#include "../include/palindrome.h"

static int calc_power(int nb, int p)
{
    int result = 1;
    int power = p;

    while (power != 0) {
        result *= nb;
        power--;
    }
    return (result);
}

void decimal_conv(global_t *data)
{
    int power = strlen(data->rev_n_str) - 1;
    int result = 0;
    int result2 = 0;
    int tmp = 0;
    int tmp2 = 0;
    int i = 0;

    while (data->rev_based_str[i] != '\0' && power >= 0) {
        tmp = calc_power(data->base, power);
        result += ((data->rev_n_str[i] - '0') * tmp);
        tmp2 = calc_power(data->base, power);
        result2 += ((data->n_str[i] - '0') * tmp2);
        power--;
        i++;
    }
    data->rev_n = result;
    data->n = result2;
    return;
}
