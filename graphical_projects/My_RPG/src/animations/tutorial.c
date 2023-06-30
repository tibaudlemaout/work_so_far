/*
** EPITECH PROJECT, 2023
** B-MUL-200-NAN-2-1-myrpg-tibaud.le-maout
** File description:
** tutorial
*/
#include "../../include/my.h"

void display_tutorial_animation(struct_t *data)
{
    sfRenderWindow_clear(WIN, sfBlack);
    sfRenderWindow_setView(WIN, data->view);
    sfRenderWindow_drawSprite(WIN, data->bg.sprite, NULL);
    sfRenderWindow_drawSprite(WIN, TUTO.npc[3].sprite, NULL);
    sfRenderWindow_drawSprite(WIN, P.sprite, NULL);
    sfRenderWindow_display(WIN);
}

void soldier_move_animation(struct_t *data)
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
        sfSprite_setTextureRect(TUTO.npc[3].sprite, P.rect);
        sfClock_restart(P.clock.clock);
    }
    return;
}

void tutorial_animation_update(struct_t *data, sfVector2f movement, int end)
{
    sfTexture *TextureLeft = TUTO.npc[3].TextureLeft;

    if (end == 0) {
    sfSprite_setTextureRect(TUTO.npc[3].sprite, P.rect);
    move_all(data, movement);
    sfRectangleShape_move(P.hitbox, movement);
    sfSprite_move(TUTO.npc[3].sprite, movement);
    soldier_move_animation(data);
    } else {
        sfSprite_setTexture(P.sprite, P.TextureRight, sfTrue);
        sfSprite_setTexture(TUTO.npc[3].sprite, TextureLeft, sfTrue);
        sfSprite_setTextureRect(P.sprite, P.rect);
        sfSprite_setTextureRect(TUTO.npc[3].sprite, P.rect);
        data->talk = 1;
        data->set = 5;
    }
}

void tutorial_animation_movements(struct_t *data)
{
    sfVector2f movement = {0, 0};
    sfTexture *TextureRight = TUTO.npc[3].TextureRight;
    sfTexture *TextureUp = TUTO.npc[3].TextureUp;

    if (sfSprite_getPosition(P.sprite).x < 1430) {
        movement.x = 4;
        sfSprite_setTexture(P.sprite, P.TextureRight, sfTrue);
        sfSprite_setTexture(TUTO.npc[3].sprite, TextureRight, sfTrue);
        tutorial_animation_update(data, movement, 0);
    } else if (sfSprite_getPosition(P.sprite).y > 370) {
        movement.y = -4;
        sfSprite_setTexture(P.sprite, P.TextureUp, sfTrue);
        sfSprite_setTexture(TUTO.npc[3].sprite, TextureUp, sfTrue);
        tutorial_animation_update(data, movement, 0);
    } else
        tutorial_animation_update(data, movement, 1);
}

void tutorial_animation(struct_t *data)
{
    sfVector2f playerPosition = sfSprite_getPosition(P.sprite);
    sfVector2f cameraPosition = sfView_getCenter(data->view);

    data->view = sfView_create();
    sfView_setSize(data->view, (sfVector2f){480, 270});
    sfRenderWindow_setView(WIN, data->view);
    cameraPosition.x = playerPosition.x + P.rect.width / 2;
    cameraPosition.y = playerPosition.y + P.rect.height / 2;
    sfView_setCenter(data->view, cameraPosition);
    while (data->set == 11) {
        while (sfRenderWindow_pollEvent(WIN, &EVENT))
            fight_animation_manage_events(data);
        tutorial_animation_movements(data);
        display_tutorial_animation(data);
    }
    sfView_destroy(data->view);
    return;
}
