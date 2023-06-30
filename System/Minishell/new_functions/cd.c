/*
** EPITECH PROJECT, 2023
** Semester_2
** File description:
** cd
*/
#include "../include/struct.h"
#include "../include/minishell_1.h"

char *cd_path(global_t *data, char *pwd, size_t size, int err)
{
    if (data->tab[1][0] == '/') {
        data->oldpwd = NULL;
        data->oldpwd = getcwd(data->oldpwd, size);
        pwd = retrieve_tab_1(data, pwd);
        err = chdir(pwd);
        if (err != 0)
            my_printf("%s: Not a directory.\n", data->tab[1]);
    }
    return (pwd);
}

char *cd_previous(global_t *data, char *pwd, size_t size, int err)
{
    if (data->tab[1][0] == '.' && data->tab[1][1] == '.') {
        data->oldpwd = NULL;
        data->oldpwd = getcwd(data->oldpwd, size);
        pwd = getcwd(pwd, size);
        pwd = pre_dir(data, pwd);
        err = chdir(pwd);
        if (err != 0)
            perror(pwd);
    }
    return (pwd);
}

char *cd_return(global_t *data, char *pwd, size_t size, int err)
{
    if (data->tab[1][0] == '-') {
        pwd = my_strcpy(pwd, data->oldpwd);
        data->oldpwd = NULL;
        data->oldpwd = getcwd(data->oldpwd, size);
        err = chdir(pwd);
        if (err != 0)
            perror(pwd);
    }
    return (pwd);
}

int new_cd(global_t *data)
{
    char *pwd = NULL;
    int err = 0;
    size_t size = 0;

    if (data->tab[1] == NULL) {
        data->oldpwd = NULL;
        data->oldpwd = getcwd(data->oldpwd, size);
        pwd = retrieve_home(data, pwd);
        err = chdir(pwd);
        return (0);
    }
    pwd = cd_path(data, pwd, size, err);
    pwd = cd_previous(data, pwd, size, err);
    pwd = cd_return(data, pwd, size, err);
    free(pwd);
    return (0);
}
