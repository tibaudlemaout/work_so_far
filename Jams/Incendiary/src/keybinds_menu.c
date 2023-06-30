/*
** EPITECH PROJECT, 2023
** EPITECH
** File description:
** keybinds_menu
*/
#include "../include/struct.h"
#include "../include/my.h"
#include "../include/define.h"

void display_keybinds(struct_t *all, menu_t *menu, menu_key_t *key)
{
    sfRenderWindow_drawSprite(WIN, key->bg.sprite, NULL);
    sfRenderWindow_drawSprite(WIN, menu->buttons[3].sprite, NULL);
    sfRenderWindow_drawSprite(WIN, key->keybinds[0].sprite, NULL);
    sfRenderWindow_drawSprite(WIN, key->keybinds[1].sprite, NULL);
    sfRenderWindow_drawSprite(WIN, key->keybinds[2].sprite, NULL);
    sfRenderWindow_drawText(WIN, key->instructions[0].text, NULL);
    sfRenderWindow_drawText(WIN, key->instructions[1].text, NULL);
    sfRenderWindow_drawText(WIN, key->instructions[2].text, NULL);
    return;
}

void init_keybinds_bg(menu_key_t *key)
{
    key->bg.texture = sfTexture_createFromFile("asset/backgrounds/keybinds_menu_bg.png", NULL);
    key->bg.sprite = sfSprite_create();
    key->bg.scale.x = 2.3;
    key->bg.scale.y = 2.9;
    sfSprite_setTexture(key->bg.sprite, key->bg.texture, sfFalse);
    sfSprite_setScale(key->bg.sprite, key->bg.scale);
    return;
}

void init_keybinds_sprite(menu_key_t *key)
{
    key->keybinds = malloc(sizeof(sprite_t) * 3);
    key->keybinds[0].sprite = sfSprite_create();
    key->keybinds[0].texture = sfTexture_createFromFile("asset/buttons/zqsd_keybinds.png", NULL);
    key->keybinds[0].scale.y = 5;
    key->keybinds[0].scale.x = 5;
    key->keybinds[0].pos.y = 250;
    key->keybinds[0].pos.x = 300;
    sfSprite_setTexture(key->keybinds[0].sprite, key->keybinds[0].texture, sfFalse);
    sfSprite_setScale(key->keybinds[0].sprite, key->keybinds[0].scale);
    sfSprite_setPosition(key->keybinds[0].sprite, key->keybinds[0].pos);

    key->keybinds[1].sprite = sfSprite_create();
    key->keybinds[1].texture = sfTexture_createFromFile("asset/buttons/arrow_keybinds.png", NULL);
    key->keybinds[1].scale.y = 5;
    key->keybinds[1].scale.x = 5;
    key->keybinds[1].pos.y = 250;
    key->keybinds[1].pos.x = 1000;
    sfSprite_setTexture(key->keybinds[1].sprite, key->keybinds[1].texture, sfFalse);
    sfSprite_setScale(key->keybinds[1].sprite, key->keybinds[1].scale);
    sfSprite_setPosition(key->keybinds[1].sprite, key->keybinds[1].pos);

    key->keybinds[2].sprite = sfSprite_create();
    key->keybinds[2].texture = sfTexture_createFromFile("asset/buttons/spacebar_keybind.png", NULL);
    key->keybinds[2].scale.y = 5;
    key->keybinds[2].scale.x = 5;
    key->keybinds[2].pos.y = 650;
    key->keybinds[2].pos.x = 300;
    sfSprite_setTexture(key->keybinds[2].sprite, key->keybinds[2].texture, sfFalse);
    sfSprite_setScale(key->keybinds[2].sprite, key->keybinds[2].scale);
    sfSprite_setPosition(key->keybinds[2].sprite, key->keybinds[2].pos);
    return;
}

void init_keybinds_text(menu_key_t *key)
{
    key->instructions = malloc(sizeof(text_t) * 3);
    key->instructions[0].text = sfText_create();
    key->instructions[0].font = sfFont_createFromFile("asset/font/prstart.ttf");
    key->instructions[0].pos.y = 420;
    key->instructions[0].pos.x = 300;
    sfText_setFont(key->instructions[0].text, key->instructions[0].font);
    sfText_setString(key->instructions[0].text, "Use 'Z' 'Q' 'S' 'D'\n\nto move around");
    sfText_setColor(key->instructions[0].text, sfWhite);
    sfText_setPosition(key->instructions[0].text, key->instructions[0].pos);
    sfText_setCharacterSize(key->instructions[0].text, 22);

    key->instructions[1].text = sfText_create();
    key->instructions[1].font = sfFont_createFromFile("asset/font/prstart.ttf");
    key->instructions[1].pos.y = 420;
    key->instructions[1].pos.x = 1000;
    sfText_setFont(key->instructions[1].text, key->instructions[1].font);
    sfText_setString(key->instructions[1].text, "Use the arrow keys\n\nto look around");
    sfText_setColor(key->instructions[1].text, sfWhite);
    sfText_setPosition(key->instructions[1].text, key->instructions[1].pos);
    sfText_setCharacterSize(key->instructions[1].text, 22);

    key->instructions[2].text = sfText_create();
    key->instructions[2].font = sfFont_createFromFile("asset/font/prstart.ttf");
    key->instructions[2].pos.y = 730;
    key->instructions[2].pos.x = 300;
    sfText_setFont(key->instructions[2].text, key->instructions[2].font);
    sfText_setString(key->instructions[2].text, "Use the spacebar to use your\n\nwater lance");
    sfText_setColor(key->instructions[2].text, sfWhite);
    sfText_setPosition(key->instructions[2].text, key->instructions[2].pos);
    sfText_setCharacterSize(key->instructions[2].text, 22);
    return;
}

void keybinds_manage_mouse_click(struct_t *all, menu_t *menu, sfEvent *event)
{
    if (event->mouseButton.x >= 1450 && event->mouseButton.x <= 1595) {
        if (event->mouseButton.y >= 820 && event->mouseButton.y <= 890) {
            all->set = 1;
        }
    }
}

void keybinds_manage_event(struct_t *all, sfEvent *event, menu_t *menu)
{
     if (event->type == sfEvtClosed) {
        all->set = 0;
    }
    if (event->type == sfEvtMouseButtonPressed) {
        keybinds_manage_mouse_click(all, menu, event);
    }
    return;
}

void init_keybinds(menu_key_t *key)
{
    init_keybinds_bg(key);
    init_keybinds_sprite(key);
    init_keybinds_text(key);
    return;
}

void destroy_key(menu_key_t *key)
{
    sfSprite_destroy(key->bg.sprite);
    sfTexture_destroy(key->bg.texture);

    sfSprite_destroy(key->keybinds[0].sprite);
    sfSprite_destroy(key->keybinds[1].sprite);
    sfSprite_destroy(key->keybinds[2].sprite);

    sfTexture_destroy(key->keybinds[0].texture);
    sfTexture_destroy(key->keybinds[1].texture);
    sfTexture_destroy(key->keybinds[2].texture);

    sfText_destroy(key->instructions[0].text);
    sfText_destroy(key->instructions[1].text);
    sfText_destroy(key->instructions[2].text);

    sfFont_destroy(key->instructions[0].font);
    sfFont_destroy(key->instructions[1].font);
    sfFont_destroy(key->instructions[2].font);

    free(key->instructions);
    free(key->keybinds);
    return;
}

void play_keybinds(struct_t *all, menu_t *menu, sfEvent *event)
{
    menu_key_t key;
    init_keybinds(&key);
    while (all->set == 2) {
        sfRenderWindow_display(WIN);
        sfRenderWindow_clear(WIN, sfBlack);

        display_keybinds(all, menu, &key);

        while (sfRenderWindow_pollEvent(WIN, event)) {
            keybinds_manage_event(all, event, menu);
        }
    }
    destroy_key(&key);
    return;
}
