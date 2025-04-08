/*
** EPITECH PROJECT, 2024
** gui get actions
** File description:
** main
*/

/**
 * @file gui_get_actions.c
 * @brief Some prototype functions for the gui
*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "include/gui_actions.h"

const action_map_gui_t action_map_gui[] = {
    {"msz", gui_map_size},
    {"bct", gui_tile_content},
    {"mct", gui_map_content},
    {"tna", gui_teams_names},
    {"ppo", gui_player_position},
    {"plv", gui_player_level},
    {"pin", gui_player_inventory},
    {"sgt", gui_time_request},
    {"sst", gui_time_modif},
    {NULL, NULL}
};

/**
 * @brief prototype for the unknown function
 * @param str the string corresponding to the message
*/
void gui_unknown(char *str)
{
    printf("suc\n");
}

/**
 * @brief returns the first three characters of a string
 * @param str the string based
 * @return the first three characters of the string
*/
char *first_three_chars(const char *str)
{
    char *result = (char *)malloc(4 * sizeof(char));

    if (!result) {
        return NULL;
    }
    strncpy(result, str, 3);
    result[3] = '\0';
    return result;
}

/**
 * @brief Main function for function pointer for the parsing of GUI messages
 * @param str the string corresponding to the message
*/
void gui_get_actions(char *str)
{
    const char *command = first_three_chars(str);

    for (int i = 0; action_map_gui[i].command != NULL; i++) {
        if (strcmp(action_map_gui[i].command, command) == 0) {
            return action_map_gui[i].func(str);
        }
    }
    gui_unknown(str);
}
