/*
** EPITECH PROJECT, 2024
** Appzy
** File description:
** AiInventory
*/

/**
 * @file AiInventory.hpp
 * @brief Header file for AiInventory.
 * In this file, we have all functions about the inventory of the AI
 * 
*/

#ifndef AIINVENTORY_HPP_
#define AIINVENTORY_HPP_

namespace AI {

    /**
     * @class AiInventory
     * @brief Class representing an AI's inventory.
     */
    class AiInventory {
        // TODO: #24
        public:

            /**
             * @brief Construct a new Ai Inventory object with given parameters.
             * 
             * @param food Initial quantity of food.
             * @param linemate Initial quantity of linemate.
             * @param deraumere Initial quantity of deraumere.
             * @param sibur Initial quantity of sibur.
             * @param mendiane Initial quantity of mendiane.
             * @param phiras Initial quantity of phiras.
             * @param thystame Initial quantity of thystame.
             */
            AiInventory(int food, int linemate, int deraumere, int sibur, int mendiane, int phiras, int thystame) {
                _food = food;
                _linemate = linemate;
                _deraumere = deraumere;
                _sibur = sibur;
                _mendiane = mendiane;
                _phiras = phiras;
                _thystame = thystame;
            }

            /**
             * @brief Construct a new Ai Inventory object with default values.
             */
            AiInventory() = default;

            /**
             * @brief Destroy the Ai Inventory object.
             */
            ~AiInventory() = default;

            /**
             * @brief Set food quantity to the inventory.
             * 
             * @param food Quantity of food to add.
             */
            void setFood(int food) {
                _food = food;
            }


            /**
             * @brief Set linemate quantity to the inventory.
             * 
             * @param linemate Quantity of linemate to add.
             */
            void setLinemate(int linemate) {
                _linemate = linemate;
            }


            /**
             * @brief Set deraumere quantity to the inventory.
             * 
             * @param deraumere Quantity of deraumere to add.
             */
            void setDeraumere(int deraumere) {
                _deraumere = deraumere;
            }

            /**
             * @brief Set sibur quantity to the inventory.
             * 
             * @param sibur Quantity of sibur to add.
             */
            void setSibur(int sibur) {
                _sibur = sibur;
            }

            /**
             * @brief Set mendiane quantity to the inventory.
             * 
             * @param mendiane Quantity of mendiane to add.
             */
            void setMendiane(int mendiane) {
                _mendiane = mendiane;
            }


            /**
             * @brief Set the Phiras quantity to the inventory.
             * 
             * @param phiras 
             */
            void setPhiras(int phiras) {
                _phiras = phiras;
            }

            /**
             * @brief Set the Thystame quantity to the inventory.
             * 
             * @param thystame 
             */
            void setThystame(int thystame) {
                _thystame = thystame;
            }

            /**
             * @brief Get the food quantity from the inventory.
             * 
             * @return int Quantity of food.
             */
            int getFood() {
                return _food;
            }

            /**
             * @brief Get the linemate quantity from the inventory.
             * 
             * @return int Quantity of linemate.
             */
            int getLinemate() {
                return _linemate;
            }

            /**
             * @brief Get the deraumere quantity from the inventory.
             * 
             * @return int Quantity of deraumere.
             */
            int getDeraumere() {
                return _deraumere;
            }

            /**
             * @brief Get the sibur quantity from the inventory.
             * 
             * @return int Quantity of sibur.
             */
            int getSibur() {
                return _sibur;
            }

            /**
             * @brief Get the mendiane quantity from the inventory.
             * 
             * @return int Quantity of mendiane.
             */
            int getMendiane() {
                return _mendiane;
            }

            /**
             * @brief Get the phiras quantity from the inventory.
             * 
             * @return int Quantity of phiras.
             */
            int getPhiras() {
                return _phiras;
            }

            /**
             * @brief Get the thystame quantity from the inventory.
             * 
             * @return int Quantity of thystame.
             */
            int getThystame() {
                return _thystame;
            }

        protected:
        private:

            /**
             * @brief Quantity of food in the inventory.
             */
            int _food;

            /**
             * @brief Quantity of linemate in the inventory.
             */
            int _linemate;

            /**
             * @brief Quantity of deraumere in the inventory.
             */
            int _deraumere;

            /**
             * @brief Quantity of sibur in the inventory.
             */
            int _sibur;

            /**
             * @brief Quantity of mendiane in the inventory.
             */
            int _mendiane;

            /**
             * @brief Quantity of phiras in the inventory.
             */
            int _phiras;

            /**
             * @brief Quantity of thystame in the inventory.
             */
            int _thystame;
    };
}

#endif /* !AIINVENTORY_HPP_ */
