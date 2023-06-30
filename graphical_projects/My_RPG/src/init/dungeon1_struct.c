/*
** EPITECH PROJECT, 2023
** B-MUL-200-NAN-2-1-myrpg-tibaud.le-maout
** File description:
** dungeon1_struct
*/
#include "../../include/my.h"

void dungeon1_set_again_some_sprites(struct_t *data)
{
    sfTexture *bg = sfTexture_createFromFile("asset/1dungeon.png", NULL);
    sfTexture *overlay = sfTexture_createFromFile("asset/1dungeon3D.png", NULL);
    sfVector2f pos = {576, 936};
    sfVector2f cameraPosition;
    sfVector2f pp = sfSprite_getPosition(P.sprite);

    data->view = sfView_create();
    sfView_setSize(data->view, (sfVector2f){480, 270});
    sfRenderWindow_setView(WIN, data->view);
    cameraPosition.x = pos.x + P.rect.width / 2;
    cameraPosition.y = pos.y + P.rect.height / 2;
    sfView_setCenter(data->view, cameraPosition);
    sfSprite_setTexture(data->bg.sprite, bg, sfTrue);
    sfSprite_setTexture(data->minimap.sprite, bg, sfTrue);
    sfSprite_setTexture(data->overlay.sprite, overlay, sfTrue);
    sfSprite_setTextureRect(data->minimap.sprite, data->minimap.rect);
    sfSprite_setTextureRect(P.sprite, (sfIntRect) {47, 0, 47, 48});
    sfRectangleShape_setPosition(P.hitbox, (sfVector2f) {pp.x + 4, pp.y + 15});
}

void init_dungeon1_struct(struct_t *data)
{
    dungeon1_set_again_some_sprites(data);
    data->map = 2;
    data->area = 1;
    data->old_set = 16;
    get_collision_tab(data, "script/Collision1_3.txt");
    init_dungeon_1_npc(data);
    sfText_setColor(data->interact_txt.txt, sfWhite);
}
