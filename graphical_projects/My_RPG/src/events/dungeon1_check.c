/*
** EPITECH PROJECT, 2023
** B-MUL-200-NAN-2-1-myrpg-tibaud.le-maout
** File description:
** dungeon1_check
*/
#include "../../include/my.h"

void get_into_fight_with_bobtheblueblob(struct_t *data)
{
    if (D1.quest_index == 14 && data->random_mob_nb != 6) {
        data->old_set = 16;
        data->random_mob_nb = 6;
        data->set = 6;
    }
}

void is_npc_for_quest_dungeon1_2(struct_t *data, int pos[2], int l_x, int l_y)
{
    if (pos[0] == l_x && pos[1] == l_y) {
        if (!(D1.quest_2 == 0 && D1.quest_index == 14) &&
            !(D1.quest_1 < 25 && D1.quest_index == 4))
            data->interact = 1;
    } else {
        data->interact = 0;
    }
}

void is_npc_for_quest_dungeon1(struct_t *data, sfRectangleShape *rect)
{
    sfVector2f rect_pos = sfRectangleShape_getPosition(rect);
    int list_x = D1.rect_pos[D1.quest[D1.quest_index] - 1].x;
    int list_y = D1.rect_pos[D1.quest[D1.quest_index] - 1].y;
    int rectPos[2] = {rect_pos.x, rect_pos.y};

    if (D1.quest_index == 0) {
        list_x = D1.rect_pos[0].x;
        list_y = D1.rect_pos[0].y;
    }
    is_npc_for_quest_dungeon1_2(data, rectPos, list_x, list_y);
    return;
}

int dungeon1_progress_check(struct_t *data, sfVector2f pos)
{
    sfVector2f NewPos = {950, 144};
    sfVector2f Hitbox = sfRectangleShape_getPosition(P.hitbox);

    if ((pos.x == 1704 && pos.y == 192) && ((Hitbox.x >= 1670 && Hitbox.x <= 1750) && (Hitbox.y >= 160 && Hitbox.y <= 250))) {
        data->old_set = 16;
        get_into_fight_with_bobtheblueblob(data);
        return (0);
    }

    if (pos.x == 576 && pos.y == 960 &&
        ((Hitbox.x >= 576 && Hitbox.x <= 590)  && Hitbox.y > 936)) {
        sfSprite_setPosition(P.sprite, NewPos);
        NewPos = (sfVector2f) {NewPos.x + 4, NewPos.y + 15};
        sfRectangleShape_setPosition(P.hitbox, NewPos);
        data->set = 14;
        return (0);
    }
    return (1);
}
