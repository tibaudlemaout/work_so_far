/*
** EPITECH PROJECT, 2024
** Appzy
** File description:
** Main loop for server
*/

/**
 * @file assign_client_player_teams.c
 * @brief File containing functions that assigns clients to teams
*/

#include "../include/zappy_server.h"

/**
 * @brief function that initiate a client in case of a new connection
 * @param client a pointer to a client structure, containing informations
 *  for each client
 * @param clifd the fd of the precised client
 * @param addr_cli the address of the given client
*/
void init_client(client_t *client, int clifd, sockaddr_in_t addr_cli)
{
    client->fd = clifd;
    client->addr = addr_cli;
    client->disconnect = 0;
    client->player = NULL;
    strcpy(client->w_buffer, "");
    strcpy(client->r_buffer, "");
}

static void pnw(player_t *player, info_t *info)
{
    char str_gui[128] = "";

    sprintf(str_gui, "pnw %d %d %d %d %d %s\n", player->id,
        player->position.x, player->position.y,
        player->direction + 1, player->level, player->team_name);
    append_to_gui(info, str_gui);
}

static void ebo(player_t *player, info_t *info)
{
    char str_gui[128] = "";

    sprintf(str_gui, "ebo %d\n", player->id);
    append_to_gui(info, str_gui);
    return;
}

static void edi(player_t *player, info_t *info)
{
    char str_gui[128] = "";

    sprintf(str_gui, "ebo %d\n", player->id);
    append_to_gui(info, str_gui);
    return;
}

static void egg_hatch(char *team_name, client_t *client, info_t *info,
    linked_player_t *player)
{
    char str[128] = "";

    if (strcmp(team_name, player->player.team_name) == 0 &&
        player->player.state == EGG) {
            player->player.state = ALIVE;
            client->player = &player->player;
            sprintf(str, "%d\n%d %d\n",
                get_nb_unused(info->head_player, team_name),
                info->map.width, info->map.height);
            ebo(&player->player, info);
            edi(&player->player, info);
            pnw(&player->player, info);
            append_to_string(client->player->w_buffer, str);
        }
    return;
}

/**
 * @brief function that assigns a player to a team
 * @param client a pointer to a structure corresponding to one client
 * @param info a pointer to a structure containing informations about the game
*/
void assign_player_by_team(char *team_name, client_t *client,
    info_t *info)
{
    char buffer[128];
    linked_player_t *player = info->head_player;

    while (player != NULL) {
        egg_hatch(team_name, client, info, player);
        if (strcmp(player->player.team_name, team_name) == 0 &&
        player->player.state == UNUSED) {
            player->player.state = ALIVE;
            client->player = &player->player;
            sprintf(buffer, "%d\n%d %d\n",
                get_nb_unused(info->head_player, team_name),
                info->map.width, info->map.height);
            ebo(&player->player, info);
            edi(&player->player, info);
            pnw(&player->player, info);
            append_to_string(client->player->w_buffer, buffer);
            break;
        }
        player = player->next;
    }
}

/**
 * @brief function that calls the team assigning and saving the info
 * @param args an array containing all arguments
 * @param client a pointer to a structure corresponding to one client
 * @param info a pointer to a structure containing informations about the game
*/
void assign_player(char **args, client_t *client, info_t *info)
{
    if (is_valid_team(args[0], info)) {
        assign_player_by_team(args[0], client, info);
    } else {
        append_to_string(client->w_buffer, "ko\n");
    }
}
