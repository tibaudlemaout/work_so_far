/*
** EPITECH PROJECT, 2024
** Appzy
** File description:
** EventHandler
*/

/**
 * @file EventHandler.hpp
 * @brief File containing functions that manages the event handler
*/

#ifndef EVENTHANDLER_HPP_
    #define EVENTHANDLER_HPP_

    #include <SFML/Graphics.hpp>
    #include "Scene.hpp"

namespace Graphic {

    /**
     * @class Class with every function needed to manage the event handler
    */
    class EventReceiver {
        public:
            EventReceiver(sf::RenderWindow& window) : _window(window) {}
            void OnEvent(const sf::Event& event, Scene& scene);
            void zoom(const sf::Event& event, Scene& scene);
            void getInfo(const sf::Event& event, Scene& scene);
            void movingCamera(const sf::Event& event, Scene& scene);
            void movingPlayer(const sf::Event& event, Scene& scene);
            void handleResourceCollection(Scene& scenee, const char *name);

        private:

            /**
             * @brief The window
            */
            sf::RenderWindow& _window;
        };
}

#endif /* !EVENTHANDLER_HPP_ */
