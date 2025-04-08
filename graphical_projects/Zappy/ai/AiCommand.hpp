/*
** EPITECH PROJECT, 2024
** Appzy
** File description:
** AiCommand
*/

/**
 * @file AiCommand.hpp
 * @brief Header file for AiCommand.
 * In this file, we have all functions about Commands that the AI can send to the server
 * We also have response parsing functions
 * 
*/

#ifndef AICOMMAND_HPP_
    #define AICOMMAND_HPP_

    #include <iostream>
    #include <sys/socket.h>
    #include <deque>
    #include <sstream>
    #include <map>
    #include <vector>
    #include "AiInventory.hpp"
    #include "AiLooked.hpp"
    #include "AiTile.hpp"

namespace AI
{
    /**
     * @class AiCommand
     * @brief Class representing an AI command.
     */
    class AiCommand
    {
    private:
        /**
         * @brief Queue of commands to be executed.
         */
        std::deque<std::string> _commandsQueue;

        /**
         * @brief Queue of commands waiting to be executed.
         */
        std::deque<std::string> _waitingQueue;

        /**
         * @brief Maximum size of the history.
         */
        static const int MAX_HISTORY_SIZE = 10;

        /**
         * @brief Inventory of the AI.
         */
        AI::AiInventory _inventory;

        /**
         * @brief Number of connected players.
         */
        long _connectedPlayers;

        /**
         * @brief Looked object of the AI.
         */
        AI::AiLooked _looked;
        bool _canFork;
        int _level;

        const std::vector<int> player_tab = {1, 2, 2, 4, 4, 6, 6};
        const std::vector<int> linemate_tab = {1, 1, 2, 1, 1, 1, 2};
        const std::vector<int> deraumere_tab = {0, 1, 0, 1, 2, 2, 2};
        const std::vector<int> sibur_tab = {0, 1, 1, 2, 1, 3, 2};
        const std::vector<int> mendiane_tab = {0, 0, 0, 0, 3, 0, 2};
        const std::vector<int> phiras_tab = {0, 0, 2, 1, 0, 1, 2};
        const std::vector<int> thystame_tab = {0, 0, 0, 0, 0, 0, 1};
    public:
        AiCommand();
        ~AiCommand();
        void checkReturn(char *message);

        void MoveForward(int sockfd);
        void MoveRight(int sockfd);
        void MoveLeft(int sockfd);

        void LookAround(int sockfd);
        void Inventory(int sockfd);
        void Broadcast(int sockfd, std::string message);

        void ConnectNbr(int sockfd);
        void Fork(int sockfd);
        void Eject(int sockfd);

        void TakeObject(int sockfd, std::string object);
        void SetObject(int sockfd, std::string object);
        void Incantation(int sockfd);

        void addHistoryMessage(int sockfd, std::string message);
        void parseInventoryString(const std::string& str);

        /**
         * @brief Get the Inventory object
         * 
         * @return AI::AiInventory 
         */
        AI::AiInventory getInventory() { return _inventory; };

        /**
         * @brief Get the Looked object
         * 
         * @return AI::AiLooked 
         */
        AI::AiLooked getLooked() { return _looked; };

        /**
         * @brief Function to check if a command is waiting
         * 
         * @return true 
         * @return false 
         */
        bool isCommandWaiting() { return !_commandsQueue.empty(); };
        void parseStringToTiles(const std::string& str);
        void updateSendQueue(int sockfd);

        int checkIncantation(AI::AiInventory inventory, int level);
        void dropLevelUpItems(int sockfd, int level);
        int getMissingItems(AI::AiInventory inventory, int level);

        bool canFork() { return _canFork; };
        void setCanFork(bool canFork) { _canFork = canFork; };

        int getLevel() { return _level; };
    };
};
#endif /* !AICOMMAND_HPP_ */
