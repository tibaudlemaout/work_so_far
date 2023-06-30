/*
** EPITECH PROJECT, 2023
** Epitech_Jam_1
** File description:
** win
*/
#include "../../include/struct.h"
#include "../../include/my.h"
#include "../../include/define.h"

void init_win_buttons(menu_t *win)
{
    win->buttons = malloc(sizeof(sprite_t) * 2);
    win->buttons[0].sprite = sfSprite_create();
    win->buttons[0].texture = sfTexture_createFromFile("asset/buttons/red_home_button.png", NULL);
    win->buttons[0].scale.y = 6;
    win->buttons[0].scale.x = 6;
    win->buttons[0].pos.y = 850;
    win->buttons[0].pos.x = 320;
    win->buttons[0].rect.top = 0;
    win->buttons[0].rect.left = 0;
    win->buttons[0].rect.height = 20;
    win->buttons[0].rect.width = 43;
    sfSprite_setTextureRect(win->buttons[0].sprite, win->buttons[0].rect);
    sfSprite_setTexture(win->buttons[0].sprite, win->buttons[0].texture, sfFalse);
    sfSprite_setScale(win->buttons[0].sprite, win->buttons[0].scale);
    sfSprite_setPosition(win->buttons[0].sprite, win->buttons[0].pos);

    win->buttons[1].sprite = sfSprite_create();
    win->buttons[1].texture = sfTexture_createFromFile("asset/buttons/red_exit_button.png", NULL);
    win->buttons[1].scale.y = 6;
    win->buttons[1].scale.x = 6;
    win->buttons[1].pos.y = 850;
    win->buttons[1].pos.x = 60;
    win->buttons[1].rect.top = 0;
    win->buttons[1].rect.left = 3;
    win->buttons[1].rect.height = 20;
    win->buttons[1].rect.width = 42;
    sfSprite_setTextureRect(win->buttons[1].sprite, win->buttons[1].rect);
    sfSprite_setTexture(win->buttons[1].sprite, win->buttons[1].texture, sfFalse);
    sfSprite_setScale(win->buttons[1].sprite, win->buttons[1].scale);
    sfSprite_setPosition(win->buttons[1].sprite, win->buttons[1].pos);
}

void init_win_text(menu_t *win)
{
    win->t_title.text = sfText_create();
    win->t_title.font = sfFont_createFromFile("asset/font/prstart.ttf");
    win->t_title.color = sfColor_fromRGB(147, 174, 36);
    win->t_title.pos.y = 300;
    win->t_title.pos.x = 500;
    sfText_setString(win->t_title.text, "YOU WIN");
    sfText_setFont(win->t_title.text, win->t_title.font);
    sfText_setOutlineColor(win->t_title.text, sfBlack);
    sfText_setOutlineThickness(win->t_title.text, 3);
    sfText_setColor(win->t_title.text, win->t_title.color);
    sfText_setCharacterSize(win->t_title.text, 96);
    sfText_setPosition(win->t_title.text, win->t_title.pos);
    return;
}

void init_win(menu_t *win)
{
    win->bg.sprite = sfSprite_create();
    win->bg.texture = sfTexture_createFromFile("asset/backgrounds/win_screen.png", NULL);
    win->bg.scale.x = 2.2;
    win->bg.scale.y = 2.2;
    sfSprite_setTexture(win->bg.sprite, win->bg.texture, sfFalse);
    sfSprite_setScale(win->bg.sprite, win->bg.scale);
    init_win_buttons(win);    
    init_win_text(win);
}

void win_manage_events(struct_t *all, menu_t *win, sfEvent *event)
{
    if (event->type == sfEvtClosed) {
        all->set = 0;
    }
    if (event->type == sfEvtMouseButtonPressed) {
        if (event->mouseButton.x >= win->buttons[0].pos.x && event->mouseButton.x <= win->buttons[0].pos.x + (43 * 6)) {
            if (event->mouseButton.y >= win->buttons[0].pos.y && event->mouseButton.y <= win->buttons[0].pos.y + (20 * 6)) {
                all->set = 1;
            }
        }
        if (event->mouseButton.x >= win->buttons[1].pos.x && event->mouseButton.x <= win->buttons[1].pos.x + (42 * 6)) {
            if (event->mouseButton.y >= win->buttons[1].pos.y && event->mouseButton.y <= win->buttons[1].pos.y + (20 * 6)) {
                all->set = 0;
            }
        }
    }
}

void destroy_win(menu_t *win)
{
    sfSprite_destroy(win->buttons[0].sprite);
    sfSprite_destroy(win->buttons[1].sprite);
    sfSprite_destroy(win->bg.sprite);

    sfTexture_destroy(win->buttons[0].texture);
    sfTexture_destroy(win->buttons[1].texture);
    sfTexture_destroy(win->bg.texture);

    sfText_destroy(win->t_title.text);
    sfFont_destroy(win->t_title.font);

    free(win->buttons);
    return;
}

void win_screen(struct_t *all, sfEvent *event)
{
    menu_t win;
    init_win(&win);
    while (all->set == 5) {
        sfRenderWindow_display(WIN);
        sfRenderWindow_clear(WIN, sfBlue);

        sfRenderWindow_drawSprite(WIN, win.bg.sprite, NULL);
        sfRenderWindow_drawSprite(WIN, win.buttons[0].sprite, NULL);
        sfRenderWindow_drawSprite(WIN, win.buttons[1].sprite, NULL);
        sfRenderWindow_drawText(WIN, win.t_title.text, NULL);

        while (sfRenderWindow_pollEvent(WIN, event)) {
                win_manage_events(all, &win, event);
        }
    }
    destroy_win(&win);
}
