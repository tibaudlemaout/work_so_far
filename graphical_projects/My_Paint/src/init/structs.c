/*
** EPITECH PROJECT, 2023
** Paint
** File description:
** struct
*/
#include "../../include/my.h"

tool_t *init_tools(void)
{
    tool_t *tools = malloc(sizeof(tool_t) * 2);
    
    tools[0].color = sfTransparent;
    tools[0].shape = 1;
    tools[0].size = 20;
    tools[1].color = sfBlack;
    tools[1].shape = 1;
    tools[1].size = 10;
    return tools;
}

void init_menu_design(menu_t *menu)
{
    menu->bg.sprite = sfSprite_create();
    menu->bg.texture = sfTexture_createFromFile("assets/smoke_4.png", NULL);
    sfVector2f scale1 = {4, 4};
    sfSprite_setTexture(menu->bg.sprite, menu->bg.texture, sfTrue);
    sfSprite_setScale(menu->bg.sprite, scale1);
    menu->menu.sprite = sfSprite_create();
    menu->menu.texture = sfTexture_createFromFile("assets/menu.png", NULL);
    sfVector2f pos = {725, 400};
    sfVector2f scale2 = {0.6, 0.6};
    sfSprite_setTexture(menu->menu.sprite, menu->menu.texture, sfTrue);
    sfSprite_setPosition(menu->menu.sprite, pos);
    sfSprite_setScale(menu->menu.sprite, scale2);
}

menu_t *init_menu(void)
{
    menu_t *menu = malloc(sizeof(menu_t));
    menu->color = malloc(sizeof(sfColor) * 8);
    menu->color[0] = sfBlack;
    menu->color[1] = sfWhite;
    menu->color[2] = sfRed;
    menu->color[3] = sfGreen;
    menu->color[4] = sfBlue;
    menu->color[5] = sfYellow;
    menu->color[6] = sfMagenta;
    menu->set_tool = 1;
    menu->tools = init_tools();
    menu->side_menu = init_side_menu(menu);
    init_menu_design(menu);
    init_colors(menu);
    init_menu_buttons(menu);
    return menu;
}

struct_t *init_struct(void)
{
    struct_t *data = malloc(sizeof(struct_t));
    H = 1080;
    W = 1920;
    MODE.bitsPerPixel = 32;
    MODE.height = H;
    MODE.width = W;
    WIN = sfRenderWindow_create(MODE, "my_paint", sfResize | sfClose, NULL);
    sfRenderWindow_setFramerateLimit(WIN, 60);
    IMG.sprite = sfSprite_create();
    IMG.texture = sfTexture_create(W, H);
    sfSprite_setTexture(IMG.sprite, IMG.texture, sfTrue);
    PIXEL = malloc(sizeof(sfColor) * (W * H));
    for (int i = 0; i < (H * W); i++)
        PIXEL[i] = sfWhite;       // background color choosed
    data->set_color = 0;
    data->menu = 1;
    data->set = 1;
    return data;
}
