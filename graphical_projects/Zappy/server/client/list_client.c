/*
** EPITECH PROJECT, 2024
** Appzy
** File description:
** Main loop for server
*/

/**
 * @file list_client.c
 * @brief File containing functions to manage the main linked list
 *  containing every client
*/

#include "../include/zappy_server.h"

/**
 * @brief function that adds a new client to the main linked list
 * @param list pointer to the linked list
 * @param client pointer to a structure corresponding to one client
*/
void append_client_node(linked_client_t **list, client_t client)
{
    linked_client_t *new_node =
    (linked_client_t *)malloc(sizeof(linked_client_t));
    linked_client_t *last = *list;

    if (new_node == NULL) {
        client.disconnect = 1;
        show_error("error client list malloc\n");
        return;
    }
    new_node->client = client;
    new_node->next = NULL;
    if (*list == NULL) {
        *list = new_node;
        return;
    }
    while (last->next != NULL)
        last = last->next;
    last->next = new_node;
    return;
}

/**
 * @brief function that assigns a node to the linked list
 * @param list pointer to the linked list
 * @param tmp pointer to a temporary node
 * @param prev pointer to the previous node
*/
static void assign_node(linked_client_t **list, linked_client_t *tmp,
    linked_client_t *prev)
{
    if (prev == NULL)
        *list = tmp->next;
    else
        prev->next = tmp->next;
}

/**
 * @brief function that removes a client from the list using its fd
 * @param list pointer to the linked list
 * @param destroy_fd fd of the client to destroy
*/
void remove_client_node_by_fd(linked_client_t **list, int destroy_fd)
{
    linked_client_t *tmp = *list;
    linked_client_t *prev = NULL;

    while (tmp != NULL) {
        if (tmp->client.fd == destroy_fd) {
            assign_node(list, tmp, prev);
            free_client(&tmp->client);
            return;
        }
        prev = tmp;
        tmp = tmp->next;
    }
}

/**
 * @brief function that skips a node if it does not corresponds to the fd
 * @param list pointer to the linked list
 * @param destroy_fd the fd to be found
*/
void skip_client_node_by_fd(linked_client_t **list, int destroy_fd)
{
    linked_client_t *tmp = *list;
    linked_client_t *prev = NULL;

    while (tmp != NULL) {
        if (tmp->client.fd == destroy_fd) {
            assign_node(list, tmp, prev);
            return;
        }
        prev = tmp;
        tmp = tmp->next;
    }
}

/**
 * @brief function that prints the fds of every clients in the linked list
 * @param list pointer to the linked list
*/
void print_linked(linked_client_t *list)
{
    linked_client_t *tmp = list;

    while (tmp != NULL) {
        printf("client_fd: %d\n", tmp->client.fd);
        tmp = tmp->next;
    }
}
