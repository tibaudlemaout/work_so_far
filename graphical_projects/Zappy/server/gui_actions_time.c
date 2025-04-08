/*
** EPITECH PROJECT, 2024
** ee
** File description:
** gui_actions_time
*/

/**
 * @file gui_actions_time.c
 * @brief Some prototype functions for the gui
*/

#include <stdio.h>
#include "include/gui_actions.h"

/**
 * @brief prototype for the request of time function
 * @param str the string corresponding to the message
*/
void gui_time_request(char *str)
{
    int T = 0;

    printf("sgt %i\n", T);
}

/**
 * @brief prototype for the time modification function
 * @param str the string corresponding to the message
*/
void gui_time_modif(char *str)
{
    int T = 0;
    int lost = 0;

    if (!gui_str_two_values_getter(str, &T, &lost)) {
        printf("suc\n");
        return;
    }
    printf("sst %i\n", T);
}
