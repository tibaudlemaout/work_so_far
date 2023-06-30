/*
** EPITECH PROJECT, 2023
** Semester_2
** File description:
** env
*/
#include "../include/struct.h"
#include "../include/minishell_1.h"

int new_env(global_t *data)
{
    int index = 0;

    if (data->c_env == NULL)
        return (0);
    while (data->c_env[index] != NULL) {
        my_printf("%s\n", data->c_env[index]);
        index ++;
    }
    return (0);
}
