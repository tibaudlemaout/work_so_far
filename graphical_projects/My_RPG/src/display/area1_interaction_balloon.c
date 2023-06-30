/*
** EPITECH PROJECT, 2023
** B-MUL-200-NAN-2-1-myrpg-tibaud.le-maout
** File description:
** interaction_balloon
*/
#include "../../include/my.h"

void area1_interaction_balloon_clock(struct_t *data)
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

void area1_display_interaction_ballon(struct_t *data)
{
    sfVector2f pos = Z1.rect_pos[Z1.quest[Z1.quest_index] - 1];
    sfVector2f pos2 = {pos.x + 2, pos.y - 30};

    if (Z1.quest_index == 0)
        pos = Z1.rect_pos[0];
    sfSprite_setPosition(data->interact_balloon.sprite, pos2);
    if (Z1.quest_1 < 12 && Z1.quest_index == 3)
        return;
    if (Z1.quest_2 == 0 && Z1.quest_index == 6)
        return;
    if (Z1.end == 0)
        sfRenderWindow_drawSprite(WIN, data->interact_balloon.sprite, NULL);
    area1_interaction_balloon_clock(data);
}
