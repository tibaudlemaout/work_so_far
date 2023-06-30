/*
** EPITECH PROJECT, 2023
** Paint
** File description:
** lib
*/
#include <unistd.h>

void my_putchar(char c)
{
    write(1, &c, 1);
}

int my_putstr(char const *str)
{
    for (int i = 0; str[i] != '\0'; i++)
        my_putchar(str[i]);
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
