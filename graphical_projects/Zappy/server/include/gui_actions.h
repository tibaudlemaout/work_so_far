/*
** EPITECH PROJECT, 2024
** ee
** File description:
** gui_actions
*/

/**
 * @file gui_actions.h
 * @brief Header File containing main gui prototypes and a structure
 *  for command handling
*/

#ifndef GUI_ACTIONS_H_
    #define GUI_ACTIONS_H_

    #include <stdbool.h>

typedef void (*action_gui_t)(char *str);

/**
 * @struct action_map_gui
 * @brief Structure for gui function pointer
 */
typedef struct {
    /**
     * @brief Given command to parse
     */
    char *command;

    /**
     * @brief Linken function
     */
    action_gui_t func;
} action_map_gui_t;

void gui_get_actions(char *str);

bool gui_str_two_values_getter(char *str, int *val1, int *val2);
bool gui_str_value_getter(char *str, int *val);

void gui_map_size(char *str);
void gui_tile_content(char *str);
void gui_map_content(char *str);
void gui_teams_names(char *str);

void gui_player_position(char *str);
void gui_player_level(char *str);
void gui_player_inventory(char *str);

void gui_time_request(char *str);
void gui_time_modif(char *str);

#endif /* !GUI_ACTIONS_H_ */
