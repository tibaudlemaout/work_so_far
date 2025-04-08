/* 
** EPITECH PROJECT, 2024
** Appzy
** File description:
** ParsingArgs
*/

/**
 * @file ParsingArgs.hpp
 * @brief Source file for ParsingArgs.
 * In this file, we have all functions about parsing the arguments of the program.
 * 
 */

#ifndef PARSINGARGS_HPP_
    #define PARSINGARGS_HPP_

    #include <iostream>

namespace AI {

    /**
     * @brief The configuration of the program
     * @param port The port of the program
     * @param name The name of the program
     * @param machine_name The machine name of the program
     */
    struct Config {
        int port;
        std::string name;
        std::string machine_name;
    };
}

AI::Config parse_args(int ac, char **av);
void verify_config(AI::Config config);

#endif // PARSINGARGS_HPP_
