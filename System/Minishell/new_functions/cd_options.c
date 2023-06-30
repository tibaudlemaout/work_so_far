/*
** EPITECH PROJECT, 2023
** B-PSU-200-NAN-2-1-minishell1-tibaud.le-maout
** File description:
** cd_options
*/
#include "../include/struct.h"
#include "../include/minishell_1.h"

char *home_dir(char *home, char *pwd)
{
    int idx = 0;
    pwd = malloc(sizeof(char *) * (my_strlen(home) - 4));

    for (int i = 5; home[i] != '\0'; i++) {
        pwd[idx] = home[i];
        idx++;
    }
    pwd[idx + 1] = '\0';
    return (pwd);
}

char *retrieve_home(global_t *data, char *pwd)
{
    int i = 0;

    if (data->c_env == NULL) {
        my_printf("%s: No home directory.\n", data->tab[0]);
        return (NULL);
    }
    for (int q = 0; data->c_env[q] != NULL; q++) {
        if (data->c_env[q][0] == 'H' && data->c_env[q][1] == 'O' &&
            data->c_env[q][2] == 'M' && data->c_env[q][3] == 'E') {
            pwd = home_dir(data->c_env[q], pwd);
            return (pwd);
        }
    }
    return (NULL);
}

char *retrieve_tab_1(global_t *data, char *pwd)
{
    int i = 0;
    pwd = malloc(sizeof(char *) * (strlen(data->tab[1]) + 1));

    while (data->tab[1][i] != '\0') {
        pwd[i] = data->tab[1][i];
        i++;
    }
    pwd[i + 1] = '\0';
    return (pwd);
}

char *pre_dir(global_t *data, char *pwd)
{
    int size = my_strlen(pwd);

    while (pwd[size] != '/') {
        size--;
    }
    pwd[size] = '\0';
    return (pwd);
}
