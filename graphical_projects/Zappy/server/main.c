/*
** EPITECH PROJECT, 2024
** Appzy
** File description:
** Main
*/

/**
 * @file main.c
 * @brief Main file with main function and help message
*/

#include "include/zappy_server.h"

/**
 * @brief function that displays the help message
*/
static void help_display(void)
{
    printf("USAGE: ./zappy_server -p port -x width -y height -n name1 ");
    printf("name2 . . . -c clientsNB -f freq\n");
    printf("    -p port \tport number\n    -x width \twidth of the world\n");
    printf("    -y height \theight of the world\n    -n name1 name2... \t");
    printf("name of the team\n    -c clientsNb \tnumber of authorized ");
    printf("clients per team\n    -f freq \treciprocal of time unit for ");
    printf("execution of actions\n");
    return;
}

/**
 * @brief Main function of the program
 * @param argc the number of arguments given to the program
 * @param argv an array containing every argument
*/
int main(const int argc, const char **argv)
{
    info_t info;
    zappy_server_t server = {.addr_serv = {0}};
    time_t tm;

    if (argc >= 2 && strcmp(argv[1], "-h") == 0) {
        help_display();
        return (0);
    } else {
        srand((unsigned)time(&tm));
        signal(SIGINT, signal_handler);
        init_job(argc, argv, &info);
        init_server(argc, argv, &server);
        start_server(&server);
        main_loop(&info, &server);
    }
    return (0);
}
