/*
** EPITECH PROJECT, 2023
** B-MUL-200-NAN-2-1-myrpg-tibaud.le-maout
** File description:
** fight
*/
#include "../../include/my.h"

void fight_display_player(struct_t *data, fight_t *fight)
{
    sfRenderWindow_drawRectangleShape(WIN, fight->player_area.rect, NULL);
    sfRenderWindow_drawRectangleShape(WIN, ADSarea.rect, NULL);
    for (int i = 0; i < 3; i++)
        sfRenderWindow_drawText(WIN, ADS[i].txt, NULL);
    sfRenderWindow_drawText(WIN, fight->player_name.txt, NULL);
    sfRenderWindow_drawText(WIN, fight->player_hp.txt, NULL);
    sfRenderWindow_drawText(WIN, fight->player_ActualHp.txt, NULL);
    sfRenderWindow_drawText(WIN, fight->player_xp.txt, NULL);
}

void fight_display_monster(struct_t *data, fight_t *fight)
{
    sfRenderWindow_drawSprite(WIN, M.sprite.sprite, NULL);
    sfRenderWindow_drawRectangleShape(WIN, fight->monster_area.rect, NULL);
    sfRenderWindow_drawText(WIN, M.txt_name.txt, NULL);
    sfRenderWindow_drawText(WIN, M.monster_hp.txt, NULL);
    sfRenderWindow_drawText(WIN, M.monster_ActualHp.txt, NULL);
}

void fight_display(struct_t *data, fight_t *fight)
{
    sfRenderWindow_clear(WIN, sfBlack);
    sfRenderWindow_setView(WIN, data->view);
    sfRenderWindow_drawSprite(WIN, fight->bg.sprite, NULL);
    for (int i = 0; i < 4; i++) {
        sfRenderWindow_drawRectangleShape(WIN, fight->button[i].rect, NULL);
        sfRenderWindow_drawText(WIN, fight->button[i].txt.txt, NULL);
    }
    fight_display_player(data, fight);
    fight_display_monster(data, fight);
    sfRenderWindow_display(WIN);
}
