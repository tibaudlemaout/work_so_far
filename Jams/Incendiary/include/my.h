/*
** EPITECH PROJECT, 2023
** Epitech_Jam_1
** File description:
** my
*/

#ifndef MY_H_
    #define MY_H_
    #include <SFML/Graphics.h>
    #include <SFML/Window.h>
    #include <SFML/System.h>
    #include <SFML/Audio.h>
    #include <SFML/Graphics/Export.h>
    #include <SFML/Graphics/Color.h>
    #include <SFML/Graphics/Rect.h>
    #include <SFML/Graphics/Transform.h>
    #include <SFML/Graphics/Types.h>
    #include <SFML/System/Vector2.h>
    #include <stddef.h>
    #include <sys/stat.h>
    #include <fcntl.h>
    #include <time.h>
    #include <math.h>
    #include <stdlib.h>
    #include <stdio.h>
    #include <unistd.h>
    #include "struct.h"

void play_game(struct_t *all, sfEvent *event);
void init_game(struct_t *all, sprite_t **fire, sprite_t **obj);
void read_script(struct_t *all, sprite_t **fire, sprite_t **obj);
void init_menu(menu_t *menu);
void fire_detection(struct_t *all, sprite_t *fire);
void countdown(struct_t *all, sprite_t *fire);
void game_manage_events(struct_t *all, sprite_t *fire, sfEvent *event, int map[11][20]);
void play_menu(struct_t *all, menu_t *menu, sfEvent *event);
void play_keybinds(struct_t *all, menu_t *menu, sfEvent *event);
int my_get_nbr(int i, char *str);
void get_fire_script(struct_t *all, char *buffer, int i);
void add_fire(struct_t *all, sprite_t **fire);
void get_object_script(struct_t *all, char *buffer, int i);
void add_object(struct_t *all, sprite_t **obj);
void destroy_menu(menu_t *menu, struct_t *all);
void lose_screen(struct_t *all, sfEvent *event);
void win_screen(struct_t *all, sfEvent *event);
void init_sound(struct_t *all);
void ingame_audio(struct_t *all);
void win_audio(struct_t *all);
void play_villain(struct_t *all, sfEvent *event);

#endif /* !MY_H_ */
