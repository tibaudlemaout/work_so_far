/*
** EPITECH PROJECT, 2024
** Appzy
** File description:
** Scene
*/

/**
 * @file Scene.hpp
 * @brief File containing functions that manages the scene
*/

#ifndef SCENE_HPP_
    #define SCENE_HPP_

    #include <iostream>
    #include <vector>
    #include <SFML/Graphics.hpp>
    #include "Tile.hpp"
    #include "Player.hpp"
    #include "Egg.hpp"

namespace Graphic {

    /**
     * @class Class with every function needed to manage the scene
    */
    class Scene {
        public:
            Scene();
            ~Scene() = default;
            void initializeTiles();
            void updateCharacterAnimation(sf::Time deltaTime);
            void zoomViewAt(sf::Vector2i pixel, float zoomFactor);
            void displayInfo(sf::RenderWindow &window);
            void displayText(sf::RenderWindow &window, std::string str, sf::Vector2i position);
            void displayGlobal();

            /**
             * @brief The window
             */
            sf::RenderWindow _window;

            /**
             * @brief The view
             */
            sf::View _view;

            /**
             * @brief Boolean that checks if the camera is moving
             */
            bool _isMovingCamera;

            /**
             * @brief The initial mouse position
             */
            sf::Vector2i _initialMousePosition;

            /**
             * @brief The grid width
             */
            int gridWidth;

            /**
             * @brief The grid height
             */
            int gridHeight;

            /**
             * @brief The size of the map
             */
            std::pair<int, int> _mapSize;

            /**
             * @brief The list of tiles of the map
             */
            std::vector<std::vector<Tile>> _mapTiles;

            /**
             * @brief The list of team names
             */
            std::vector<std::string> _teamNames;

            /**
             * @brief The list of team texture index
             */
            std::vector<int> _teamTextureIndex;

            /**
             * @brief The list of textures
             */
            std::vector<std::string> _textureList;

            /**
             * @brief The list of players
             */
            std::vector<Player> _players;

            /**
             * @brief The list of eggs
             */
            std::vector<Egg> _eggs;

            /**
             * @brief The frequence of the server
             */
            int _freq;

            /**
             * @brief The current frame
             */
            int currentFrame;

            /**
             * @brief The frame time
             */
            sf::Time frameTime;

            /**
             * @brief The elapsed time
             */
            sf::Time elapsedTime;

            /**
             * @brief The info to display
             */
            std::string _info;
        };
}

#endif /* !SCENE_HPP_ */
