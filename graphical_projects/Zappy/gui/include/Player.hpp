/*
** EPITECH PROJECT, 2024
** Appzy
** File description:
** Player
*/

/**
 * @file Player.hpp
 * @brief File containing functions that manages the player
*/

#ifndef PLAYER_HPP_
    #define PLAYER_HPP_

    #include <iostream>
    #include <vector>
    #include <functional>
    #include <unordered_map>
    #include "Tile.hpp"

namespace Graphic {

    /**
     * @brief Enum that contains the orientation of the player
    */
    enum class Orientation : int {
        NORTH = 1,
        EAST = 2,
        SOUTH = 3,
        WEST = 4
    };

    /**
     * @class Class with every function needed to manage the player
    */
    class Player {
        public:
            Player(int id, int x, int y, std::string TexturePath);
            ~Player() = default;
            void setPosition(int x, int y);
            void setOrientation(Orientation orientation);
            void setOrientation(int orientation);
            void setLevel(int level);
            void setTeamName(std::string teamName);
            int getId();
            sf::Vector2i getPosition();
            Orientation getOrientation();
            int getLevel();
            std::string getTeamName();
            void collectResource(const std::string& resourceType);
            int getResourceCount(const std::string& resourceType);

            /**
             * @brief The id of the player
            */
            int _id;

            /**
             * @brief The position of the player
            */
            sf::Vector2i _position;

            /**
             * @brief The current tile of the player
            */
            sf::Vector2i _currentTile;

            /**
             * @brief The orientation of the player
            */
            Orientation _orientation;

            /**
             * @brief The level of the player
            */
            int _level;

            /**
             * @brief The inventory of the player
            */
            std::unordered_map<std::string, int> _inventory;

            /**
             * @brief The team name of the player
            */
            std::string _teamName;

            /**
             * @brief The texture of the player
            */
            sf::Texture _texture;

            /**
             * @brief The sprite of the player
            */
            sf::Sprite _sprite;
    };
}

#endif /* !PLAYER_HPP_ */
