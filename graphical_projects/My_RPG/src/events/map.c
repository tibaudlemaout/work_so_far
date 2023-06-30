/*
** EPITECH PROJECT, 2023
** B-MUL-200-NAN-2-1-myrpg-tibaud.le-maout
** File description:
** map
*/
#include "../../include/my.h"

// revoir le calcul de zoom
void map_zoom(struct_t *data)
{
    sfVector2f size = sfView_getSize(data->view);
    if (EVENT.mouseWheelScroll.delta > 0) {
        if (size.x < 1920) {
            size.x *= 1.1;
            size.y *= 1.1;
        }
    } else {
        size.x /= 1.1;
        size.y /= 1.1;
    }
    sfView_setSize(data->view, size);
}

void map_manage_events(struct_t *data)
{
    sfVector2i posi = get_mouse_position(data);
    if (EVENT.type == sfEvtClosed)
        data->set = 0;
    if (EVENT.type == sfEvtKeyReleased && EVENT.key.code == sfKeyEscape)
        data->set = 15;
    if (EVENT.type == sfEvtMouseButtonReleased &&
        EVENT.key.code == sfMouseLeft) {
        if (posi.x >= 30 && posi.x <= 130 && posi.y >= 30 && posi.y <= 130)
            data->set = 15;
    }
    if (EVENT.type == sfEvtMouseWheelScrolled)
        map_zoom(data);
}
