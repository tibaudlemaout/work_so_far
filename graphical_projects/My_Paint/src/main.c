/*
** EPITECH PROJECT, 2023
** Paint
** File description:
** main
*/
#include "../include/my.h"

int is_on_color(struct_t *data, menu_t *menu, sfVector2i pos, int i)
{
    float button_x = menu->b_color[i].pos.x;
    float button_y = menu->b_color[i].pos.y;
    float size_x = menu->b_color[i].size.x;
    float size_y = menu->b_color[i].size.y;

    if (menu->b_color[i].display == 1) {
        if (pos.x >= button_x && pos.x <= button_x + 30 &&
            pos.y >= button_y && pos.y <= button_y + 30) {
            return 1;
        }
    }
    return 0;
}

void display(struct_t *data, menu_t *menu)
{
    sfRenderWindow_clear(WIN, sfBlack);
    sfTexture_updateFromPixels(IMG.texture, (sfUint8 *) PIXEL, W, H, 0, 0);
    sfRenderWindow_drawSprite(WIN, IMG.sprite, NULL);
    if (data->menu == 1) {
        sfRenderWindow_drawSprite(WIN, menu->bg.sprite, NULL);
        sfRenderWindow_drawSprite(WIN, menu->menu.sprite, NULL);
        for (int i = 0; i < 7; i++) {
            if (menu->b_color[i].display == 1) {
                sfRenderWindow_drawRectangleShape(WIN, menu->b_color[i].rect, NULL);
                sfRenderWindow_drawRectangleShape(WIN, menu->b_color_on[data->set_color].rect, NULL);
            }
            if (i < 5 && menu->button[i].display == 1)
                sfRenderWindow_drawRectangleShape(WIN, menu->button[i].rect, NULL);
        }
        if (menu->side_menu.display == 1)
            draw_side_menu(data, menu, menu->side_menu.set);
    }
    sfRenderWindow_display(WIN);
}

void main_loop(void)
{
    struct_t *data = init_struct();
    menu_t *menu = init_menu();
    sfRenderWindow_setMouseCursorVisible(WIN, sfTrue);
    sfRenderWindow_isOpen(WIN);
    while (data->set == 1) {
        while (sfRenderWindow_pollEvent(WIN, &EVENT))
            manage_events(data, menu);
        display(data, menu);
    }
    sfRenderWindow_close(WIN);
    free(menu);
    free(data);
}

int main(int ac, char **av)
{
    if (ac == 2 && my_strcmp(av[1], "-h") == 0) {
        my_putstr("DESCRIPTION\n");
        my_putstr("\t- simple raster graphics editor\n");
        my_putstr("\t- opens, modifies and saves image files in");
        my_putstr(" .jpg and .png\n");
        my_putstr("\t- SPACE key opens tolls menu\n");
        my_putstr("\nno arguments needed\n");
        return 0;
    }
    if (ac > 2) {
        my_putstr("bad arguments, try with -h");
        return 84;
    }
    main_loop();
    return 0;
}
