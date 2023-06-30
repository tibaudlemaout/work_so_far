/*
** EPITECH PROJECT, 2023
** Semester_2
** File description:
** unsetenv
*/
#include "../include/struct.h"
#include "../include/minishell_1.h"

int remove_env(global_t *data, int i)
{
    data->c_env[i] = NULL;
    return (0);
}

int env_already_exist(global_t *data, char *env_name, int env_index)
{
    int index = 0;
    char *cur_env_name;

    while (data->c_env[env_index][index] != '=')
        index ++;
    cur_env_name = malloc(sizeof(char) * (index + 1));
    for (int i = 0; data->c_env[env_index][i] != '='; i ++)
        cur_env_name[i] = data->c_env[env_index][i];
    if (my_strcmp(cur_env_name, env_name) == 0) {
        remove_env(data, env_index);
    }
    return (0);
}

int verif_env_name(global_t *data, char *env_name)
{
    int env_idx = 0;

    while (data->c_env[env_idx] != NULL) {
        env_already_exist(data, env_name, env_idx);
        env_idx ++;
    }
    return (0);
}

int copy_env_name(global_t *data, char *env_name)
{
    int size = 0;
    int index = 0;
    int env_idx = 1;

    while (data->tab[env_idx] != NULL) {
        size = my_strlen(data->tab[env_idx]);
        index = 0;
        env_name = malloc(sizeof(char) * (size + 1));
        while (data->tab[env_idx][index] != '\0') {
            env_name[index] = data->tab[env_idx][index];
            index ++;
        }
        if (data->c_env != NULL)
            verif_env_name(data, env_name);
        free(env_name);
        env_idx ++;
    }
    return (0);
}

int new_unsetenv(global_t *data)
{
    char *env_name = NULL;
    int index = 0;

    while (data->tab[index] != NULL)
        index ++;
    if (index == 1) {
        my_putstr("unsetenv: Too few arguments\n");
        return (0);
    }
    copy_env_name(data, env_name);
    return (0);
}
