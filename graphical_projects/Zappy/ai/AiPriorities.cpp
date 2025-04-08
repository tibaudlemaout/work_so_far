/*
** EPITECH PROJECT, 2024
** Appzy
** File description:
** AiPriorities
*/

/**
 * @file AiPriorities.cpp
 * @brief Source file for AiPriorities.
 * In this file, we have all functions about the priorities of the AI
 * 
*/

#include <vector>
#include <iostream>
#include "AiPriorities.hpp"

/**
 * @brief Construct a new AI::AiPriorities::AiPriorities object
 * 
 */
AI::AiPriorities::AiPriorities()
{
    for (int i = 0; i < 6; i++) {
        _priorities_list.push_back(i);
    }
    _priorities_list[static_cast<int>(FOOD)] = 10;
    _priorities_list[static_cast<int>(GO_TO)] = 0;
    _priorities_list[static_cast<int>(LEVEL_UP)] = 0;
    _priorities_list[static_cast<int>(STONES)] = 5;
    _priorities_list[static_cast<int>(IDLE)] = 0;
    _priorities_list[static_cast<int>(EXTERMINATE)] = 0;
}

AI::AiPriorities::~AiPriorities()
{
}

/**
 * @brief Function that reorganizes the priorities list
 * 
 * @param priorities_list The list of priorities to reorganize
 */
void AI::AiPriorities::reorganizeVector(std::vector<Priorities> &priorities_list)
{
    int pos = 0;
    std::vector<Priorities> new_list;

    for (int i = 0; i < priorities_list.size(); i++) {
        pos = 0;
        while (pos < new_list.size() && _priorities_list[static_cast<int>(priorities_list[i])] < _priorities_list[static_cast<int>(new_list[pos])]) {
            pos++;
        }
        if (pos == new_list.size()) {
            new_list.push_back(priorities_list[i]);
        } else {
            new_list.insert(new_list.begin() + pos, priorities_list[i]);
        }
    }
    priorities_list = new_list;
}

/**
 * @brief Get the priority at the specified position
 * @param pos The position of the priority
 * 
 * @return The priority at the specified position
 */
AI::Priorities AI::AiPriorities::getPriority(int pos)
{
    std::vector<Priorities> priorities_list = {FOOD, GO_TO, LEVEL_UP, STONES, IDLE, EXTERMINATE};
    reorganizeVector(priorities_list);
    return priorities_list[pos];
}

/**
 * @brief Change the value of a priority
 * @param priority The priority to change
 * @param qte The quantity to add or substract.
 *  If the quantity is not specified, it will be set to 1
 */
void AI::AiPriorities::addPriority(Priorities priority, int qte)
{
    _priorities_list[static_cast<int>(priority)] += qte;
}

/**
 * @brief Set the value of a priority
 * @param priority The priority to change
 * @param qte The quantity to set.
 *  If the quantity is not specified, it will be set to 0
 */
void AI::AiPriorities::setPriority(Priorities priority, int qte)
{
    _priorities_list[static_cast<int>(priority)] = qte;
}