/*
** EPITECH PROJECT, 2023
** B-MUL-200-NAN-2-1-myrpg-tibaud.le-maout
** File description:
** dungeon1_interaction
*/
#include "../../include/my.h"

void dungeon1_interaction_balloon_clock(struct_t *data)
{
    sfIntRect rect = data->interact_balloon.rect;
    data->mark_clock.time = sfClock_getElapsedTime(data->mark_clock.clock);
    data->mark_clock.seconds = data->mark_clock.time.microseconds / 1000000.0;
    if (data->mark_clock.seconds > 0.1) {
        if (data->interact_balloon.rect.left == 312)
            data->interact_balloon.rect.left = 0;
        else
            data->interact_balloon.rect.left += 39;
        rect.left = data->interact_balloon.rect.left;
        sfSprite_setTextureRect(data->interact_balloon.sprite, rect);
        sfClock_restart(data->mark_clock.clock);
    }
}

void dungeon1_display_interaction_ballon(struct_t *data)
{
    sfVector2f pos = D1.rect_pos[D1.quest[D1.quest_index] - 1];
    sfVector2f pos2 = {pos.x + 2, pos.y - 30};

    if (D1.quest_index == 0)
        pos = D1.rect_pos[0];
    sfSprite_setPosition(data->interact_balloon.sprite, pos2);
    if (D1.quest_1 < 25 && D1.quest_index == 4)
        return;
    if (D1.quest_2 == 0 && D1.quest_index == 14)
        return;
    if (D1.end == 0)
        sfRenderWindow_drawSprite(WIN, data->interact_balloon.sprite, NULL);
    dungeon1_interaction_balloon_clock(data);
}
