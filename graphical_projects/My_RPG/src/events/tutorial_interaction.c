/*
** EPITECH PROJECT, 2023
** B-MUL-200-NAN-2-1-myrpg-tibaud.le-maout
** File description:
** tutorial_interaction
*/
#include "../../include/my.h"

void last_tutorial_interaction(struct_t *data)
{
    sfVector2f soldierPosition = sfSprite_getPosition(TUTO.npc[3].sprite);
    sfTexture *TextureDown = TUTO.npc[3].TextureDown;
    sfIntRect rect = {47, 0, 47, 48};

    if (TUTO.quest_index == 13) {
        TUTO.end = 1;
        data->set = 13;
    }
}

void given_tutorial_items(struct_t *data)
{
    if (TUTO.quest_index == 3) {
        data->inventory.tab[5].taken = 1;
        data->inventory.tab[5].item = data->item[8];
        set_item_position(data, 5);
        data->inventory.tab[6].taken = 1;
        data->inventory.tab[6].item = data->item[9];
        set_item_position(data, 6);
    }
    if (TUTO.quest_index == 5) {
        data->inventory.tab[7].taken = 1;
        data->inventory.tab[7].item = data->item[10];
        set_item_position(data, 7);
        data->inventory.tab[8].taken = 1;
        data->inventory.tab[8].item = data->item[11];
        set_item_position(data, 8);
    }
}

void interaction_management(struct_t *data)
{
    if (data->talk == 0)
        data->talk = 1;
    else {
        if (TUTO.quest_1 == 1) {
            TUTO.quest_1 = 0;
            data->interact = 0;
            data->talk = 0;
            return;
        }
        if (TUTO.quest[TUTO.quest_index + 1] != TUTO.quest[TUTO.quest_index]) {
            data->interact = 0;
            data->talk = 0;
            last_tutorial_interaction(data);
        }
        if (TUTO.quest_1 == 0 && (TUTO.quest_index + 1) < 14) {
            TUTO.quest_index++;
        }
    }
    given_tutorial_items(data);
}
