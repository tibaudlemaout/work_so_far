/*
** EPITECH PROJECT, 2023
** B-MUL-200-NAN-2-1-myrpg-tibaud.le-maout
** File description:
** player_moves
*/
#include "../../include/my.h"

void move_all(struct_t *data, sfVector2f movement)
{
    sfSprite_move(P.sprite, movement);
    sfSprite_move(P.profile.sprite, movement);
    sfSprite_move(data->minimap.sprite, movement);
    sfSprite_move(data->icon[2], movement);
    sfRectangleShape_move(data->minimapOutline, movement);
    sfSprite_setTextureRect(P.sprite, P.rect);
}

int up_n_down(struct_t *data)
{
    sfVector2f movement = {0, 0};
    if (sfKeyboard_isKeyPressed(sfKeyUp)) {
        movement.y = -5;
        P.direction = 1;
        if (check_hitbox(data, movement) == 1)
            return (0);
        sfSprite_setTexture(P.sprite, P.TextureUp, sfTrue);
        move_all(data, movement);
        return (1);
    }
    if (sfKeyboard_isKeyPressed(sfKeyDown)) {
        movement.y = 5;
        P.direction = 3;
        if (check_hitbox(data, movement) == 1)
            return (0);
        sfSprite_setTexture(P.sprite, P.TextureDown, sfTrue);
        move_all(data, movement);
        return (1);
    }
    return (0);
}

int left_n_right(struct_t *data)
{
    sfVector2f movement = {0, 0};
    if (sfKeyboard_isKeyPressed(sfKeyLeft)) {
        movement.x = -5;
        P.direction = 4;
        if (check_hitbox(data, movement) == 1)
            return (0);
        sfSprite_setTexture(P.sprite, P.TextureLeft, sfTrue);
        move_all(data, movement);
        return (1);
    }
    if (sfKeyboard_isKeyPressed(sfKeyRight)) {
        movement.x = 5;
        P.direction = 2;
        if (check_hitbox(data, movement) == 1)
            return (0);
        sfSprite_setTexture(P.sprite, P.TextureRight, sfTrue);
        move_all(data, movement);
        return (1);
    }
    return (0);
}

int manage_player_moves(struct_t *data)
{
    if (up_n_down(data) == 1)
        return (1);
    if (left_n_right(data) == 1)
        return (1);
    return (0);
}
