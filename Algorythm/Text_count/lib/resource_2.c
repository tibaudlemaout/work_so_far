/*
** EPITECH PROJECT, 2023
** Semester_2
** File description:
** resource_2
*/
#include "../include/lib.h"

int my_strcmp(char *str1, char *str2)
{
    int index = 0;
    int size1 = my_strlen(str1);
    int size2 = my_strlen(str2);

    if (size1 != size2)
        return (1);
    while (index != size1) {
        if (str1[index] != str2[index])
            return (1);
        index++;
    }
    return (0);
}

char *my_strcpy(char *dest, char const *src)
{
    int i;

    for (i = 0; src[i] != '\0'; i++) {
        dest[i] = src[i];
        my_putchar(dest[i]);
    }
    dest[i] = '\0';
    return (dest);
}
