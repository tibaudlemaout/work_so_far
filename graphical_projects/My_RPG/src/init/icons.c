/*
** EPITECH PROJECT, 2023
** B-MUL-200-NAN-2-1-myrpg-tibaud.le-maout
** File description:
** icons
*/
#include "../../include/my.h"

button_t init_icon_button(sfVector2f pos)
{
    button_t button;
    sfVector2f size = {180, 180};
    sfColor grey = sfColor_fromRGB(160, 160, 160);

    button.rect = sfRectangleShape_create();
    sfRectangleShape_setFillColor(button.rect, grey);
    sfRectangleShape_setOutlineColor(button.rect, sfWhite);
    sfRectangleShape_setOutlineThickness(button.rect, 4);
    sfRectangleShape_setSize(button.rect, size);
    button.pos.x = pos.x;
    button.pos.y = pos.y;
    sfRectangleShape_setPosition(button.rect, pos);
    return (button);
}

text_t init_icon_text_title(sfVector2f pos, char *title)
{
    text_t text;

    text.font = sfFont_createFromFile("asset/BreatheFire.otf");
    text.txt = sfText_create();
    sfText_setFont(text.txt, text.font);
    sfText_setPosition(text.txt, (sfVector2f) {pos.x, pos.y + 200});
    sfText_setColor(text.txt, sfBlack);
    sfText_setCharacterSize(text.txt, 50);
    sfText_setString(text.txt, title);
    return (text);
}

icon_t init_icon(sfVector2f pos, char *filepath, char *title)
{
    icon_t icon;

    icon.button = init_icon_button(pos);
    icon.title = init_icon_text_title(pos, title);
    icon.sprite.texture = sfTexture_createFromFile(filepath, NULL);
    icon.sprite.sprite = sfSprite_create();
    icon.sprite.pos.x = pos.x;
    icon.sprite.pos.y = pos.y;
    sfSprite_setScale(icon.sprite.sprite, (sfVector2f) {1.3, 1.3});
    sfSprite_setPosition(icon.sprite.sprite, icon.sprite.pos);
    sfSprite_setTexture(icon.sprite.sprite, icon.sprite.texture, sfTrue);
    return (icon);
}

void init_icons(menu_t *menu)
{
    sfVector2f pos = {500, 250};
    sfVector2f offset = {700, 375};
    menu->icon = malloc(sizeof(icon_t) * 4);
    menu->icon[0] = init_icon(pos, "asset/IconBag.png", "Inventory");
    pos.x += offset.x;
    menu->icon[1] = init_icon(pos, "asset/IconMap.png", "    Map");
    pos.x -= offset.x;
    pos.y += offset.y;
    menu->icon[2] = init_icon(pos, "asset/IconTools.png", " Options");
    pos.x += offset.x;
    menu->icon[3] = init_icon(pos, "asset/IconSave.png", "   Save");
}
