/*
** EPITECH PROJECT, 2023
** Semester_2
** File description:
** main
*/
#include "../include/dante.h"
#include "../include/struct.h"

void retrieve_size(global_t *data, int argc, char **argv)
{
    int index = 0;
    data->length = atoi(argv[1]);
    data->layers = atoi(argv[2]);
    data->tab = malloc(sizeof(char *) * data->layers);
    for (int q = 0; q <= data->layers; q ++) {
        data->tab[q] = malloc(sizeof(char) * data->length);
        for (int i = 0; i < data->length; i ++) {
            data->tab[q][i] = '*';
        }
    }
    return;
}

void free_tab(global_t *data)
{
    free(data->tab);
    return;
}

void create_passage(global_t *data, int index, int argc)
{
    if (argc == 3) {
        int hole_pos1 = (rand() % data->length);
        int hole_pos2 = (rand() % data->length);
        int hole_pos3 = (rand() % data->length);
        data->tab[index][hole_pos1] = '*';
        data->tab[index][hole_pos2] = '*';
        data->tab[index][hole_pos3] = '*';
    }
    if (argc == 4) {
        int hole_pos = (rand() % data->length);
        if (index != data->layers - 1)
            data->tab[index][hole_pos] = '*';
    }
    return;
}

void set_walls(global_t *data, int argc)
{
    int index = 0;

    if (argc == 4)
        index = 1;
    else
        index = (rand() % 1);

    while (index <= (data->layers - 1)) {
        for (int i = 0; i < data->length; i ++) {
            data->tab[index][i] = 'X';
        }
        create_passage(data, index, argc);
        index += 2;
    }
    data->tab[0][0] = '*';
    data->tab[data->layers - 1][data->length - 1] = '*';
    return;
}

int main(int argc, char **argv)
{
    global_t data;

    if (error_handling_gen(argc, argv) == 84)
        return (84);
    retrieve_size(&data, argc, argv);
    set_walls(&data, argc);
    display_gen_map(&data);
    free_tab(&data);
    return (0);
}
