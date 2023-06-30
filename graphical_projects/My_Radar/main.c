/*
** EPITECH PROJECT, 2022
** EPITECH
** File description:
** main
*/
#include "./include/radar.h"
#include "./include/struct.h"

int main(int ac, char **av)
{
    global_t data;
    tower_t *towers = NULL;
    plane_t *planes = NULL;
    data.sprite_view = 1;
    data.view_hitbox = 1;

    if (ac != 2)
        return (84);
    if (av[1][0] == '-' && av[1][1] == 'h') {
        help_manual();
    } else {
        if (read_script(av, &data, &towers, &planes) == 84) {
            return (84);
        } else
        play_radar(&data, towers, planes);
    free(data.tab);
    }
    return (0);
}
