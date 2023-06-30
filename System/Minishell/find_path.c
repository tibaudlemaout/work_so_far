/*
** EPITECH PROJECT, 2023
** Semester_2
** File description:
** find_path
*/
#include "./include/struct.h"
#include "./include/minishell_1.h"

int is_builtin(global_t *data)
{
    builtin_t builtin [] = {
        {"cd", "change_directory", &new_cd},
        {"exit", "exit_mysh", &new_exit},
        {"env", "display env", &new_env},
        {"setenv", "set environment", &new_setenv},
        {"unsetenv", "unset environment", &new_unsetenv},
        {0, 0, 0}
    };

    for (int i = 0; builtin[i].name != 0; i++) {
        if (my_strcmp(data->tab[0], builtin[i].name) == 0) {
            builtin[i].f_builtin(data);
            return (1);
        }
    }
    return (0);
}

int path_or_absolute(global_t *data)
{
    int index = 0;

    while (data->tab[0][index] != '\0') {
        if (data->tab[0][index] == '/') {
            return (1);
        }
        index ++;
    }
    return (0);
}

int set_path_buff(char *path, char *exec, global_t *data)
{
    int size = my_strlen(exec) + my_strlen(path);
    int index = 0;
    int buff_index = 0;
    data->path_buff = malloc(sizeof(char) * size + 1);

    while (path[index] != '\0') {
        data->path_buff[buff_index] = path[index];
        buff_index ++;
        index ++;
    }
    data->path_buff[buff_index] = '/';
    buff_index += 1;
    index = 0;
    while (exec[index] != '\0') {
        data->path_buff[buff_index] = exec[index];
        buff_index ++;
        index ++;
    }
    return (0);
}

int going_in_path(global_t *data, int index, int found)
{
    if (data->c_env == NULL) {
        create_own_path(data, index, found);
        return (0);
    }
    while (data->c_path[index] != NULL) {
        set_path_buff(data->c_path[index], data->tab[0], data);
        found = access(data->path_buff, F_OK);
        if (found == 0) {
            access(data->path_buff, X_OK);
            handle_child(data, data->path_buff);
            return (1);
        }
        index ++;
    }
    my_printf("%s: Command not found.\n", data->tab[0]);
    return (0);
}

int search_in_path(global_t *data)
{
    int index = 1;
    int found = 0;

    if (path_or_absolute(data) == 0) {
        if (going_in_path(data, index, found) == 1)
            return (1);
    }
    return (0);
}
