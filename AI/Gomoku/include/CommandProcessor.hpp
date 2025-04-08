/*
** EPITECH PROJECT, 2024
** Gomoku
** File description:
** CommandProcessor.hpp
*/

#ifndef COMMANDPROCESSOR_HPP
    #define COMMANDPROCESSOR_HPP

    #include <iostream>
    #include <sstream>
    #include <unordered_map>
    #include <functional>
    #include <mutex>
    #include <thread>
    #include "include/Gomoku.hpp"

/**
 * @class CommandProcessor
 *
 * @brief Handles commands and dispatches them to the appropriate handler functions.
 */
class CommandProcessor {
    public:
        /**
         * @brief Constructs a new CommandProcessor object and initializes command mappings.
         */
        CommandProcessor();
        
        /**
         * @brief Default destructor.
         */
        ~CommandProcessor() = default;

        /**
         * @brief Starts listening for input commands in a loop, processes each command received.
         */
        void listener();
        
        /**
         * @brief Waits for messages in the game’s message queue and sends them to stdout.
         */
        void sender();

        /**
         * @brief Processes a given command string by parsing it and calling the associated handler function.
         *
         * @param input The input command string to process.
         */
        void processCommand(const std::string& input);
        Game game;
        std::mutex commandMutex;

        bool inBoardCommand;

    private:
        std::unordered_map<std::string, std::function<void(std::istringstream&)>> command_map_;

        /**
         * @brief Handles the "START" command to initialize the game with a specified board size.
         *
         * @param size The size of the board for the game.
         */
        void handleStart(int size);

        /**
         * @brief Handles the "TURN" command, updating the game state based on the opponent's move.
         *
         * @param x The x-coordinate of the opponent's move.
         * @param y The y-coordinate of the opponent's move.
         */
        void handleTurn(int x, int y);

        /**
         * @brief Handles the "BOARD" command, which allows multiple moves to be entered in succession.
         *
         * @param command The full board command string containing moves.
         */
        void handleBoard(const std::string& command);

        /**
         * @brief Handles the "BEGIN" command, which starts the game and initiates the player's first move.
         */
        void handleBegin();

        /**
         * @brief Handles the "END" command, which terminates the program.
         */
        void handleEnd();

        /**
         * @brief Handles the "INFO" command, which sets various game configuration parameters.
         *
         * @param input The string containing key-value pairs of game information.
         */
        void handleInfo(const std::string& input);

        /**
         * @brief Handles the "ABOUT" command, which provides information about the bot.
         */
        void handleAbout();
};

#endif /* !COMMANDPROCESSOR_HPP_ */
