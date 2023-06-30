/*
** EPITECH PROJECT, 2023
** B-MUL-200-NAN-2-1-myrpg-tibaud.le-maout
** File description:
** area1_check
*/
#include "../../include/my.h"

void is_npc_for_quest_area1_2(struct_t *data, int rectPos[2], int l_x, int l_y)
{
    if (rectPos[0] == l_x && rectPos[1] == l_y) {
        if (!(Z1.quest_2 == 0 && Z1.quest_index == 6))
            data->interact = 1;
    } else {
        data->interact = 0;
    }
}

void is_npc_for_quest_area1(struct_t *data, sfRectangleShape *rect)
{
    sfVector2f rect_pos = sfRectangleShape_getPosition(rect);
    int list_x = Z1.rect_pos[Z1.quest[Z1.quest_index] - 1].x;
    int list_y = Z1.rect_pos[Z1.quest[Z1.quest_index] - 1].y;
    int rectPos[2] = {rect_pos.x, rect_pos.y};

    if (Z1.quest_index == 0) {
        list_x = Z1.rect_pos[0].x;
        list_y = Z1.rect_pos[0].y;
    }
    is_npc_for_quest_area1_2(data, rectPos, list_x, list_y);
    return;
}

int area1_progress_check(struct_t *data, sfVector2f pos)
{
    sfVector2f NewPos = {580, 920};
    sfVector2f Hitbox = sfRectangleShape_getPosition(P.hitbox);

    if (Z1.quest_index >= 6) {
        if ((pos.y == 72 && (pos.x == 936 || pos.x == 960)) &&
            (Hitbox.y <= 120 && (Hitbox.x >= 936 && Hitbox.x <= 984))) {
            sfSprite_setPosition(P.sprite, NewPos);
            NewPos = (sfVector2f) {NewPos.x + 4, NewPos.y + 15};
            sfRectangleShape_setPosition(P.hitbox, NewPos);
            sfSprite_setTexture(P.sprite, P.TextureUp, sfTrue);
            sfSprite_setTextureRect(P.sprite, (sfIntRect) {47, 0, 47, 48});
            data->set = 16;
            return (0);
        }
    }
    return (1);
}
