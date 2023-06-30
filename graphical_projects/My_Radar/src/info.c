/*
** EPITECH PROJECT, 2023
** EPITECH
** File description:
** info
*/
#include "../include/radar.h"


void get_plane_data(global_t *data)
{
    data->tab_x = 1;
    while (data->tab[data->tab_y][data->tab_x] == ' ')
        data->tab_x ++;
    data->px_str = my_get_nbr(data);
    data->tab_x = data->tab_x + 1;
    data->py_str = my_get_nbr(data);
    while (data->tab[data->tab_y][data->tab_x] == ' ')
        data->tab_x ++;
    data->px_end = my_get_nbr(data);
    data->tab_x = data->tab_x + 1;
    data->py_end = my_get_nbr(data);
    while (data->tab[data->tab_y][data->tab_x] == ' ')
        data->tab_x ++;
    data->p_spd = my_get_nbr(data);
    while (data->tab[data->tab_y][data->tab_x] == ' ')
        data->tab_x ++;
    data->p_take_off = my_get_nbr(data);
    return;
}

void get_tower_data(global_t *data)
{
    data->tab_x = 1;

    while (data->tab[data->tab_y][data->tab_x] == ' ')
        data->tab_x ++;
    data->tx_pos = my_get_nbr(data);
    data->tab_x = data->tab_x + 1;
    data->ty_pos = my_get_nbr(data);
    while (data->tab[data->tab_y][data->tab_x] == ' ')
        data->tab_x ++;
    data->t_rds = my_get_nbr(data);
    return;
}

void count_objects(global_t *data, char *buff, tower_t **tower, plane_t **plane)
{
    data->towers = 0;
    data->planes = 0;
    data->tab_x = 0;
    data->tab_y = 0;

    while (data->tab_y < data->layers) {
        if (data->tab[data->tab_y][0] == 'T') {
            get_tower_data(data);
            create_tower(data, tower);
            data->towers ++;
        }
        if (data->tab[data->tab_y][0] == 'A') {
            get_plane_data(data);
            create_plane(data, plane);
            data->planes ++;
        }
        data->tab_y ++;
    }
    return;
}

int read_script(char **argv, global_t *data, tower_t **tower, plane_t **plane)
{
    struct stat info;
    char *filename = argv[1];
    char *buff;

    stat(filename, &info);
    data->fd = open(filename, O_RDONLY);
    if (data->fd != -1) {
        buff = malloc(sizeof(char) * (info.st_size + 1));
        read(data->fd, buff, info.st_size);
    } else {
        my_printf("Could not open file, chek using '-h'.\n");
        return (84);
    }
    if (verif_tab(buff) == 84)
        return (84);
    cpy(buff, data);
    count_objects(data, buff, tower, plane);
    close(data->fd);
    free(buff);
    return (0);
}
