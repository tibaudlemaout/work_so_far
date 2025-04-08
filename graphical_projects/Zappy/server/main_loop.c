/*
** EPITECH PROJECT, 2024
** Appzy
** File description:
** Main loop for server
*/

/**
 * @file main_loop.c
 * @brief File containing important functions like the main loop,
 *  the server start or disconnecting clients
*/

#include "include/zappy_server.h"

static bool exit_server;

/**
 * @brief Function to disconnect a player
 * @param player pointer to a structure about one specific player
 * @param info pointer to a server structure, containing all needed
 *  information about the game
*/
static void disconnect_player(player_t *player, info_t *info)
{
    char str[128];

    if (player)
        player->state = (player->state != DEAD ? UNUSED : DEAD);
    return;
}

/**
 * @brief Function to disconnect a client
 * @param head pointer to a linked list containing every client
 * @param info pointer to a server structure, containing all
 *  needed information about the game
*/
static void disconnect_clients(linked_client_t **head, info_t *info)
{
    linked_client_t *tmp = *head;
    linked_client_t *to_destroy;

    exit_server = false;
    while (tmp) {
        if (tmp->client.disconnect == 1 ||
        (tmp->client.player && tmp->client.player->state == DEAD)) {
            to_destroy = tmp;
            tmp = to_destroy->next;
            disconnect_player(to_destroy->client.player, info);
            close(to_destroy->client.fd);
            remove_client_node_by_fd(head, to_destroy->client.fd);
        }
        if (tmp != NULL)
            tmp = tmp->next;
    }
    return;
}

/**
 * @brief Function to stops the server in case of server closing
 * @param sig integer containing the signal for closing
*/
void signal_handler(int sig)
{
    if (sig == SIGINT) {
        printf("Signal closing server\n");
        exit_server = true;
    }
}

/**
 * @brief Function for the main loop of the server
 * @param info pointer to a structure containing all informations
 *  about the game itself
 * @param server pointer to a server structure, containing all
 *  needed information for network exchanges
*/
void main_loop(info_t *info, zappy_server_t *server)
{
    fd_set readset;
    fd_set writefds;

    while (exit_server == false) {
        reset_set(&readset, server, server->head_client);
        reset_set(&writefds, server, server->head_client);
        select(FD_SETSIZE, &readset, &writefds, NULL, NULL);
        if (end_cond(info) || exit_server == true)
            break;
        manage_client_connect(&readset, server);
        manage_client_msg(&readset, server, info);
        exec_command(info);
        write_buffer(server, &writefds);
        disconnect_clients(&server->head_client, info);
    }
    destroy_everything(info, server);
    return;
}

/**
 * @brief Function that initiates the server structure
 * @param server pointer to a server structure, containing all
 *  needed information for network exchanges
*/
void start_server(zappy_server_t *server)
{
    int sockfd = socket(AF_INET, SOCK_STREAM, 0);
    int opt = 1;

    if (sockfd < 0)
        show_error("sockfd error\n");
    server->addr_serv = generate_addr(server->port);
    server->sock_size = sizeof(server->addr_serv);
    server->sockfd = sockfd;
    if (setsockopt(sockfd, SOL_SOCKET, SO_REUSEADDR, &opt, sizeof(opt)) == -1)
        show_error("setsockopt error\n");
    if (bind(sockfd, (sockaddr_t *)&server->addr_serv, server->sock_size) < 0)
        show_error("bind error\n");
    if (listen(sockfd, MAX_CLIENTS) < 0)
        show_error("listen error\n");
    return;
}
