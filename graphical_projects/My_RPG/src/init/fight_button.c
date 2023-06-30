/*
** EPITECH PROJECT, 2023
** B-MUL-200-NAN-2-1-myrpg-tibaud.le-maout
** File description:
** fight_button
*/
#include "../../include/my.h"

void init_shape(fight_t *fight, int i, sfVector2f pos, sfVector2f size)
{
    sfColor grey = sfColor_fromRGB(160, 160, 160);

    fight->button[i].rect = sfRectangleShape_create();
    sfRectangleShape_setFillColor(fight->button[i].rect, grey);
    sfRectangleShape_setOutlineColor(fight->button[i].rect, sfWhite);
    sfRectangleShape_setOutlineThickness(fight->button[i].rect, 3);
    sfRectangleShape_setSize(fight->button[i].rect, size);
    fight->button[i].pos.x = pos.x;
    fight->button[i].pos.y = pos.y;
    sfRectangleShape_setPosition(fight->button[i].rect, pos);
    fight->button[i].display = 1;
    fight->button[i].hover = 0;
}

void init_fight_button_txt(fight_t *fight, int i, sfVector2f pos)
{
    pos.x += 130;
    sfFont *font = sfFont_createFromFile("asset/BreatheFire.otf");
    fight->button[i].txt.txt = sfText_create();
    fight->button[i].txt.color = sfBlack;
    sfText_setFont(fight->button[i].txt.txt, font);
    sfText_setPosition(fight->button[i].txt.txt, pos);
    sfText_setColor(fight->button[i].txt.txt, fight->button[i].txt.color);
    sfText_setCharacterSize(fight->button[i].txt.txt, 70);
}

void assign_txt_to_fight_button(fight_t *fight)
{
    sfText_setString(fight->button[0].txt.txt, "     Strike");
    sfText_setString(fight->button[1].txt.txt, " Shield Bash");
    sfText_setString(fight->button[2].txt.txt, "Rand Armor");
    sfText_setString(fight->button[3].txt.txt, "   Leg Strike");
}

void init_fight_button(fight_t *fight)
{
    sfVector2f position = {50, 805};
    sfVector2f size = {600, 100};
    fight->button = malloc(sizeof(button_t) * 4);

    for (int i = 0; i < 4; i++) {
        init_shape(fight, i, position, size);
        init_fight_button_txt(fight, i, position);
        position.x += size.x + 20;
        if (i == 1) {
            position.y += size.y + 20;
            position.x = 50;
        }
    }
    assign_txt_to_fight_button(fight);
}
