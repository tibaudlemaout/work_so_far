/*
** EPITECH PROJECT, 2024
** Appzy
** File description:
** Main loop for server
*/

/**
 * @file free_client.c
 * @brief File containing functions to free infos in client structure
*/

#include "../include/zappy_server.h"

/**
 * @brief function that frees the pointer to the structure itself
 * @param client pointer to a structure corresponding to one client
*/
void free_client(client_t *client)
{
    free(client);
}

/**
 * @brief function that frees the linked list of every client
 * @param list pointer to a linked list containing every client
*/
void destroy_clients(linked_client_t *list)
{
    linked_client_t *tmp = list;

    while (tmp != NULL) {
        list = tmp->next;
        free_client(&tmp->client);
        tmp = list;
    }
}
