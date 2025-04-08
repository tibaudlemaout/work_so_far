/*
** EPITECH PROJECT, 2024
** Appzy
** File description:
** Client
*/

/**
 * @file Tile.cpp
 * @brief File containing functions that manages the tile
 */

#include "include/Tile.hpp"

/**
 * @brief Construct a new Tile:: Tile object
 * 
 * @param x The x position of the tile
 * @param y The y position of the tile
 */
Graphic::Tile::Tile(const int x, const int y)
{
    _x = x;
    _y = y;

    _resources.emplace("food", Resource("food", _x, _y));
    _resources.emplace("linemate", Resource("linemate", _x, _y));
    _resources.emplace("deraumere", Resource("deraumere", _x, _y));
    _resources.emplace("sibur", Resource("sibur", _x, _y));
    _resources.emplace("mendiane", Resource("mendiane", _x, _y));
    _resources.emplace("phiras", Resource("phiras", _x, _y));
    _resources.emplace("thystame", Resource("thystame", _x, _y));

    if (!_texture.loadFromFile("gui/Assets/TileSet.png")) {
        std::cerr << "Error: loading texture" << std::endl;
        exit(84);
    }
    _sprite.setTexture(_texture);
    _sprite.setTextureRect(sf::IntRect(0, 0, 64, 40));
    _sprite.setPosition(_x, _y);
    _sprite.setScale(2.0f, 2.0f);

    _items["food"] = 1;
    _items["linemate"] = 1;
    _items["deraumere"] = 1;
    _items["sibur"] = 1;
    _items["mendiane"] = 3;
    _items["phiras"] = 1;
    _items["thystame"] = 1;
}

/**
 * @brief Function that gets the resource type quantity by name
 * 
 * @param name The name of the resource type to count
 * @return int The quantity of the resource type
 */
int Graphic::Tile::getResourceTypeNb(const std::string& name)
{
    auto it = _items.find(name);
    if (it != _items.end()) {
        return it->second;
    }
    return -1;
}

/**
 * @brief Function that gets the position of the tile
 * 
 * @return sf::Vector2f The position of the tile
 */
sf::Vector2f Graphic::Tile::getPosition()
{
    return _sprite.getPosition();
}
