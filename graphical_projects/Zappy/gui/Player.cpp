/*
** EPITECH PROJECT, 2024
** Appzy
** File description:
** Client
*/

/**
 * @file Player.cpp
 * @brief File containing functions that manages the player
 */

#include "include/Player.hpp"

/**
 * @brief Construct a new Player:: Player object
 * 
 * @param id The id of the player
 * @param x The x position of the player
 * @param y The y position of the player
 */
Graphic::Player::Player(int id, int x, int y, std::string texturePath)
{
    _id = id;
    _level = 1;
    _orientation = Orientation::SOUTH;

    if (!_texture.loadFromFile(texturePath)) {
        std::cerr << "Error: loading texture" << std::endl;
        exit(84);
    }
    _sprite.setTexture(_texture);
    _sprite.setTextureRect(sf::IntRect(0, 0, 22, 40));
    _sprite.setScale(2.0f, 2.0f);
    setPosition(x, y);

    _inventory["food"] = 0;
    _inventory["linemate"] = 0;
    _inventory["deraumere"] = 0;
    _inventory["sibur"] = 0;
    _inventory["mendiane"] = 0;
    _inventory["phiras"] = 0;
    _inventory["thysmate"] = 0;
}

/**
 * @brief Function that moves the player
 * 
 * @param x The x position
 * @param y The y position
 */
void Graphic::Player::setPosition(int x, int y)
{
    _position = sf::Vector2i(x, y);
    _currentTile = sf::Vector2i(x, y);
    _sprite.setPosition(x, y);
}

/**
 * @brief Function that set the orientation of the player
 * 
 * @param orientation The orientation
 */
void Graphic::Player::setOrientation(Orientation orientation)
{
    _orientation = orientation;
    if (_orientation == Graphic::Orientation::NORTH || _orientation == Graphic::Orientation::EAST) {
        this->setPosition(this->_position.x + 64.0f, this->_position.y - 32.0f);
        this->_sprite.setScale(-2.0f, 2.0f); // mirror
    } else if (_orientation == Graphic::Orientation::SOUTH || _orientation == Graphic::Orientation::WEST) {
        this->setPosition(this->_position.x - 64.0f, this->_position.y + 32.0f);
        this->_sprite.setScale(2.0f, 2.0f); // reset mirror
    }
}

/**
 * @brief Function that set the orientation of the player
 * 
 * @param orientation The orientation
 */
void Graphic::Player::setOrientation(int orientation)
{
    switch (orientation) {
        case 1: _orientation = Orientation::NORTH; break;
        case 2: _orientation = Orientation::EAST; break;
        case 3: _orientation = Orientation::SOUTH; break;
        case 4: _orientation = Orientation::WEST; break;
    }
    setOrientation(_orientation);
}

/**
 * @brief Function that set the level of the player
 * 
 * @param level The level
 */
void Graphic::Player::setLevel(int level)
{
    _level = level;
}

/**
 * @brief Function that set the team name of the player
 * 
 * @param teamName The team name
 */
void Graphic::Player::setTeamName(std::string teamName)
{
    _teamName = teamName;
}

/**
 * @brief Function that get the id of the player
 * 
 * @return int The id of the player
 */
int Graphic::Player::getId()
{
    return _id;
}

/**
 * @brief Function that get the position of the player
 * 
 * @return sf::Vector2i The position of the player
 */
sf::Vector2i Graphic::Player::getPosition()
{
    return _position;
}

/**
 * @brief Function that get the orientation of the player
 * 
 * @return Graphic::Orientation The orientation of the player
 */
Graphic::Orientation Graphic::Player::getOrientation()
{
    return _orientation;
}

/**
 * @brief Function that get the level of the player
 * 
 * @return int The level of the player
 */
int Graphic::Player::getLevel()
{
    return _level;
}

/**
 * @brief Function that get the team name of the player
 * 
 * @return std::string The team name of the player
 */
std::string Graphic::Player::getTeamName()
{
    return _teamName;
}

/**
 * @brief Function that collect a resource for the player
 * 
 * @param resourceType The type of the resource to collect
 */
void Graphic::Player::collectResource(const std::string& resourceType)
{
    _inventory[resourceType]++;
}

/**
 * @brief Function that get the number of a resource for the player
 * 
 * @param resourceType The type of the resource to drop
 * @return int The number of the resource
 */
int Graphic::Player::getResourceCount(const std::string& resourceType)
{
    auto it = _inventory.find(resourceType);
    if (it != _inventory.end()) {
        return it->second;
    }
    return 0;
}
