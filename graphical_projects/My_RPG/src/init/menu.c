/*
** EPITECH PROJECT, 2023
** B-MUL-200-NAN-2-1-myrpg-tibaud.le-maout
** File description:
** menu
*/
#include "../../include/my.h"

sprite_t init_menu_sprite(char *filepath, sfVector2f pos, sfVector2f scale)
{
    sprite_t sprite;

    sprite.sprite = sfSprite_create();
    sprite.texture = sfTexture_createFromFile(filepath, NULL);
    sfSprite_setTexture(sprite.sprite, sprite.texture, sfTrue);
    sfSprite_setScale(sprite.sprite, scale);
    sfSprite_setPosition(sprite.sprite, pos);
    return (sprite);
}

void init_menu_signs(menu_t *menu)
{
    sfVector2f sign1_pos = {1050, 450};
    sfVector2f sign1_scl = {0.7, 0.7};
    sfVector2f sign2_pos = {300, 825};
    sfVector2f sign2_scl = {0.4, 0.4};
    sfVector2f sign3_pos = {1650, 950};
    sfVector2f sign3_scl = {0.3, 0.3};

    menu->sign1 = init_menu_sprite("asset/Sign1.png", sign1_pos, sign1_scl);
    menu->sign2 = init_menu_sprite("asset/Sign2.png", sign2_pos, sign2_scl);
    menu->sign3 = init_menu_sprite("asset/Sign3.png", sign3_pos, sign3_scl);
}

void init_menu_signs_texts(menu_t *menu)
{
    menu->text = malloc(sizeof(text_t) * 6);
    for (int i = 0; i < 6; i++) {
        menu->text[i].font = sfFont_createFromFile("asset/BreatheFire.otf");
        menu->text[i].txt = sfText_create();
        sfText_setFont(menu->text[i].txt, menu->text[i].font);
        sfText_setColor(menu->text[i].txt, sfBlack);
        sfText_setCharacterSize(menu->text[i].txt, 50);
    }
    sfText_setPosition(menu->text[0].txt, (sfVector2f) {1145, 500});
    sfText_setString(menu->text[0].txt, "Start");
    sfText_setPosition(menu->text[1].txt, (sfVector2f) {1120, 585});
    sfText_setString(menu->text[1].txt, "Continue");
    sfText_setPosition(menu->text[2].txt, (sfVector2f) {1120, 673});
    sfText_setString(menu->text[2].txt, "Settings");
    sfText_setPosition(menu->text[3].txt, (sfVector2f) {340, 880});
    sfText_setString(menu->text[3].txt, "Quit");
    sfText_setPosition(menu->text[4].txt, (sfVector2f) {1720, 960});
    sfText_setString(menu->text[4].txt, "Next");
    sfText_setPosition(menu->text[5].txt, (sfVector2f) {1720, 960});
    sfText_setString(menu->text[5].txt, "Play");
}

menu_t *init_menu(void)
{
    menu_t *menu = malloc(sizeof(menu_t));
    sfVector2f bg_scale = {0.4, 0.4};
    sfVector2f bg_pos = {0, 0};
    menu->bg_day = init_menu_sprite("asset/Menu1.jpg", bg_pos, bg_scale);
    menu->bg_night = init_menu_sprite("asset/Menu2.jpg", bg_pos, bg_scale);
    menu->bg_selection = init_menu_sprite("asset/Menu3.jpg", bg_pos, bg_scale);
    menu->personnage = 0;
    init_menu_signs(menu);
    init_menu_signs_texts(menu);
    init_selection_from_menu(menu);
    init_name_from_menu(menu);
    return (menu);
}
