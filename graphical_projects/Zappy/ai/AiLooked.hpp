/*
** EPITECH PROJECT, 2024
** Appzy
** File description:
** AiLooked
*/

/**
 * @file AiLooked.hpp
 * @brief Header file for AiLooked.
 * In this file, we have all functions about the tiles that the AI can see
 * 
*/

#ifndef AILOOKED_HPP_
#define AILOOKED_HPP_

#include <vector>
#include "AiTile.hpp"

namespace AI
{
    /**
     * @enum LookedType
     * @brief Enum representing the type of ressource that the AI can see
     */
    enum LookedType {
        FOOD_LOOKED = 0,
        LINEMATE = 1,
        DERAUMERE = 2,
        SIBUR = 3,
        MENDIANE = 4,
        PHIRAS = 5,
        THYSTAME = 6,
        PLAYER = 7,
        EGG_SEEN = 8,
        NOTHING = 9
    };

    /**
     * @class AiLooked
     * @brief Class representing the tiles that the AI can see.
     */
    class AiLooked
    {
        public:
            AiLooked();
            ~AiLooked();

            int getNearest(LookedType type);
            void push_back(AiTile tile);

            /**
             * @brief Function to get the size of the looked vector
             * 
             * @return int 
             */
            int size() { return _looked.size(); };

        private:
            /**
             * @brief Store all the tiles that the AI can see
             */
            std::vector<AiTile> _looked;
    };
}

#endif /* !AILOOKED_HPP_ */
