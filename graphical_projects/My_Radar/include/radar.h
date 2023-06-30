/*
** EPITECH PROJECT, 2022
** radar
** File description:
** radar
*/
#include <SFML/Graphics.h>
#include <SFML/System.h>
#include <SFML/Audio.h>
#include <SFML/Window.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <stddef.h>
#include <stdarg.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <math.h>
#include "define.h"
#include "struct.h"

#ifndef RADAR_H
    #define RADAR_H
void play_radar(global_t *data, tower_t *tower, plane_t *plane);
void destroy(global_t *data, tower_t *tower, plane_t *plane);
int cond_printf(const char *format, int i, va_list list);
int my_printf(const char *format, ...);
void my_putchar(char c);
int my_strlen(char const *str);
int my_put_nbr(int nb);
int my_putstr(char const *str);
int my_get_nbr(global_t *data);
int read_script(char **argv, global_t *data, tower_t **tower, plane_t **plane);
void create_tower(global_t *data, tower_t **tower);
void create_plane(global_t *data, plane_t **plane);
void cpy(const char *buff, global_t *data);
int verif_tab(const char *buff);
void move_hitbox(plane_t *plane, global_t *data);
void collision(global_t *data, plane_t *plane, tower_t *tower);
void set_movement(plane_t *plane);
int help_manual(void);
void make_clock(global_t *data, plane_t *plane, tower_t *tower);
void create_hitbox(plane_t *plane, global_t *data);
void create_circle(tower_t *twr, global_t *data);

#endif /* RADAR_H */
