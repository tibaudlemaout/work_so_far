/*
** EPITECH PROJECT, 2024
** Appzy
** File description:
** Main loop for server
*/

/**
 * @file client_connection.c
 * @brief File containing functions to handle client connections and messages
*/

#include "../include/zappy_server.h"

/**
 * @brief function that checkes if a buffer is empty
 * @param readset corresponds to the fd set to read
 * @param server pointer to a structure corresponding to the network
*/
void manage_client_connect(fd_set *readset, zappy_server_t *server)
{
    int clifd = -1;
    sockaddr_in_t addr_cli;
    client_t new_client;

    if (FD_ISSET(server->sockfd, readset)) {
        clifd = accept(server->sockfd,
            (sockaddr_t *)&addr_cli, &server->sock_size);
        if (clifd < 0)
            show_error("error client connection\n");
        printf("client connected\n");
        dprintf(clifd, "WELCOME\n");
        init_client(&new_client, clifd, addr_cli);
        append_client_node(&server->head_client, new_client);
    }
}

/**
 * @brief Function that display eggs
 * @param args The list of arguments
 * @param client The client
 * @param info The info structure
 */
static void display_eggs(char **args, client_t *client, info_t *info)
{
    char str[128] = "";
    linked_player_t *player = info->head_player;

    while (player != NULL) {
        if (player->player.position.x != -1 &&
            player->player.position.y != -1 &&
            player->player.state == UNUSED) {
            sprintf(str, "enw %d -1 %d %d\n", player->player.id,
                player->player.position.x, player->player.position.y);
            append_to_gui(info, str);
        }
        player = player->next;
    }
    return;
}

/**
 * @brief Function that check if it's GUI or not to handle the first message
 * @param args The list of arguments
 * @param client The client
 * @param info The info structure
 */
static void handle_first_message(char **args, client_t *client, info_t *info)
{
    char str[126] = "";

    if (strcmp(args[0], "GRAPHIC") == 0) {
        client->player = &info->head_player->player;
        client->player->state = ALIVE;
        sprintf(str, "0\n%d %d\n", info->map.width, info->map.height);
        append_to_gui(info, str);
    } else {
        display_eggs(args, client, info);
        assign_player(args, client, info);
    }
}

/**
 * @brief function that checkes if a buffer is empty
 * @param buffer string containing read values to get
 * @param client pointer to a structure corresponding to one client
 * @param info pointer to a structure containing every info about the game
*/
void manage_readvalue(char *buffer, client_t *client, info_t *info)
{
    size_t end = 0;
    char **args = NULL;

    for (; buffer[end] && buffer[end] != '\n' && buffer[end] != '\r'; end++);
    buffer[end] = '\0';
    if (strlen(buffer) > 0 && (buffer[0] == '\r' || buffer[0] == '\n'))
        return;
    if (verify_empty(buffer))
        return;
    create_args_list(&args, buffer);
    if (client->player == NULL)
        handle_first_message(args, client, info);
    else
        use_command(args, client);
    free_array(&args);
}

/**
 * @brief function that checkes if a buffer is empty
 * @param readset corresponds to the fd set to read
 * @param server pointer to a structure corresponding to one client
 * @param info pointer to a structure containing every info about the game
*/
void manage_client_msg(fd_set *readset, zappy_server_t *server, info_t *info)
{
    char buffer[READ_BUFFER_SIZE];
    ssize_t readval = 0;
    linked_client_t *tmp = server->head_client;

    while (tmp != NULL) {
        if (FD_ISSET(tmp->client.fd, readset)) {
            reset_buffer(buffer, READ_BUFFER_SIZE);
            readval = read(tmp->client.fd, &buffer, READ_BUFFER_SIZE - 1);
            execute_buffer(readval, buffer, &tmp->client, info);
        }
        tmp = tmp->next;
    }
}
