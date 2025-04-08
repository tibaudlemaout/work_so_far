/*
** EPITECH PROJECT, 2024
** Gomoku
** File description:
** Gomoku.hpp file
*/

#ifndef GOMOKU_HPP
    #define GOMOKU_HPP
    #include "stdio.h"
    #include "unistd.h"
    #include "stdlib.h"
    #include "iostream"
    #include <climits>
    #include <time.h>
    #include <queue>
    #include <condition_variable>
    #include <vector>

    /**
     * @class Game
     * @brief Represents a game with a board and evaluation state.
     *
     * The Game class manages the state of the board, evaluates moves,
     * and contains functions to handle gameplay.
     */
    class Game {
        public:
        /**
         * @brief Constructor for the Game class.
         */
        Game() = default;

        /**
         * @brief Destructor for the Game class.
         *
         * Frees allocated memory for the board array.
         */
        ~Game()
        {
            for (int i = 0; i< boardSize; i++) {
                free(boardArray[i]);
            }
            free(boardArray);
        }

        /**
         * @brief Initializes the board and it's arrays to the given size.
         * @param size The size of the game board (width and height).
         */
        void init(int size)
        {
            boardArray = createBoardState(size);
            evalArray = createBoardState(size);
            boardSize = size;
        }

        /**
         * @brief Evaluates the current state of the game board.
         * @param boardState The current state of the game board.
         * @return A pointer to a 2D array representing the evaluated state.
         */
        int **evaluationFunction(int **boardState);

        /**
         * @brief Creates an empty game board of the specified size.
         * @param size The size of the game board (width and height).
         * @return A pointer to the created 2D board array.
         */
        int **createBoardState(int size);

        /**
         * @brief Cleans the game board of evaluation values and resets them all to -1.
         * @param size The size of the game board (width and height).
         * @return A pointer to the created 2D board array.
         */
        int **cleanEvalState(int size);

        /**
         * @brief Updates the game state for the enemy's move.
         * @param x The x-coordinate of the enemy's move.
         * @param y The y-coordinate of the enemy's move.
         */
        void updateEnemyTurn(int x, int y);

        /**
         * @brief Initiates the play loop for the game.
         *
         * Handles the main gameplay logic and turn-based interactions.
         */
        void play();

        /**
         * @brief Evaluates the board for winning moves and assigns high values for such moves in evalArray.
         *
         * This function iterates over the board positions and checks if any empty cell would result
         * in a winning move for the specified player. If such a move is found, it assigns the maximum
         * possible int value to the corresponding position in evalArray to prioritize it in AI evaluation.
         *
         * @param boardArray The current state of the board as a 2D array.
         * @param evalArray The evaluation array where values are assigned based on move priorities.
         * @param player The player ID (e.g., 1 or 2) representing the player to check for winning moves.
         */
        void evaluateWinningMoves(int **boardArray, int **evalArray, int player);

        /**
         * @brief Evaluates the board for losing moves and assigns high values for blocking such moves in evalArray.
         *
         * This function iterates over the board positions and checks if any empty cell would result
         * in a winning move for the opponent. If such a move is found, it assigns the maximum possible
         * int value minus 1 to the corresponding position in evalArray to prioritize blocking it in AI evaluation.
         *
         * @param boardArray The current state of the board as a 2D array.
         * @param evalArray The evaluation array where values are assigned based on move priorities.
         * @param opponent The opponent's player ID (e.g., 1 or 2) representing the player to check for losing moves.
         */
        void evaluateLosingMoves(int **boardArray, int **evalArray, int opponent);

        /**
         * @brief Checks if placing a token at (x, y) would result in a winning move for the specified player.
         *
         * This function examines the board in four directions (horizontal, vertical, diagonal, anti-diagonal)
         * from the specified position (x, y) to determine if placing the player's token there would
         * complete a line of 5 consecutive tokens, indicating a winning move.
         *
         * @param boardArray The current state of the board as a 2D array.
         * @param x The x-coordinate of the position to check.
         * @param y The y-coordinate of the position to check.
         * @param player The player ID (e.g., 1 or 2) representing the player to check for a winning move.
         * @return true if placing a token at (x, y) would create a line of 5 for the player, otherwise false.
         */
        bool checkFinalMove(int **boardArray, int x, int y, int player);

        /**
         * @brief Evaluates and assigns a value of 1 to positions adjacent to an already placed stone.
         *
         * This function iterates over each cell on the board. For each empty cell, it checks
         * its eight neighboring cells (if they exist). If any neighbor contains a stone (1 or 2),
         * it increments the evaluation value at that position in evalArray by 1.
         *
         */
        void evaluateAdjacentMoves(void);

        /**
         * @brief Evaluates the board to find moves that could lead to a 3x3 fork in the future.
         *
         * This function assigns a higher evaluation score to moves that could lead to a fork
         * by creating or extending two or more open-ended sequences.
         *
         * @param player The player ID (e.g., 1 or 2) representing the player for whom to create forks.
         */
        void evaluateForkCreationMoves(int player);

        /**
         * @brief Inserts a move on the board for the specified player.
         *
         * This function updates the game board by placing the player's token at the specified 
         * coordinates (x, y). The player is represented by an integer (e.g., 1, 2 or 3) that 
         * corresponds to the stone's player(1 = own stone, 2 = opponent stone, 3 = winning or other). 
         * The function assumes that the coordinates provided are within the bounds of the board and that
         * the specified position is empty.
         *
         * @param x The x-coordinate on the board where the move is to be inserted.
         * @param y The y-coordinate on the board where the move is to be inserted.
         * @param player The ID of the player making the move, represented as an integer (e.g., 1 or 2).
         */
        void insertBoardMove(int x, int y, int player);

        /**
         * @brief Searches the highest evaluation value on the evalArray and returns the positions of said highest value.
         *
         * This function searches through the evalArray for the highest value present which represent the current best
         * play with the current board. The position of said value is then stored in a pair<int, int> to be returned to
         * be used for Game::play.
         *
         * @return A pair that contains the x and y position of the highest value.
         */
        std::pair<int, int> findMaxValuePosition(void);

        /**
         * @brief Evaluates the board for potential three-in-a-row moves and assigns scores to positions.
         * 
         * This function iterates through the board, evaluating all empty positions (`boardArray[x][y] == 0`) 
         * and calculating their potential scores based on their ability to create or contribute to a 
         * three-in-a-row for the specified player. The scores are stored in the evaluation array (`evalArray`).
         * Scoring rules:
         * - +10: Completing a three-in-a-row in one direction.
         * - +8: Linking two pieces into a three-in-a-row by playing in the middle.
         * @param player The player ID (e.g., 1 or 2) for whom the evaluation is being performed.
         *               Only the specified player's pieces are considered when evaluating potential moves.
         * @warning Accessing indices out of bounds can cause undefined behavior. Make sure the board size 
         *          and indices are valid.
        */
        void evaluateThreeInARowMoves(int player);

        /**
         * @brief Evaluates the board for positions that block an opponent's open three-in-a-row.
         * 
         * This function checks all empty positions (`boardArray[x][y] == 0`) to see if placing a piece 
         * would block one side of an opponent's existing three-in-a-row. If so, it assigns a score 
         * to that position, indicating its importance in preventing the opponent from winning.
         * Scoring rules:
         * - +100: Blocks one side of an opponent's open three-in-a-row.
         * - +7: Contributes to blocking a potential open three-in-a-row.
         * @param player The player ID (e.g., 1 or 2) for whom the evaluation is being performed.
         *               The function checks the opponent's potential open lines, so ensure the player 
         *               is the one making the move.
         * @warning Accessing indices out of bounds can cause undefined behavior. Make sure the board size 
         *          and indices are valid.
         */
        void evaluateBlockOpponentOpenThreeInARow(int player);

        void evaluateFourInARowMoves(int player);

        /**
         * @struct about_values
         * @brief Contains metadata about the ai.
         *
         * This structure holds information such as the game's name, version, author and country.
         */
        struct {
            std::string name;
            std::string version;
            std::string author;
            std::string country;
        } about_values;

        /**
         * @struct infos
         * @brief Contains metadata about the game.
         *
         * This structure holds given informations from the manager.
         */
        struct  {
            unsigned long timeout_turn;     // time limit for each move (milliseconds, 0=play as fast as possible)
            unsigned long timeout_match;    // time limit of a whole match (milliseconds, 0=no limit)
            unsigned long max_memory;       // memory limit (bytes, 0=no limit)
            unsigned long time_left;        // remaining time limit of a whole match (milliseconds)
            int game_type;                  // 0=opponent is human, 1=opponent is brain, 2=tournament, 3=network tournament
            int rule;                       // bitmask or sum of 1=exactly five in a row win, 2=continuous game, 4=renju, 8=caro
            int evaluate_x;                 // coordinates X,Y representing current position of the mouse cursor
            int evaluate_y;                 // coordinates X,Y representing current position of the mouse cursor
            std::string folder;             // folder for persistent files
        } infos;

        int **boardArray;
        int **evalArray;
        int boardSize;

        // threads variables
        std::queue<std::string> _messageQueue;
        std::mutex _queueMutex;
        std::condition_variable _queueCondVar;

    private:
        int playerValue;
};

#endif // GOMOKU_HPP
