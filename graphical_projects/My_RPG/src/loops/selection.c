/*
** EPITECH PROJECT, 2023
** B-MUL-200-NAN-2-1-myrpg-tibaud.le-maout
** File description:
** selection
*/
#include "../../include/my.h"

void selection_loop(struct_t *data, menu_t *menu)
{
    reset_view(data);
    while (data->set == 3) {
        while (sfRenderWindow_pollEvent(WIN, &EVENT))
            selection_manage_events(data, menu);
        selection_display(data, menu);
    }
    sfView_destroy(data->view);
}
