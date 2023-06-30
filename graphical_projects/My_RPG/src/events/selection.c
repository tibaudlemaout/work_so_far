/*
** EPITECH PROJECT, 2023
** B-MUL-200-NAN-2-1-myrpg-tibaud.le-maout
** File description:
** selection
*/
#include "../../include/my.h"

void is_avatar_hover(menu_t *menu, sfVector2i posi)
{
    sfVector2f pos;
    int set = menu->personnage;

    for (int i = 0; i < 4; i++) {
        pos = sfSprite_getPosition(FRAME[i].sprite);
        if (posi.x >= pos.x && posi.x <= pos.x + 400)
            sfRectangleShape_setOutlineColor(menu->rect[i], sfWhite);
        else
            sfRectangleShape_setOutlineColor(menu->rect[i], sfTransparent);
    }
    if (set != 0)
        sfRectangleShape_setOutlineColor(menu->rect[set - 1], sfGreen);
    pos = sfSprite_getPosition(menu->sign3.sprite);
    if (posi.x >= pos.x && posi.x <= pos.x + 240 &&
        posi.y >= pos.y - 50 && posi.y <= pos.y + 40)
        sfText_setColor(menu->text[4].txt, sfWhite);
    else
        sfText_setColor(menu->text[4].txt, sfBlack);
}

void selection_avatar_update2(struct_t *data, int avatar)
{
    P.stat.att = 10;
    P.stat.def = 10;
    P.stat.spd = 10;
    switch (avatar) {
        case 1:
            P.stat.att = 15;
            P.stat.def = 15;
            P.stat.spd = 15;
            break;
        case 2:
            P.stat.def = 20;
            break;
        case 3:
            P.stat.att = 20;
            break;
        case 4:
            P.stat.spd = 20;
            break;
    }
    data->set = 4;
}

void selection_avatar_update(struct_t *data, int avatar)
{
    char *str = my_strcat("asset/player/", nbr_to_str(avatar));
    char *Down = my_strcat(str, "Down.png");
    char *Up = my_strcat(str, "Up.png");
    char *Right = my_strcat(str, "Right.png");
    char *Left = my_strcat(str, "Left.png");
    char *Profile = my_strcat(str, "PP.png");
    sfIntRect rect = {47, 0, 47, 48};

    P.TextureDown = sfTexture_createFromFile(Down, NULL);
    P.TextureUp = sfTexture_createFromFile(Up, NULL);
    P.TextureRight = sfTexture_createFromFile(Right, NULL);
    P.TextureLeft = sfTexture_createFromFile(Left, NULL);
    P.profile.texture = sfTexture_createFromFile(Profile, NULL);
    sfSprite_setTexture(P.sprite, P.TextureDown, sfTrue);
    sfSprite_setTexture(P.profile.sprite, P.profile.texture, sfTrue);
    sfSprite_setTextureRect(P.sprite, rect);
    data->avatar = avatar;
    selection_avatar_update2(data, avatar);
}

void is_selec_clicked(struct_t *data, menu_t *menu, sfVector2i posi)
{
    sfVector2f pos;

    for (int i = 0; i < 4; i++) {
        pos = sfRectangleShape_getPosition(menu->rect[i]);
        if (posi.x >= pos.x && posi.x <= pos.x + 216 &&
            posi.y >= pos.y && posi.y <= pos.y + 216)
            menu->personnage = i + 1;
    }
    pos = sfSprite_getPosition(menu->sign3.sprite);
    if (posi.x >= pos.x && posi.x <= pos.x + 240 &&
        posi.y >= pos.y - 50 && posi.y <= pos.y + 40) {
        if (menu->personnage != 0)
            selection_avatar_update(data, menu->personnage);
    }
}

void selection_manage_events(struct_t *data, menu_t *menu)
{
    sfVector2i posi = get_mouse_position(data);

    if (EVENT.type == sfEvtClosed)
        data->set = 0;
    if (EVENT.type == sfEvtMouseButtonReleased && EVENT.key.code == sfMouseLeft)
        is_selec_clicked(data, menu, posi);
    if (EVENT.type == sfEvtMouseMoved && EVENT.type == sfEvtMouseButtonReleased
        && EVENT.key.code == sfMouseLeft)
        is_selec_clicked(data, menu, posi);
    is_avatar_hover(menu, posi);
    if (menu->personnage == 0)
        sfText_setColor(menu->text[4].txt, sfColor_fromRGB(120, 120, 120));
}
