/*
** EPITECH PROJECT, 2023
** Semester_2
** File description:
** free_all
*/
#include "./include/struct.h"
#include "./include/minishell_1.h"

void free_tab(global_t *data, char *buff)
{
    for (int i = 0;data->tab[i] != NULL; i++)
        free(data->tab[i]);
    return;
}

void free_c_env(global_t *data)
{
    int index = 0;

    if (data->c_env == NULL)
        return;
    while (data->c_env[index] != NULL) {
        free(data->c_env[index]);
        index ++;
    }
    return;
}

void free_path(global_t *data)
{
    for (int i = 0; data->c_path[i]; i++)
        free(data->c_path[i]);
    return;
}
