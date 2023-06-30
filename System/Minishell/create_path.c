/*
** EPITECH PROJECT, 2023
** B-PSU-200-NAN-2-1-minishell1-tibaud.le-maout
** File description:
** create_path
*/
#include "./include/struct.h"
#include "./include/minishell_1.h"

void create_path(global_t *data)
{
    data->c_path = malloc (sizeof(char *) * 6);
    data->c_path[0] = "/usr/local/bin";
    data->c_path[1] = "/usr/bin";
    data->c_path[2] = "/bin";
    data->c_path[3] = "/usr/local/sbin";
    data->c_path[4] = "/usr/sbin";
    data->c_path[5] = NULL;
    return;
}

int create_own_path(global_t *data, int index, int found)
{
    create_path(data);
    for (int index = 0 ;data->c_path[index] != NULL; index++) {
        set_path_buff(data->c_path[index], data->tab[0], data);
        found = access(data->path_buff, F_OK);
        if (found == 0) {
            access(data->path_buff, X_OK);
            handle_child(data, data->path_buff);
            return (1);
            }
        }
    my_printf("%s: Command not found.\n", data->tab[0]);
    return (0);
}
