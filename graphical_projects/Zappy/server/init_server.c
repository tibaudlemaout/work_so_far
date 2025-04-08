/*
** EPITECH PROJECT, 2024
** Appzy
** File description:
** initialization of the server
*/

/**
 * @file init_server.c
 * @brief File containing functions for server initialization
*/

#include "include/zappy_server.h"

/**
 * @brief Function that fills the info structure, containing a lot of
 *  informations about the game itself
 * @param argc integer containing the number of arguments
 * @param argv array containing every arguments
 * @param data pointer to a structure containing every information about
 *  the game (to be initialized)
*/
void init_job(const int argc, const char **argv, info_t *info)
{
    int nb_cli = get_nb_cli(argc, argv);

    info->freq = get_freq(argc, argv);
    info->map.width = get_width(argc, argv);
    info->map.height = get_height(argc, argv);
    info->next_id = 0;
    info->head_player = NULL;
    init_map(info);
    init_teams(argc, argv, info);
    init_players(nb_cli, info);
    init_inventory(&info->global_inv);
    info->global_inv.food = 0;
    gen_res(info);
    return;
}

/**
 * @brief Function that fills the zappy_server structure, containing
 *  all informations about the server
 * @param argc integer containing the number of arguments
 * @param argv array containing every arguments
 * @param server pointer to a structure containing every information
 *  about the server and network
*/
void init_server(const int argc, const char **argv, zappy_server_t *server)
{
    server->port = get_port(argc, argv);
    server->head_client = NULL;
    server->sock_size = sizeof(struct sockaddr_in);
    server->server_client = NULL;
    server->head_client = NULL;
    printf("Port: %d\n", server->port);
    return;
}
