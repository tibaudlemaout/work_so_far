/*
** EPITECH PROJECT, 2024
** Appzy
** File description:
** AiPriorities
*/

/**
 * @file AiPriorities.hpp
 * @brief Header file for AiPriorities.
 * In this file, we have all functions about the priorities of the AI
 * 
 */

#ifndef AIPRIORITIES_HPP_
#define AIPRIORITIES_HPP_

namespace AI
{
    /**
     * @enum Priorities
     * @brief Enum representing the priorities of the AI
     */
    enum Priorities {
        FOOD = 0,
        GO_TO = 1,
        LEVEL_UP = 2,
        STONES = 3,
        IDLE = 4,
        EXTERMINATE = 5
    };


    /**
     * @brief The class that handles the priorities of the AI
     * It is used by the players to decide what to do next
     */
    class AiPriorities
    {
    private:
        std::vector<int> _priorities_list;
    public:
        AiPriorities();
        ~AiPriorities();
        Priorities getPriority(int pos);
        void reorganizeVector(std::vector<Priorities> &priorities_list);
        void addPriority(Priorities priority, int qte = 1);
        void setPriority(Priorities priority, int qte = 0);
    };
    
}

#endif /* !AIPRIORITIES_HPP_ */
