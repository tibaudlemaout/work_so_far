/*
** EPITECH PROJECT, 2023
** Semester_2
** File description:
** setenv
*/
#include "../include/struct.h"
#include "../include/minishell_1.h"

int empty_env_data(global_t *data, char *env_name, int env_idx)
{
    int index = 0;
    data->c_env[env_idx] = NULL;
    data->c_env[env_idx] = malloc(sizeof(char) * (my_strlen(env_name) + 2));

    while (env_name[index] != '\0') {
        data->c_env[env_idx][index] = env_name[index];
        index ++;
    }
    index ++;
    data->c_env[env_idx][index] = '=';
    data->c_env[env_idx][index + 1] = '\0';
    return (0);
}

int change_env_data(global_t *data, int env_idx, char *env_name)
{
    int index = 0;
    int size = (my_strlen(env_name) + (my_strlen(data->tab[2]) + 2));
    data->c_env[env_idx] = NULL;
    data->c_env[env_idx] = malloc(sizeof(char) * size);

    while (env_name[index] != '\0') {
        data->c_env[env_idx][index] = env_name[index];
        index ++;
    }
    data->c_env[env_idx][index] = '=';
    index += 1;
    for (int i = 0; data->tab[2][i] != '\0'; i ++) {
        data->c_env[env_idx][index] = data->tab[2][i];
        index ++;
    }
    data->c_env[env_idx][index + 1] = '\0';
    return (0);
}

int check_env_name(global_t *data, char *env_name, int env_index, int argc)
{
    int size = 0;
    char *cur_env_name;

    while (data->c_env[env_index][size] != '=')
        size ++;
    cur_env_name = malloc(sizeof(char) * (size + 1));
    for (int i = 0; data->c_env[env_index][i] != '='; i ++)
        cur_env_name[i] = data->c_env[env_index][i];
    if (my_strcmp(cur_env_name, env_name) == 0) {
        if (argc == 2)
            empty_env_data(data, env_name, env_index);
        if (argc == 3)
            change_env_data(data, env_index, env_name);
        return (1);
    }
    return (0);
}

int create_env_name(global_t *data, int argc)
{
    int index = 0;
    int e_index = 0;
    int size_en = my_strlen(data->tab[1]);
    char *env_name = malloc(sizeof(char) * (size_en));

    while (data->tab[1][index] != '\0') {
        env_name[index] = data->tab[1][index];
        index ++;
    }
    env_name[index + 1] = '\0';
    while (data->c_env[e_index] != NULL) {
        if (check_env_name(data, env_name, e_index, argc) == 1)
            return (0);
        e_index ++;
    }
    create_new_env(data, env_name, argc);
    free(env_name);
    return (0);
}

int new_setenv(global_t *data)
{
    int argc = 0;

    while (data->tab[argc] != NULL)
        argc ++;
    if (argc > 3) {
        my_putstr("setenv: Too many arguments\n");
        return (0);
    }
    if (data->c_env == NULL)
        return (0);
    if (argc == 1) {
        for (int q = 0; data->c_env[q] != NULL; q ++)
            my_printf("%s\n", data->c_env[q]);
        return (0);
    }
    create_env_name(data, argc);
    return (0);
}
