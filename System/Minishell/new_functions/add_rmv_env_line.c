/*
** EPITECH PROJECT, 2023
** EPITECH
** File description:
** add_rmv_env_line
*/
#include "../include/struct.h"
#include "../include/minishell_1.h"

char *new_env_line(global_t *data, char *new_line, char *env_name, int argc)
{
    int index = 0;
    int size = my_strlen(env_name);

    if (argc == 2) {
        new_line = malloc(sizeof(char) * (size + 1));
        while (env_name[index] != '\0') {
            new_line[index] = env_name[index];
            index ++;
        }
        new_line[index] = '=';
        index ++;
        new_line[index] = '\0';
    }
    return (new_line);
}

void free_old_tmp_env(global_t *data, char **temp_env)
{
    free_c_env(data);
    copy_env(data, temp_env);
    for (int i = 0; temp_env[i] != NULL; i ++)
        free(temp_env[i]);
    return;
}

int create_new_env(global_t *data, char *env_name, int argc)
{
    int y = 0;
    int i = 0;
    char **temp_env;

    while (data->c_env[y] != NULL)
        y ++;
    temp_env = malloc(sizeof(char *) * (y + 1));
    for (int q = 0; data->c_env[q] != NULL; q ++) {
        temp_env[q] = malloc(sizeof(char) * my_strlen(data->c_env[q]));
        while (data->c_env[q][i] != '\0') {
            temp_env[q][i] = data->c_env[q][i];
            i ++;
        }
        temp_env[q][i] = '\0';
        i = 0;
    }
    temp_env[y] = new_env_line(data, temp_env[y + 1], env_name, argc);
    temp_env[y + 1] = NULL;
    free_old_tmp_env(data, temp_env);
    return (0);
}
