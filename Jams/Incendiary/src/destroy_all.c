/*
** EPITECH PROJECT, 2023
** Jam
** File description:
** destroy_all
*/
#include "../include/struct.h"
#include "../include/my.h"
#include "../include/define.h"

void destroy_menu(menu_t *menu, struct_t *all)
{
    sfSprite_destroy(menu->bg.sprite);
    sfSprite_destroy(menu->bat.sprite);
    sfSprite_destroy(menu->buttons[0].sprite);
    sfSprite_destroy(menu->buttons[1].sprite);
    sfSprite_destroy(menu->buttons[2].sprite);
    sfSprite_destroy(menu->buttons[3].sprite);

    sfTexture_destroy(menu->bg.texture);
    sfTexture_destroy(menu->bat.texture);
    sfTexture_destroy(menu->buttons[0].texture);
    sfTexture_destroy(menu->buttons[1].texture);
    sfTexture_destroy(menu->buttons[2].texture);
    sfTexture_destroy(menu->buttons[3].texture);

    sfText_destroy(menu->t_title.text);
    sfFont_destroy(menu->t_title.font);
    sfClock_destroy(menu->move_bat.clock);

    free(menu->buttons);

    sfSprite_destroy(P.sprite);
    sfSprite_destroy(all->bg.sprite);
    sfSprite_destroy(all->walls.sprite);
    sfSprite_destroy(all->water.sprite);
    sfSprite_destroy(all->hourglass.sprite);

    sfTexture_destroy(P.TextureDown);
    sfTexture_destroy(P.TextureRight);
    sfTexture_destroy(P.TextureLeft);
    sfTexture_destroy(P.TextureUp);
    sfTexture_destroy(all->bg.texture);
    sfTexture_destroy(all->walls.texture);
    sfTexture_destroy(all->water.TextureDown);
    sfTexture_destroy(all->water.TextureLeft);
    sfTexture_destroy(all->water.TextureRight);
    sfTexture_destroy(all->water.TextureUp);
    sfTexture_destroy(all->hourglass.texture);

    sfMusic_destroy(all->soundtrack[0].music);
    sfMusic_destroy(all->soundtrack[1].music);
    sfMusic_destroy(all->soundtrack[2].music);
    free(all->soundtrack);
    return;
}
