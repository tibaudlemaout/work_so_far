/*
** EPITECH PROJECT, 2024
** Appzy
** File description:
** AiPlayer
*/

/**
 * @file AiPlayer.cpp
 * @brief Source file for AiPlayer.
 * In this file, we have all functions about the player
 * 
*/

#include <iostream>
#include <unistd.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <string.h>
#include <cmath>
#include <sys/wait.h>
#include "AiPlayer.hpp"
#include "Encryption.hpp"

std::map<pid_t, AI::AiPlayer*> AI::AiPlayer::_instances;

void AI::AiPlayer::handle_sigint(int sig) {
    pid_t pid = getpid();
    if (_instances.count(pid) > 0) {
        AiPlayer* instance = _instances[pid];
        for (pid_t child : instance->_children) {
            kill(child, SIGTERM);
            int status;
            waitpid(child, &status, 0);
        }
    }
    exit(0);
}

/**
 * @brief Construct a new AI::AiPlayer::AiPlayer object
 * 
 * @param children  The list of children of the player
 * @param port  The port of the server
 * @param ip  The ip of the server
 * @param teamName  The name of the team
 */
AI::AiPlayer::AiPlayer(std::vector<pid_t> &children, int port, const char *ip, std::string teamName)
    : _port{port}, _ip{ip}, _teamName{teamName}, _children{children}, _waiting{0}
{
    _instances[getpid()] = this;
    _lvlUpCount = 0;
    pid_t pid = fork();
    if (pid != 0) {
        children.push_back(pid);
        _id = -1;
        signal(SIGINT, handle_sigint);
    } else {
        _priorities = AI::AiPriorities();
        _thread = new pthread_t;
        _id = rand() % 100000;
        _goingToLevelUp = false;
        start();
    }
}

/**
 * @brief Destroy the AI::AiPlayer::AiPlayer object
 */
AI::AiPlayer::~AiPlayer()
{
    close(_sockfd);
}

/**
 * @brief The function that cleans a string
 * 
 * @param dest The string to clean
 * @param size The size of the string
 */
static void cleanString(char *dest, int size)
{
    for (int i = 0; i < size; i++) {
        dest[i] = '\0';
    }
}

/**
 * @brief The function that waits for the server to send a message
 * 
 * @return void* 
 */
void AI::AiPlayer::waitForServer()
{
    char buffer[1024] = {0};
    ssize_t bytes_read = 0;

    while (1) {
        select(FD_SETSIZE, &_readfds, NULL, NULL, NULL);
        bytes_read = read(_sockfd, buffer, 1024);
        if (bytes_read == 0) {
            std::cout << "Server disconnected" << std::endl;
            handle_sigint(0);
        }
        char *commands = strtok(buffer, "\n");
        while (commands != NULL) {
            analyseCommand(commands, strlen(commands));
            commands = strtok(NULL, "\n");
        }
        cleanString(buffer, 1024);
    }
}

/**
 * @brief The function that create a player thread
 * 
 * @param params The parameters of the thread
 * @return void* 
 */
static void *threadFunction(void *params)
{
    AI::AiPlayer *player = static_cast<AI::AiPlayer *>(params);
    player->waitForServer();
    return NULL;
}

/**
 * @brief The function that creates the thread
 */
void AI::AiPlayer::createThread()
{
    pthread_create(_thread, NULL, threadFunction, this);
}

void AI::AiPlayer::action()
{
    if (_lastCommand.checkIncantation(_lastCommand.getInventory(), _lastCommand.getLevel()) == 1) {
        _lastCommand.dropLevelUpItems(_sockfd, _lastCommand.getLevel());
        _lastCommand.Incantation(_sockfd);
        return;
    } else if (_lastCommand.checkIncantation(_lastCommand.getInventory(), _lastCommand.getLevel()) != 0 && _goingToLevelUp == false) {
        _priorities.setPriority(AI::Priorities::LEVEL_UP, 10);
    }
    switch (_priorities.getPriority(0))
    {
    case AI::Priorities::FOOD:
        if (_lastCommand.getLooked().getNearest(AI::LookedType::FOOD_LOOKED) == -1) {
            sendMessage(HUNGRY);
            moveToPosition(2);
            _lastCommand.LookAround(_sockfd);
        } else {
            moveToPosition(_lastCommand.getLooked().getNearest(AI::LookedType::FOOD_LOOKED));
            _lastCommand.TakeObject(_sockfd, "food");
            _lastCommand.LookAround(_sockfd);
        }
        break;
    case AI::Priorities::GO_TO:
        sendMessage(TIK);
        _lastCommand.MoveForward(_sockfd);
        break;
    case AI::Priorities::LEVEL_UP:
        if (_lvlUpCount == 0 && _goingToLevelUp == false) {
            _lvlUpCount = 1;
            sendMessage(AI::message_type::LVL_UP);
        }
        break;
    case AI::Priorities::EXTERMINATE:
        if (_lastCommand.getLooked().getNearest(AI::LookedType::EGG_SEEN) != -1) {
            moveToPosition(_lastCommand.getLooked().getNearest(AI::LookedType::EGG_SEEN));
            _lastCommand.LookAround(_sockfd);
        }
        break;
    case AI::Priorities::IDLE:
        _lastCommand.Fork(_sockfd);
        _waiting = 20;
        if (_lastCommand.canFork()) {
            AI::AiPlayer *newPlayer = new AI::AiPlayer(_children, _port, _ip, _teamName);
            _lastCommand.setCanFork(false);
        }
            _lastCommand.TakeObject(_sockfd, "food");
        break;
    case AI::Priorities::STONES:
        _lastCommand.TakeObject(_sockfd, "food");
        _lastCommand.TakeObject(_sockfd, "linemate");
        _lastCommand.TakeObject(_sockfd, "deraumere");
        _lastCommand.TakeObject(_sockfd, "sibur");
        _lastCommand.TakeObject(_sockfd, "mendiane");
        _lastCommand.TakeObject(_sockfd, "phiras");
        _lastCommand.TakeObject(_sockfd, "thystame");
        if (_lastCommand.getLooked().getNearest(AI::LookedType::LINEMATE) != -1) {
            moveToPosition(_lastCommand.getLooked().getNearest(AI::LookedType::LINEMATE));
            _lastCommand.LookAround(_sockfd);
        } else {
            moveToPosition(2);
            _lastCommand.LookAround(_sockfd);
        }
        break;
    default:
        break;
    }
}

/**
 * @brief The function that starts the player
 * This function is the main function of the player that containt the logic of the player
 */
void AI::AiPlayer::start()
{
    int sockfd = socket(AF_INET, SOCK_STREAM, 0);
    int spaces = 0;
    struct sockaddr_in serv_addr;
    fd_set readfds;
    char buffer[1024] = {0};

    FD_ZERO(&readfds);
    FD_SET(sockfd, &readfds);
    if (!FD_ISSET(sockfd, &readfds)) {
        std::cerr << "ERROR select" << std::endl;
    }
    if (sockfd < 0)
        std::cerr << "ERROR opening socket" << std::endl;
    memset(&serv_addr, 0, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(_port);
    if (inet_pton(AF_INET, _ip, &serv_addr.sin_addr) <= 0)
        std::cerr << "ERROR invalid address" << std::endl;
    if (connect(sockfd, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0)
        std::cerr << "ERROR connecting" << std::endl;
    _sockfd = sockfd;
    select(FD_SETSIZE, &readfds, NULL, NULL, NULL);
    read(sockfd, buffer, 1024);
    _teamName += "\n";
    if (write(sockfd, _teamName.c_str(), _teamName.size()) < 0) {
        std::cerr << "ERROR sending team name" << std::endl;
        return;
    }
    select(FD_SETSIZE, &readfds, NULL, NULL, NULL);
    read(sockfd, buffer, 1024);
    if (strchr(buffer, '\n') == NULL) {
        select(FD_SETSIZE, &readfds, NULL, NULL, NULL);
        read(sockfd, buffer, 1024);
    }
    spaces = strtod(buffer, NULL);
    if (spaces > 0) {
        AI::AiPlayer *newPlayer = new AI::AiPlayer(_children, _port, _ip, _teamName);
    }
    _readfds = readfds;
    sendMessage(BORN);
    createThread();
    _lastCommand.LookAround(_sockfd);
    while(1) {
        _lastCommand.updateSendQueue(_sockfd);
        if (_lastCommand.isCommandWaiting()) {
            continue;
        }
        _priorities.setPriority(FOOD, 10 - getFood());
        _priorities.setPriority(STONES, (_lastCommand.getMissingItems(_lastCommand.getInventory(), _lastCommand.getLevel()) / 2) + 1);
        if (_priorities.getPriority(0) != AI::Priorities::GO_TO) {
            _lastCommand.Inventory(_sockfd);
        }
        if (_waiting > 0) {
            _waiting--;
            continue;
        }
        action();
    }
}

/**
 * @brief This function analyzes the command received from the server
 * 
 * @param line The command received from the server
 * @param bytes_read The number of bytes read
 */
void AI::AiPlayer::analyseCommand(char *line, ssize_t bytes_read)
{
    if (bytes_read == 0) {
        return;
    }
    line[bytes_read] = '\0';
    if (bytes_read == 4 && strncmp(line, "dead", 4) == 0) {
        exit(0);
    }
    if (strncmp(line, "ok", 2) == 0 || strncmp(line, "ko", 2) == 0 || line[0] == '['|| strncmp(line, "Current level: ", 14) == 0 || strcmp(line, "Elevation underway") == 0) {
        _lastCommand.checkReturn(line);
    } else if (strncmp(line, "message ", 8) == 0) {
        _orientation = std::stoi(line + 8);
        std::string message = line;
        message = message.substr(message.find(" ") + 1);
        message = message.substr(message.find(" ") + 1);
        message = decrypt(message);
        getMessage(message);
    }
}

/**
 * @brief Get the Id of the child
 * 
 * @return int 
 */
int AI::AiPlayer::getChildId()
{
    if (_children.size() == 0)
        return -1;
    return _children.front();
}

/**
 * @brief Pop the first child id
 * 
 */
void AI::AiPlayer::popChildId()
{
    _children.erase(_children.begin());
}


/**
 * @brief Send a message to the other players
 * -id: The id of the player
 * -l: The level of the player
 * -q: The quantity of food
 * -s: The id of the player that the player is searching
 * 
 * @param type The type of the message
 * 
*/
void AI::AiPlayer::sendMessage(message_type type)
{
    std::string message = "";
    
    switch (type)
    {
        case HUNGRY:
            message = "hungry -id " + std::to_string(_id) + "\n";
            break;
        case HAS_FOOD:
            message = "food -id " + std::to_string(_id) + " -q " + std::to_string(getFood()) + "\n";
            break;
        case FOOD_OK:
            message = "food_ok -s " + std::to_string(_searchingId) + " -id " + std::to_string(_id) + "\n";
            break;
        case LVL_UP:
            message = "lvl_up -id " + std::to_string(_id) + " -l " + std::to_string(_lastCommand.getLevel()) + "\n";
            _waiting = 20;
            break;
        case LVL_UP_CHECK:
            message = "check -id " + std::to_string(_id) + " -s " + std::to_string(_searchingId) + "\n";
            _goingToLevelUp = true;
            break;
        case LVL_UP_OK:
            message = "lvl_up_ok -id " + std::to_string(_id) + "\n";
            break;
        case LVL_UP_KO:
            message = "lvl_up_ko -id " + std::to_string(_id) + "\n";
            _lvlUpCount = 0;
            _waiting = 20;
            _priorities.setPriority(AI::Priorities::LEVEL_UP, 0);
            break;
        case TIK:
            message = "tik -id " + std::to_string(_id) + " -s " + std::to_string(_searchingId) + "\n";
            break;
        case TOK:
            message = "tok -id " + std::to_string(_id) + " -l " +
                std::to_string(_lastCommand.getLevel()) + "\n";
            break;
        case BORN:
            message = "born -id " + std::to_string(_id) + "\n";
            break;
        case NO_EGG:
            message = "extermination\n";
            break;
        case NO_EGG_END:
            message = "stop_extermination\n";
            break;
        default:
            break;
    }
    _lastCommand.Broadcast(_sockfd, encrypt(message));
}

/**
 * @brief The function that gets the message from the server
 * 
 * @param words The words list of the message
 */
void AI::AiPlayer::getMessage2(std::vector<std::string> words)
{
    if (words[0] == "lvl_up_ok") {
        if (words[2] == std::to_string(_searchingId)) {
            _priorities.setPriority(AI::Priorities::LEVEL_UP, 9);
            _lvlUpCount = 0;
            _priorities.setPriority(AI::Priorities::GO_TO, 10);
        }
    }
    if (words[0] == "tik") {
        if (words[3] == "-s" && words[4] == std::to_string(_id)){
            sendMessage(TOK);
            if (_priorities.getPriority(0) == AI::Priorities::LEVEL_UP && _orientation == 0) {
                _lvlUpCount--;
                if (_lvlUpCount == 1) {
                    _lastCommand.Incantation(_sockfd);
                }
            }
        }
    }
    if (words[0] == "tok") {
        if (words[1] == "-id" && words[2] == std::to_string(_searchingId)) {
            if (_lastCommand.isCommandWaiting()) {
                return;
            }
            if (_orientation == 0) {
                _priorities.setPriority(AI::Priorities::GO_TO, 0);
                if (_priorities.getPriority(0) == AI::Priorities::LEVEL_UP) {
                    _priorities.setPriority(AI::Priorities::LEVEL_UP, 0);
                    _priorities.setPriority(AI::Priorities::IDLE, 10);
                }
                return;
            } else if (_orientation == 3 || _orientation == 4) {
                _lastCommand.MoveLeft(_sockfd);
            } else if (_orientation == 5) {
                _lastCommand.MoveRight(_sockfd);
                _lastCommand.MoveRight(_sockfd);
            } else if (_orientation == 6 || _orientation == 7) {
                _lastCommand.MoveRight(_sockfd);
            }
        }
    }
    if (words[0] == "extermination") {
        _priorities.addPriority(AI::Priorities::EXTERMINATE, 5);
    }
    if (words[0] == "stop_extermination") {
        _priorities.addPriority(AI::Priorities::EXTERMINATE, -5);
    }
    if (words[0] == "lvl_up_ko") {
        if (words[2] == std::to_string(_searchingId)) {
            _lvlUpCount = 0;
            _priorities.setPriority(AI::Priorities::LEVEL_UP, 0);
            _priorities.setPriority(AI::Priorities::IDLE, 0);
            _goingToLevelUp = false;
        }
    }
}

/**
 * @brief The function that gets the message from the server and parse it before sending it to getMessage2
 * 
 * @param message The words list of the message
 */
void AI::AiPlayer::getMessage(std::string message)
{
    std::vector<std::string> words;

    message = message.substr(0, message.find("\n"));
    while (message.find(" ") != std::string::npos) {
        words.push_back(message.substr(0, message.find(" ")));
        message = message.substr(message.find(" ") + 1);
    }
    words.push_back(message);
    if (words[0] == "hungry") {
        if (words[1] == "-id") {
            if (getFood() > 10) {
                sendMessage(HAS_FOOD);
            }
        }
    }
    if (words[0] == "food"){
        if (words[1] == "-id") {
            _searchingId = std::stoi(words[2]);
            _priorities.addPriority(AI::Priorities::GO_TO, 5);
            sendMessage(FOOD_OK);
        }
    }
    if (words[0] == "food_ok") {
        if (words[3] == "-s" && words[4] == std::to_string(_id)) {
            _searchingId = std::stoi(words[2]);
            _priorities.addPriority(AI::Priorities::GO_TO, 5);
        }
    }
    if (words[0] == "lvl_up") {
        if (words[3] == "-l" && words[4] == std::to_string(_lastCommand.getLevel()) && _priorities.getPriority(0) != AI::Priorities::FOOD && 
            _priorities.getPriority(0) != AI::Priorities::GO_TO) {
            _searchingId = std::stoi(words[2]);
            sendMessage(LVL_UP_CHECK);
        }
    }
    if (words[0] == "check" && words[3] == "-s" && words[4] == std::to_string(_id)) {
            _lvlUpCount++;
            if (_lvlUpCount == _lastCommand.checkIncantation(_lastCommand.getInventory(), _lastCommand.getLevel()) && _lvlUpCount != 0) {
                sendMessage(LVL_UP_OK);
            } else if (_waiting == 0) {
                sendMessage(LVL_UP_KO);
            } 
    }
    getMessage2(words);
}


int AI::AiPlayer::getFood()
{
    return _lastCommand.getInventory().getFood();
}

/**
 * @brief This function moves the player to a specific position
 * 
 * @param pos The position to move to
 */
void AI::AiPlayer::moveToPosition(int pos)
{
    double squareRoot = std::sqrt(pos);
    int roundedDown = static_cast<int>(std::floor(squareRoot));

    if (pos == 0) {
        return;
    }
    for (int i = 0; i < roundedDown; i++) {
        _lastCommand.MoveForward(_sockfd);
    }
    int last_square = roundedDown * roundedDown;
    int next_square = (roundedDown + 1) * (roundedDown + 1);
    int dif_square = next_square - last_square - 1;
    int dif = pos - last_square;
    int abs = 0;
    if (dif == dif_square / 2)
        return;
    if (dif < dif_square / 2) {
        _lastCommand.MoveLeft(_sockfd);
        for (int i = 0; i < dif - (dif_square / 2); i++) {
            _lastCommand.MoveForward(_sockfd);
        }
        abs = (dif_square / 2) - dif;
    } else {
        _lastCommand.MoveRight(_sockfd);
        for (int i = dif; i < dif_square / 2; i++) {
            _lastCommand.MoveForward(_sockfd);
        }
        abs = dif - (dif_square / 2);
    }
    for (int i = 0; i < abs; i++) {
        _lastCommand.MoveForward(_sockfd);
    }
}
