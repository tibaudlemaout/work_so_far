/*
** EPITECH PROJECT, 2024
** Appzy
** File description:
** AiTile
*/

/**
 * @file AiTile.hpp
 * @brief Header file for AiTile.
 * In this file, we have all functions about the tiles that the AI can see
 * 
*/

#ifndef AITILE_HPP_
#define AITILE_HPP_

namespace AI {

    /**
     * @class AiTile
     * @brief Class representing a tile.
     */
    class AiTile {
        public:

            /**
             * @brief Construct a new Ai Tile object with default values.
             */
            AiTile() {
                _food = 0;
                _linemate = 0;
                _deraumere = 0;
                _sibur = 0;
                _mendiane = 0;
                _phiras = 0;
                _thystame = 0;
                _players = 0;
                _eggs = 0;
            }

            /**
             * @brief Destroy the Ai Tile object.
             */
            ~AiTile() = default;

            /**
             * @brief Set food quantity to the tile.
             * 
             * @param food Quantity of food.
             */
            void setFood(int food) {
                _food = food;
            }

            /**
             * @brief Set linemate quantity to the tile.
             * 
             * @param linemate Quantity of linemate.
             */
            void setLinemate(int linemate) {
                _linemate = linemate;
            }

            /**
             * @brief Set deraumere quantity to the tile.
             * 
             * @param deraumere Quantity of deraumere.
             */
            void setDeraumere(int deraumere) {
                _deraumere = deraumere;
            }

            /**
             * @brief Set sibur quantity to the tile.
             * 
             * @param sibur Quantity of sibur.
             */
            void setSibur(int sibur) {
                _sibur = sibur;
            }

            /**
             * @brief Set mendiane quantity to the tile.
             * 
             * @param mendiane Quantity of mendiane.
             */
            void setMendiane(int mendiane) {
                _mendiane = mendiane;
            }

            /**
             * @brief Set phiras quantity to the tile.
             * 
             * @param phiras Quantity of phiras.
             */
            void setPhiras(int phiras) {
                _phiras = phiras;
            }

            /**
             * @brief Set thystame quantity to the tile.
             * 
             * @param thystame Quantity of thystame.
             */
            void setThystame(int thystame) {
                _thystame = thystame;
            }

            /**
             * @brief Set players quantity to the tile.
             * 
             * @param players Quantity of players.
             */
            void setPlayers(int players) {
                _players = players;
            }
            
            /**
             * @brief Set eggs quantity to the tile.
             * 
             * @param eggs Quantity of eggs.
             */
            void setEggs(int eggs) {
                _eggs = eggs;
            }

            /**
             * @brief Get the food quantity of the tile.
             * 
             * @return Return the food quantity.
             */
            int getFood() {
                return _food;
            }

            /**
             * @brief Get the linemate quantity of the tile.
             * 
             * @return Return the linemate quantity.
             */
            int getLinemate() {
                return _linemate;
            }

            /**
             * @brief Get the deraumere quantity of the tile.
             * 
             * @return Return the deraumere quantity.
             */
            int getDeraumere() {
                return _deraumere;
            }

            /**
             * @brief Get the sibur quantity of the tile.
             * 
             * @return Return the sibur quantity.
             */
            int getSibur() {
                return _sibur;
            }

            /**
             * @brief Get the mendiane quantity of the tile.
             * 
             * @return Return the mendiane quantity.
             */
            int getMendiane() {
                return _mendiane;
            }

            /**
             * @brief Get the phiras quantity of the tile.
             * 
             * @return Return the phiras quantity.
             */
            int getPhiras() {
                return _phiras;
            }

            /**
             * @brief Get the thystame quantity of the tile.
             * 
             * @return Return the thystame quantity.
             */
            int getThystame() {
                return _thystame;
            }

            /**
             * @brief Get the players quantity of the tile.
             * 
             * @return Return the players quantity.
             */
            int getPlayers() {
                return _players;
            }

            /**
             * @brief Get the eggs quantity of the tile.
             * 
             * @return Return the eggs quantity.
             */
            int getEggs() {
                return _eggs;
            }

        private:
            /**
             * @brief Quantity of food.
             */
            int _food;

            /**
             * @brief Quantity of linemate.
             */
            int _linemate;

            /**
             * @brief Quantity of deraumere.
             */
            int _deraumere;

            /**
             * @brief Quantity of sibur.
             */
            int _sibur;

            /**
             * @brief Quantity of mendiane.
             */
            int _mendiane;

            /**
             * @brief Quantity of phiras.
             */
            int _phiras;

            /**
             * @brief Quantity of thystame.
             */
            int _thystame;

            /**
             * @brief Quantity of players.
             */
            int _players;

            /**
             * @brief Quantity of eggs.
             */
            int _eggs;
    };
}

#endif /* !AITILE_HPP_ */
