/*
** EPITECH PROJECT, 2024
** Appzy
** File description:
** Commands
*/

/**
 * @file Commands.hpp
 * @brief File containing functions that manages the commands
*/

#ifndef COMMANDS_HPP_
    #define COMMANDS_HPP_

    #include <iostream>
    #include <vector>
    #include <functional>
    #include <sstream>
    #include "Player.hpp"
    #include "Scene.hpp"
    #include "Egg.hpp"

namespace Graphic{

    /**
     * @class Class with every function needed to manage the Scene
    */
    class Scene;
    
    /**
     * @class Class with every function needed for commands
    */
    class Commands {
        public:
            Commands(Scene& scene) : _scene(scene) {}
            ~Commands() = default;
            void setMapSize(const std::string str);
            void setTileContent(const std::string str);
            void setTeamName(const std::string str);
            void newPlayerConnection(const std::string str);
            void setPlayerPosition(const std::string str);
            void setPlayerLevel(const std::string str);
            void broadcast(const std::string str);
            void setFreq(const std::string str);
            void editFreq(const std::string str);
            void setPlayerInventory(const std::string str);
            void startIncantation(const std::string str);
            void endIncantation(const std::string str);
            void eggLaying(const std::string str);
            void eggLaid(const std::string str);
            void connectionByEgg(const std::string str);
            void playerDeath(const std::string str);
            void eggDeath(const std::string str);
            void endGame(const std::string str);
            void resourceDropping(const std::string str);
            void resourceCollecting(const std::string str);
            void messageFromServer(const std::string str);
            void unknowCommand(const std::string str);
            void commandParameter(const std::string str);

            /**
             * @brief The scene
             */
            Scene& _scene;
    };
}

#endif /* !COMMANDS_HPP_ */
