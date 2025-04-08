/*
** EPITECH PROJECT, 2024
** Appzy
** File description:
** Tile
*/

/**
 * @file Tile.hpp
 * @brief File containing functions that manages the tile
*/

#ifndef TILE_HPP_
    #define TILE_HPP_

    #include <iostream>
    #include <vector>
    #include <unordered_map>
    #include <SFML/Graphics.hpp>
    #include "Resource.hpp"

namespace Graphic {

    /**
     * @enum Enum that contains the items types
    */
    enum Items : int
    {
        FOOD = 0,
        LINEMATE = 1,
        DERAUMERE = 2,
        SIBUR = 3,
        MENDIANE = 4,
        PHIRAS = 5,
        THYSTAME = 6
    };

    /**
     * @class Class with every function needed to manage the tile
    */
    class Tile {
        public:
            Tile(const int x, const int y);
            ~Tile() = default;
            int getResourceTypeNb(const std::string& name);
            sf::Vector2f getPosition();

            /**
             * @brief The list of ressources of the tile
             */
            std::unordered_map<std::string, Resource> _resources;

            /**
             * @brief The list of items of the tile
             */
            std::unordered_map<std::string, int> _items;

            /**
             * @brief The x position of the tile
             */
            int _x;

            /**
             * @brief The y position of the tile
             */
            int _y;

            /**
             * @brief The texture of the tile
             */
            sf::Texture _texture;

            /**
             * @brief The sprite of the tile
             */
            sf::Sprite _sprite;
    };
}

#endif /* !TILE_HPP_ */
