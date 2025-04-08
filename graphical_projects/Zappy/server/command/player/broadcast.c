/*
** EPITECH PROJECT, 2024
** Appzy
** File description:
** Main loop for server
*/

/**
 * @file broadcast.c
 * @brief File containing functions for the broadcast AI command
*/

#include "../../include/zappy_server.h"

/**
 * @brief function that returns the absolute value
 * @param n the number to pass at absolute
 * @return the absolute val of the given integer
*/
static int absolute(int n)
{
    if (n < 0)
        n *= -1;
    return (n);
}

/**
 * @brief function that returns the shortest length
 * @param x1 the first x position
 * @param x2 the second x position
 * @param full_length the total length
 * @return the shortest length
*/
static int get_shorter(int x1, int x2, int full_length)
{
    int res = x2 - x1;

    if (absolute(res) > full_length / 2 && res > 0)
        res = res - full_length;
    if (absolute(res) > full_length / 2 && res < 0)
        res = full_length + res;
    return (res);
}

/**
 * @brief function that returns the orientation of the broadcast
 * @param x the x axis for the given position
 * @param y the y axis for the given position
 * @param reciever the position for the recieving player
 * @param sender the position for the broadcasting player
 * @return the orientation for the broadcast
*/
orientation_t get_orientation(int x, int y, position_t reciever,
    position_t sender)
{
    if (reciever.x == sender.x && reciever.y == sender.y)
        return SAME;
    if (y > 0 && sender.x == reciever.x)
        return DOWN_CENTER;
    if (y < 0 && sender.x == reciever.x)
        return UP_CENTER;
    if (sender.y == reciever.y && x > 0)
        return CENTER_LEFT;
    if (sender.y == reciever.y && x < 0)
        return CENTER_RIGHT;
    if (y > 0 && x > 0)
        return DOWN_LEFT;
    if (y > 0 && x < 0)
        return DOWN_RIGHT;
    if (y < 0 && x > 0)
        return UP_LEFT;
    if (y < 0 && x < 0)
        return UP_RIGHT;
    return SAME;
}

/**
 * @brief function that returns the distance and direction of the broadcast
 *  from different positions
 * @param direction the direction of the broadcast
 * @param reciever the position for the reciever player
 * @param sender the position for the broadcasting player
 * @param info a pointer to a structure containing every game info
 * @return the distance from the reciever and the sender
*/
static int get_direction_sound(direction_t direction, position_t reciever,
    position_t sender, info_t *info)
{
    orientation_t res;
    int x = get_shorter(sender.x, reciever.x, info->map.width);
    int y = get_shorter(sender.y, reciever.y, info->map.height);

    res = get_orientation(x, y, reciever, sender);
    if (res == SAME)
        return (res);
    if (direction == RIGHT)
        res += 2;
    if (direction == DOWN)
        res += 4;
    if (direction == LEFT)
        res += 6;
    if (res > 8)
        res -= 8;
    return (res);
}

/**
 * @brief function that is called for the broadcast AI command
 * @param player a pointer to a structure corresponding to a player
 * @param args an array that contains every arguments
 * @param info a pointer to a structure containing every game info
*/
void broadcast(player_t *player, char **args, info_t *info)
{
    linked_player_t *tmp = info->head_player;
    char str[128];

    if (args == NULL || args[1] == NULL)
        return;
    while (tmp != NULL) {
        if (tmp->player.id != player->id && tmp->player.state == ALIVE &&
            strcmp(tmp->player.team_name, "GRAPHIC") != 0) {
            sprintf(str, "message %d, ",
                get_direction_sound(tmp->player.direction,
                tmp->player.position, player->position, info));
            append_to_string(tmp->player.w_buffer, str);
            append_to_string(tmp->player.w_buffer, args[1]);
            append_to_string(tmp->player.w_buffer, "\n");
        }
        tmp = tmp->next;
    }
    append_to_string(player->w_buffer, "ok\n");
}

/**
 * @brief function that is first called for the broadcast AI command
 * @param player a pointer to a structure corresponding to a player
 * @param args an array that contains every arguments
 * @param info a pointer to a structure containing every game info
*/
void start_broadcast(player_t *player, char **args, info_t *info)
{
    char str[1128];

    set_time(player);
    if (!args || !args[1])
        return;
    sprintf(str, "pbc %d %s\n", player->id, args[1]);
    append_to_gui(info, str);
}
