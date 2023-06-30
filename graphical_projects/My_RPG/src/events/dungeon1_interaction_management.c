/*
** EPITECH PROJECT, 2023
** B-MUL-200-NAN-2-1-myrpg-tibaud.le-maout
** File description:
** dungeon1_interaction_management
*/
#include "../../include/my.h"

void dungeon1_last_interaction(struct_t *data)
{
    if (D1.quest_index == 17) {
        D1.end = 1;
    }
    return;
}

void dungeon1_index_gestion(struct_t *data)
{
    if ((D1.quest_index + 1) < 5)
        D1.quest_index++;
    if (D1.quest_index >= 5 && (D1.quest_index + 1) < 15)
        D1.quest_index++;
    if (D1.quest_1 < 25 && D1.quest_index == 4) {
        data->interact = 0;
        data->talk = 0;
    }
    if (D1.quest_2 == 0 && D1.quest_index == 14) {
        data->interact = 0;
        data->talk = 0;
    }
    if (D1.quest_2 == 1 && (D1.quest_index + 1) < 16) // à vérifer si c'est pas 18 à  la place
        D1.quest_index++;
}

void dungeon1_interaction_management(struct_t *data)
{
    if (data->talk == 0)
        data->talk = 1;
    else {
        if (D1.quest[D1.quest_index + 1] != D1.quest[D1.quest_index]) {
            data->interact = 0;
            data->talk = 0;
            dungeon1_last_interaction(data);
        }
        dungeon1_index_gestion(data);
    }
    return;
}
