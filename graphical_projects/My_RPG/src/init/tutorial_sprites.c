/*
** EPITECH PROJECT, 2023
** B-MUL-200-NAN-2-1-myrpg-tibaud.le-maout
** File description:
** tutorial_sprites
*/
#include "../../include/my.h"

char *init_tutorial_sprites_images(struct_t *data, int i)
{
    char *str = my_strcat("asset/npc/", TUTO.npc[i].name);
    char *Profile = my_strcat(str, "PP.png");
    char *Down = my_strcat(str, "Down.png");
    sfVector2f pos[4] = {{792, 300}, {456, 804}, {528, 804}, {1104, 576}};
    sfTexture *profile_texture = sfTexture_createFromFile(Profile, NULL);

    TUTO.npc[i].sprite = sfSprite_create();
    TUTO.npc[i].profile.sprite = sfSprite_create();
    TUTO.npc[i].profile.texture = sfTexture_createFromFile(Profile, NULL);
    TUTO.npc[i].TextureDown = sfTexture_createFromFile(Down, NULL);
    sfSprite_setTexture(TUTO.npc[i].sprite, TUTO.npc[i].TextureDown, sfTrue);
    sfSprite_setTexture(TUTO.npc[i].profile.sprite, profile_texture, sfTrue);
    sfSprite_setPosition(TUTO.npc[i].sprite, pos[i]);
    sfSprite_setScale(TUTO.npc[i].sprite, (sfVector2f) {0.5, 0.5});
    sfSprite_setScale(TUTO.npc[i].profile.sprite, (sfVector2f) {0.45, 0.45});
    return (str);
}

void set_up_right_left_textures(struct_t *data, int i, char *str)
{
    char *Up;
    char *Right;
    char *Left;

    Up = my_strcat(str, "Up.png");
    Right = my_strcat(str, "Right.png");
    Left = my_strcat(str, "Left.png");
    TUTO.npc[i].TextureUp = sfTexture_createFromFile(Up, NULL);
    TUTO.npc[i].TextureRight = sfTexture_createFromFile(Right, NULL);
    TUTO.npc[i].TextureLeft = sfTexture_createFromFile(Left, NULL);
    sfSprite_setTexture(TUTO.npc[i].sprite, TUTO.npc[i].TextureUp, sfTrue);
    sfSprite_setTexture(TUTO.npc[i].sprite, TUTO.npc[i].TextureRight, sfTrue);
    sfSprite_setTexture(TUTO.npc[i].sprite, TUTO.npc[i].TextureLeft, sfTrue);
}

void init_tutorial_sprites(struct_t *data)
{
    sfIntRect rect = {47, 0, 47, 48};
    char *str;

    for (int i = 0; i < 4; i++) {
        str = init_tutorial_sprites_images(data, i);
        if (i == 3) {
            set_up_right_left_textures(data, i, str);
        }
        sfSprite_setTextureRect(TUTO.npc[i].sprite, rect);
    }
}
