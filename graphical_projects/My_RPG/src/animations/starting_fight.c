/*
** EPITECH PROJECT, 2023
** B-MUL-200-NAN-2-1-myrpg-tibaud.le-maout
** File description:
** fight
*/
#include "../../include/my.h"

sfRectangleShape **init_starting_fight_animation(void)
{
    sfRectangleShape **rect = malloc(sizeof(sfRectangleShape *) * 32);
    sfVector2f size = {240, 270};
    sfVector2f pos = {0, 0};

    for (int i = 0; i < 33; i++) {
        rect[i] = sfRectangleShape_create();
        sfRectangleShape_setFillColor(rect[i], sfWhite);
        sfRectangleShape_setSize(rect[i], size);
        sfRectangleShape_setPosition(rect[i], pos);
        pos.x += size.x;
        if (i == 7 || i == 15 || i == 23) {
            pos.x = 0;
            pos.y += size.y;
        }
    }
    return (rect);
}

void display_starting_fight(struct_t *data, sfRectangleShape **rect, int max)
{
    sfRenderWindow_clear(WIN, sfBlack);
    sfRenderWindow_setView(WIN, data->view);
    sfRenderWindow_drawSprite(WIN, data->bg.sprite, NULL);
    sfRenderWindow_drawSprite(WIN, P.sprite, NULL);
    for (int i = 0; i < max; i++)
        sfRenderWindow_drawRectangleShape(WIN, rect[i], NULL);
    sfRenderWindow_display(WIN);
}

void check_end(struct_t *data, int starting_fight, int set)
{
    if (starting_fight == 33)
        data->set = set;
}

void starting_fight_animation(struct_t *data, int starting_fight, int set)
{
    sfRectangleShape **rect = init_starting_fight_animation();
    countdown_t clock;

    reset_view(data);
    clock.clock = sfClock_create();
    while (data->set == 6) {
        while (sfRenderWindow_pollEvent(WIN, &EVENT))
            fight_animation_manage_events(data);
        display_starting_fight(data, rect, starting_fight);
        clock.time = sfClock_getElapsedTime(clock.clock);
        clock.seconds = clock.time.microseconds / 1000000.0;
        if (clock.seconds > 0.02) {
            sfClock_restart(clock.clock);
            starting_fight++;
        }
        check_end(data, starting_fight, set);
    }
    free(rect);
    sfClock_destroy(clock.clock);
    return;
}
