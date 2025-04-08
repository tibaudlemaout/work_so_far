/*
** EPITECH PROJECT, 2024
** Appzy
** File description:
** Client
*/

/**
 * @file EventHandler.cpp
 * @brief File containing functions that manages the event handler
 */

#include "include/EventHandler.hpp"

/**
 * @brief Construct a new Event Receiver:: Event Receiver object
 * 
 * @param window The window
 */
void Graphic::EventReceiver::OnEvent(const sf::Event& event, Scene& scene)
{
    if (event.type == sf::Event::Closed)
        _window.close();
    zoom(event, scene);
    getInfo(event, scene);
    movingCamera(event, scene);
    movingPlayer(event, scene);
}

/**
 * @brief Function that handle the zoom
 * 
 * @param event The event
 * @param scene The scene
 */
void Graphic::EventReceiver::zoom(const sf::Event& event, Scene& scene)
{
    if (event.type == sf::Event::MouseWheelScrolled) {
        if (event.mouseWheelScroll.delta > 0) {
            scene.zoomViewAt({event.mouseWheelScroll.x, event.mouseWheelScroll.y}, 0.9f); // Zoom in
        } else if (event.mouseWheelScroll.delta < 0) {
            scene.zoomViewAt({event.mouseWheelScroll.x, event.mouseWheelScroll.y}, 1.1f); // Zoom out
        }
    }
}

/**
 * @brief Function that get the info of the player or the tile
 * 
 * @param event The event
 * @param scene The scene
 */
void Graphic::EventReceiver::getInfo(const sf::Event& event, Scene& scene)
{
    if (event.type == sf::Event::MouseButtonPressed && event.mouseButton.button == sf::Mouse::Left) {
        sf::Vector2i mousePos = sf::Mouse::getPosition(scene._window);
        for (auto &player : scene._players) {
            if (player._sprite.getGlobalBounds().contains(mousePos.x, mousePos.y)) {
                scene._info = "ID: " + std::to_string(player.getId()) +
                            " | Level: " + std::to_string(player.getLevel()) +
                            " | Orientation: " + std::to_string(static_cast<int>(player.getOrientation())) +
                            " | Team: " + player.getTeamName();
                return;
            }
        }
        for (int y = 0; y < scene.gridHeight; y++) {
            for (int x = 0; x < scene.gridWidth; x++) {
                if (scene._mapTiles[y][x]._sprite.getGlobalBounds().contains(mousePos.x, mousePos.y)) {
                    scene._info = "Tile Position: (" + std::to_string(x) + ", " + std::to_string(y) + ")" +
                                " | Food  " + std::to_string(scene._mapTiles[y][x].getResourceTypeNb("food")) +
                                " | Linemate  " + std::to_string(scene._mapTiles[y][x].getResourceTypeNb("linemate")) +
                                " | Deraumere  " + std::to_string(scene._mapTiles[y][x].getResourceTypeNb("deraumere")) +
                                " | Sibur  " + std::to_string(scene._mapTiles[y][x].getResourceTypeNb("sibur")) +
                                " | Mendiane  " + std::to_string(scene._mapTiles[y][x].getResourceTypeNb("mendiane")) +
                                " | phiras  " + std::to_string(scene._mapTiles[y][x].getResourceTypeNb("phiras")) +
                                " | Thystame  " + std::to_string(scene._mapTiles[y][x].getResourceTypeNb("thystame"));
                    return;
                }
            }
        }
        scene._info = "";
    }
}

/**
 * @brief Function that handle the moving of the camera
 * 
 * @param event The event
 * @param scene The scene
 */
void Graphic::EventReceiver::movingCamera(const sf::Event& event, Scene& scene)
{
    if (event.type == sf::Event::MouseButtonPressed) {
        if (event.mouseButton.button == sf::Mouse::Right) {
            scene._isMovingCamera = true;
            scene._initialMousePosition = sf::Mouse::getPosition(scene._window);
        }
    }

    if (event.type == sf::Event::MouseButtonReleased) {
        if (event.mouseButton.button == sf::Mouse::Right) {
            scene._isMovingCamera = false;
        }
    }

    if (event.type == sf::Event::MouseMoved && scene._isMovingCamera) {
        sf::Vector2i newMousePosition = sf::Mouse::getPosition(scene._window);
        sf::Vector2f delta = scene._window.mapPixelToCoords(scene._initialMousePosition) - scene._window.mapPixelToCoords(newMousePosition);
        scene._view.move(delta);
        scene._initialMousePosition = newMousePosition;
    }
}

/**
 * @brief Function that handle the moving of the player
 * 
 * @param event The event
 * @param scene The scene
 */
void Graphic::EventReceiver::movingPlayer(const sf::Event& event, Scene& scene)
{
    if (event.type == sf::Event::KeyPressed) {
        int x = scene._players[0].getPosition().x;
        int y = scene._players[0].getPosition().y;

        if (event.key.code == sf::Keyboard::Up) {
            scene._players[0].setPosition(x + 64, y - 32); // up
            scene._players[0]._sprite.setScale(-2, 2); // mirror
            scene._players[0].setOrientation(Graphic::Orientation::NORTH);
        }
        if (event.key.code == sf::Keyboard::Down) {
            scene._players[0].setPosition(x - 64, y + 32); // down
            scene._players[0]._sprite.setScale(2, 2); // reset mirror
            scene._players[0].setOrientation(Graphic::Orientation::SOUTH);
        }
        if (event.key.code == sf::Keyboard::Left) {
            scene._players[0].setPosition(x - 64, y - 32); // left
            scene._players[0]._sprite.setScale(2, 2); // reset mirror
            scene._players[0].setOrientation(Graphic::Orientation::WEST);
        }
        if (event.key.code == sf::Keyboard::Right) {
            scene._players[0].setPosition(x + 64, y + 32); // right
            scene._players[0]._sprite.setScale(-2, 2); // mirror
            scene._players[0].setOrientation(Graphic::Orientation::EAST);
        }

        if (event.key.code == sf::Keyboard::F) {
            handleResourceCollection(scene, "food");
        }
    }
}

/**
 * @brief Function that handle the resource collection
 * 
 * @param scene The scene
 * @param name The name of the resource
 */
void Graphic::EventReceiver::handleResourceCollection(Scene& scene, const char *name)
{
    auto it = scene._players[0]._inventory.find(name);
    if (it != scene._players[0]._inventory.end()) {
        scene._players[0]._inventory[name]++;
        std::cout << name << ": " << it->second << std::endl;
    } else {
        std::cout << name << ": index not found" << std::endl;
    }
}
