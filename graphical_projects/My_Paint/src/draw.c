/*
** EPITECH PROJECT, 2023
** B-MUL-200-NAN-2-1-mypaint-tibaud.le-maout
** File description:
** draw
*/
#include "../include/my.h"

void draw_side_menu(struct_t *data, menu_t *menu, int set_side_menu)
{
    if (set_side_menu != 0)
        sfRenderWindow_drawRectangleShape(WIN, menu->side_menu.rect[0], NULL);
    if (set_side_menu == 1) {
        printf("pencil side menu\n");
        pencil_side_menu(data, menu);
    }
    if (set_side_menu == 2) {
        printf("eraser side menu\n");
        eraser_side_menu(data, menu);
    }
    if (set_side_menu == 3) {
        printf("grid side menu\n");
    }
    if (set_side_menu == 4) {
        printf("file side menu\n");
    }
}

sfVector2i getMousePosi(struct_t *data, menu_t *menu)
{
    sfVector2i pos;
    pos.x = sfMouse_getPositionRenderWindow(WIN).x - (menu->tools[menu->set_tool].size / 2);
    pos.y = sfMouse_getPositionRenderWindow(WIN).y - (menu->tools[menu->set_tool].size / 2);
    return (pos);
}

void draw_square(struct_t *data, menu_t *menu, int set, sfVector2i pos)
{
    for (int i = 0; i < menu->tools[menu->set_tool].size; i++) {
        for (int j = 0; j < menu->tools[menu->set_tool].size; j++)
            PIXEL[((pos.y + i) * W) + (pos.x + j)] = menu->color[set];
    }
}

void draw_circle(struct_t *data, menu_t *menu, int set, sfVector2i pos)
{
    for (int i = pos.y - menu->tools[menu->set_tool].size; i <= pos.y + menu->tools[menu->set_tool].size; i++) {
        for (int j = pos.x - menu->tools[menu->set_tool].size; j <= pos.x + menu->tools[menu->set_tool].size; j++) {
            if (pow(j - pos.x, 2) + pow(i - pos.y, 2) <= pow(menu->tools[menu->set_tool].size, 2))
                PIXEL[((pos.y + i) * W) + (pos.x + j)] = menu->color[set];
        }
    }
}
