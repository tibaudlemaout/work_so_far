/*
** EPITECH PROJECT, 2023
** B-MUL-200-NAN-2-1-myrpg-tibaud.le-maout
** File description:
** events
*/
#include "../../include/my.h"

// save function à retravailler
void temporary_save_function(struct_t *data)
{
    FILE* fichier = fopen("src/save/save_file.txt", "w");
    char *buffer = data->save.buffer;
    fwrite(buffer, sizeof(char), my_strlen(buffer), fichier);
}

void scene_changing(struct_t *data, sfVector2i posi)
{
    sfVector2f soldierPosition = sfSprite_getPosition(TUTO.npc[3].sprite);

    if (EVENT.type == sfEvtKeyReleased && EVENT.key.code == sfKeyEscape) {
        data->old_set = 5;
        data->set = 15;
    }
    if (EVENT.type == sfEvtMouseButtonReleased &&
        EVENT.key.code == sfMouseLeft) {
        if (posi.x >= 30 && posi.x <= 130 && posi.y >= 30 && posi.y <= 130) {
            data->old_set = 5;
            data->set = 15;
        }
    }
    if (TUTO.quest_index == 8 && soldierPosition.x < 1400)
        data->set = 11;
    if (TUTO.quest_index == 10 && soldierPosition.x < 1600)
        data->set = 12;
}

void manage_events(struct_t *data)
{
    sfVector2i posi = get_mouse_position(data);
    if (EVENT.type == sfEvtClosed) {
        temporary_save_function(data);
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
    if (data->interact == 1 && EVENT.type == sfEvtKeyReleased
        && EVENT.key.code == sfKeyT)
        interaction_management(data);
    scene_changing(data, posi);
}
