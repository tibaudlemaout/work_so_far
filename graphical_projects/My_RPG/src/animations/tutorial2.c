/*
** EPITECH PROJECT, 2023
** B-MUL-200-NAN-2-1-myrpg-tibaud.le-maout
** File description:
** tutorial
*/
#include "../../include/my.h"

void display_tutorial_animation2(struct_t *data)
{
    sfRenderWindow_clear(WIN, sfBlack);
    sfRenderWindow_setView(WIN, data->view);
    sfRenderWindow_drawSprite(WIN, data->bg.sprite, NULL);
    sfRenderWindow_drawSprite(WIN, TUTO.npc[3].sprite, NULL);
    sfRenderWindow_drawSprite(WIN, P.sprite, NULL);
    sfRenderWindow_display(WIN);
}

void soldier_move_animation2(struct_t *data)
{
    sfVector2f soldierPosition = sfSprite_getPosition(TUTO.npc[3].sprite);
    sfVector2f cameraPosition = sfView_getCenter(data->view);

    cameraPosition.x = soldierPosition.x + P.rect.width / 2;
    cameraPosition.y = soldierPosition.y + P.rect.height / 2;
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

void tutorial_animation_update2(struct_t *data, sfVector2f movement, int end)
{
    sfTexture *TextureLeft = TUTO.npc[3].TextureLeft;
    sfIntRect rect = {47, 0, 47, 48};

    if (end == 0) {
        sfSprite_setTextureRect(P.sprite, (sfIntRect) {47, 0, 47, 48});
        sfSprite_setTextureRect(TUTO.npc[3].sprite, P.rect);
        sfSprite_move(TUTO.npc[3].sprite, movement);
        soldier_move_animation2(data);
    } else {
        sfSprite_setTexture(TUTO.npc[3].sprite, TextureLeft, sfTrue);
        sfSprite_setTextureRect(TUTO.npc[3].sprite, rect);
        TUTO.rect_pos[3] = sfSprite_getPosition(TUTO.npc[3].sprite);
        data->interact = 0;
        data->talk = 0;
        data->set = 5;
    }
}

void tutorial_animation_movements2(struct_t *data)
{
    sfVector2f movement = {0, 0};
    sfTexture *TextureRight = TUTO.npc[3].TextureRight;
    sfTexture *TextureDown = TUTO.npc[3].TextureDown;

    if (sfSprite_getPosition(TUTO.npc[3].sprite).y < 504) {
        movement.y = 4;
        sfSprite_setTexture(TUTO.npc[3].sprite, TextureDown, sfTrue);
        tutorial_animation_update2(data, movement, 0);
    } else if (sfSprite_getPosition(TUTO.npc[3].sprite).x < 1680) {
        movement.x = 4;
        sfSprite_setTexture(TUTO.npc[3].sprite, TextureRight, sfTrue);
        tutorial_animation_update2(data, movement, 0);
    } else
        tutorial_animation_update2(data, movement, 1);
}

void tutorial_animation2(struct_t *data)
{
    sfVector2f soldierPosition = sfSprite_getPosition(TUTO.npc[3].sprite);
    sfVector2f cameraPosition = sfView_getCenter(data->view);

    data->view = sfView_create();
    sfView_setSize(data->view, (sfVector2f){480, 270});
    sfRenderWindow_setView(WIN, data->view);
    cameraPosition.x = soldierPosition.x + P.rect.width / 2;
    cameraPosition.y = soldierPosition.y + P.rect.height / 2;
    sfView_setCenter(data->view, cameraPosition);
    while (data->set == 12) {
        while (sfRenderWindow_pollEvent(WIN, &EVENT))
            fight_animation_manage_events(data);
        tutorial_animation_movements2(data);
        display_tutorial_animation2(data);
    }
    sfView_destroy(data->view);
    return;
}
