/*
** EPITECH PROJECT, 2023
** B-MUL-200-NAN-2-1-myrpg-tibaud.le-maout
** File description:
** dungeon1
*/
#include "../../include/my.h"

void dungeon1_loop(struct_t *data)
{
    sfVector2f playerPosition = sfSprite_getPosition(P.sprite);
    sfVector2f cameraPosition = sfView_getCenter(data->view);

    init_dungeon1_struct(data);
    data->view = sfView_create();
    sfView_setSize(data->view, (sfVector2f){480, 270});
    sfRenderWindow_setView(WIN, data->view);
    cameraPosition.x = playerPosition.x + P.rect.width / 2;
    cameraPosition.y = playerPosition.y + P.rect.height / 2;
    sfView_setCenter(data->view, cameraPosition);
    while (data->set == 16) {
        while (sfRenderWindow_pollEvent(WIN, &EVENT))
            dungeon1_manage_events(data);
        dungeon1_display(data);
    }
    sfView_destroy(data->view);
    return;
}
