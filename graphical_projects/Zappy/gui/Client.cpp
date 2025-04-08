/*
** EPITECH PROJECT, 2024
** Appzy
** File description:
** Client
*/

/**
 * @file Client.cpp
 * @brief File containing functions that manages the client
 */

#include <iostream>
#include <unistd.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <cstring>
#include "include/Scene.hpp"
#include "include/Commands.hpp"
#include "include/Client.hpp"
#include <functional>
#include <sstream>

/**
 * @brief Function that receive command from the server
 * 
 * @return std::string 
 */
std::string Graphic::Client::readFirstCommandsExchanges()
{
    char buffer[1024];
    recv(_sock, buffer, 1024, 0);

    std::vector<std::string> messages;
    std::string tmpMessage = buffer;
    size_t pos = 0;
    size_t nextPos;

    while ((nextPos = tmpMessage.find('\n', pos)) != std::string::npos) {
        messages.push_back(tmpMessage.substr(pos, nextPos - pos + 1));
        pos = nextPos + 1;
    }
    return messages[0];
}

/**
 * @brief Function that read/send command from/to the server
 * 
 * @param gridWidth The grid width
 * @param gridHeight The grid height
 */
void Graphic::Client::firstCommandsExchanges(int& gridWidth, int& gridHeight)
{
    std::string message = readFirstCommandsExchanges();

    std::cout << "server said: " << message <<std::endl;
    std::string identifyingToServer = "GRAPHIC\n";
    sendCommand(identifyingToServer);

    message.clear();
    message = readFirstCommandsExchanges();
    std::cout << "server said: " << message << std::endl;

    message.clear();
    message = readFirstCommandsExchanges();
    std::cout << "server said: " << message << std::endl;

    std::istringstream stream(message);
    int width = 0;
    int height = 0;

    stream >> width >> height;
    gridWidth = width;
    gridHeight = height;
}

/**
 * @brief Function that connect the client to the server
 * 
 * @param port The port of the server
 * @param machine The ip adress of the server
 * @param gridWidth The grid width
 * @param gridHeight The grid height
 */
void Graphic::Client::connectionToServer(const char* port, const char* machine, int& gridWidth, int& gridHeight)
{
    struct sockaddr_in serv_addr;

    // socket creation
    if ((_sock = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
        std::cerr << "Error: Socket creation error" << std::endl;
        exit(84);
    }
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(atoi(port));

    // address convertion into binary
    if (inet_pton(AF_INET, machine, &serv_addr.sin_addr) <= 0) {
        std::cerr << "Error: Invalid address" << std::endl;
        exit(84);
    }

    // server connection
    if (connect(_sock, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0) {
        std::cerr << "Error: Connection Failed" << std::endl;
        exit(84);
    }
    firstCommandsExchanges(gridWidth, gridHeight);
}

/**
 * @brief Function that parse the command received from the server and call the associated function
 * 
 * @param message The message received from the server
 */
void Graphic::Client::callCorrespondingFunction(const std::string &message)
{
    std::unordered_map<std::string, std::function<void (const std::string&)>> func;

    func["msz"] = [this](const std::string& msg) { this->_commands.setMapSize(msg); };
    func["bct"] = [this](const std::string& msg) { this->_commands.setTileContent(msg); };
    func["tna"] = [this](const std::string& msg) { this->_commands.setTeamName(msg); };
    func["pnw"] = [this](const std::string& msg) { this->_commands.newPlayerConnection(msg); };
    func["ppo"] = [this](const std::string& msg) { this->_commands.setPlayerPosition(msg); };
    func["plv"] = [this](const std::string& msg) { this->_commands.setPlayerLevel(msg); };
    func["pbc"] = [this](const std::string& msg) { this->_commands.broadcast(msg); };
    func["sgt"] = [this](const std::string& msg) { this->_commands.setFreq(msg); };
    func["sst"] = [this](const std::string& msg) { this->_commands.editFreq(msg); };
    func["pin"] = [this](const std::string& msg) { this->_commands.setPlayerInventory(msg); };
    func["pic"] = [this](const std::string& msg) { this->_commands.startIncantation(msg); };
    func["pie"] = [this](const std::string& msg) { this->_commands.endIncantation(msg); };
    func["pfk"] = [this](const std::string& msg) { this->_commands.eggLaying(msg); };
    func["enw"] = [this](const std::string& msg) { this->_commands.eggLaid(msg); };
    func["ebo"] = [this](const std::string& msg) { this->_commands.connectionByEgg(msg); };
    func["pdi"] = [this](const std::string& msg) { this->_commands.playerDeath(msg); };
    func["edi"] = [this](const std::string& msg) { this->_commands.eggDeath(msg); };
    func["seg"] = [this](const std::string& msg) { this->_commands.endGame(msg); };
    func["pdr"] = [this](const std::string& msg) { this->_commands.resourceDropping(msg); };
    func["pgt"] = [this](const std::string& msg) { this->_commands.resourceCollecting(msg); };
    func["smg"] = [this](const std::string& msg) { this->_commands.messageFromServer(msg); };
    func["suc"] = [this](const std::string& msg) { this->_commands.unknowCommand(msg); };
    func["sbb"] = [this](const std::string& msg) { this->_commands.commandParameter(msg); };

    std::istringstream iss(message);
    std::string key;
    iss >> key;

    auto it = func.find(key);
    if (it != func.end())
        it->second(message);
    else
        std::cerr << "Unknow command: " << message << std::endl;
}

/**
 * @brief Function that parse the received messages from the server
 * 
 * @param buffer The buffer containing the messages
 * @return std::vector<std::string> 
 */
std::vector<std::string> Graphic::Client::parseReceivedMessages(const std::string& buffer)
{
    std::vector<std::string> messages;
    std::string tmpMessage = _incompleteMessage + buffer;
    size_t pos = 0;
    size_t nextPos;

    while ((nextPos = tmpMessage.find('\n', pos)) != std::string::npos) {
        messages.push_back(tmpMessage.substr(pos, nextPos - pos + 1));
        pos = nextPos + 1;
    }
    _incompleteMessage.clear();
    _incompleteMessage = tmpMessage.substr(pos);
    return messages;
}

/**
 * @brief Function that receive messages from the server
 * 
 */
void Graphic::Client::receiveMessages()
{
    char buffer[1024];
    fd_set readfds;
    int max_sd;
    int activity;
    struct timeval timeOut;
    int serverSocket = _sock;

    FD_ZERO(&readfds);
    FD_SET(serverSocket, &readfds);
    max_sd = serverSocket;

    timeOut.tv_sec = 0;
    timeOut.tv_usec = 0;

    if (select(max_sd + 1, &readfds, NULL, NULL, &timeOut) > 0) {
        if (FD_ISSET(serverSocket, &readfds)) {
            memset(buffer, 0, sizeof(buffer));
            int bytesRead = read(serverSocket, buffer, sizeof(buffer));
            if (bytesRead > 0) {
                std::string receivedMessage(buffer, bytesRead);
                std::vector<std::string> messages = parseReceivedMessages(receivedMessage);

                for (const std::string& msg : messages) {
                    std::cout<<"Received - "<<msg<<std::endl;
                    callCorrespondingFunction(msg);
                }
            }
        }
    }
}
