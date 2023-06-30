/*
** EPITECH PROJECT, 2023
** B-MUL-200-NAN-2-1-myrpg-tibaud.le-maout
** File description:
** area1_interaction_management
*/
#include "../../include/my.h"

void area1_last_interaction(struct_t *data)
{
    if (Z1.quest_index == 10) {
        Z1.end = 1;
    }
    return;
}

void area1_index_gestion(struct_t *data)
{
    if ((Z1.quest_index + 1) < 4)
        Z1.quest_index++;
    if (Z1.quest_index >= 4 && (Z1.quest_index + 1) < 7)
        Z1.quest_index++;
    if (Z1.quest_2 == 0 && Z1.quest_index == 6) {
        data->interact = 0;
        data->talk = 0;
    }
    if (Z1.quest_2 == 1 && (Z1.quest_index + 1) < 11)
        Z1.quest_index++;
}

void area1_interaction_management(struct_t *data)
{
    if (data->talk == 0)
        data->talk = 1;
    else {
        if (Z1.quest[Z1.quest_index + 1] != Z1.quest[Z1.quest_index]) {
            data->interact = 0;
            data->talk = 0;
            area1_last_interaction(data);
        }
        area1_index_gestion(data);
    }
    return;
}
