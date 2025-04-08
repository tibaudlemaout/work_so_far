/*
** EPITECH PROJECT, 2024
** Gomoku
** File description:
** CommandProcessor.cpp
*/

#include "../include/CommandProcessor.hpp"
#include <iostream>
#include <stdexcept>
#include <cstdio>

// --- PUBLIC --- //

CommandProcessor::CommandProcessor() : game() {
    command_map_ = {
        {"START", [this](std::istringstream& iss) { 
            int size; 
            if (!(iss >> size)) {
                std::cout << "ERROR Invalid size for START command." << std::endl;
                return;
            }
            handleStart(size);
        }},
        {"TURN", [this](std::istringstream& iss) { 
            int x, y; 
            char comma; 
            if (!(iss >> x >> comma >> y) || comma != ',') {
                std::cout << "ERROR Invalid coordinates format for TURN command." << std::endl;
                return;
            }
            handleTurn(x, y);
        }},
        {"BEGIN", [this](std::istringstream& iss) {
            handleBegin();
        }},
        {"END", [this](std::istringstream& iss) {
            handleEnd();
        }},
        {"ABOUT", [this](std::istringstream& iss) {
            handleAbout();
        }}
    };

    inBoardCommand = false;

    game.about_values.name = "Brainstorminator";
    game.about_values.version = "1.0";
    game.about_values.author = "Tib-&-Toma";
    game.about_values.country = "France";
}

void CommandProcessor::listener() {
    bool running = true;
    std::string command;

    while (running && std::getline(std::cin, command)) {
        processCommand(command);
    }
}

void CommandProcessor::sender() {
    while (true) {
        std::unique_lock<std::mutex> lock(game._queueMutex);
        game._queueCondVar.wait(lock, [this] { return !game._messageQueue.empty(); });

        while (!game._messageQueue.empty()) {
            std::string message = game._messageQueue.front();
            game._messageQueue.pop();
            std::cout << message << std::endl;
        }
    }
}

void CommandProcessor::processCommand(const std::string& input) {
    std::istringstream iss(input);
    std::string cmd;
    iss >> cmd;

    if (cmd == "INFO") {
        std::string remaining;
        std::getline(iss, remaining);
        remaining.erase(0, 1);
        handleInfo(remaining);
        return;
    }

    if (inBoardCommand) {
        handleBoard(input);
    } else if (cmd == "BOARD") {
        inBoardCommand = true;

    } else {
        auto it = command_map_.find(cmd);
        if (it != command_map_.end()) {
            it->second(iss);
        } else {
            std::cout << "UNKNOWN" << std::endl;
        }
    }
}

// --- PRIVATE --- //

void CommandProcessor::handleStart(int size) {
    if (size < 5) {
        std::cout << "ERROR Size must be greater or equal to 5 in START command" << std::endl;
        return;
    }
    game.init(size);
    std::cout << "OK" << std::endl;
}

void CommandProcessor::handleTurn(int x, int y) {
    if (x < 0 || y < 0) {
        std::cout << "ERROR Coordinates must be non-negative in TURN command" << std::endl;
        return;
    }
    game.updateEnemyTurn(x, y);
    game.play();
}

void CommandProcessor::handleBoard(const std::string& command) {
    std::istringstream iss(command);
    std::string line;
    std::getline(iss, line); 

    if (line == "DONE") {
        inBoardCommand = false;
        game.play();
        return;
    }

    int x, y, player;
    char comma;
    std::istringstream moveStream(line);
    
    if (moveStream >> x >> comma >> y >> comma >> player)
        game.insertBoardMove(x, y, player);
    else
        std::cout << "ERROR Invalid move format. Expected 'x,y,player'." << std::endl;
}

void CommandProcessor::handleBegin() {
    game.play();
}

void CommandProcessor::handleEnd() {
    exit(0);
}

void CommandProcessor::handleInfo(const std::string& input) {
    std::istringstream iss(input);
    std::string key;
    iss >> key;

    std::string value;
    std::getline(iss, value);
    value.erase(0, 1);

    if (key == "timeout_turn") {
        game.infos.timeout_turn = std::stoul(value);
    } else if (key == "timeout_match") {
        game.infos.timeout_match = std::stoul(value);
    } else if (key == "max_memory") {
        game.infos.max_memory = std::stoul(value);
    } else if (key == "time_left") {
        game.infos.time_left = std::stoul(value);
    } else if (key == "game_type") {
        game.infos.game_type = std::stoi(value);
    } else if (key == "rule") {
        game.infos.rule = std::stoi(value);
    } else if (key == "folder") {
        game.infos.folder = value;
    } else if (key == "evaluate") {
        size_t commaPos = value.find(',');
        if (commaPos != std::string::npos) {
            game.infos.evaluate_x = std::stoi(value.substr(0, commaPos));
            game.infos.evaluate_y = std::stoi(value.substr(commaPos + 1));
        }
    }
}

void CommandProcessor::handleAbout() {
    std::string aboutInfo;

    aboutInfo += !game.about_values.name.empty() ? "name=\"" + game.about_values.name + "\", " : "name=\"unknow\", ";
    aboutInfo += !game.about_values.version.empty() ? "version=\"" + game.about_values.version + "\", " : "version=\"unknow\", ";
    aboutInfo += !game.about_values.author.empty() ? "author=\"" + game.about_values.author + "\", " : "author=\"unkonw\", ";
    aboutInfo += !game.about_values.country.empty() ? "country=\"" + game.about_values.country + "\", " : "country=\"unknow\", ";
    
    if (!aboutInfo.empty()) {
        aboutInfo.pop_back();
        aboutInfo.pop_back();
    }

    std::cout << aboutInfo << std::endl;
}
