/*
** EPITECH PROJECT, 2023
** B-MUL-200-NAN-2-1-myrpg-tibaud.le-maout
** File description:
** player
*/
#include "../../include/my.h"

void player_move_animation(struct_t *data)
{
    sfVector2f playerPosition = sfSprite_getPosition(P.sprite);
    sfVector2f cameraPosition = sfView_getCenter(data->view);

    cameraPosition.x = playerPosition.x + P.rect.width / 2;
    cameraPosition.y = playerPosition.y + P.rect.height / 2;
    sfView_setCenter(data->view, cameraPosition);
    P.clock.time = sfClock_getElapsedTime(P.clock.clock);
    P.clock.seconds = P.clock.time.microseconds / 1000000.0;
    if (P.clock.seconds > 0.2) {
        P.rect.left += 47;
        if (P.rect.left == 141)
            P.rect.left = 0;
        sfSprite_setTextureRect(P.sprite, P.rect);
        sfClock_restart(P.clock.clock);
    }
    return;
}
