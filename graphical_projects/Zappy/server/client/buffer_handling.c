/*
** EPITECH PROJECT, 2024
** Appzy
** File description:
** Main loop for server
*/

/**
 * @file buffer_handling.c
 * @brief File containing functions to execute functions based on a buffer
*/

#include "../include/zappy_server.h"

/**
 * @brief function that checkes if a buffer is empty
 * @param readval integer corresponding to the reading value
 * @param client pointer to a structure corresponding to one client
 * @return if the buffer is empty or not
*/
static bool is_empty(int readval, client_t *client)
{
    if (readval == 0) {
        client->disconnect = 1;
        return (true);
    }
    return (false);
}

/**
 * @brief function that calls functions based on a given buffer
 * @param readval integer corresponding to the reading value
 * @param read_buff pointer to a buffer for reading
 * @param client pointer to a structure corresponding to one client
 * @param info pointer to a structure containing every info about the game
*/
void execute_buffer(int readval, char *read_buff, client_t *client,
    info_t *info)
{
    char buff[READ_BUFFER_SIZE];
    int i = 0;

    if (readval <= 0 || is_empty(readval, client))
        return;
    read_buff[readval] = '\0';
    strcat(client->r_buffer, read_buff);
    while (client->r_buffer[i]) {
        buff[i] = client->r_buffer[i];
        if (buff[i] == '\n') {
            buff[i] = '\0';
            manage_readvalue(buff, client, info);
            strcpy(buff, "");
            memmove(client->r_buffer, client->r_buffer + i + 1,
                strlen(client->r_buffer + i + 1) + 1);
            i = 0;
        } else {
            i++;
        }
    }
}
