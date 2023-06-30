/*
** EPITECH PROJECT, 2023
** csfml_test
** File description:
** my
*/
#include "struct.h"
#include "define.h"

#ifndef MY_H_
    #define MY_H_

void my_putchar(char c);
int my_putstr(char const *str);
int my_strlen(char const *str);
int my_strcmp(const char *s1, const char *s2);

struct_t *init_struct(void);
menu_t *init_menu(void);
void init_colors(menu_t *menu);
void init_menu_buttons(menu_t *menu);
side_menu_t init_side_menu(menu_t *menu);
void init_thickness(menu_t *menu);
void init_value_thickness(menu_t *menu);
void init_shape(menu_t *menu);
void init_color(menu_t *menu);
char *nb_to_str(int nb);
void init_text_arrows(menu_t *menu);

void manage_events(struct_t *data, menu_t *menu);

sfVector2i getMousePosi(struct_t *data, menu_t *menu);
void draw_square(struct_t *data, menu_t *menu, int set, sfVector2i pos);
void draw_circle(struct_t *data, menu_t *menu, int set, sfVector2i pos);
void draw_side_menu(struct_t *data, menu_t *menu, int set_side_menu);

int is_on_color(struct_t *data, menu_t *menu, sfVector2i pos, int i);

void pencil_side_menu(struct_t *data, menu_t * menu);
void eraser_side_menu(struct_t *data, menu_t * menu);
void grid_side_menu(struct_t *data, menu_t * menu);
void file_side_menu(struct_t *data, menu_t * menu);

#endif /* !MY_H_ */
