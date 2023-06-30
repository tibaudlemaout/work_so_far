/*
** EPITECH PROJECT, 2023
** B-MUL-200-NAN-2-1-myrpg-tibaud.le-maout
** File description:
** selection
*/
#include "../../include/my.h"

void assign_selection_textures(menu_t *menu)
{
    AVATAR = malloc(sizeof(sprite_t) * 4);
    FRAME = malloc(sizeof(sprite_t) * 8);
    AVATAR[0].texture = sfTexture_createFromFile("asset/player/1PP.png", NULL);
    AVATAR[1].texture = sfTexture_createFromFile("asset/player/2PP.png", NULL);
    AVATAR[2].texture = sfTexture_createFromFile("asset/player/3PP.png", NULL);
    AVATAR[3].texture = sfTexture_createFromFile("asset/player/4PP.png", NULL);
    FRAME[0].texture = sfTexture_createFromFile("asset/Frame1.png", NULL);
    FRAME[1].texture = sfTexture_createFromFile("asset/Frame2.png", NULL);
    FRAME[2].texture = sfTexture_createFromFile("asset/Frame3.png", NULL);
    FRAME[3].texture = sfTexture_createFromFile("asset/Frame4.png", NULL);
    FRAME[4].texture = sfTexture_createFromFile("asset/Frame1.png", NULL);
    FRAME[5].texture = sfTexture_createFromFile("asset/Frame2.png", NULL);
    FRAME[6].texture = sfTexture_createFromFile("asset/Frame3.png", NULL);
    FRAME[7].texture = sfTexture_createFromFile("asset/Frame4.png", NULL);
}

void assign_selection_positions(menu_t *menu)
{
    sfSprite_setPosition(FRAME[0].sprite, (sfVector2f) {145, 155});
    sfSprite_setPosition(FRAME[1].sprite, (sfVector2f) {530, 155});
    sfSprite_setPosition(FRAME[2].sprite, (sfVector2f) {940, 150});
    sfSprite_setPosition(FRAME[3].sprite, (sfVector2f) {1335, 140});
    sfSprite_setPosition(FRAME[4].sprite, (sfVector2f) {145, 505});
    sfSprite_setPosition(FRAME[5].sprite, (sfVector2f) {530, 505});
    sfSprite_setPosition(FRAME[6].sprite, (sfVector2f) {940, 500});
    sfSprite_setPosition(FRAME[7].sprite, (sfVector2f) {1335, 490});
    menu->rect = malloc(sizeof(sfRectangleShape *) * 4);
    for (int i = 0; i < 4; i++) {
        menu->rect[i] = sfRectangleShape_create();
        sfRectangleShape_setSize(menu->rect[i], (sfVector2f) {216, 216});
        sfRectangleShape_setFillColor(menu->rect[i], sfTransparent);
        sfRectangleShape_setOutlineThickness(menu->rect[i], 5);
        sfRectangleShape_setOutlineColor(menu->rect[i], sfTransparent);
        sfVector2f pos = sfSprite_getPosition(AVATAR[i].sprite);
        sfRectangleShape_setPosition(menu->rect[i], pos);
    }
}

void assign_selection_texts(menu_t *menu)
{
    sfVector2f pos;

    menu->stats = malloc(sizeof(text_t) * 4);
    for (int i = 0; i < 4; i++) {
        pos = sfSprite_getPosition(FRAME[i + 4].sprite);
        pos.x += 65;
        pos.y += 80;
        menu->stats[i].font = sfFont_createFromFile("asset/BreatheFire.otf");
        menu->stats[i].txt = sfText_create();
        sfText_setFont(menu->stats[i].txt, menu->stats[i].font);
        sfText_setColor(menu->stats[i].txt, sfWhite);
        sfText_setCharacterSize(menu->stats[i].txt, 60);
        sfText_setPosition(menu->stats[i].txt, pos);
    }
    sfText_setString(menu->stats[0].txt, "Att    15\nDef    15\nSpd    10");
    sfText_setString(menu->stats[1].txt, "Att    10\nDef    20\nSpd    10");
    sfText_setString(menu->stats[2].txt, "Att    20\nDef    10\nSpd    10");
    sfText_setString(menu->stats[3].txt, "Att    10\nDef    10\nSpd    20");
}

void init_selection_from_menu(menu_t *menu)
{
    sfVector2f PlayerPos = {200, 200};

    assign_selection_textures(menu);
    for (int i = 0; i < 8; i++) {
        if (i < 4) {
            AVATAR[i].sprite = sfSprite_create();
            sfSprite_setTexture(AVATAR[i].sprite, AVATAR[i].texture, sfTrue);
            sfSprite_setScale(AVATAR[i].sprite, (sfVector2f) {1.5, 1.5});
            sfSprite_setPosition(AVATAR[i].sprite, PlayerPos);
            PlayerPos.x += 400;
        }
        FRAME[i].sprite = sfSprite_create();
        sfSprite_setTexture(FRAME[i].sprite, FRAME[i].texture, sfTrue);
        if (i < 4)
            sfSprite_setScale(FRAME[i].sprite, (sfVector2f) {2, 2});
        else
            sfSprite_setScale(FRAME[i].sprite, (sfVector2f) {2, 2.5});
    }
    assign_selection_positions(menu);
    assign_selection_texts(menu);
}
