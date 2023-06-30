/*
** EPITECH PROJECT, 2023
** B-MUL-200-NAN-2-1-myrpg-tibaud.le-maout
** File description:
** dungeon1_principal
*/
#include "../../include/my.h"

void dungeon1_scene_changing(struct_t *data, sfVector2i posi)
{
    if (EVENT.type == sfEvtKeyReleased && EVENT.key.code == sfKeyEscape) {
        data->old_set = 16;
        data->set = 15;
    }
    if (EVENT.type == sfEvtMouseButtonReleased &&
        EVENT.key.code == sfMouseLeft) {
        if (posi.x >= 30 && posi.x <= 130 && posi.y >= 30 && posi.y <= 130) {
            data->old_set = 16;
            data->set = 15;
        }
    }
}

void dungeon1_manage_events(struct_t *data)
{
    sfVector2i posi = get_mouse_position(data);
    if (EVENT.type == sfEvtClosed) {
        data->set = 0;
    }
    if (data->talk == 0) {
        if (manage_player_moves(data) == 1) {
            player_move_animation(data);
        } else {
            P.rect.left = 47;
            sfSprite_setTextureRect(P.sprite, P.rect);
        }
    }
    if (D1.quest_1 == 25 && D1.quest_index == 4)
        D1.quest_index++;
    if (data->interact == 1 && EVENT.type == sfEvtKeyReleased
        && EVENT.key.code == sfKeyT)
        dungeon1_interaction_management(data);
    dungeon1_scene_changing(data, posi);
}
