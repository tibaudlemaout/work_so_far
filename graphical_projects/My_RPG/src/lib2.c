/*
** EPITECH PROJECT, 2023
** B-MUL-200-NAN-2-1-myrpg-tibaud.le-maout
** File description:
** lib2
*/
#include "../include/my.h"

char *my_strcat(char *dest, char *str)
{
    int i = 0;
    char *ret = malloc(sizeof(char) * (my_strlen(dest) + my_strlen(str) + 1));

    while (dest[i]) {
        ret[i] = dest[i];
        i++;
    }
    for (int idx = 0; str[idx]; idx++) {
        ret[i] = str[idx];
        i++;
    }
    ret[i] = '\0';
    return (ret);
}

sfVector2i get_mouse_position(struct_t *data)
{
    sfVector2i pos;
    pos.x = sfMouse_getPositionRenderWindow(WIN).x;
    pos.y = sfMouse_getPositionRenderWindow(WIN).y;
    return (pos);
}

void reset_view(struct_t *data)
{
    sfVector2f cameraPosition;

    data->view = sfView_create();
    sfView_setSize(data->view, (sfVector2f){1920, 1080});
    sfRenderWindow_setView(WIN, data->view);
    cameraPosition.x = data->settings.width / 2;
    cameraPosition.y = data->settings.height / 2;
    sfView_setCenter(data->view, cameraPosition);
    return;
}

int get_random_number(int max, int range)
{
    int nb = rand() % max;

    if (nb <= range)
        return (1);
    else
        return (0);
}
