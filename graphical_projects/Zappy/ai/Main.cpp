/* 
** EPITECH PROJECT, 2024
** Appzy
** File description:
** Main
*/

/**
 * @file Main.cpp
 * @brief Source file for Main.
 * In this file, we have the main function of the program
 * 
*/

#include <wait.h>
#include <iostream>
#include <string>
#include <cstring>
#include "AiPlayer.hpp"
#include "ParsingArgs.hpp"

/**
 * @brief Displays the usage of the program
 * 
 * @return void
 */
static void print_help()
{
    std::cout << "USAGE: ./zappy_ai -p port -n name -h machine" << std::endl;
}

/**
 * @brief Function that displays the error message
 * 
 * @param err Error code
 */
static void display_error(int *err)
{
    if (WIFSIGNALED(*err) == true) {
        std::cerr << strsignal(WTERMSIG(*err)) << std::endl;
        if (strcmp(strsignal(WTERMSIG(*err)), "Segmentation fault") == 0)
            std::cerr << " (core dumped)" << std::endl;
    }
}

/**
 * @brief Function that verifies the configuration and throws an exception if it is invalid
 * The function checks if the port is valid, if the name is not empty and if the machine name is not empty
 * If the configuration is invalid, the function throws an exception
 * 
 * @param ac The number of arguments
 * @param av The arguments
 * @return int 
 */
int main(int ac, char **av)
{
    if (ac == 2 && (std::string(av[1]) == "-help" || std::string(av[1]) == "--help"
        || std::string(av[1]) == "-h" || std::string(av[1]) == "--h")){
        print_help();
        return 0;
    } else if (ac != 7) {
        print_help();
        return 84;
    }

    try {
        AI::Config config = parse_args(ac, av);
        verify_config(config);
        std::vector<pid_t> children;
        AI::AiPlayer player(children, config.port, config.machine_name.c_str(), config.name);
        int err;
        while (children.size() != 0 && player.getId() == -1) {
            waitpid(children[0], &err, 0);
            display_error(&err);
            children.erase(children.begin());
        }
    } catch (const std::exception& e) {
        std::cerr << e.what() << std::endl;
        return 84;
    }
    return 0;
}
