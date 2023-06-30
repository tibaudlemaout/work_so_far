/*
** EPITECH PROJECT, 2023
** B-MUL-200-NAN-2-1-myrpg-tibaud.le-maout
** File description:
** struct
*/
#include "../../include/my.h"

void init_bg(struct_t *data)
{
    data->bg.texture = sfTexture_createFromFile("asset/1vil.png", NULL);
    data->bg.sprite = sfSprite_create();
    data->bg.pos.x = 0;
    data->bg.pos.y = 0;
    sfSprite_setTexture(data->bg.sprite, data->bg.texture, sfTrue);
    sfSprite_setPosition(data->bg.sprite, data->bg.pos);
    data->overlay.texture = sfTexture_createFromFile("asset/1vil3D.png", NULL);
    data->overlay.sprite = sfSprite_create();
    data->overlay.pos.x = 0;
    data->overlay.pos.y = 0;
    sfSprite_setTexture(data->overlay.sprite, data->overlay.texture, sfTrue);
    sfSprite_setPosition(data->overlay.sprite, data->overlay.pos);
}

void init_minimap(struct_t *data)
{
    sfIntRect rect = {200, 100, 1520, 880};
    sfVector2f size = {(rect.width * 0.07), (rect.height * 0.07)};

    data->minimap.texture = sfTexture_createFromFile("asset/1vil.png", NULL);
    data->minimap.sprite = sfSprite_create();
    data->minimap.pos.x = P.pos.x + 144;
    data->minimap.pos.y = P.pos.y - 99;
    data->minimap.rect = rect;
    sfSprite_setScale(data->minimap.sprite, (sfVector2f) {0.07, 0.07});
    sfSprite_setTexture(data->minimap.sprite, data->minimap.texture, sfTrue);
    sfSprite_setTextureRect(data->minimap.sprite, data->minimap.rect);
    sfSprite_setPosition(data->minimap.sprite, data->minimap.pos);
    data->minimapOutline = sfRectangleShape_create();
    sfRectangleShape_setFillColor(data->minimapOutline, sfTransparent);
    sfRectangleShape_setOutlineColor(data->minimapOutline, sfBlack);
    sfRectangleShape_setOutlineThickness(data->minimapOutline, 2);
    sfRectangleShape_setSize(data->minimapOutline, size);
    sfRectangleShape_setPosition(data->minimapOutline, data->minimap.pos);
}

void init_basics(struct_t *data)
{
    H = 1080;
    W = 1920;
    MODE.bitsPerPixel = 32;
    MODE.height = H;
    MODE.width = W;
    WIN = sfRenderWindow_create(MODE, "my_rpg", sfResize | sfClose, NULL);
    sfRenderWindow_setFramerateLimit(WIN, 60);
    data->set = 1;
}

struct_t *init_struct(void)
{
    struct_t *data = malloc(sizeof(struct_t));

    init_basics(data);
    data->fight_start.clock = sfClock_create();
    init_player(data);
    init_bg(data);
    init_minimap(data);
    init_items_tab(data);
    init_inventory(data);
    get_collision_tab(data, "script/Collision1.txt");
    init_mobs_area_1(data);
    init_tutorial(data);
    init_interact_balloon(data);
    init_main_icons(data);
    init_all_quests(data);
    data->old_set = 1;
    data->random_mob_nb = 0;
    data->map = 0;
    return data;
}
