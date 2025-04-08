/*
** EPITECH PROJECT, 2024
** Appzy
** File description:
** server arguments
*/

/**
 * @file struct_server.h
 * @brief Header file containing network structures and main game structure
*/

#ifndef STRUCT_SERVER_H_
    #define STRUCT_SERVER_H_
    #include "zappy_server.h"
    #include "client.h"
    #include "player.h"

typedef struct sockaddr_in sockaddr_in_t;
typedef struct sockaddr sockaddr_t;

/**
 * @struct info
 * @brief Main structure for game managment
 */
typedef struct info {
    /**
     * @brief next info id
     */
    int next_id;

    /**
     * @brief main game frequency / clock
     */
    int freq;

    /**
     * @brief number of current teams
     */
    int nb_teams;

    /**
     * @brief list of all team names
     */
    char **teams;

    /**
     * @brief current map of the game
     */
    map_t map;

    /**
     * @brief global inventory
     */
    inventory_t global_inv;

    /**
     * @brief linked list containing all players
     */
    linked_player_t *head_player;

    /**
     * @brief generation for time
     */
    long int time_gen;
} info_t;

/**
 * @struct zappy_server
 * @brief structure for network interactions
 */
typedef struct zappy_server {
    /**
     * @brief server port
     */
    int port;

    /**
     * @brief server socket file directory
     */
    int sockfd;

    /**
     * @brief address of the socket
     */
    sockaddr_in_t addr_serv;

    /**
     * @brief size of the socket
     */
    socklen_t sock_size;

    /**
     * @brief list of all clients
     */
    client_t *server_client;

    /**
     * @brief linked list containing all clients
     */
    linked_client_t *head_client;
} zappy_server_t;

#endif /* !STRUCT_SERVER_H_ */
