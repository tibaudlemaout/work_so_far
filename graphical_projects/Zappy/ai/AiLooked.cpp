/*
** EPITECH PROJECT, 2024
** Appzy
** File description:
** AiLooked
*/

/**
 * @file AiLooked.cpp
 * @brief Source file for AiLooked.
 * In this file, we have all functions about the tiles that the AI can see
 * 
*/

#include <cmath>
#include <iostream>
#include "AiLooked.hpp"

AI::AiLooked::AiLooked()
{
}

AI::AiLooked::~AiLooked()
{
}

/**
 * @brief In this function, we get the nearest the nearest tile that has the type we are looking for
 * 
 * @param type  The type of the ressource we are looking for
 * @return int The number of the nearest tile
 * The function returns -1 if no tile has the ressource we are looking for
 */
int AI::AiLooked::getNearest(LookedType type)
{
    int nearest = -1;
    int square = 1;
    int last = -1;
    int temp = 0;
    int h = 0;
    int i = -1;
    bool found = false;

    for (auto &line : _looked) {
        i++;
        switch (type) {
            case FOOD_LOOKED:
                if (line.getFood() == 0)
                    continue;
                break;
            case LINEMATE:
                if (line.getLinemate() == 0)
                    continue;
                break;
            case DERAUMERE:
                if (line.getDeraumere() == 0)
                    continue;
                break;
            case SIBUR:
                if (line.getSibur() == 0)
                    continue;
                break;
            case MENDIANE:
                if (line.getMendiane() == 0)
                    continue;
                break;
            case PHIRAS:
                if (line.getPhiras() == 0)
                    continue;
                break;
            case THYSTAME:
                if (line.getThystame() == 0)
                    continue;
                break;
            case PLAYER:
                if (line.getPlayers() == 0)
                    continue;
                break;
            case EGG_SEEN:
                if (line.getEggs() == 0)
                    continue;
                break;
        }
        square = static_cast<int>(std::floor(std::sqrt(i)));
        temp += square;
        h = (square * square) - ((1 + square) * (1 + square)) - 1;
        h = (abs(i - (square * square) - (h / 2)));
        if (h > 0) {
            h++;
        }
        temp += h;
        if (temp < nearest || nearest == -1) {
            nearest = temp;
            last = i;
        }
    }
    return last;
}

void AI::AiLooked::push_back(AiTile tile)
{
    _looked.push_back(tile);
}
