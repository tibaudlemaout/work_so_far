/*
** EPITECH PROJECT, 2024
** Appzy
** File description:
** AiCommand
*/

/**
 * @file AiCommand.cpp
 * @brief Source file for AiCommand.
 * In this file, we have all functions about Commands that the AI can send to the server
 * We also have response parsing functions
 * 
*/

#include "AiCommand.hpp"
#include <string.h>

AI::AiCommand::AiCommand()
{
    _canFork = false;
    _level = 1;
}

AI::AiCommand::~AiCommand()
{
}


/**
 * @brief The function parses the inventory string received from the server
 * and stores the values in the AiInventory object
 * 
 * @param str The inventory string to parse
 */
void AI::AiCommand::parseInventoryString(const std::string& str)
{
    std::map<std::string, int> values;

    std::string cleaned = str.substr(1, str.size() - 2);

    std::stringstream ss(cleaned);
    std::string pair;
    while (std::getline(ss, pair, ',')) {
        std::stringstream pairStream(pair);
        pairStream >> std::ws;

        std::string name;
        std::getline(pairStream, name, ' ');

        std::string valueStr;
        pairStream >> valueStr;

        int value = std::stoi(valueStr);
        values[name] = value;
    }

    AI::AiInventory inventory(
        values["food"],
        values["linemate"],
        values["deraumere"],
        values["sibur"],
        values["mendiane"],
        values["phiras"],
        values["thystame"]);
    
    _inventory = inventory;
}


/**
 * @brief This function parses ressources on the tile and stores them in the AiLooked object
 * 
 * @param str The string to parse that represents tiles
 */
void AI::AiCommand::parseStringToTiles(const std::string& str)
{
    AiLooked tiles;

    std::string cleaned = str.substr(1, str.size() - 2);

    std::stringstream ss(cleaned);
    std::string element;
    while (std::getline(ss, element, ',')) {
        element.erase(0, element.find_first_not_of(' '));
        element.erase(element.find_last_not_of(' ') + 1);
        AI::AiTile tile;
        if (!element.empty()) {
            std::stringstream ess(element);
            std::string resource;
            while (ess >> resource) {
                if (resource == "food") {
                    tile.setFood(tile.getFood() + 1);
                } else if (resource == "linemate") {
                    tile.setLinemate(tile.getLinemate() + 1);
                } else if (resource == "deraumere") {
                    tile.setDeraumere(tile.getDeraumere() + 1);
                } else if (resource == "sibur") {
                    tile.setSibur(tile.getSibur() + 1);
                } else if (resource == "mendiane") {
                    tile.setMendiane(tile.getMendiane() + 1);
                } else if (resource == "phiras") {
                    tile.setPhiras(tile.getPhiras() + 1);
                } else if (resource == "thystame") {
                    tile.setThystame(tile.getThystame() + 1);
                } else if (resource == "player") {
                    tile.setPlayers(tile.getPlayers() + 1);
                } else if (resource == "egg") {
                    tile.setEggs(tile.getEggs() + 1);
                }
            }
        }
        tiles.push_back(tile);
    }
    _looked = tiles;
}

/**
 * @brief This function checks the return message from the server
 * and analyzes to send in the correct parsing function
 * After parsing, the command is removed from the queue
 * 
 * @param message The message to check received from the server
 */
void AI::AiCommand::checkReturn(char *message)
{
    std::string command = _commandsQueue.front();

    if (strcmp(message, "Elevation underway") == 0) {
        if (_commandsQueue.empty() || _commandsQueue.back() != "Incantation\n") {
            _commandsQueue.push_back("Incantation\n");
            return;
        }
        return;
    }
    if (!_commandsQueue.empty()) {
        std::string command = _commandsQueue.front();
        
        if (command == "Look\n") {
            parseStringToTiles(message);
        } else if (command == "Inventory\n") {
            try {
            parseInventoryString(message);
            }
            catch(const std::exception& e)
            {
                std::cerr << e.what() << '\n';
                return;
            }
        } else if (command == "Connect_nbr\n") {
            _connectedPlayers = std::stol(message);
        } else if (command == "Fork\n") {
            _canFork = true;
        }
        if (strncmp(message, "Current level: ", 15) == 0) {
            _level = std::stoi(message + 15);
        }
        _commandsQueue.pop_front();
    }
}

/**
 * @brief This function sends a message to the server
 * 
 * @param sockfd The socket file descriptor
 * @param message The message to send
*/

void static sendMessage(int sockfd, std::string message)
{
    try
    {
        if (send(sockfd, message.c_str(), message.size(), 0) < 0) {
            std::cerr << "ERROR sending message: " << message;
            return;
        }
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
}

/**
 * @brief This function add commands to the history queue
 * 
 * @param sockfd The socket file descriptor
 * @param message The command to add to the history queue
 */
void AI::AiCommand::addHistoryMessage(int sockfd, std::string message)
{
    if (_waitingQueue.size() != 0) {
        while (_commandsQueue.size() < MAX_HISTORY_SIZE && _waitingQueue.size() != 0) {
            _commandsQueue.push_back(_waitingQueue.front());
            sendMessage(sockfd, _commandsQueue.back());
            _waitingQueue.pop_front();
        }
    }
    if (_commandsQueue.size() < MAX_HISTORY_SIZE) {
        _commandsQueue.push_back(message);
        sendMessage(sockfd, _commandsQueue.back());
    } else {
        _waitingQueue.push_back(message);
    }
}

/**
 * @brief This function updates the send queue, 
 * if there are commands in the waiting queue and the history queue is not full
 * 
 * @param sockfd The socket file descriptor
 */
void AI::AiCommand::updateSendQueue(int sockfd)
{
    if (_waitingQueue.size() != 0) {
        while (_commandsQueue.size() < MAX_HISTORY_SIZE && _waitingQueue.size() != 0) {
            _commandsQueue.push_back(_waitingQueue.front());
            sendMessage(sockfd, _commandsQueue.front());
            _waitingQueue.pop_front();
        }
    }
}

/**
 * @brief Move the player forward.
 * 
 * @param sockfd The socket file descriptor
*/
void AI::AiCommand::MoveForward(int sockfd)
{
    std::string message = "Forward\n";

    addHistoryMessage(sockfd, message);
}

/**
 * @brief Turn the player right
 * 
 * @param sockfd The socket file descriptor
*/
void AI::AiCommand::MoveRight(int sockfd)
{
    std::string message = "Right\n";

    addHistoryMessage(sockfd, message);
}

/**
 * @brief Turn the player left
 * 
 * @param sockfd The socket file descriptor
*/
void AI::AiCommand::MoveLeft(int sockfd)
{
    std::string message = "Left\n";

    addHistoryMessage(sockfd, message);
}

/**
 * @brief Look around the player
 * 
 * @param sockfd The socket file descriptor
*/
void AI::AiCommand::LookAround(int sockfd)
{
    std::string message = "Look\n";

    addHistoryMessage(sockfd, message);
}

/**
 * @brief Get the player inventory
 * 
 * @param sockfd The socket file descriptor
*/
void AI::AiCommand::Inventory(int sockfd)
{
    std::string message = "Inventory\n";

    addHistoryMessage(sockfd, message);
}

/**
 * @brief Broadcast a message to all players
 * 
 * @param sockfd The socket file descriptor
 * @param message Message to broadcast
*/
void AI::AiCommand::Broadcast(int sockfd, std::string message)
{
    std::string messageToSend = "Broadcast " + message + "\n";

    addHistoryMessage(sockfd, messageToSend);
}

/**
 * @brief Ask the number of team unused slots
 * 
 * @param sockfd The socket file descriptor
*/
void AI::AiCommand::ConnectNbr(int sockfd)
{
    std::string message = "Connect_nbr\n";

    addHistoryMessage(sockfd, message);
}

/**
 * @brief Fork a player
 * 
 * @param sockfd The socket file descriptor
*/
void AI::AiCommand::Fork(int sockfd)
{
    std::string message = "Fork\n";

    addHistoryMessage(sockfd, message);
}

/**
 * @brief Eject a player from the tile
 * 
 * @param sockfd The socket file descriptor
*/
void AI::AiCommand::Eject(int sockfd)
{
    std::string message = "Eject\n";

    addHistoryMessage(sockfd, message);
}

/**
 * @brief Take an object from the tile
 * 
 * @param sockfd The socket file descriptor
 * @param object Object to take
*/
void AI::AiCommand::TakeObject(int sockfd, std::string object)
{
    std::string message = "Take " + object + "\n";

    addHistoryMessage(sockfd, message);
}

/**
 * @brief Set an object on the tile
 * 
 * @param sockfd The socket file descriptor
 * @param object Object to set
*/
void AI::AiCommand::SetObject(int sockfd, std::string object)
{
    std::string message = "Set " + object + "\n";

    addHistoryMessage(sockfd, message);
}

/**
 * @brief Start the incantation
 * 
 * @param sockfd The socket file descriptor
*/
void AI::AiCommand::Incantation(int sockfd)
{
    std::string message = "Incantation\n";

    addHistoryMessage(sockfd, message);
}

/**
 * @brief check if the player can level up
 * 
 * @param inventory Player inventory
 * @param level Player level
 * 
 * @return the number of players needed to level up. 0 if the player can't level up
 */
int AI::AiCommand::checkIncantation(AI::AiInventory inventory, int level)
{
    if (inventory.getLinemate() >= linemate_tab[level - 1] &&
        inventory.getDeraumere() >= deraumere_tab[level - 1] &&
        inventory.getSibur() >= sibur_tab[level - 1] &&
        inventory.getMendiane() >= mendiane_tab[level - 1] &&
        inventory.getPhiras() >= phiras_tab[level - 1] &&
        inventory.getThystame() >= thystame_tab[level - 1] &&
        inventory.getFood() >= 7) {
        return player_tab[level - 1];
    } else {
        return 0;
    }
}

/**
 * @brief Drop the items needed to level up
 * 
 * @param level Player level
 */
void AI::AiCommand::dropLevelUpItems(int sockfd, int level)
{
    for (int i = 0; i < linemate_tab[level - 1]; i++)
        SetObject(sockfd, "linemate");
    for (int i = 0; i < deraumere_tab[level - 1]; i++)
        SetObject(sockfd, "deraumere");
    for (int i = 0; i < sibur_tab[level - 1]; i++)
        SetObject(sockfd, "sibur");
    for (int i = 0; i < mendiane_tab[level - 1]; i++)
        SetObject(sockfd, "mendiane");
    for (int i = 0; i < phiras_tab[level - 1]; i++)
        SetObject(sockfd, "phiras");
    for (int i = 0; i < thystame_tab[level - 1]; i++)
        SetObject(sockfd, "thystame");
}

/**
 * @brief Get the number of missing items to level up
 * 
 * @param inventory Player inventory
 * @param level Player level
 * 
 * @return the number of missing items
 */
int AI::AiCommand::getMissingItems(AI::AiInventory inventory, int level)
{
    int missing = 0;

    if (inventory.getLinemate() < linemate_tab[level - 1])
        missing += std::max(0, linemate_tab[level - 1] - inventory.getLinemate());
    if (inventory.getDeraumere() < deraumere_tab[level - 1])
        missing += std::max(0, deraumere_tab[level - 1] - inventory.getDeraumere());
    if (inventory.getSibur() < sibur_tab[level - 1])
        missing += std::max(0, sibur_tab[level - 1] - inventory.getSibur());
    if (inventory.getMendiane() < mendiane_tab[level - 1])
        missing += std::max(0, mendiane_tab[level - 1] - inventory.getMendiane());
    if (inventory.getPhiras() < phiras_tab[level - 1])
        missing += std::max(0, phiras_tab[level - 1] - inventory.getPhiras());
    if (inventory.getThystame() < thystame_tab[level - 1])
        missing += std::max(0, thystame_tab[level - 1] - inventory.getThystame());
    return missing;
}