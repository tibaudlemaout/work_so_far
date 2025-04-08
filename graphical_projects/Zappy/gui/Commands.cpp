/*
** EPITECH PROJECT, 2024
** Appzy
** File description:
** Commands
*/

/**
 * @file Commands.cpp
 * @brief File containing functions that manages the commands
*/

#include <random>
#include "include/Commands.hpp"

/**
 * @brief Function that set the map size
 * 
 * @param str The string that contains the size
 */
void Graphic::Commands::setMapSize(const std::string str)
{
    std::istringstream stream(str);
    std::string command;
    int width = 0;
    int height = 0;

    stream >> command >> width >> height;
    _scene.gridWidth = width;
    _scene.gridHeight = height;
}

/**
 * @brief Function that set the tile content
 * 
 * @param str The string that contains the content
 */
void Graphic::Commands::setTileContent(const std::string str)
{
    std::istringstream stream(str);
    std::string command;
    int x = 0;
    int y = 0;
    int food = 0;
    int linemate = 0;
    int deraumere = 0;
    int sibur = 0;
    int mendiane = 0;
    int phiras = 0;
    int thystame = 0;

    stream >> command >> x >> y >> food >> linemate >> deraumere >> sibur >> mendiane >> phiras >> thystame;
    _scene._mapTiles[y][x]._items["food"] = food;
    _scene._mapTiles[y][x]._items["linemate"] = linemate;
    _scene._mapTiles[y][x]._items["deraumere"] = deraumere;
    _scene._mapTiles[y][x]._items["sibur"] = sibur;
    _scene._mapTiles[y][x]._items["mendiane"] = mendiane;
    _scene._mapTiles[y][x]._items["phiras"] = phiras;
    _scene._mapTiles[y][x]._items["thystame"] = thystame;
}

/**
 * @brief Function that set the team name
 * 
 * @param str The string that contains the team name
 */
void Graphic::Commands::setTeamName(const std::string str)
{
    std::istringstream stream(str);
    std::string command;
    std::string teamName;
    
    stream >> command >> teamName;

    _scene._teamNames.push_back(teamName);
}

/**
 * @brief Function that set the player connection
 * 
 * @param str The string that contains the player connection
 */
void Graphic::Commands::newPlayerConnection(const std::string str)
{
    std::istringstream stream(str);
    std::string command;
    std::string idStr;
    std::string teamName;
    int level = 0;
    int x = 0;
    int y = 0;
    int orientation = 0;
    
    stream >> command >> idStr >> x >> y >> orientation >> level >> teamName;

    if (!_scene._mapTiles.empty() && !_scene._mapTiles[0].empty()) {
        int tileCenterX = _scene._mapTiles[y][x].getPosition().x + 64 - 22;
        int tileCenterY = _scene._mapTiles[y][x].getPosition().y - 40;
        if (std::find(_scene._teamNames.begin(), _scene._teamNames.end(), teamName) == _scene._teamNames.end()) {
            _scene._teamNames.push_back(teamName);

            auto getRandomInt = [] (int min, int max) {
                static std::mt19937 rng{std::random_device{}()};
                std::uniform_int_distribution<int> dist(min, max);
                return dist(rng);
            };
            _scene._teamTextureIndex.push_back(getRandomInt(0, 7));
            
            auto it = std::find(_scene._teamNames.begin(), _scene._teamNames.end(), teamName);

            if (it != _scene._teamNames.end()) {
                int index = std::distance(_scene._teamNames.begin(), it);
                Player player(std::stoi(idStr), tileCenterX, tileCenterY, _scene._textureList[index]);
                player.setOrientation(orientation);
                player.setLevel(level);
                player.setTeamName(teamName);
                _scene._players.push_back(player);
            } else {
                Player player(std::stoi(idStr), tileCenterX, tileCenterY, _scene._textureList[0]);
                player.setOrientation(orientation);
                player.setLevel(level);
                player.setTeamName(teamName);
                _scene._players.push_back(player);
            }
        }
    }
}

/**
 * @brief Function that set the player position
 * 
 * @param str The string that contains the player position
 */
void Graphic::Commands::setPlayerPosition(const std::string str)
{
    std::istringstream stream(str);
    std::string command;
    std::string idStr;
    int x = 0;
    int y = 0;
    int orientation = 0;
    
    stream >> command >> idStr >> x >> y >> orientation;

    if (!_scene._mapTiles.empty() && !_scene._mapTiles[0].empty()) {
        int tileCenterX = _scene._mapTiles[y][x].getPosition().x + 64 - 22;
        int tileCenterY = _scene._mapTiles[y][x].getPosition().y - 40;

        for (auto& player : _scene._players) {
            if (player.getId() == std::stoi(idStr)) {
                player.setPosition(tileCenterX, tileCenterY);
                player.setOrientation(orientation);
                break;
            }
        }
    }
}

/**
 * @brief Function that set the player level
 * 
 * @param str The string that contains the player level
 */
void Graphic::Commands::setPlayerLevel(const std::string str)
{
    std::istringstream stream(str);
    std::string command;
    std::string idStr;
    int level = 0;

    stream >> command >> idStr >> level;

    for (auto& player : _scene._players) {
        if (player.getId() == std::stoi(idStr)) {
            player.setLevel(level);
            break;
        }
    }
}

/**
 * @brief Function that set the player inventory
 * 
 * @param str The string that contains the player inventory
 */
void Graphic::Commands::broadcast(const std::string str)
{
    std::cout << "broadcast" << std::endl;
    // todo
}

/**
 * @brief Function that set the player inventory
 * 
 * @param str The string that contains the player inventory
 */
void Graphic::Commands::setFreq(const std::string str)
{
    std::cout << "setFreq" << std::endl;

    std::istringstream stream(str);
    std::string command;
    int freq = 0;

    stream >> command >> freq;

    _scene._freq = freq;
}

/**
 * @brief Function that set the player inventory
 * 
 * @param str The string that contains the player inventory
 */
void Graphic::Commands::editFreq(const std::string str)
{
    std::cout << "editFreq" << std::endl;
    // todo
}

/**
 * @brief Function that set the player inventory
 * 
 * @param str The string that contains the player inventory
 */
void Graphic::Commands::setPlayerInventory(const std::string str)
{
    std::cout << "setPlayerInventory" << std::endl;
    // todo
}

/**
 * @brief Function that set the player inventory
 * 
 * @param str The string that contains the player inventory
 */
void Graphic::Commands::startIncantation(const std::string str)
{
    std::cout << "startIncantation" << std::endl;
    // todo
}

/**
 * @brief Function that set the player inventory
 * 
 * @param str The string that contains the player inventory
 */
void Graphic::Commands::endIncantation(const std::string str)
{
    std::cout << "endIncantation" << std::endl;
    // todo
}

/**
 * @brief Function that set the player inventory
 * 
 * @param str The string that contains the player inventory
 */
void Graphic::Commands::eggLaying(const std::string str)
{
    std::cout << "eggLaying" << std::endl;
    // todo
}

/**
 * @brief Function that set the player inventory
 * 
 * @param str The string that contains the player inventory
 */
void Graphic::Commands::eggLaid(const std::string str)
{
    
    std::istringstream stream(str);
    std::string command;
    std::string idStrEgg;
    std::string idStrPlayer;
    int x = 0;
    int y = 0;
    
    stream >> command >> idStrEgg >> idStrPlayer >> x >> y;

    if (!_scene._mapTiles.empty() && !_scene._mapTiles[0].empty()) {
        float tileCenterX = _scene._mapTiles[y][x].getPosition().x + 50;
        float tileCenterY = _scene._mapTiles[y][x].getPosition().y + 20;
        Egg egg(std::stoi(idStrEgg), std::stoi(idStrPlayer), sf::Vector2i(tileCenterX, tileCenterY));
        _scene._eggs.push_back(egg);
    }
}

/**
 * @brief Function that set the player inventory
 * 
 * @param str The string that contains the player inventory
 */
void Graphic::Commands::connectionByEgg(const std::string str)
{
    std::cout << "connectionByEgg" << std::endl;
    // todo
}

/**
 * @brief Function that set the player inventory
 * 
 * @param str The string that contains the player inventory
 */
void Graphic::Commands::playerDeath(const std::string str)
{
    std::istringstream stream(str);
    std::string command;
    std::string idStr;
    
    stream >> command >> idStr;

    auto it = std::remove_if(_scene._players.begin(), _scene._players.end(), [&idStr](const Player& player) {
        return player._id == std::stoi(idStr);
    });

    if (it != _scene._players.end()) {
        _scene._players.erase(it, _scene._players.end());
        std::cout << "Player (" << idStr << ") dead" << std::endl;
    } else {
        std::cout << "Player (" << idStr << ") not found" << std::endl;
    }
}

/**
 * @brief Function that set the player inventory
 * 
 * @param str The string that contains the player inventory
 */
void Graphic::Commands::eggDeath(const std::string str)
{
    std::istringstream stream(str);
    std::string command;
    std::string idStr;
    
    stream >> command >> idStr;

    auto it = std::remove_if(_scene._eggs.begin(), _scene._eggs.end(), [&idStr](const Egg& egg) {
        return egg._id == std::stoi(idStr);
    });

    if (it != _scene._eggs.end()) {
        _scene._eggs.erase(it, _scene._eggs.end());
        std::cout << "Egg (" << idStr << ") dead" << std::endl;
    } else {
        std::cout << "Egg (" << idStr << ") not found" << std::endl;
    }
}

/**
 * @brief Function that set the player inventory
 * 
 * @param str The string that contains the player inventory
 */
void Graphic::Commands::endGame(const std::string str)
{
    std::cout << "endGame" << std::endl;
    // todo
}

/**
 * @brief Function that set the player inventory
 * 
 * @param str The string that contains the player inventory
 */
void Graphic::Commands::resourceDropping(const std::string str)
{
    std::cout << "resourceDropping" << std::endl;
    // todo
}

/**
 * @brief Function that set the player inventory
 * 
 * @param str The string that contains the player inventory
 */
void Graphic::Commands::resourceCollecting(const std::string str)
{
    std::cout << "resourceCollecting" << std::endl;
    // todo
}

/**
 * @brief Function that set the player inventory
 * 
 * @param str The string that contains the player inventory
 */
void Graphic::Commands::messageFromServer(const std::string str)
{
    std::cout << "messageFromServer" << std::endl;
    // todo
}

/**
 * @brief Function that set the player inventory
 * 
 * @param str The string that contains the player inventory
 */
void Graphic::Commands::unknowCommand(const std::string str)
{
    std::cout << "unknowCommand" << std::endl;
    // todo
}

/**
 * @brief Function that set the player inventory
 * 
 * @param str The string that contains the player inventory
 */
void Graphic::Commands::commandParameter(const std::string str)
{
    std::cout << "commandParameter" << std::endl;
    // todo
}
