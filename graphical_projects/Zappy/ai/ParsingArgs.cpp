/* 
** EPITECH PROJECT, 2024
** Appzy
** File description:
** ParsingArgs
*/

/**
 * @file ParsingArgs.cpp
 * @brief Source file for ParsingArgs.
 * In this file, we have all functions about parsing the arguments of the program
 * 
*/

#include "ParsingArgs.hpp"

/**
 * @brief Parse the arguments of the program
 * @param ac The number of arguments
 * @param av The list of arguments
 * 
 * @return Appzy::Config The configuration of the program
 */
AI::Config parse_args(int ac, char **av) {
    AI::Config config;
    for (int i = 1; i < ac; i++) {
        std::string arg = av[i];
        if (arg == "-p" && i + 1 < ac) {
            config.port = std::stoi(av[++i]);
        } else if (arg == "-n" && i + 1 < ac) {
            config.name = av[++i];
        } else if (arg == "-h" && i + 1 < ac) {
            config.machine_name = av[++i];
        } else {
            throw std::invalid_argument("Unknown argument: " + arg);
        }
    }
    return config;
}

/**
 * @brief Verify the validity of the configuration
 * @param config The configuration structure of the program
 * 
 * @return void
 */
void verify_config(AI::Config config) {
    if (config.port <= 0) {
        throw std::invalid_argument("Invalid port");
    }
    if (config.name.empty()) {
        throw std::invalid_argument("Invalid name");
    }
    if (config.machine_name.empty()) {
        throw std::invalid_argument("Invalid machine name");
    }
}
