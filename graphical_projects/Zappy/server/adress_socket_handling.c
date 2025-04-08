/*
** EPITECH PROJECT, 2024
** Appzy
** File description:
** Argument handling for server
*/

/**
 * @file adress_socket_handling.c
 * @brief File containing functions for sockets handling, generation or reset
*/

#include "include/zappy_server.h"

/**
 * @brief function that generates an addr for the bind function
 * @param port an integer corresponding to the port
 * @return the addr
*/
sockaddr_in_t generate_addr(const int port)
{
    sockaddr_in_t addr;

    addr.sin_addr.s_addr = INADDR_ANY;
    addr.sin_family = AF_INET;
    addr.sin_port = port == 0 ? 0 : htons(port);
    return (addr);
}

/**
 * @brief function that reset the write and fd for new values
 * @param set a pointer to a structure containing all fd informations
 * @param server a pointer to a structure containing all server network
 *  informations
 * @param head a pointer to the head of a linked list containing every clients
*/
void reset_set(fd_set *set, zappy_server_t *server, linked_client_t *head)
{
    linked_client_t *tmp = head;

    FD_ZERO(set);
    FD_SET(server->sockfd, set);
    while (tmp) {
        if (tmp->client.fd >= 0) {
            FD_SET(tmp->client.fd, set);
        }
        tmp = tmp->next;
    }
    return;
}
