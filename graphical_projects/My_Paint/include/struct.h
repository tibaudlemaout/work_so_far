/*
** EPITECH PROJECT, 2023
** csfml_test
** File description:
** struct
*/
#include <SFML/Graphics.h>
#include <SFML/Window.h>
#include <SFML/System.h>
#include <SFML/Audio.h>
#include <stddef.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <time.h>
#include <math.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#ifndef STRUCT_H_
    #define STRUCT_H_

    typedef struct {
        sfVideoMode video_mode;
        sfRenderWindow *window;
        sfEvent event;
        int height;
        int width;
    } window_t;

    typedef struct {
        sfSprite *sprite;
        sfTexture *texture;
        sfVector2f scale;
        sfVector2f pos;
        sfIntRect rect;
    } sprite_t;

    typedef struct text {
        sfText *text;
        sfFont* font;
        sfColor color;
        sfVector2f scale;
        sfVector2f pos;
    } text_t;

    typedef struct button {
        sfRectangleShape *rect;
        sfVector2f pos;
        sfVector2f size;
        text_t text;
        int display;
        int clicked;
    } button_t;

    typedef struct {
        sfColor color;
        int shape;
        int size;
    } tool_t;

    typedef struct {
        sfRectangleShape **rect;
        sfVector2f pos;
        sfVector2f size;
        sfText *text;
        sfFont *font;
        int display;
        int set;
    } side_menu_t;

    typedef struct {
        sprite_t bg;
        sprite_t menu;
        button_t *button;
        button_t *button_on;
        button_t *button_hover;
        button_t *b_color;
        button_t *b_color_on;
        button_t *b_color_hover;
        side_menu_t side_menu;
        side_menu_t sm_pencil;
        side_menu_t sm_eraser;
        side_menu_t sm_grid;
        side_menu_t sm_file;
        sfColor *color;
        tool_t *tools;
        text_t *txt_arrows;
        text_t txt_thickness;
        text_t txt_value_thickness;
        text_t txt_shape;
        text_t txt_color;
        button_t *arrows;
        button_t *arrows_correction;
        int set_tool; // eraser(0), pencil(1)
    } menu_t;

    typedef struct {
        window_t settings;
        sprite_t image;
        sfColor *pixels;
        sfImage *output;
        int set_color;
        int menu;
        int set;
    } struct_t;


#endif /* !STRUCT_H_ */
