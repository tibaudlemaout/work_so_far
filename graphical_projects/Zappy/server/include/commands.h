/*
** EPITECH PROJECT, 2024
** Appzy
** File description:
** server arguments
*/

/**
 * @file command.h
 * @brief Header File containing main structure and functions
 *  for command handling
*/

#ifndef COMMANDS_H_
    #define COMMANDS_H_
    #include "client.h"

typedef struct command command_t;
typedef struct player player_t;
typedef struct info info_t;

/**
 * @struct look_coords
 * @brief Structure to look arround a player
 */
typedef struct look_coords {
    /**
     * @brief Integer corresponding to coordinate up
     */
    int j;

    /**
     * @brief Integer corresponding to coordinate down
     */
    int k;

    /**
     * @brief Integer corresponding to coordinate left
     */
    int lx;

    /**
     * @brief Integer corresponding to coordinate right
     */
    int ly;
} look_coords_t;

/**
 * @struct command
 * @brief Main structure for command handling
 */
typedef struct command {
    /**
     * @brief Main command without args
     */
    char *cmd;

    /**
     * @brief Pointer to functions linked to the command
     */
    void (*use_function)(player_t *player, char **args, info_t *info);

    /**
     * @brief Pointer to functions linked to the command
     */
    void (*end_function)(player_t *player, char **args, info_t *info);

    /**
     * @brief Arguments of the command
     */
    char **args;

    /**
     * @brief Time needed for the command to finish
     */
    int time;
} command_t;

//map commands
void map_size(player_t *player, char **args, info_t *info);
void tile_content(player_t *player, char **args, info_t *info);
void map_content(player_t *player, char **args, info_t *info);

//player commands
void player_pos(player_t *player, char **args, info_t *info);
void player_lvl(player_t *player, char **args, info_t *info);
void player_inv(player_t *player, char **args, info_t *info);

//team commands
void teams_names(player_t *player, char **args, info_t *info);

//freq commands
void freq_content(player_t *player, char **args, info_t *info);
void freq_update(player_t *player, char **args, info_t *info);

//command preparation
void start_no_check(player_t *player, char **args, info_t *info);
void start_forward(player_t *player, char **args, info_t *info);
void start_right(player_t *player, char **args, info_t *info);
void start_left(player_t *player, char **args, info_t *info);
void start_look(player_t *player, char **args, info_t *info);
void start_broadcast(player_t *player, char **args, info_t *info);
void start_fork(player_t *player, char **args, info_t *info);
void start_incantation(player_t *player, char **args, info_t *info);
void start_drop(player_t *player, char **args, info_t *info);
void start_take(player_t *player, char **args, info_t *info);

//player commands
void forward(player_t *player, char **args, info_t *info);
void right(player_t *player, char **args, info_t *info);
void left(player_t *player, char **args, info_t *info);
void look(player_t *player, char **args, info_t *info);
void unused_players(player_t *player, char **args, info_t *info);
void inventory(player_t *player, char **args, info_t *info);
void broadcast(player_t *player, char **args, info_t *info);
void fork_player(player_t *player, char **args, info_t *info);
void end_incantation(player_t *player, char **args, info_t *info);
void end_drop(player_t *player, char **args, info_t *info);
void end_take(player_t *player, char **args, info_t *info);

static command_t PLAYER_COMMANDS[] = {
    {"Forward", start_forward, forward, NULL, 7},
    {"Right", start_right, right, NULL, 7},
    {"Left", start_left, left, NULL, 7},
    {"Look", start_look, look, NULL, 7},
    {"Connect_nbr", start_no_check, unused_players, NULL, 0},
    {"Inventory", start_no_check, inventory, NULL, 1},
    {"Broadcast", start_broadcast, broadcast, NULL, 7},
    {"Fork", start_fork, fork_player, NULL, 42},
    {"Incantation", start_incantation, end_incantation, NULL, 300},
    {"Take", start_take, end_take, NULL, 7},
    {"Set", start_drop, end_drop, NULL, 7},
    {NULL, NULL, NULL, NULL, 0}
};

static command_t GUI_COMMANDS[] = {
    {"msz", map_size, NULL, NULL, 0},
    {"bct", tile_content, NULL, NULL, 0},
    {"mct", map_content, NULL, NULL, 0},
    {"tna", teams_names, NULL, NULL, 0},
    {"ppo", player_pos, NULL, NULL, 0},
    {"plv", player_lvl, NULL, NULL, 0},
    {"pin", player_inv, NULL, NULL, 0},
    {"sgt", freq_content, NULL, NULL, 0},
    {"sst", freq_update, NULL, NULL, 0},
    {NULL, NULL, NULL, NULL, 0}
};

#endif /* !COMMANDS_H_ */
