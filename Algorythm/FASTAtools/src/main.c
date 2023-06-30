/*
** EPITECH PROJECT, 2023
** base_layout
** File description:
** main
*/
#include "../include/fastatools.h"

static void init_data(global_t *data, char **argv)
{
    data->option = atoi(argv[1]);
    data->k = 0;
    data->tab = NULL;
    data->seq = NULL;
    data->string = NULL;
    return;
}

static void options_cont(global_t *data)
{
    switch (data->option) {
    case 6:
        option_6(data);
        break;
    case 7:
        option_7(data);
        break;
    }
    return;
}

static void options(global_t *data)
{
    switch (data->option) {
    case 1:
        option_1(data);
        break;
    case 2:
        option_2(data);
        break;
    case 3:
        option_3(data);
        break;
    case 4:
        option_4(data);
        break;
    case 5:
        option_5(data);
        break;
    }
    return;
}

static void free_all(global_t *data)
{
    if (data->string)
        free(data->string);
    if (data->tab) {
        for (int i = 0; data->tab[i]; i++)
            free(data->tab[i]);
        free(data->tab);
    }
    return;
}

int main(int argc, char **argv)
{
    global_t data;

    if (argc == 1)
        exit(84);
    init_data(&data, argv);
    error_handling(&data, argc, argv);
    get_input(&data);
    options(&data);
    options_cont(&data);
    free_all(&data);
    return (0);
}
