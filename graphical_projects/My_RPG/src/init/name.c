/*
** EPITECH PROJECT, 2023
** B-MUL-200-NAN-2-1-myrpg-tibaud.le-maout
** File description:
** name
*/
#include "../../include/my.h"

void init_name_from_menu(menu_t *menu)
{
    menu->name.txt = sfText_create();
    menu->name.font = sfFont_createFromFile("asset/BreatheFire.otf");
    sfText_setFont(menu->name.txt, menu->name.font);
    sfText_setColor(menu->name.txt, sfWhite);
    sfText_setCharacterSize(menu->name.txt, 50);
    sfText_setPosition(menu->name.txt, (sfVector2f){800, 425});
    menu->idx = 0;
    menu->input.sprite = sfSprite_create();
    menu->input.texture = sfTexture_createFromFile("asset/name.png", NULL);
    sfSprite_setTexture(menu->input.sprite, menu->input.texture, sfTrue);
    sfSprite_setPosition(menu->input.sprite, (sfVector2f) {540, 80});
    sfSprite_setScale(menu->input.sprite, (sfVector2f) {1.8, 1.5});
    menu->name_txt.txt = sfText_create();
    menu->name_txt.font = sfFont_createFromFile("asset/BreatheFire.otf");
    sfText_setFont(menu->name_txt.txt, menu->name_txt.font);
    sfText_setColor(menu->name_txt.txt, sfBlack);
    sfText_setCharacterSize(menu->name_txt.txt, 70);
    sfText_setPosition(menu->name_txt.txt, (sfVector2f){760, 250});
    sfText_setString(menu->name_txt.txt, "Enter your name");
}
