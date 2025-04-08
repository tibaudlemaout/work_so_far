/*
** EPITECH PROJECT, 2024
** Appzy
** File description:
** Main loop for server
*/

/**
 * @file list_player.c
 * @brief File containing functions to manage the players linked list
*/

#include "../include/zappy_server.h"

/**
 * @brief function used for adding a player to the linked list
 * @param list a pointer to a linked list containing every players
 * @param player a pointer to a structure for a player
*/
void append_player_node(linked_player_t **list, player_t player)
{
    linked_player_t *new_node =
        (linked_player_t *)malloc(sizeof(linked_player_t));
    linked_player_t *last = *list;

    if (new_node == NULL)
        show_error("error player list malloc\n");
    new_node->player = player;
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
 * @brief function used for assignment of a player in the linked list
 * @param list a pointer to a linked list containing every players
 * @param tmp a pointer to a specific node
 * @param prev a pointer to the previous node
*/
static void assign_node(linked_player_t **list, linked_player_t *tmp,
    linked_player_t *prev)
{
    if (prev == NULL)
        *list = tmp->next;
    else
        prev->next = tmp->next;
    return;
}

/**
 * @brief function used to remove a player from the linked list
 * @param list a pointer to a linked list containing every players
 * @param destroy_id the id of the player to be destroyed
*/
void remove_player_node_by_id(linked_player_t **list, int destroy_id)
{
    linked_player_t *tmp = *list;
    linked_player_t *prev = NULL;

    while (tmp != NULL) {
        if (tmp->player.id == destroy_id) {
            assign_node(list, tmp, prev);
            free_player(&tmp->player);
            return;
        }
        prev = tmp;
        tmp = tmp->next;
    }
    return;
}

/**
 * @brief function used to print the linked list
 * @param list a pointer to a linked list containing every players
*/
void print_linked_player(linked_player_t *list)
{
    linked_player_t *tmp = list;

    while (tmp != NULL) {
        printf("player_fd: %d\n", tmp->player.id);
        tmp = tmp->next;
    }
    return;
}
