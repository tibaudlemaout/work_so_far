/*
** EPITECH PROJECT, 2024
** Appzy
** File description:
** Resource
*/

/**
 * @file Resource.hpp
 * @brief File containing functions that manages the resource
 */

#ifndef RESOURCE_HPP_
    #define RESOURCE_HPP_

    #include <iostream>
    #include <cstring>
    #include <SFML/Graphics.hpp>

namespace Graphic {

    /**
     * @class Class with every function needed to manage the resource
     */
    class Resource {
        public:
            Resource(const std::string name, const int x, const int y);
            ~Resource() = default;
            void setPosition(const int x, const int y);
            sf::Vector2f getPosition();

            /**
             * @brief The position of the resource
             */
            sf::Vector2i _position;

            /**
             * @brief The texture of the resource
             */
            sf::Texture _texture; 

            /**
             * @brief The sprite of the resource
             */
            sf::Sprite _sprite;

            /**
             * @brief The name of the resource
             */
            std::string _name;
    };
}

#endif /* !RESOURCE_HPP_ */
