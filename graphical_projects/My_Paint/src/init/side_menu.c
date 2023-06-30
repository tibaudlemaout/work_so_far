/*
** EPITECH PROJECT, 2023
** Paint
** File description:
** side_menu
*/
#include "../../include/my.h"

void init_eraser_side_menu(menu_t *menu)
{
    sfVector2f position = {1450, 3};
    sfVector2f size = {500, 40};
    menu->sm_eraser.rect = malloc(sizeof(sfRectangleShape *) * 2);
    for (int i = 0; i < 2; i++) {
        menu->sm_eraser.rect[i] = sfRectangleShape_create();
        sfRectangleShape_setFillColor(menu->sm_eraser.rect[i], sfBlack);
        sfRectangleShape_setSize(menu->sm_eraser.rect[i], size);
        menu->sm_eraser.pos.x = position.x;
        menu->sm_eraser.pos.y = position.y;
        sfRectangleShape_setPosition(menu->sm_eraser.rect[i], position);
        position.y += 300;
    }
    return;
}

void init_pencil_side_menu(menu_t *menu)
{
    sfVector2f position = {1450, 3};
    sfVector2f size = {500, 40};
    menu->sm_pencil.rect = malloc(sizeof(sfRectangleShape *) * 3);
    for (int i = 0; i < 3; i++) {
        menu->sm_pencil.rect[i] = sfRectangleShape_create();
        sfRectangleShape_setFillColor(menu->sm_pencil.rect[i], sfBlack);
        sfRectangleShape_setSize(menu->sm_pencil.rect[i], size);
        menu->sm_pencil.pos.x = position.x;
        menu->sm_pencil.pos.y = position.y;
        sfRectangleShape_setPosition(menu->sm_pencil.rect[i], position);
        position.y += 300;
    }
    return;
}

void init_arrows_correction(menu_t *menu)
{
    sfVector2f position = {1530, 60};
    sfVector2f size = {30, 50};
    menu->arrows_correction = malloc(sizeof(button_t) * 4);
    for (int i = 0; i < 4; i++) {
        menu->arrows_correction[i].rect = sfRectangleShape_create();
        sfRectangleShape_setFillColor(menu->arrows_correction[i].rect, sfWhite);
        sfRectangleShape_setSize(menu->arrows_correction[i].rect, size);
        sfRectangleShape_setPosition(menu->arrows_correction[i].rect, position);
        if (i == 1)
            position.x += 170;
        else
            position.x += 50;
    }
}

void init_arrows(menu_t *menu)
{
    sfVector2f position = {1530, 60};
    sfVector2f size = {30, 30};
    menu->arrows = malloc(sizeof(button_t) * 4);
    for (int i = 0; i < 4; i++) {
        menu->arrows[i].rect = sfRectangleShape_create();
        sfRectangleShape_setFillColor(menu->arrows[i].rect, sfRed);
        sfRectangleShape_setSize(menu->arrows[i].rect, size);
        sfRectangleShape_setPosition(menu->arrows[i].rect, position);
        sfRectangleShape_setRotation(menu->arrows[i].rect, 45);
        if (i == 1)
            position.x += 200;
        else
            position.x += 50;
    }
}

side_menu_t init_side_menu(menu_t *menu)
{
    side_menu_t side_menu;
    sfVector2f position = {1450, 3};
    sfVector2f size = {500, 1022};
    side_menu.rect = malloc(sizeof(sfRectangleShape *) * 1);
    side_menu.rect[0] = sfRectangleShape_create();
    sfRectangleShape_setFillColor(side_menu.rect[0], sfWhite);
    sfRectangleShape_setOutlineColor(side_menu.rect[0], sfColor_fromRGB(160, 160, 160));
    sfRectangleShape_setOutlineThickness(side_menu.rect[0], 3);
    sfRectangleShape_setSize(side_menu.rect[0], size);
    side_menu.pos.x = position.x;
    side_menu.pos.y = position.y;
    sfRectangleShape_setPosition(side_menu.rect[0], position);
    side_menu.display = 0;
    side_menu.set = 0;
    init_pencil_side_menu(menu);
    init_eraser_side_menu(menu);
    init_thickness(menu);
    init_value_thickness(menu);
    init_shape(menu);
    init_color(menu);
    init_arrows(menu);
    init_arrows_correction(menu);
    init_text_arrows(menu);
    return side_menu;
}
