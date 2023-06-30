/*
** EPITECH PROJECT, 2023
** B-MUL-200-NAN-2-1-myrpg-tibaud.le-maout
** File description:
** in_game_menu
*/
#include "../../include/my.h"

menu_t *init_in_game_menu(void)
{
    menu_t *menu = malloc(sizeof(menu_t));

    menu->bg_day.sprite = sfSprite_create();
    menu->bg_day.texture = sfTexture_createFromFile("asset/Menu1.jpg", NULL);
    sfSprite_setTexture(menu->bg_day.sprite, menu->bg_day.texture, sfTrue);
    sfSprite_setScale(menu->bg_day.sprite, (sfVector2f) {0.4, 0.4});
    sfSprite_setPosition(menu->bg_day.sprite, (sfVector2f) {0, 0});
    init_icons(menu);
    return (menu);
}

void in_game_menu_display(struct_t *data, menu_t *menu)
{
    sfRenderWindow_clear(WIN, sfBlack);
    sfRenderWindow_setView(WIN, data->view);
    sfRenderWindow_drawSprite(WIN, menu->bg_day.sprite, NULL);
    for (int i = 0; i < 4; i++) {
        if (i < 2)
            sfRenderWindow_drawSprite(WIN, data->icon[i], NULL);
        sfRenderWindow_drawRectangleShape(WIN, menu->icon[i].button.rect, NULL);
        sfRenderWindow_drawSprite(WIN, menu->icon[i].sprite.sprite, NULL);
        sfRenderWindow_drawText(WIN, menu->icon[i].title.txt, NULL);
    }
    sfRenderWindow_display(WIN);
}

void in_game_menu_loop(struct_t *data)
{
    menu_t *menu = init_in_game_menu();

    reset_view(data);
    while (data->set == 15) {
        while (sfRenderWindow_pollEvent(WIN, &EVENT))
            in_game_menu_manage_events(data, menu);
        in_game_menu_display(data, menu);
    }
    sfView_destroy(data->view);
    free(menu);
}
