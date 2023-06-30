/*
** EPITECH PROJECT, 2023
** B-MUL-200-NAN-2-1-myrpg-tibaud.le-maout
** File description:
** collision
*/
#include "../../include/my.h"

int check_hit(struct_t *data, sfVector2f old_pos, sfRectangleShape *rect)
{
    sfFloatRect player_box;
    sfFloatRect wall_box;
    sfColor color;

    color = sfRectangleShape_getFillColor(rect);
    if (color.r == 255) {
        player_box = sfRectangleShape_getGlobalBounds(P.hitbox);
        wall_box = sfRectangleShape_getGlobalBounds(rect);
        if (player_box.left < wall_box.left + wall_box.width &&
            player_box.left + player_box.width > wall_box.left &&
            player_box.top < wall_box.top + wall_box.height &&
            player_box.top + player_box.height > wall_box.top) {
            sfRectangleShape_setPosition(P.hitbox, old_pos);
            return (1);
        }
    }
    return (0);
}

int check_for_fight(struct_t *data, sfRectangleShape *rect)
{
    sfFloatRect player_box;
    sfFloatRect wall_box;
    sfColor color;
    int nb = 0;

    color = sfRectangleShape_getFillColor(rect);
    if (color.g == 255) {
        player_box = sfRectangleShape_getGlobalBounds(P.hitbox);
        wall_box = sfRectangleShape_getGlobalBounds(rect);
        if (player_box.left < wall_box.left + wall_box.width &&
            player_box.left + player_box.width > wall_box.left &&
            player_box.top < wall_box.top + wall_box.height &&
            player_box.top + player_box.height > wall_box.top &&
            P.stat.hp > 0) {
                nb = get_random_number(1, 1);
                // nb = get_random_number(190, 1);
        }
    }
    return (nb);
}

int check_hitbox2(struct_t *data, sfVector2f old_pos, int y)
{
    for (int x = 0; x < 80; x++) {
        if (check_hit(data, old_pos, data->wall[y][x]) == 1)
            return (1);
        // in comment for dev
        /* if (check_for_fight(data, data->wall[y][x]) == 1) {
            data->random_mob_nb = rand() % 5;
            data->set = 6;
        } */
        if (check_interact(data, old_pos, data->wall[y][x]) == 1) {
            is_npc_for_quest(data, data->wall[y][x], data->map);
            return (1);
        }
    }
    return (0);
}

void check_hitbox_false(struct_t *data, int set)
{
    data->interact = 0;
    if (set == 0)
        TUTO.quest_1 = 0;
}

int check_hitbox(struct_t *data, sfVector2f movement)
{
    sfVector2f old_pos = sfRectangleShape_getPosition(P.hitbox);
    sfRectangleShape_move(P.hitbox, movement);

    for (int y = 0; y < 45; y++) {
        if (check_hitbox2(data, old_pos, y) == 1)
            return (1);
        else
            check_hitbox_false(data, data->map);
    }
    return (0);
}
