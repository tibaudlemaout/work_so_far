/*
** EPITECH PROJECT, 2024
** Appzy
** File description:
** Scene
*/

/**
 * @file Scene.cpp
 * @brief File containing functions that manages the scene
 */

#include "include/Scene.hpp"

/**
 * @brief Construct a new Scene:: Scene object
 */
Graphic::Scene::Scene()
{
    _window.create(sf::VideoMode(1920, 1080), "Zappy");
    _view = _window.getDefaultView();
    _isMovingCamera = false;
    _mapSize = std::make_pair(0, 0);
    _freq = 0;
    currentFrame = 0;
    frameTime = sf::seconds(0.5f);
    elapsedTime = sf::Time::Zero;
    _info = "";
    _textureList = {
        "gui/Assets/Character1.png",
        "gui/Assets/Character2.png",
        "gui/Assets/Character3.png",
        "gui/Assets/Character4.png",
        "gui/Assets/Character5.png",
        "gui/Assets/Character6.png",
        "gui/Assets/Character7.png",
        };
}

/**
 * @brief Function that initialize the scene
 */
void Graphic::Scene::initializeTiles()
{
    float tileWidth = 64.0f * 2;
    float tileHeight = 40.0f * 2;
    float offsetX = tileWidth / 2.0f;
    float offsetY = tileHeight / 4.0f;
    float additionalOffsetY = 6.0f * 2;
    float totalHeight = (gridHeight + gridWidth - 1) * offsetY + (gridHeight + gridWidth - 1) * additionalOffsetY;
    float startX = _window.getSize().x / 2.0f - tileWidth / 2.0f;
    float startY = (_window.getSize().y / 2.0f) - (totalHeight / 2.0f);

    _mapTiles.resize(gridHeight, std::vector<Tile>(gridWidth, Tile(0, 0)));
    for (int y = 0; y < gridHeight; y++) {
        for (int x = 0; x < gridWidth; x++) {
            _mapTiles[y][x] = Tile((x - y) * offsetX + startX, (x + y) * offsetY + startY + (x + y) * additionalOffsetY);
        }
    }
}

/**
 * @brief Function that initialize the scene
 */
void Graphic::Scene::updateCharacterAnimation(sf::Time deltaTime)
{
    elapsedTime += deltaTime;
    if (elapsedTime >= frameTime) {
        elapsedTime -= frameTime;
        currentFrame = (currentFrame + 1) % 2;
        for (auto& player : _players) {
            player._sprite.setTextureRect(sf::IntRect(currentFrame * 22, 0, 22, 40));
        }
    }
}

/**
 * @brief Function that zoom the view
 * 
 * @param pixel The pixel
 * @param zoomFactor The zoom factor
 */
void Graphic::Scene::zoomViewAt(sf::Vector2i pixel, float zoomFactor)
{
    sf::Vector2f beforeCoord = _window.mapPixelToCoords(pixel);
    _view.zoom(zoomFactor);
    sf::Vector2f afterCoord = _window.mapPixelToCoords(pixel);
    sf::Vector2f offsetCoords = beforeCoord - afterCoord;
    _view.move(offsetCoords);
}

/**
 * @brief Function that display text
 * 
 * @param window The window
 * @param str The string
 * @param position The position
 */
void Graphic::Scene::displayText(sf::RenderWindow &window, std::string str, sf::Vector2i position)
{
    sf::View view = window.getView();
    sf::Font font;
    if (!font.loadFromFile("gui/Assets/Font.ttf")) {
        std::cerr << "Error: loading font" << std::endl;
        return;
    }

    sf::Text text(str, font, 20);
    text.setFillColor(sf::Color::White);
    sf::Vector2f pos = window.mapPixelToCoords(position, view);
    text.setPosition(pos);
    window.draw(text);
}

/**
 * @brief Function that display the info
 * 
 * @param window The window
 */
void Graphic::Scene::displayInfo(sf::RenderWindow &window)
{
    // map size
    std::string mapSize = "Map witdh: " + std::to_string(gridWidth) + "\nMap height: " + std::to_string(gridHeight);
    displayText(window, mapSize, sf::Vector2i(10, 10));
    
    // frequence
    std::string frequence = "frequence: " + std::to_string(_freq);
    displayText(window, frequence, sf::Vector2i(window.getSize().x - 200, 10));
    
    // resources count
    std::unordered_map<std::string, int> resourceCounts;
    for (auto& row : _mapTiles) {
        for (auto& tile : row) {
            for (auto& resourcePair : tile._resources) {
                const std::string& resourceName = resourcePair.first;
                int resourceQuantity = tile._items[resourceName];
                resourceCounts[resourceName] += resourceQuantity;
            }
        }
    }
    std::string count;
    for (const auto& pair : resourceCounts) {
        count += pair.first + ": " + std::to_string(pair.second) + '\n';
    }
    displayText(window, count, sf::Vector2i(10, 200));

    // rank info
    std::string rank = "Rank";
    displayText(window, rank, sf::Vector2i(window.getSize().x - 200, 80));
    std::vector<Graphic::Player> sortedPlayers = _players;
    std::sort(sortedPlayers.begin(), sortedPlayers.end(), [](const Graphic::Player& a, const Graphic::Player& b) {
        return a._level > b._level;
    });
    std::string playerList;
    for (const auto& player : sortedPlayers) {
        playerList += player._teamName + ": " + std::to_string(player._level) + '\n';
    }
    displayText(window, playerList, sf::Vector2i(window.getSize().x - 200, 100));

    // user clic
    if (_info != "")
        displayText(window, _info, sf::Vector2i(10, window.getSize().y - 30));
}

/**
 * @brief Function that display the scene
 */
void Graphic::Scene::displayGlobal()
{
    _window.clear(sf::Color::Black);
    _window.setView(_view);

    for (auto& row : _mapTiles) {
        for (auto& tile : row) {
            tile._sprite.setTexture(tile._texture);
            _window.draw(tile._sprite);
            for (auto& resourcePair : tile._resources) {
                const std::string& resourceName = resourcePair.first;
                Graphic::Resource& resource = resourcePair.second;
                
                if (tile._items[resourceName] > 0) {
                    resource._sprite.setTexture(resource._texture);
                    _window.draw(resource._sprite);
                }
            }
        }
    }

    for (auto& egg : _eggs) {
        egg._sprite.setTexture(egg._texture);
        _window.draw(egg._sprite);
    }

    for (auto& player : _players) {
        player._sprite.setTexture(player._texture);
        _window.draw(player._sprite);
    }

    displayInfo(_window);

    _window.display();
}
