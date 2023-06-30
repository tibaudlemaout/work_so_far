/*
** EPITECH PROJECT, 2023
** B-SYN-200-NAN-2-1-FASTAtools-tibaud.le-maout
** File description:
** testing
*/
#include "include/fastatools.h"

char *my_test(char *str)
{
    for (int i = 0; str[i]; i++) {
        if (i == 0 && str[i] >= 97 && str[i] <= 122)
            str[i] = str[i] - 32;
        if (i > 0 && (str[i] >= 97 && str[i] <= 122) && (str[i - 1] < 65) &&
            (str[i - 1] > '9' || str[i - 1] < '0'))
            str[i] = str[i] - 32;
        if (i > 0 && (str[i - 1] >= 65 && str[i - 1] <= 90) &&
            (str[i] >= 65 && str[i] <= 90))
            str[i] = str[i] + 32;
    }
    printf("%s", str);
    return (str);
}

int calling_test(int a, int b, char *str)
{
    int c = a + b;

    my_test(str);
    fflush(stdout);
    return (c);
}

int main(int ac, char **av)
{
    char *str = malloc(sizeof(char) * strlen("hello world"));
    char *str2 = "hello world";

    str = strdup(str2);
    calling_test(1,2, str);
    return (0);
}
