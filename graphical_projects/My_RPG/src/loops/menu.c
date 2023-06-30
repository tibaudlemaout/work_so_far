/*
** EPITECH PROJECT, 2023
** B-MUL-200-NAN-2-1-myrpg-tibaud.le-maout
** File description:
** menu
*/
#include "../../include/my.h"

void menu_loop(struct_t *data, menu_t *menu)
{
    reset_view(data);
    while (data->set == 1) {
        while (sfRenderWindow_pollEvent(WIN, &EVENT))
            menu_manage_events(data, menu);
        menu_display(data, menu);
    }
    sfView_destroy(data->view);
}
