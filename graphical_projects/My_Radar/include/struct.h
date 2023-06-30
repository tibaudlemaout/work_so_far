/*
** EPITECH PROJECT, 2022
** EPITECH
** File description:
** struct
*/
#include <SFML/Graphics.h>
#include <SFML/System.h>
#include <SFML/Audio.h>
#include <SFML/Window.h>

#ifndef STRUCT_H_
    #define STRUCT_H_

    typedef struct global {
        sfRenderWindow *window;
        sfClock *clock;
        sfClock *timer;
        sfTime plane_timer;
        sfTime time;
        sfSprite *map;
        sfTexture *map_txt;
        sfSprite *done;
        sfTexture *done_txt;
        float seconds;
        float disp_timer;
        int take_off_timer;
        int fd;
        char **tab;
        int tab_y;
        int tab_x;
        int layers;
        int columns;
        int towers;
        int tx_pos;
        int ty_pos;
        int t_rds;
        int planes;
        int px_str;
        int py_str;
        int px_end;
        int py_end;
        int p_spd;
        int p_take_off;
        int sprite_view;
        int view_hitbox;
        int end_value;
    } global_t;

    typedef struct tower {
        sfSprite *sprite;
        sfTexture *texture;
        sfVector2f t_pos;
        float rds;
        int sprite_vis;
        int circle_vis;
        struct tower *T2;
    } tower_t;

    typedef struct plane {
        sfSprite *sprite;
        sfTexture *texture;
        sfVector2f a_pos;
        sfVector2f end_pos;
        sfVector2f mvmt;
        float speed;
        int str_flight;
        int done;
        int invuln;
        struct plane *P2;
    } plane_t;

#endif /* !STRUCT_H_ */
