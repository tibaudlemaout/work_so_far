/*
** EPITECH PROJECT, 2024
** Appzy
** File description:
** initialization of the server
*/

/**
 * @file error_handling.c
 * @brief File containing functions for error handling and display
*/

#include "include/zappy_server.h"

/**
 * @brief function that displays a string given at parameters and
 *  closes the server
 * @param error a string containing an error message to be displayed
*/
void show_error(const char *error)
{
    printf("%s\n", error);
    exit(84);
}

/**
 * @brief function that analyses the arguments to see if there are errors
 * @param argc an integer containing the number of arguments
 * @param argf an array containing every arguments
*/
void handle_errors(const int argc, const char **argv)
{
    if (argc < 2)
        show_error("no arguments, use -h to see usage\n");
    for (size_t i = 0; argv[1][i]; i++) {
        if (!isdigit(argv[1][i]))
            show_error("port needs to be a number\n");
    }
    if (atoi(argv[1]) < 0)
        show_error("port needs to be > 0\n");
    return;
}
