/*
** EPITECH PROJECT, 2023
** Epitech_Jam_1
** File description:
** init_game
*/
#include "../../include/struct.h"
#include "../../include/my.h"
#include "../../include/define.h"

void init_player(struct_t *all)
{
    P.TextureDown = sfTexture_createFromFile("asset/player/PlayerDown.png", NULL);
    P.TextureUp = sfTexture_createFromFile("asset/player/PlayerUp.png", NULL);
    P.TextureRight = sfTexture_createFromFile("asset/player/PlayerRight.png", NULL);
    P.TextureLeft = sfTexture_createFromFile("asset/player/PlayerLeft.png", NULL);
    P.sprite = sfSprite_create();
    P.scale.x = 5;
    P.scale.y = 5;
    P.pos.x = 400;
    P.pos.y = 940;
    P.life = 3;
    P.direction = 3;
    P.tab_x = 5;
    P.tab_y = 10;

    sfSprite_setTexture(P.sprite, P.TextureDown, sfTrue);
    sfSprite_setScale(P.sprite, P.scale);
    sfSprite_setPosition(P.sprite, P.pos);
}

void init_water(struct_t *all)
{
    W.TextureDown = sfTexture_createFromFile("asset/player/WaterDown.png", NULL);
    W.TextureUp = sfTexture_createFromFile("asset/player/WaterUp.png", NULL);
    W.TextureRight = sfTexture_createFromFile("asset/player/WaterRight.png", NULL);
    W.TextureLeft = sfTexture_createFromFile("asset/player/WaterLeft.png", NULL);
    W.sprite = sfSprite_create();
    W.scale.x = 5;
    W.scale.y = 5;
    W.pos.x = 0;
    W.pos.y = 0;
    W.life = 0;

    sfSprite_setTexture(W.sprite, W.TextureDown, sfTrue);
    sfSprite_setScale(W.sprite, W.scale);
    sfSprite_setPosition(W.sprite, W.pos);
}

void init_map(struct_t *all)
{
    all->bg.sprite = sfSprite_create();
    all->bg.texture = sfTexture_createFromFile("asset/backgrounds/map.png", NULL);
    all->bg.scale.x = 5;
    all->bg.scale.y = 5;
    sfSprite_setTexture(all->bg.sprite, all->bg.texture, sfFalse);
    sfSprite_setScale(all->bg.sprite, all->bg.scale);
    all->walls.sprite = sfSprite_create();
    all->walls.texture = sfTexture_createFromFile("asset/backgrounds/walls.png", NULL);
    all->walls.scale.x = 5;
    all->walls.scale.y = 5;
    sfSprite_setTexture(all->walls.sprite, all->walls.texture, sfFalse);
    sfSprite_setScale(all->walls.sprite, all->walls.scale);
}

void init_hourglass_sprite(struct_t *all)
{
    all->hourglass.texture = sfTexture_createFromFile("asset/countdown.png", NULL);
    all->hourglass.sprite = sfSprite_create();
    all->hourglass.scale.x = 5;
    all->hourglass.scale.y = 5;
    all->hourglass.pos.x = 1700;
    all->hourglass.pos.y = 250;
    all->hourglass.rect.top = 0;
    all->hourglass.rect.left = 0;
    all->hourglass.rect.width = 23;
    all->hourglass.rect.height = 35;
    all->hourglass.life = 80;

    sfSprite_setTexture(all->hourglass.sprite, all->hourglass.texture, sfTrue);
    sfSprite_setTextureRect(all->hourglass.sprite, all->hourglass.rect);
    sfSprite_setScale(all->hourglass.sprite, all->hourglass.scale);
    sfSprite_setPosition(all->hourglass.sprite, all->hourglass.pos);
}

void init_hourglass_text(struct_t *all)
{
    sfVector2f scale = {0.8, 0.8};
    all->countdown.text = sfText_create();
    all->countdown.font = sfFont_createFromFile("asset/font/prstart.ttf");
    sfText_setFont(all->countdown.text, all->countdown.font);
    sfText_setCharacterSize(all->countdown.text, 50);
    all->countdown.pos.x = 1720;
    all->countdown.pos.y = 450;
    all->countdown.color = sfColor_fromRGB(255, 255, 255);
    sfText_setPosition(all->countdown.text, all->countdown.pos);
    sfText_setColor(all->countdown.text, all->countdown.color);
    sfText_setScale(all->countdown.text, scale);
    sfText_setString(all->countdown.text, "80");
    sfRenderWindow_drawText(WIN, all->countdown.text, NULL);
}

void init_pv(struct_t *all)
{
    all->pv.sprite = sfSprite_create();
    all->pv.texture = sfTexture_createFromFile("asset/pv/pv03.png", NULL);
    all->pv.scale.x = 5;
    all->pv.scale.y = 5;
    all->pv.pos.x = 1670;
    all->pv.pos.y = 700;
    sfSprite_setTexture(all->pv.sprite, all->pv.texture, sfFalse);
    sfSprite_setScale(all->pv.sprite, all->pv.scale);
    sfSprite_setPosition(all->pv.sprite, all->pv.pos);
}

void init_smoke(struct_t *all)
{
    all->smoke.TextureDown = sfTexture_createFromFile("asset/smoke/smoke_1.png", NULL);
    all->smoke.TextureLeft = sfTexture_createFromFile("asset/smoke/smoke_2.png", NULL);
    all->smoke.TextureRight = sfTexture_createFromFile("asset/smoke/smoke_3.png", NULL);
    all->smoke.TextureUp = sfTexture_createFromFile("asset/smoke/smoke_4.png", NULL);
    all->smoke.sprite = sfSprite_create();
    all->smoke.scale.y = 5;
    all->smoke.scale.x = 5;
    all->smoke.pos.y = 0;
    all->smoke.pos.x = 0;
    sfSprite_setTexture(all->smoke.sprite, all->smoke.TextureDown, sfFalse);
    sfSprite_setScale(all->smoke.sprite, all->smoke.scale);
    sfSprite_setPosition(all->smoke.sprite, all->smoke.pos);
}

void init_game(struct_t *all, sprite_t **fire, sprite_t **obj)
{
    read_script(all, fire, obj);
    init_player(all);
    init_water(all);
    init_map(all);
    init_hourglass_sprite(all);
    init_hourglass_text(all);
    init_pv(all);
    init_smoke(all);
    all->seconds.clock = sfClock_create();
    all->delay.clock = sfClock_create();
    all->damage.clock = sfClock_create();
}