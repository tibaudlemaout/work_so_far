/*
** EPITECH PROJECT, 2023
** Epitech_Jam_1
** File description:
** struct
*/
#include "my.h"

#ifndef STRUCT_H_
    #define STRUCT_H_

    typedef struct audio{
        sfMusic *music;
    }audio_t;

    typedef struct {
        sfVideoMode video_mode;
        sfRenderWindow *window;
        sfEvent event;
        int height;
        int width;
    } window_t;

    typedef struct sprite {
        sfTexture *texture;
        sfSprite *sprite;
        sfVector2f scale;
        sfVector2f pos;
        sfIntRect rect;
        int display;
        int delay;
        int life;
        int number;
        struct sprite *next;
    } sprite_t;

    typedef struct {
        sfText *text;
        sfFont *font;
        sfColor color;
        sfVector2f scale;
        sfVector2f pos;
    } text_t;

    typedef struct countdown {
        sfTime time;
        sfClock *clock;
        float seconds;
    } countdown_t;

    typedef struct {
        sfTexture *TextureUp;
        sfTexture *TextureDown;
        sfTexture *TextureRight;
        sfTexture *TextureLeft;
        sfSprite *sprite;
        sfVector2f scale;
        sfVector2f pos;
        int life;
        int direction;
        int tab_x;
        int tab_y;
    } player_t;

    typedef struct {
        sprite_t bg;
        text_t t_title;
        sprite_t *buttons;
        sprite_t bat;
        sprite_t villain;
        countdown_t move_bat;
    } menu_t;

    typedef struct {
        sprite_t bg;
        text_t *instructions;
        sprite_t *keybinds;
    } menu_key_t;

    typedef struct {
        window_t settings;
        countdown_t seconds;
        countdown_t delay;
        countdown_t damage;
        countdown_t anim_clock;
        player_t player;
        player_t water;
        sprite_t bg;
        sprite_t walls;
        sprite_t pv;
        sprite_t hourglass;
        sprite_t anim_bg;
        sprite_t match;
        player_t smoke;
        text_t countdown;
        audio_t *soundtrack;
        int set;
        int lvl_nb_fire;
        int fire_nb;
        int tmp_x;
        int tmp_y;
        int tmp_delay;
        int tmp_scale;
        char *tmp_filepath;
    } struct_t;

#endif /* !STRUCT_H_ */
