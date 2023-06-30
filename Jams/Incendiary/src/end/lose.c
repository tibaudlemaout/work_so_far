/*
** EPITECH PROJECT, 2023
** Epitech_Jam_1
** File description:
** lose
*/
#include "../../include/struct.h"
#include "../../include/my.h"
#include "../../include/define.h"

void init_lose_buttons(menu_t *lose)
{
    lose->buttons = malloc(sizeof(sprite_t) * 2);
    lose->buttons[0].sprite = sfSprite_create();
    lose->buttons[0].texture = sfTexture_createFromFile("asset/buttons/red_home_button.png", NULL);
    lose->buttons[0].scale.y = 6;
    lose->buttons[0].scale.x = 6;
    lose->buttons[0].pos.y = 850;
    lose->buttons[0].pos.x = 1320;
    lose->buttons[0].rect.top = 0;
    lose->buttons[0].rect.left = 0;
    lose->buttons[0].rect.height = 20;
    lose->buttons[0].rect.width = 43;
    sfSprite_setTextureRect(lose->buttons[0].sprite, lose->buttons[0].rect);
    sfSprite_setTexture(lose->buttons[0].sprite, lose->buttons[0].texture, sfFalse);
    sfSprite_setScale(lose->buttons[0].sprite, lose->buttons[0].scale);
    sfSprite_setPosition(lose->buttons[0].sprite, lose->buttons[0].pos);

    lose->buttons[1].sprite = sfSprite_create();
    lose->buttons[1].texture = sfTexture_createFromFile("asset/buttons/red_exit_button.png", NULL);
    lose->buttons[1].scale.y = 6;
    lose->buttons[1].scale.x = 6;
    lose->buttons[1].pos.y = 850;
    lose->buttons[1].pos.x = 1600;
    lose->buttons[1].rect.top = 0;
    lose->buttons[1].rect.left = 3;
    lose->buttons[1].rect.height = 20;
    lose->buttons[1].rect.width = 42;
    sfSprite_setTextureRect(lose->buttons[1].sprite, lose->buttons[1].rect);
    sfSprite_setTexture(lose->buttons[1].sprite, lose->buttons[1].texture, sfFalse);
    sfSprite_setScale(lose->buttons[1].sprite, lose->buttons[1].scale);
    sfSprite_setPosition(lose->buttons[1].sprite, lose->buttons[1].pos);
}

void init_lose_text(menu_t *lose)
{
    lose->t_title.text = sfText_create();
    lose->t_title.font = sfFont_createFromFile("asset/font/prstart.ttf");
    lose->t_title.color = sfColor_fromRGB(147, 174, 36);
    lose->t_title.pos.y = 300;
    lose->t_title.pos.x = 580;
    sfText_setString(lose->t_title.text, "YOU LOSE");
    sfText_setFont(lose->t_title.text, lose->t_title.font);
    sfText_setOutlineColor(lose->t_title.text, sfBlack);
    sfText_setOutlineThickness(lose->t_title.text, 3);
    sfText_setColor(lose->t_title.text, lose->t_title.color);
    sfText_setCharacterSize(lose->t_title.text, 96);
    sfText_setPosition(lose->t_title.text, lose->t_title.pos);
    return;
}

void init_lose(menu_t *lose)
{
    lose->bg.sprite = sfSprite_create();
    lose->bg.texture = sfTexture_createFromFile("asset/backgrounds/lose_screen.png", NULL);
    lose->bg.scale.x = 1.6;
    lose->bg.scale.y = 1.6;
    sfSprite_setTexture(lose->bg.sprite, lose->bg.texture, sfFalse);
    sfSprite_setScale(lose->bg.sprite, lose->bg.scale);
    init_lose_buttons(lose);    
    init_lose_text(lose);
}

void lose_manage_events(struct_t *all, menu_t *lose, sfEvent *event)
{
    if (event->type == sfEvtClosed) {
        all->set = 0;
    }
    if (event->type == sfEvtMouseButtonPressed) {
        if (event->mouseButton.x >= lose->buttons[0].pos.x && event->mouseButton.x <= lose->buttons[0].pos.x + (43 * 6)) {
            if (event->mouseButton.y >= lose->buttons[0].pos.y && event->mouseButton.y <= lose->buttons[0].pos.y + (20 * 6)) {
                all->set = 1;
            }
        }
        if (event->mouseButton.x >= lose->buttons[1].pos.x && event->mouseButton.x <= lose->buttons[1].pos.x + (42 * 6)) {
            if (event->mouseButton.y >= lose->buttons[1].pos.y && event->mouseButton.y <= lose->buttons[1].pos.y + (20 * 6)) {
                all->set = 0;
            }
        }
    }
}

void destroy_lose(menu_t *lose)
{
    sfSprite_destroy(lose->buttons[0].sprite);
    sfSprite_destroy(lose->buttons[1].sprite);
    sfSprite_destroy(lose->bg.sprite);

    sfTexture_destroy(lose->buttons[0].texture);
    sfTexture_destroy(lose->buttons[1].texture);
    sfTexture_destroy(lose->bg.texture);

    sfText_destroy(lose->t_title.text);
    sfFont_destroy(lose->t_title.font);

    free(lose->buttons);
    return;
}

void lose_screen(struct_t *all, sfEvent *event)
{
    menu_t lose;
    init_lose(&lose);
    while (all->set == 4) {
        sfRenderWindow_display(WIN);
        sfRenderWindow_clear(WIN, sfBlue);

        sfRenderWindow_drawSprite(WIN, lose.bg.sprite, NULL);
        sfRenderWindow_drawSprite(WIN, lose.buttons[0].sprite, NULL);
        sfRenderWindow_drawSprite(WIN, lose.buttons[1].sprite, NULL);
        sfRenderWindow_drawText(WIN, lose.t_title.text, NULL);

        while (sfRenderWindow_pollEvent(WIN, event)) {
                lose_manage_events(all, &lose, event);
        }
    }
    destroy_lose(&lose);
}
