/*
** EPITECH PROJECT, 2023
** B-MUL-200-NAN-2-1-myrpg-tibaud.le-maout
** File description:
** finishing_fight
*/
#include "../../include/my.h"

void update_quests_after_fight(struct_t *data)
{
    if (data->winner == 1 && data->map == 1)
        Z1.quest_1++;
    if (data->winner == 1 && data->map == 2 && data->random_mob_nb != 6)
        D1.quest_1++;
    if (data->winner == 1 && data->map == 2 && D1.quest_2 == 0
        && data->random_mob_nb == 6) {
        D1.quest_2 = 1;
        Z1.quest_2 = 1;
        Z1.quest_index++;
    }
}

void init_finishing_fight_txt(struct_t *data, looting_t *looting, int idx)
{
    sfFont *font = sfFont_createFromFile("asset/BreatheFire.otf");

    looting->loot_name = sfText_create();
    sfText_setFont(looting->loot_name, font);
    sfText_setColor(looting->loot_name, sfBlack);
    sfText_setCharacterSize(looting->loot_name, 50);
    sfText_setPosition(looting->loot_name, (sfVector2f) {850, 620});
    sfText_setString(looting->loot_name, data->item[idx].name);
    looting->str = sfText_create();
    sfText_setFont(looting->str, font);
    sfText_setColor(looting->str, sfBlack);
    sfText_setCharacterSize(looting->str, 55);
    sfText_setPosition(looting->str, (sfVector2f) {700, 350});
    sfText_setString(looting->str, "Look, you've got something !\n");
}

looting_t *init_finishing_fight(struct_t *data, int idx)
{
    looting_t *looting = malloc(sizeof(looting_t));
    sfColor grey = sfColor_fromRGB(160, 160, 160);

    looting->bg.sprite = sfSprite_create();
    looting->bg.texture = sfTexture_createFromFile("asset/fight_bg.png", NULL);
    sfSprite_setTexture(looting->bg.sprite, looting->bg.texture, sfTrue);
    looting->rect = sfRectangleShape_create();
    sfRectangleShape_setFillColor(looting->rect, grey);
    sfRectangleShape_setOutlineColor(looting->rect, sfWhite);
    sfRectangleShape_setOutlineThickness(looting->rect, 4);
    sfRectangleShape_setSize(looting->rect, (sfVector2f) {700, 450});
    sfRectangleShape_setPosition(looting->rect, (sfVector2f) {635, 315});
    looting->loot_sprite = sfSprite_create();
    sfSprite_setTexture(looting->loot_sprite, data->item[idx].texture, sfTrue);
    sfSprite_setPosition(looting->loot_sprite, (sfVector2f) {680, 600});
    sfSprite_setScale(looting->loot_sprite, (sfVector2f) {1.5, 1.5});
    init_finishing_fight_txt(data, looting, idx);
    update_quests_after_fight(data);
    return (looting);
}
