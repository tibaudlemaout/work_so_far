/*
** EPITECH PROJECT, 2023
** B-MUL-200-NAN-2-1-myrpg-tibaud.le-maout
** File description:
** check_interact
*/
#include "../../include/my.h"

void is_npc_for_quest_tuto2(struct_t *data, int rectPos[2], int l_x, int l_y)
{
    if (rectPos[0] == l_x && rectPos[1] == l_y)
        data->interact = 1;
    else if (TUTO.quest_index < 7 && rectPos[0] == TUTO.rect_pos[3].x &&
            rectPos[1] == TUTO.rect_pos[3].y) {
        data->interact = 1;
        TUTO.quest_1 = 1;
    } else {
        data->interact = 0;
        TUTO.quest_1 = 0;
    }
}

void is_npc_for_quest_tuto(struct_t *data, sfRectangleShape *rect)
{
    sfVector2f rect_pos = sfRectangleShape_getPosition(rect);
    int list_x = TUTO.rect_pos[TUTO.quest[TUTO.quest_index] - 1].x;
    int list_y = TUTO.rect_pos[TUTO.quest[TUTO.quest_index] - 1].y;
    int rectPos[2] = {rect_pos.x, rect_pos.y};

    if (TUTO.quest_index == 0) {
        list_x = TUTO.rect_pos[0].x;
        list_y = TUTO.rect_pos[0].y;
    }
    is_npc_for_quest_tuto2(data, rectPos, list_x, list_y);
    return;
}

int tuto_progress_check(struct_t *data, sfVector2f pos)
{
    sfVector2f NewPos = {217, 470};
    sfVector2f Hitbox = sfRectangleShape_getPosition(P.hitbox);

    if (TUTO.quest_index > 7) {
        if (pos.x == 1104 && (pos.y == 600 || pos.y == 576
            || pos.y == 552 || pos.y == 528))
            return (0);
    }
    if (TUTO.end == 1) {
        if (pos.x == 1680 && (pos.y == 528 || pos.y == 504 || pos.y == 480))
            return (0);
        if (Hitbox.x == 1742 && (Hitbox.y >= 480 && Hitbox.y <= 540)) {
            sfSprite_setPosition(P.sprite, NewPos);
            NewPos = (sfVector2f) {NewPos.x + 4, NewPos.y + 15};
            sfRectangleShape_setPosition(P.hitbox, NewPos);
            data->set = 14;
            return (0);
        }
    }
    return (1);
}

int check_interact(struct_t *data, sfVector2f old_pos, sfRectangleShape *rect)
{
    sfFloatRect player_box;
    sfFloatRect wall_box;
    sfColor color = sfRectangleShape_getFillColor(rect);
    sfVector2f pos = sfRectangleShape_getPosition(rect);

    if (color.b == 255) {
        player_box = sfRectangleShape_getGlobalBounds(P.hitbox);
        wall_box = sfRectangleShape_getGlobalBounds(rect);
        if (progress_check(data, pos, data->map) == 0)
            return (0);
        if (player_box.left < wall_box.left + wall_box.width &&
            player_box.left + player_box.width > wall_box.left &&
            player_box.top < wall_box.top + wall_box.height &&
            player_box.top + player_box.height > wall_box.top) {
            sfRectangleShape_setPosition(P.hitbox, old_pos);
            return (1);
        }
    }
    return (0);
}
