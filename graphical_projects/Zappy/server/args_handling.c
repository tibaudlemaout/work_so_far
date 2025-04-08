/*
** EPITECH PROJECT, 2024
** Appzy
** File description:
** Argument handling for server
*/

/**
 * @file args_handling.c
 * @brief File containing functions for arguments handling and parsing
*/

#include "include/zappy_server.h"

/**
 * @brief function that get the port based on the -p argument on program launch
 * @param argc an integer containing the number of arguments
 * @param argf an array containing every arguments
 * @return the port as an integer
*/
int get_port(const int argc, const char **argv)
{
    int port = 0;
    int i = 0;

    for (; i != argc; i++) {
        if (strcmp(argv[i], "-p") == 0)
            break;
    }
    if (i == argc)
        show_error("no port\n");
    if (i + 1 >= argc || atoi(argv[i + 1]) <= 0)
        show_error("missing/invalid port\n");
    port = atoi(argv[i + 1]);
    return (port);
}

/**
 * @brief function that get the frequency based on the -f argument on
 *  program launch
 * @param argc an integer containing the number of arguments
 * @param argf an array containing every arguments
 * @return the frequency as an integer
*/
int get_freq(const int argc, const char **argv)
{
    int freq = 100;
    int i = 0;

    for (; i != argc; i++)
        if (strcmp(argv[i], "-f") == 0)
            break;
    if (i == argc)
        return (freq);
    if (i + 1 >= argc || atoi(argv[i + 1]) <= 0)
        show_error("missing/invalid freq\n");
    freq = atoi(argv[i + 1]);
    return (freq);
}

/**
 * @brief function that get the width based on the -x argument on program
 *  launch
 * @param argc an integer containing the number of arguments
 * @param argf an array containing every arguments
 * @return the width as an integer
*/
int get_width(const int argc, const char **argv)
{
    int x = 0;
    int i = 0;

    for (; i != argc; i++)
        if (strcmp(argv[i], "-x") == 0)
            break;
    if (i == argc)
        show_error("no width\n");
    if (i + 1 >= argc || atoi(argv[i + 1]) <= 0)
        show_error("missing/invalid width\n");
    x = atoi(argv[i + 1]);
    return (x);
}

/**
 * @brief function that get the height based on the -y argument on program
 *  launch
 * @param argc an integer containing the number of arguments
 * @param argf an array containing every arguments
 * @return the height as an integer
*/
int get_height(const int argc, const char **argv)
{
    int y = 0;
    int i = 0;

    for (; i != argc; i++)
        if (strcmp(argv[i], "-y") == 0)
            break;
    if (i == argc)
        show_error("no height\n");
    if (i + 1 >= argc || atoi(argv[i + 1]) <= 0)
        show_error("missing/invalid height\n");
    y = atoi(argv[i + 1]);
    return (y);
}

/**
 * @brief function that get the number of client based on the -c argument on
 *  program launch
 * @param argc an integer containing the number of arguments
 * @param argf an array containing every arguments
 * @return the number of client as an integer
*/
int get_nb_cli(const int argc, const char **argv)
{
    int c = 0;
    int i = 0;

    for (; i != argc; i++)
        if (strcmp(argv[i], "-c") == 0)
            break;
    if (i == argc)
        show_error("no client number\n");
    if (i + 1 >= argc || atoi(argv[i + 1]) <= 0)
        show_error("missing/invalid client number\n");
    c = atoi(argv[i + 1]);
    return (c);
}
