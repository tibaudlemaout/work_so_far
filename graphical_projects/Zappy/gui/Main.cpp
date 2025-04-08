/* 
** EPITECH PROJECT, 2024
** Appzy
** File description:
** Main
*/

/**
 * @file Main.cpp
 * @brief File containing the main function
 */

#include <cstring>
#include <unistd.h>
#include <SFML/Audio.hpp>
#include "include/Scene.hpp"
#include "include/EventHandler.hpp"
#include "include/Client.hpp"

/**
 * @brief Function that handles the error
 * 
 * @param ac The number of arguments
 * @param av The arguments
 */
static void errorHandling(int &ac, char**av)
{
    if (ac == 5 && !strcmp(av[1], "-p") && !strcmp(av[3], "-h")) {
        for (int i = 0; av[2][i]; i++) {
            if (!isdigit(av[2][i]))
                exit(84);
        }
    } else {
        exit(84);
    }
}

/**
 * @brief Function that displays the loading screen
 * 
 * @param scene The scene
 */
static void loadingScreen(Graphic::Scene &scene)
{
    sf::Font font;
    if (!font.loadFromFile("gui/Assets/Font.ttf"))
        exit(84);

    sf::Text loadingText;
    loadingText.setFont(font);
    loadingText.setString("Loading, please wait...");
    loadingText.setCharacterSize(24);
    loadingText.setFillColor(sf::Color::White);
    loadingText.setStyle(sf::Text::Bold);
    float posX = (1920 / 2.0f) - (loadingText.getGlobalBounds().width / 2.0f);
    float posY = (1080 / 2.0f) - (loadingText.getGlobalBounds().height / 2.0f);
    loadingText.setPosition(posX, posY + 50);

    sf::Texture tileTexture;
    sf::Sprite tileSprite;

    if (!tileTexture.loadFromFile("gui/Assets/TileSet.png")) {
        std::cerr << "Error: loading texture" << std::endl;
        exit(84);
    }
    tileSprite.setTexture(tileTexture);
    tileSprite.setTextureRect(sf::IntRect(0, 0, 64, 40));
    tileSprite.setScale(2.0f, 2.0f);
    float spriteWidth = tileSprite.getGlobalBounds().width;
    float spriteHeight = tileSprite.getGlobalBounds().height;
    float spritePosX = (1920 / 2.0f) - (spriteWidth / 2.0f);
    float spritePosY = (1080 / 2.0f) - (spriteHeight / 2.0f);
    tileSprite.setPosition(spritePosX, spritePosY - 20);

    scene._window.clear(sf::Color::Black);
    scene._window.draw(loadingText);
    scene._window.draw(tileSprite);
    scene._window.display();
}

/**
 * @brief Main function
 * 
 * @param ac The number of arguments
 * @param av The arguments
 * @return int
 */
int main(int ac, char **av)
{
    errorHandling(ac, av);
    sf::Clock clock;
    Graphic::Scene scene;
    Graphic::Client client(scene);

    loadingScreen(scene);

    sf::Music music;
    if (!music.openFromFile("gui/Assets/Music.ogg"))
        return 84;
    music.setVolume(50);
    music.setLoop(true);
    music.play();

    client.connectionToServer(av[2], av[4], scene.gridWidth, scene.gridHeight);
    Graphic::EventReceiver receiver(scene._window);

    scene.initializeTiles();
    client.requestMapContent();
    client.requestFrequence();
    while (scene._window.isOpen()) {

        sf::Event event;
        while (scene._window.pollEvent(event))
            receiver.OnEvent(event, scene);

        client.receiveMessages();

        sf::Time deltaTime = clock.restart();
        scene.updateCharacterAnimation(deltaTime);

        scene.displayGlobal();
    }

    close(client._sock);
    return 0;
}
