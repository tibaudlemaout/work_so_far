/*
** EPITECH PROJECT, 2023
** B-MUL-200-NAN-2-1-myrpg-tibaud.le-maout
** File description:
** tutorial3
*/
#include "../../include/my.h"

void display_tutorial_animation3(struct_t *data)
{
    sfRenderWindow_clear(WIN, sfBlack);
    sfRenderWindow_setView(WIN, data->view);
    sfRenderWindow_drawSprite(WIN, data->bg.sprite, NULL);
    sfRenderWindow_drawSprite(WIN, TUTO.npc[3].sprite, NULL);
    sfRenderWindow_drawSprite(WIN, P.sprite, NULL);
    sfRenderWindow_display(WIN);
}

void soldier_move_animation3(struct_t *data)
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
        sfSprite_setTextureRect(P.sprite, (sfIntRect) {47, 0, 47, 48});
        sfSprite_setTextureRect(TUTO.npc[3].sprite, P.rect);
        sfClock_restart(P.clock.clock);
    }
    return;
}

void tutorial_animation_update3(struct_t *data, sfVector2f movement, int end)
{
    sfIntRect rect = {47, 0, 47, 48};

    if (end == 0) {
        sfSprite_setTextureRect(P.sprite, (sfIntRect) {47, 0, 47, 48});
        sfSprite_setTextureRect(TUTO.npc[3].sprite, P.rect);
        sfSprite_move(TUTO.npc[3].sprite, movement);
        soldier_move_animation3(data);
    } else {
        sfSprite_setTextureRect(TUTO.npc[3].sprite, rect);
        TUTO.rect_pos[3] = sfSprite_getPosition(TUTO.npc[3].sprite);
        sfSprite_move(TUTO.npc[3].sprite, movement);
        data->interact = 0;
        data->talk = 0;
        data->set = 5;
    }
}

void tutorial_animation_movements3(struct_t *data)
{
    sfVector2f movement = {0, 0};
    sfTexture *TextureUp = TUTO.npc[3].TextureUp;
    sfTexture *TextureDown = TUTO.npc[3].TextureDown;

    if (sfSprite_getPosition(TUTO.npc[3].sprite).y > 456) {
        movement.y = -4;
        sfSprite_setTexture(TUTO.npc[3].sprite, TextureUp, sfTrue);
        tutorial_animation_update3(data, movement, 0);
    } else {
        movement.x = 2;
        sfSprite_setTexture(TUTO.npc[3].sprite, TextureDown, sfTrue);
        tutorial_animation_update3(data, movement, 1);
    }
}

void tutorial_animation3(struct_t *data)
{
    sfVector2f playerPosition = sfSprite_getPosition(P.sprite);
    sfVector2f cameraPosition = sfView_getCenter(data->view);

    data->view = sfView_create();
    sfView_setSize(data->view, (sfVector2f){480, 270});
    sfRenderWindow_setView(WIN, data->view);
    cameraPosition.x = playerPosition.x + P.rect.width / 2;
    cameraPosition.y = playerPosition.y + P.rect.height / 2;
    sfView_setCenter(data->view, cameraPosition);
    while (data->set == 13) {
        while (sfRenderWindow_pollEvent(WIN, &EVENT))
            fight_animation_manage_events(data);
        tutorial_animation_movements3(data);
        display_tutorial_animation3(data);
    }
    sfView_destroy(data->view);
    return;
}
