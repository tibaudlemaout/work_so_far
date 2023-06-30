/*
** EPITECH PROJECT, 2023
** EPITECH
** File description:
** Step_4
*/
#include "./include/minishell_1.h"
#include "./include/struct.h"

void copy_env(global_t *data, char **env)
{
    int y = 0;
    int i = 0;

    if (env[0] == NULL)
        return;
    while (env[y] != NULL)
        y ++;
    data->c_env = malloc(sizeof(char *) * (y + 2));
    for (int q = 0; env[q] != NULL; q ++) {
        data->c_env[q] = malloc(sizeof(char) * (my_strlen(env[q]) + 1));
        while (env[q][i] != '\0') {
            data->c_env[q][i] = env[q][i];
            i++;
        }
        data->c_env[q][i] = '\0';
        i = 0;
    }
    data->c_env[y + 1] = NULL;
}

void prepare_input(global_t *data, char *buff, char **env)
{
    get_path(data, env);
    print_arg(buff, data);
    return;
}

void shell_loop(global_t *data, char *buff, size_t *size)
{
    int ret = 0;

    if (isatty(0))
        my_printf("$> ");
    if (getline(&buff, size, stdin) < 0) {
        my_printf("exit\n");
        exit(0);
    }
    prepare_input(data, buff, data->c_env);
    if (is_builtin(data) == 0) {
        if (search_in_path(data) == 0) {
            handle_child(data, data->tab[0]);
        }
    }
    return;
}

void init_data(global_t *data)
{
    data->tab = NULL;
    data->c_env = NULL;
    data->c_path = NULL;
    data->path_buff = NULL;
    data->pwd = NULL;
    data->oldpwd = NULL;
    return;
}

int main(int argc, char **argv, char **env)
{
    global_t data;
    char *buff = NULL;
    size_t size = 10;

    if (argc != 1)
        return (84);
    init_data(&data);
    copy_env(&data, env);
    while (1) {
        buff = (char *)malloc(size * sizeof(char));
        shell_loop(&data, buff, &size);
    }
    free_c_env(&data);
    free(data.tab);
    return (0);
}
