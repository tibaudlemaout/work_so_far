/*
** EPITECH PROJECT, 2023
** Paint
** File description:
** lib
*/
#include "../include/my.h"

int my_putstr(char const *str)
{
    for (int i = 0; str[i] != '\0'; i++)
        write(1, &str[i], 1);
    return 0;
}

int my_strlen(char const *str)
{
    int cmp = 0;

    for (int i = 0; str[i]; i++)
        cmp++;
    return (cmp);
}

int my_strcmp(const char *s1, const char *s2)
{
    if (my_strlen(s1) != my_strlen(s2))
        return 1;
    for (int i = 0; s1[i]; i++) {
        if (s1[i] != s2[i])
            return 1;
    }
    return 0;
}

int my_get_nbr(int i, char *str)
{
    long nb = 0;
    int is_neg = 0;

    for (i; str[i] != '\n' && str[i] != '\0'; i++) {
        if (str[i] == '-')
            is_neg = 1;
        if (str[i] >= '0' && str[i] <= '9') {
            nb *= 10;
            nb += str[i] - 48;
        }
    }
    if (nb < -2147483648 || nb > 2147483647)
        return (0);
    if (is_neg == 1)
        return (-nb);
    return nb;
}

char *nbr_to_str(int nb)
{
    int i = 0;
    int cmp = 0;
    char *str;

    for (int cpy = nb; cpy != 0; cpy /= 10)
        cmp++;
    str = malloc(sizeof(char) * (cmp + 1));
    for (int i = cmp - 1; i >= 0; i--) {
        str[i] = (nb % 10) + 48;
        nb /= 10;
    }
    str[cmp] = '\0';
    return str;
}
