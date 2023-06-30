/*
** EPITECH PROJECT, 2023
** B-MUL-200-NAN-2-1-myrpg-tibaud.le-maout
** File description:
** struct2
*/
#include "../../include/my.h"

void init_interact_txt(struct_t *data)
{
    sfVector2f scale = {0.47, 0.2};
    sfTexture * t = sfTexture_createFromFile("asset/TextFrame.png", NULL);

    data->txt_frame.sprite = sfSprite_create();
    sfSprite_setTexture(data->txt_frame.sprite, t, sfTrue);
    sfSprite_setPosition(data->txt_frame.sprite, (sfVector2f) {0, 0});
    sfSprite_setScale(data->txt_frame.sprite, scale);
    data->interact = 0;
    data->talk = 0;
    data->interact_txt.txt = sfText_create();
    data->interact_txt.font = sfFont_createFromFile("asset/BreatheFire.otf");
    sfText_setFont(data->interact_txt.txt, data->interact_txt.font);
    sfText_setFillColor(data->interact_txt.txt, sfBlack);
    sfText_setCharacterSize(data->interact_txt.txt, 20);
    sfText_setString(data->interact_txt.txt, "Press 'T' to interact");
    sfText_setPosition(data->interact_txt.txt, (sfVector2f) {P.pos.x, P.pos.y});
}

void init_interact_balloon(struct_t *data)
{
    sfVector2f scale = {0.5, 0.5};
    sfIntRect rect = {0, 0, 39, 40};
    sfTexture * t = sfTexture_createFromFile("asset/Interaction.png", NULL);

    data->interact_balloon.sprite = sfSprite_create();
    data->interact_balloon.rect = rect;
    sfSprite_setTexture(data->interact_balloon.sprite, t, sfTrue);
    sfSprite_setScale(data->interact_balloon.sprite, scale);
    sfSprite_setTextureRect(data->interact_balloon.sprite, rect);
    data->mark_clock.clock = sfClock_create();
    init_interact_txt(data);
}

sfSprite *init_icon2(sfVector2f pos, char *filepath)
{
    sfSprite *sprite;

    sprite = sfSprite_create();
    sfTexture *texture = sfTexture_createFromFile(filepath, NULL);
    sfSprite_setScale(sprite, (sfVector2f) {0.2, 0.2});
    sfSprite_setPosition(sprite, pos);
    sfSprite_setTexture(sprite, texture, sfTrue);
    return (sprite);
}

void init_main_icons(struct_t *data)
{
    sfVector2f pos = sfSprite_getPosition(P.sprite);

    data->icon = malloc(sizeof(sfSprite *) * 3);
    data->icon[0] = init_icon2((sfVector2f) {30, 30}, "asset/IconBack.png");
    data->icon[1] = init_icon2((sfVector2f) {1805, 30}, "asset/IconInfo.png");
    pos = (sfVector2f) {pos.x - 208, pos.y - 103};
    data->icon[2] = init_icon2(pos, "asset/IconMenu.png");
    sfSprite_setScale(data->icon[2], (sfVector2f) {0.05, 0.05});
}

void init_all_quests(struct_t *data)
{
    TUTO.quest_index = 0;
    TUTO.quest_1 = 0;
    TUTO.end = 0;
    Z1.quest_index = 0;
    Z1.quest_1 = 0;
    Z1.quest_2 = 0;
    Z1.end = 0;
    D1.quest_index = 0;
    D1.quest_1 = 0;
    D1.quest_2 = 0;
    D1.end = 0;
}
