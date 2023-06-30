/*
** EPITECH PROJECT, 2023
** Semester_2
** File description:
** copy_path
*/
#include "./include/struct.h"
#include "./include/minishell_1.h"

void path_in_tab(global_t *data, const char *path, int layers)
{
    int index = 0;
    int y = 0;
    int x = 0;

    data->c_path = malloc(sizeof(char *) * layers + 1);
    for (int q = 0;  q <= layers; q ++)
        data->c_path[q] = malloc(sizeof(char) * my_strlen(path));
    while (path[index] != '\0') {
        data->c_path[y][x] = path[index];
        index ++;
        x ++;
        if (path[index] == ':' || index == 5) {
            data->c_path[y][x] = '\0';
            y ++;
            x = 0;
            index ++;
        }
    }
    data->c_path[y + 1] = NULL;
    return;
}

void copy_path(global_t *data, char *path)
{
    int size = 0;
    int layers = 1;
    int index = 0;

    if (path == NULL)
        return;
    while (path[index] != '\0') {
        if (path[index] == ':') {
            layers ++;
        }
        index ++;
    }
    path_in_tab(data, path, layers);
    return;
}

void get_path(global_t *data, char **env)
{
    int index = 0;

    if (data->c_env == NULL)
        return;
    while (env[index] != NULL) {
        if (env[index][0] == 'P' && env[index][1] == 'A' &&
        env[index][2] == 'T' && env[index][3] == 'H' &&
        env[index][4] == '=') {
            copy_path(data, env[index]);
            return;
        }
        index ++;
    }
    return;
}
