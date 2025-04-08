/*
** EPITECH PROJECT, 2024
** Appzy
** File description:
** AiPlayer
*/

/**
 * @file AiPlayer.hpp
 * @brief Header file for AiPlayer.
 * In this file, we have all functions about the AI player
 * 
*/

#ifndef AIPLAYER_HPP_
#define AIPLAYER_HPP_

    #include <vector>
    #include <string>
    #include "AiPriorities.hpp"
    #include "AiInventory.hpp"
    #include "AiCommand.hpp"

namespace AI
{
    /**
     * @brief Enum for the different message types that can be sent
     * to other players.
     * HUNGRY: The player is hungry and needs food
     * FOOD: The player has enough food to give to another player
     * FOOD_OK: The player has found another player that can give him food
     * LVL_UP: The player wants to level up
     * LVL_UP_CHECK: This player can level up with the other
     * LVL_UP_OK: The player has found enough players that can level up with him
     * LVL_UP_KO: The player has not found enough players that can level up with him
     * TIK: The player is sending a tik to find another player
     * TOK: The player is sending a tok to answer to a tik
     * BORN: The player has been born
     * NO_EGG: The team has no egg: each player destroy eggs at sight
     * NO_EGG_END: The team has eggs: must stop destroying eggs
    */
    enum message_type {
        HUNGRY = 0,
        HAS_FOOD = 1,
        FOOD_OK = 2,

        LVL_UP = 3,
        LVL_UP_CHECK = 4,
        LVL_UP_OK = 5,
        LVL_UP_KO = 6,
        LVL_UP_COME = 7,

        TIK = 8,
        TOK = 9,

        BORN = 10,

        NO_EGG = 11,
        NO_EGG_END = 12
    };

    /**
     * @class AiPlayer
     * @brief Class representing an AI's player.
     */
    class AiPlayer
    {
        public:
            AiPlayer(std::vector<pid_t> &children, int port, const char *ip, std::string teamName);
            ~AiPlayer();
            void start();
            void waitForServer();
            void analyseCommand(char *line, ssize_t bytes_read);
            void createThread();
            int getChildId();
            void popChildId();
            void sendMessage(message_type type);
            void getMessage(std::string message);
            void getMessage2(std::vector<std::string> words);
            int getFood();

            /**
             * @brief Get the player id
             * 
             * @return Return the player id
             */
            int getId(){return _id;};
            void moveToPosition(int pos);
            void action();
            static void handle_sigint(int sig);

        private:

            /**
             * @brief The id of the player
             */
            int _id;

            /**
             * @brief The id of the targeted player
             */
            int _searchingId;

            /**
             * @brief The orientation of the player
             */
            int _orientation;
            int _key;

            /**
             * @brief The number of players ready to level up with the player
             */

            int _lvlUpCount;

            /**
             * @brief The port of the server
             */
            int _port;

            /**
             * @brief The socket file descriptor of the server
             */
            int _sockfd;
            bool _goingToLevelUp;
            bool _canLevelUp;

            /**
             * @brief The list of all forked children
             */
            std::vector<pid_t> &_children;

            int _waiting;
            static std::map<pid_t, AiPlayer*> _instances;


            /**
             * @brief The priorities of the player
             */
            AiPriorities _priorities;

            /**
             * @brief The ip of the server
             */
            const char *_ip;

            /**
             * @brief The name of the player team
             */
            std::string _teamName;

            /**
             * @brief The thread of the player that will listen to the server
             */
            pthread_t *_thread;

            /**
             * @brief The list of last 10 send commands
             */
            AiCommand _lastCommand;
            fd_set _readfds;
    };
}

#endif /* !AIPLAYER_HPP_ */
