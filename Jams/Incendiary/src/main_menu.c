/*
** EPITECH PROJECT, 2023
** EPITECH
** File description:
** main_menu
*/
#include "../include/struct.h"
#include "../include/my.h"
#include "../include/define.h"

void display_menu(struct_t *all, menu_t *menu)
{
    sfRenderWindow_drawSprite(WIN, menu->bg.sprite, NULL);
    sfRenderWindow_drawSprite(WIN, menu->bat.sprite, NULL);
    sfRenderWindow_drawText(WIN, menu->t_title.text, NULL);
    sfRenderWindow_drawSprite(WIN, menu->buttons[0].sprite, NULL);
    sfRenderWindow_drawSprite(WIN, menu->buttons[1].sprite, NULL);
    sfRenderWindow_drawSprite(WIN, menu->buttons[2].sprite, NULL);
    sfRenderWindow_drawSprite(WIN, menu->villain.sprite, NULL);
    return;
}

void init_menu_bg(menu_t *menu)
{
    menu->bg.texture = sfTexture_createFromFile("asset/backgrounds/main_menu_bg.png", NULL);
    menu->bg.sprite = sfSprite_create();
    menu->bg.scale.x = 2.3;
    menu->bg.scale.y = 2.9;
    sfSprite_setTexture(menu->bg.sprite, menu->bg.texture, sfFalse);
    sfSprite_setScale(menu->bg.sprite, menu->bg.scale);
    return;
}

void init_buttons(menu_t *menu)
{
    menu->buttons = malloc(sizeof(sprite_t) * 4);
    menu->buttons[0].sprite = sfSprite_create();
    menu->buttons[0].texture = sfTexture_createFromFile("asset/buttons/red_play_button.png", NULL);
    menu->buttons[0].scale.y = 4;
    menu->buttons[0].scale.x = 4;
    menu->buttons[0].pos.y = 695;
    menu->buttons[0].pos.x = 470;
    menu->buttons[0].rect.top = 0;
    menu->buttons[0].rect.left = 0;
    menu->buttons[0].rect.height = 20;
    menu->buttons[0].rect.width = 39;
    sfSprite_setTextureRect(menu->buttons[0].sprite, menu->buttons[0].rect);
    sfSprite_setTexture(menu->buttons[0].sprite, menu->buttons[0].texture, sfFalse);
    sfSprite_setScale(menu->buttons[0].sprite, menu->buttons[0].scale);
    sfSprite_setPosition(menu->buttons[0].sprite, menu->buttons[0].pos);

    menu->buttons[1].sprite = sfSprite_create();
    menu->buttons[1].texture = sfTexture_createFromFile("asset/buttons/red_exit_button.png", NULL);
    menu->buttons[1].scale.y = 4;
    menu->buttons[1].scale.x = 4;
    menu->buttons[1].pos.y = 695;
    menu->buttons[1].pos.x = 990;
    menu->buttons[1].rect.top = 0;
    menu->buttons[1].rect.left = 3;
    menu->buttons[1].rect.height = 20;
    menu->buttons[1].rect.width = 42;
    sfSprite_setTextureRect(menu->buttons[1].sprite, menu->buttons[1].rect);
    sfSprite_setTexture(menu->buttons[1].sprite, menu->buttons[1].texture, sfFalse);
    sfSprite_setScale(menu->buttons[1].sprite, menu->buttons[1].scale);
    sfSprite_setPosition(menu->buttons[1].sprite, menu->buttons[1].pos);

    menu->buttons[2].sprite = sfSprite_create();
    menu->buttons[2].texture = sfTexture_createFromFile("asset/buttons/red_options_button.png", NULL);
    menu->buttons[2].scale.y = 4;
    menu->buttons[2].scale.x = 4;
    menu->buttons[2].pos.y = 695;
    menu->buttons[2].pos.x = 725;
    menu->buttons[2].rect.top = 0;
    menu->buttons[2].rect.left = 0;
    menu->buttons[2].rect.height = 20;
    menu->buttons[2].rect.width = 44;
    sfSprite_setTextureRect(menu->buttons[2].sprite, menu->buttons[2].rect);
    sfSprite_setTexture(menu->buttons[2].sprite, menu->buttons[2].texture, sfFalse);
    sfSprite_setScale(menu->buttons[2].sprite, menu->buttons[2].scale);
    sfSprite_setPosition(menu->buttons[2].sprite, menu->buttons[2].pos);

    menu->buttons[3].sprite = sfSprite_create();
    menu->buttons[3].texture = sfTexture_createFromFile("asset/buttons/red_home_button.png", NULL);
    menu->buttons[3].scale.y = 4;
    menu->buttons[3].scale.x = 4;
    menu->buttons[3].pos.y = 815;
    menu->buttons[3].pos.x = 1425;
    menu->buttons[3].rect.top = 0;
    menu->buttons[3].rect.left = 0;
    menu->buttons[3].rect.height = 20;
    menu->buttons[3].rect.width = 43;
    sfSprite_setTextureRect(menu->buttons[3].sprite, menu->buttons[3].rect);
    sfSprite_setTexture(menu->buttons[3].sprite, menu->buttons[3].texture, sfFalse);
    sfSprite_setScale(menu->buttons[3].sprite, menu->buttons[3].scale);
    sfSprite_setPosition(menu->buttons[3].sprite, menu->buttons[3].pos);
    return;
}

void init_text_title(menu_t *menu)
{
    menu->t_title.text = sfText_create();
    menu->t_title.font = sfFont_createFromFile("asset/font/prstart.ttf");
    menu->t_title.color = sfColor_fromRGB(147, 174, 36);
    menu->t_title.pos.y = 200;
    menu->t_title.pos.x = 500;
    sfText_setString(menu->t_title.text, "INCENDIARY");
    sfText_setFont(menu->t_title.text, menu->t_title.font);
    sfText_setOutlineColor(menu->t_title.text, sfBlack);
    sfText_setOutlineThickness(menu->t_title.text, 3);
    sfText_setColor(menu->t_title.text, menu->t_title.color);
    sfText_setCharacterSize(menu->t_title.text, 96);
    sfText_setPosition(menu->t_title.text, menu->t_title.pos);
    return;
}

void init_bat(menu_t *menu)
{
    menu->bat.sprite = sfSprite_create();
    menu->bat.rect.top = 0;
    menu->bat.rect.left = 0;
    menu->bat.rect.height = 65;
    menu->bat.rect.width = 97;
    menu->bat.scale.y = 1;
    menu->bat.scale.x = 1;
    menu->bat.pos.y = 225;
    menu->bat.pos.x = -150;
    menu->bat.texture = sfTexture_createFromFile("asset/flying_bat_full.png", NULL);
    sfSprite_setTexture(menu->bat.sprite, menu->bat.texture, sfFalse);
    sfSprite_setTextureRect(menu->bat.sprite, menu->bat.rect);
    sfSprite_setPosition(menu->bat.sprite, menu->bat.pos);
    sfSprite_setScale(menu->bat.sprite, menu->bat.scale);

    return;
}

void init_villain(menu_t *menu)
{
    menu->villain.texture = sfTexture_createFromFile("asset/BadGuy.png", NULL);
    menu->villain.sprite = sfSprite_create();
    menu->villain.scale.x = 0.1;
    menu->villain.scale.y = 0.1;
    menu->villain.pos.x = 520;
    menu->villain.pos.y = 445;

    sfSprite_setTexture(menu->villain.sprite, menu->villain.texture, sfTrue);
    sfSprite_setScale(menu->villain.sprite, menu->villain.scale);
    sfSprite_setPosition(menu->villain.sprite, menu->villain.pos);
}

void init_menu(menu_t *menu)
{
    init_menu_bg(menu);
    init_text_title(menu);
    init_buttons(menu);
    init_bat(menu);
    init_villain(menu);
    return;
}

void menu_manage_mouse_click(struct_t *all, menu_t *menu, sfEvent *event)
{
    if (event->mouseButton.x >= 475 && event->mouseButton.x <= 620) {
        if (event->mouseButton.y >= 703 && event->mouseButton.y <= 765) {
            all->set = 6;
        }
    }
    if (event->mouseButton.x >= 730 && event->mouseButton.x <= 895) {
        if (event->mouseButton.y >= 700 && event->mouseButton.y <= 770) {
            all->set = 2;
        }
    }
    if (event->mouseButton.x >= 1000 && event->mouseButton.x <= 1150) {
        if (event->mouseButton.y >= 700 && event->mouseButton.y <= 770) {
            all->set = 0;
        }
    }
}

void menu_manage_event(struct_t *all, sfEvent *event, menu_t *menu)
{
    if (event->type == sfEvtClosed) {
        all->set = 0;
    }
    if (event->type == sfEvtMouseButtonPressed) {
        menu_manage_mouse_click(all, menu, event);
    }
    return;
}

void handle_menu_clock(menu_t *menu)
{
    menu->move_bat.time = sfClock_getElapsedTime(menu->move_bat.clock);
    menu->move_bat.seconds = menu->move_bat.time.microseconds / 1000000.0;
    if (menu->move_bat.seconds > 0.1) {
        menu->bat.pos.x += 10;
        menu->bat.rect.left += 97;
        if (menu->bat.pos.x > 1920)
            menu->bat.pos.x = -150;
        if (menu->bat.rect.left > 580)
            menu->bat.rect.left = 0;
        sfSprite_setPosition(menu->bat.sprite, menu->bat.pos);
        sfSprite_setTextureRect(menu->bat.sprite, menu->bat.rect);
        sfClock_restart(menu->move_bat.clock);
    }
    return;
}

void play_menu(struct_t *all, menu_t *menu, sfEvent *event)
{
    menu->move_bat.clock = sfClock_create();
    while (all->set == 1) {
        sfRenderWindow_display(WIN);
        sfRenderWindow_clear(WIN, sfBlack);

        handle_menu_clock(menu);
        display_menu(all, menu);

        while (sfRenderWindow_pollEvent(WIN, event)) {
            menu_manage_event(all, event, menu);
        }
    }
    return;
}
