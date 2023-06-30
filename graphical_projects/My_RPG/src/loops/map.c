/*
** EPITECH PROJECT, 2023
** B-MUL-200-NAN-2-1-myrpg-tibaud.le-maout
** File description:
** map
*/
#include "../../include/my.h"

void map_loop(struct_t *data)
{
    reset_view(data);
    while (data->set == 10) {
        while (sfRenderWindow_pollEvent(WIN, &EVENT))
            map_manage_events(data);
        map_display(data);
    }
    sfView_destroy(data->view);
}
