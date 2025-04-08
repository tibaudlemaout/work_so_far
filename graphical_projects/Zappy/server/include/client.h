/*
** EPITECH PROJECT, 2024
** Appzy
** File description:
** server arguments
*/

/**
 * @file client.h
 * @brief Header File containing main structure for the client
*/

#ifndef CLIENT_H_
    #define CLIENT_H_
    #include "zappy_server.h"
    #include "player.h"
    #define CLIENT_WRITE_SIZE 8
    #define READ_BUFFER_SIZE 8056

typedef struct client client_t;
typedef struct linked_client linked_client_t;
typedef struct zappy_server zappy_server_t;

/**
 * @struct client
 * @brief Main structure containing informations about the clients
 */
typedef struct client {
    /**
     * @brief The file descriptor of the assigned client
     */
    int fd;

    /**
     * @brief The socket address of the assigned client
     */
    sockaddr_in_t addr;

    /**
     * @brief Used to know if the client has to be disconnected
     */
    int disconnect;

    /**
     * @brief A player structure corresponding to the player itself
     */
    player_t *player;

    /**
     * @brief The exit buffer of the client
     */
    char w_buffer[CLIENT_WRITE_SIZE];

    /**
     * @brief The enter buffer of the client
     */
    char r_buffer[READ_BUFFER_SIZE];
} client_t;

    /**
     * @struct linked_client
     * @brief Main linked list containing all the clients
    */
typedef struct linked_client {
    /**
     * @brief A client structure for the element
     */
    client_t client;
    /**
     * @brief A pointer to the next element
     */
    linked_client_t *next;
} linked_client_t;

#endif /* !CLIENT_H_ */
