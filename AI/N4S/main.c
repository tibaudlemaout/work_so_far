/*
** EPITECH PROJECT, 2023
** B-AIA-200-NAN-2-1-n4s-tibaud.le-maout
** File description:
** main
*/
#include "include/my.h"

struct_t *init_struct(void)
{
    struct_t *data = malloc(sizeof(struct_t));

    data->left = 0;
    data->middle = 0;
    data->right = 0;
    data->speed = 0.5;
    return(data);
}

int main(int ac, char **av)
{
    struct_t *data = init_struct();
    char *buffer;
    char **tab;

    write(1, "start_simulation\n", 17);
    buffer = get_next_line(0, 0);
    dprintf(1, "car_forward: %.2f\n", data->speed);
    get_next_line(0, 0);
    free(buffer);
    while (1) {
        write(1, "get_info_lidar\n", 15);
        buffer = get_next_line(0, 0);
        tab = str_to_tab(buffer);
        free(buffer);
        if (strcmp(tab[1], "OK") == 0)
            change_direction(data, tab);
    }
    return (0);
}
