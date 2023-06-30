/*
** EPITECH PROJECT, 2023
** B-MUL-200-NAN-2-1-myrpg-tibaud.le-maout
** File description:
** collisions_tab
*/
#include "../../include/my.h"

sfRectangleShape *create_rectangle(sfVector2f pos, char *buffer, int idx)
{
    sfRectangleShape *rect = sfRectangleShape_create();
    sfRectangleShape_setSize(rect, (sfVector2f) {24, 24});
    sfRectangleShape_setOutlineColor(rect, sfBlack);
    sfRectangleShape_setOutlineThickness(rect, 2);
    sfRectangleShape_setPosition(rect, pos);

    if (buffer[idx] == '0')
        sfRectangleShape_setFillColor(rect, sfTransparent);
    if (buffer[idx] == '1')
        sfRectangleShape_setFillColor(rect, sfRed);
    if (buffer[idx] == '2')
        sfRectangleShape_setFillColor(rect, sfBlue);
    if (buffer[idx] == '3')
        sfRectangleShape_setFillColor(rect, sfGreen);
        return (rect);
}

sfRectangleShape ***my_str_to_rect_tab(char *buffer, char c)
{
    sfRectangleShape ***tab = malloc(sizeof(sfRectangleShape **) * 45);
    sfVector2f pos = {0, 0};
    int idx = 0;

    for (int y = 0; y < 45; y++) {
        tab[y] = malloc(sizeof(sfRectangleShape *) * 80);
        for (int x = 0; x < 80; x++) {
            tab[y][x] = create_rectangle(pos, buffer, idx);
            idx++;
            pos.x += 24;
        }
        idx++;
        pos.x = 0;
        pos.y += 24;
    }
    return (tab);
}

void get_collision_tab(struct_t *data, char *filepath)
{
    FILE *fp;
    struct stat sb;
    stat(filepath, &sb);
    char *buffer = malloc(sizeof(char) * sb.st_size);

    fp = fopen(filepath, "r");
    fread(buffer, sizeof(char), sb.st_size, fp);
    data->wall = my_str_to_rect_tab(buffer, '\n');
    fclose(fp);
}
