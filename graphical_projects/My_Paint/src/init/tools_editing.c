/*
** EPITECH PROJECT, 2023
** Paint
** File description:
** tools_editing
*/
#include "../../include/my.h"

void init_color(menu_t *menu)
{
    sfVector2f scale = {2, 2};
    sfVector2f pos = {1460, 610};
    menu->txt_color.text = sfText_create();
    menu->txt_color.font = sfFont_createFromFile("assets/sserif.ttf");
    menu->txt_color.color = sfWhite;
    sfText_setFont(menu->txt_color.text, menu->txt_color.font);
    sfText_setScale(menu->txt_color.text, scale);
    sfText_setPosition(menu->txt_color.text, pos);
    sfText_setColor(menu->txt_color.text, menu->txt_color.color);
    sfText_setCharacterSize(menu->txt_color.text, 11);
    sfText_setString(menu->txt_color.text, "Color");
    return;
}

void init_shape(menu_t *menu)
{
    sfVector2f scale = {2, 2};
    sfVector2f pos = {1460, 310};
    menu->txt_shape.text = sfText_create();
    menu->txt_shape.font = sfFont_createFromFile("assets/sserif.ttf");
    menu->txt_shape.color = sfWhite;
    sfText_setFont(menu->txt_shape.text, menu->txt_shape.font);
    sfText_setScale(menu->txt_shape.text, scale);
    sfText_setPosition(menu->txt_shape.text, pos);
    sfText_setColor(menu->txt_shape.text, menu->txt_shape.color);
    sfText_setCharacterSize(menu->txt_shape.text, 11);
    sfText_setString(menu->txt_shape.text, "Shape");
    return;
}

void init_thickness(menu_t *menu)
{
    sfVector2f scale = {2, 2};
    sfVector2f pos = {1460, 10};
    menu->txt_thickness.text = sfText_create();
    menu->txt_thickness.font = sfFont_createFromFile("assets/sserif.ttf");
    menu->txt_thickness.color = sfWhite;
    sfText_setFont(menu->txt_thickness.text, menu->txt_thickness.font);
    sfText_setScale(menu->txt_thickness.text, scale);
    sfText_setPosition(menu->txt_thickness.text, pos);
    sfText_setColor(menu->txt_thickness.text, menu->txt_thickness.color);
    sfText_setCharacterSize(menu->txt_thickness.text, 11);
    sfText_setString(menu->txt_thickness.text, "Thickness");
    return;
}

char *nb_to_str(int nb)
{
    char *str = malloc(sizeof(char) * 6);
    int div = 1;
    int i = 0;

    for (div; nb / div > 9; div *= 10);
    for (div; div > 1; div /= 10) {
        str[i] = (nb / div) % 10 + '0';
        i++;
    }
    str[i] = (nb % 10) + '0';
    str[i + 1] = '\0';
    return str;
}

void init_value_thickness(menu_t *menu)
{
    sfVector2f scale = {2, 2};
    sfVector2f pos = {1665, 70};
    menu->txt_value_thickness.text = sfText_create();
    menu->txt_value_thickness.font = sfFont_createFromFile("assets/sserif.ttf");
    menu->txt_value_thickness.color = sfBlack;
    sfText_setFont(menu->txt_value_thickness.text, menu->txt_value_thickness.font);
    sfText_setScale(menu->txt_value_thickness.text, scale);
    sfText_setPosition(menu->txt_value_thickness.text, pos);
    sfText_setColor(menu->txt_value_thickness.text, menu->txt_value_thickness.color);
    sfText_setCharacterSize(menu->txt_value_thickness.text, 11);
    sfText_setString(menu->txt_value_thickness.text, nb_to_str(menu->tools[menu->set_tool].size));
    return;
}

void init_text_arrows(menu_t *menu)
{
    sfVector2f scale = {2, 2};
    sfVector2f pos = {1510, 115};
    menu->txt_arrows = malloc(sizeof(text_t) * 4);
    for (int i = 0; i < 4; i++) {
        menu->txt_arrows[i].text = sfText_create();
        menu->txt_arrows[i].font = sfFont_createFromFile("assets/sserif.ttf");
        menu->txt_arrows[i].color = sfBlack;
        sfText_setFont(menu->txt_arrows[i].text, menu->txt_arrows[i].font);
        sfText_setScale(menu->txt_arrows[i].text, scale);
        sfText_setPosition(menu->txt_arrows[i].text, pos);
        sfText_setColor(menu->txt_arrows[i].text, menu->txt_arrows[i].color);
        sfText_setCharacterSize(menu->txt_arrows[i].text, 8);
        if (i == 1)
            pos.x += 200;
        else
            pos.x += 60;
    }
    sfText_setString(menu->txt_arrows[0].text, "+10");
    sfText_setString(menu->txt_arrows[1].text, "+1");
    sfText_setString(menu->txt_arrows[2].text, "-1");
    sfText_setString(menu->txt_arrows[3].text, "-10");
    return;
}
