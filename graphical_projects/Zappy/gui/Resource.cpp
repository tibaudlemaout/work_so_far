/*
** EPITECH PROJECT, 2024
** Appzy
** File description:
** Resource
*/

/**
 * @file Resource.cpp
 * @brief File containing functions that manages the resources
 */

#include "include/Resource.hpp"

/**
 * @brief Construct a new Resource:: Resource object
 * 
 * @param name The name of the resource
 * @param x The x position
 * @param y The y position
 */
Graphic::Resource::Resource(const std::string name, const int x, const int y) : _name(name)
{

    if (!strcmp(name.c_str(), "food")) {
        if (!_texture.loadFromFile("gui/Assets/Food.png")) {
            std::cerr << "Error: loading texture" << std::endl;
            exit(84);
        }
    } else if (!_texture.loadFromFile("gui/Assets/Resources.png")) {
            std::cerr << "Error: loading texture" << std::endl;
            exit(84);
    }
    
    if (!strcmp(name.c_str(), "linemate")) {
        _sprite.setTextureRect(sf::IntRect(416, 32, 32, 32));
        setPosition(x + 73, y + 33);
    } else if (!strcmp(name.c_str(), "deraumere")) {
        _sprite.setTextureRect(sf::IntRect(192, 160, 32, 32));
        setPosition(x + 50, y + 43);
    } else if (!strcmp(name.c_str(), "sibur")) {
        _sprite.setTextureRect(sf::IntRect(320, 0, 32, 32));
        setPosition(x + 28, y + 35);
    } else if (!strcmp(name.c_str(), "mendiane")) {
        _sprite.setTextureRect(sf::IntRect(224, 160, 32, 32));
        setPosition(x + 15, y + 18);
    } else if (!strcmp(name.c_str(), "phiras")) {
        _sprite.setTextureRect(sf::IntRect(320, 160, 32, 32));
        setPosition(x + 35, y + 15);
    } else if (!strcmp(name.c_str(), "thystame")) {
        _sprite.setTextureRect(sf::IntRect(480, 160, 32, 32));
        setPosition(x + 100, y + 30);
    } else if (!strcmp(name.c_str(), "food")) {
        _sprite.setTextureRect(sf::IntRect(34, 31, 16, 16));
        setPosition(x + 80, y + 18);
    } else {
        std::cerr << "Error: invalid resource" << std::endl;
        exit(84);
    }

    _sprite.setTexture(_texture);
    _sprite.setScale(0.3f, 0.3f);
    if (!strcmp(name.c_str(), "food"))
    _sprite.setScale(0.8f, 0.8f);
}

/**
 * @brief Function that set the position of the resource
 * 
 * @param x The x position
 * @param y The y position
 */
void Graphic::Resource::setPosition(const int x, const int y)
{
    _position.x = x;
    _position.y = y;
    _sprite.setPosition(_position.x, _position.y);
}

/**
 * @brief Function that returns the position of the resource
 * 
 * @return sf::Vector2f The position
 */
sf::Vector2f Graphic::Resource::getPosition()
{
    return _sprite.getPosition();
}
