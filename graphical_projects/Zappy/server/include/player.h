/*
** EPITECH PROJECT, 2024
** Appzy
** File description:
** server arguments
*/

/**
 * @file player.h
 * @brief Header File containing data for players and structures
 *  for command handling
*/

#ifndef PLAYER_H_
    #define PLAYER_H_
    #include "zappy_server.h"
    #include "struct_server.h"
    #include "commands.h"
    #include "player.h"
    #define MAX_COMMAND 10
    #define WRITE_BUFF_SIZE 100056

typedef struct player player_t;
typedef struct linked_player linked_player_t;
typedef struct sockaddr_in sockaddr_in_t;
typedef struct info info_t;

/**
 * @struct inventory
 * @brief Structure for inventory (used by players and map tiles)
 */
typedef struct inventory {
    /**
     * @brief Number of food
     */
    int food;

    /**
     * @brief Number of linemate
     */
    int linemate;

    /**
     * @brief Number of deraumere
     */
    int deraumere;

    /**
     * @brief Number of sibur
     */
    int sibur;

    /**
     * @brief Number of mendiane
     */
    int mendiane;

    /**
     * @brief Number of phiras
     */
    int phiras;

    /**
     * @brief Number of thystame
     */
    int thystame;
} inventory_t;

/**
 * @enum ressource
 * @brief Enum for all ressource type
 */
typedef enum ressource {
    FOOD,
    LINEMATE,
    DERAUMERE,
    SIBUR,
    MENDIANE,
    PHIRAS,
    THYSTAME,
    ERROR
} ressource_t;

/**
 * @struct position
 * @brief Structure used for position types
 */
typedef struct position {
    /**
     * @brief x coordinate of the position
     */
    int x;

    /**
     * @brief y coordinate of the position
     */
    int y;
} position_t;

/**
 * @enum direction
 * @brief enum used for direction of a player
 */
typedef enum direction {
    UP,
    RIGHT,
    DOWN,
    LEFT
} direction_t;

/**
 * @enum orientation
 * @brief Enum used for orientation of a player
 */
typedef enum orientation {
    SAME,
    UP_CENTER,
    UP_LEFT,
    CENTER_LEFT,
    DOWN_LEFT,
    DOWN_CENTER,
    DOWN_RIGHT,
    CENTER_RIGHT,
    UP_RIGHT
} orientation_t;

/**
 * @enum state
 * @brief Enum used for state of a player
 */
typedef enum state {
    UNUSED,
    ALIVE,
    DEAD,
    EGG
} state_t;

/**
 * @struct player
 * @brief Main structure for all players
 */
typedef struct player {
    /**
     * @brief The id of the player
     */
    int id;

    /**
     * @brief The team name of the player
     */
    char *team_name;

    /**
     * @brief Position of the player
     */
    position_t position;

    /**
     * @brief Direction of the player
     */
    direction_t direction;

    /**
     * @brief Inventory of the player
     */
    inventory_t inventory;

    /**
     * @brief State of the player
     */
    state_t state;

    /**
     * @brief List of all commands sent by the player
     */
    command_t *command[MAX_COMMAND + 1];

    /**
     * @brief Level of the player
     */
    int level;

    /**
     * @brief Time to eat for the player
     */
    long int time_to_eat;

    /**
     * @brief Start time of the player
     */
    long int time_start;

    /**
     * @brief Exit buffer of the player
     */
    char w_buffer[WRITE_BUFF_SIZE];
} player_t;

/**
 * @struct linked_player
 * @brief Linked list to store all players
 */
typedef struct linked_player {
    /**
     * @brief unique player element by node
     */
    player_t player;

    /**
     * @brief pointer to the next element
     */
    linked_player_t *next;
} linked_player_t;

/**
 * @struct map
 * @brief Structure for map and infos
 */
typedef struct map {
    /**
     * @brief List of all tiles of a map, containing elements
     */
    inventory_t **tile;

    /**
     * @brief width of the map
     */
    int width;

    /**
     * @brief height of the map
     */
    int height;
} map_t;

#endif /* !PLAYER_H_ */
