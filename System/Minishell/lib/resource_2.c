/*
** EPITECH PROJECT, 2023
** Semester_2
** File description:
** resource_2
*/
#include "../include/minishell_1.h"

char *my_strdup(char *str)
{
    int i = 0;
    int size = my_strlen(str);
    char *dup = malloc(sizeof(char) * (size + 1));

    while (i < size) {
        dup[i] = str[i];
        i++;
    }
    dup[i] = '\0';
    return (dup);
}

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
        index ++;
    }
    return (0);
}
