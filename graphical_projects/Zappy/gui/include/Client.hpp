/*
** EPITECH PROJECT, 2024
** Appzy
** File description:
** Client
*/

/**
 * @file Client.hpp
 * @brief File containing functions that manages the client
*/

#ifndef CLIENT_HPP_
    #define CLIENT_HPP_

    #include <iostream>
    #include <vector>
    #include <SFML/Graphics.hpp>
    #include "Tile.hpp"
    #include "Player.hpp"
    #include "Egg.hpp"
    #include "Commands.hpp"

namespace Graphic {

    /**
     * @class Class with every function needed to manage the client
    */
    class Client {
        public:
            Client(Scene& scene) : _commands(scene) {};
            ~Client() = default;
            void connectionToServer(const char* port, const char* machine, int& gridWidth, int& gridHeight);
            void firstCommandsExchanges(int& gridWidth, int& gridHeight);
            std::string readFirstCommandsExchanges();
            void callCorrespondingFunction(const std::string &message);
            std::vector<std::string> parseReceivedMessages(const std::string& buffer);
            void receiveMessages();

            /**
             * @brief Function that sends a command to the server
             * 
             * @param str The command to send
             */
            // request commands
            void sendCommand(std::string& str) {
                if (write(_sock, str.c_str(), strlen(str.c_str())) == -1) {
                    exit(84);
                }
            }

            /**
             * @brief Function that request the map content
             * 
             */
            void requestMapContent() {
                std::string requestMapContent = "mct\n";

                sendCommand(requestMapContent);
            }

            /**
             * @brief Function that request the player inventory
             * 
             * @param player The player
             */
            void requestPlayerPosition(Player& player) {
                std::string requestPlayerPosition = "ppo " + player._id + '\n';

                sendCommand(requestPlayerPosition);
            }

            /**
             * @brief Function that request the player level
             * 
             * @param player The player
             */
            void requestPlayerLevel(Player& player) {
                std::string requestPlayerLevel = "plv " + player._id + '\n';

                sendCommand(requestPlayerLevel);
            }

            /**
             * @brief Function that request the server frequence
             */
            void requestFrequence() {
                std::string requestPlayerLevel = "sgt\n";

                sendCommand(requestPlayerLevel);
            }

            /**
             * @brief The socket of the client
             */
            int _sock;

            /**
             * @brief The commands object
             */
            Commands _commands;

            /**
             * @brief The incomplete message
             */
            std::string _incompleteMessage;
        };
}

#endif /* !CLIENT_HPP_ */
