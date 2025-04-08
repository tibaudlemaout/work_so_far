/*
** EPITECH PROJECT, 2024
** Appzy
** File description:
** Argument handling for server
*/

/**
 * @file write_commands.c
 * @brief File containing functions to write the content of given commands
*/

#include "../include/zappy_server.h"

/**
 * @brief function that writes the lines for the buffer
 * @param fd an integer corresponding to the fd
 * @param buffer an integer corresponding to the index of the command
*/
void write_lines(int fd, char *buffer)
{
    char buff[WRITE_BUFF_SIZE];
    int i = 0;

    while (buffer[i]) {
        buff[i] = buffer[i];
        if (buff[i] == '\n') {
            buff[i + 1] = '\0';
            printf("message to %i = %s\n", fd, buff);
            dprintf(fd, "%s", buff);
            memmove(buffer, buffer + i + 1, strlen(buffer + i + 1) + 1);
            i = 0;
        } else
            i++;
    }
}

/**
 * @brief function that writes the lines for the buffer of a specified client
 * @param client a pointer to a structure for one client
*/
void write_client_buffer(client_t *client)
{
    if (strlen(client->w_buffer) != 0) {
        write_lines(client->fd, client->w_buffer);
        if (client->w_buffer[0] == '\0') {
            strcpy(client->w_buffer, "");
        }
    }
}

/**
 * @brief function that writes the lines for the buffer of a specified player
 * @param client a pointer to a structure for one client
*/
void write_player_buffer(client_t *client)
{
    if (client->player != NULL && strlen(client->player->w_buffer) != 0) {
        write_lines(client->fd, client->player->w_buffer);
        if (client->player->w_buffer[0] == '\0') {
            strcpy(client->player->w_buffer, "");
        }
    }
}

/**
 * @brief function that writes the buffers
 * @param server a pointer to a structure for the server network
 * @param writefds a set of fds for the clients
*/
void write_buffer(zappy_server_t *server, fd_set *writefds)
{
    linked_client_t *tmp = server->head_client;

    while (tmp) {
        if (FD_ISSET(tmp->client.fd, writefds) && !tmp->client.disconnect) {
            write_client_buffer(&tmp->client);
            write_player_buffer(&tmp->client);
        }
        tmp = tmp->next;
    }
}
