/*
** EPITECH PROJECT, 2023
** Paint
** File description:
** side_menu
*/
#include "../include/my.h"

void file_side_menu(struct_t *data, menu_t * menu)
{
    return;
}

void grid_side_menu(struct_t *data, menu_t * menu)
{
    return;
}

void eraser_side_menu(struct_t *data, menu_t * menu)
{
    for (int i = 0; i < 2; i++)
        sfRenderWindow_drawRectangleShape(WIN, menu->sm_eraser.rect[i], NULL);
    sfRenderWindow_drawText(WIN, menu->txt_thickness.text, NULL);
    sfText_setString(menu->txt_value_thickness.text, nb_to_str(menu->tools[menu->set_tool].size));
    sfRenderWindow_drawText(WIN, menu->txt_value_thickness.text, NULL);
    sfRenderWindow_drawText(WIN, menu->txt_shape.text, NULL);
    for (int i = 0; i < 4; i++) {
        sfRenderWindow_drawRectangleShape(WIN, menu->arrows[i].rect, NULL);
        sfRenderWindow_drawRectangleShape(WIN, menu->arrows_correction[i].rect, NULL);
        sfRenderWindow_drawText(WIN, menu->txt_arrows[i].text, NULL);
    }
    return;
}

void pencil_side_menu(struct_t *data, menu_t * menu)
{
    for (int i = 0; i < 3; i++)
        sfRenderWindow_drawRectangleShape(WIN, menu->sm_pencil.rect[i], NULL);
    sfRenderWindow_drawText(WIN, menu->txt_thickness.text, NULL);
    sfText_setString(menu->txt_value_thickness.text, nb_to_str(menu->tools[menu->set_tool].size));
    sfRenderWindow_drawText(WIN, menu->txt_value_thickness.text, NULL);
    sfRenderWindow_drawText(WIN, menu->txt_shape.text, NULL);
    sfRenderWindow_drawText(WIN, menu->txt_color.text, NULL);
    for (int i = 0; i < 4; i++) {
        sfRenderWindow_drawRectangleShape(WIN, menu->arrows[i].rect, NULL);
        sfRenderWindow_drawRectangleShape(WIN, menu->arrows_correction[i].rect, NULL);
        sfRenderWindow_drawText(WIN, menu->txt_arrows[i].text, NULL);
    }
    return;
}
