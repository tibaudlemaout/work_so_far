/*
** EPITECH PROJECT, 2024
** B-CNA-410-NAN-4-1-groundhog-thomas.cluseau
** File description:
** App
*/

#ifndef APP_HPP_
    #define APP_HPP_
#include <SFML/Graphics.hpp>
#include "Groundhog.hpp"

class App {
    public:
        App() : window(sf::VideoMode(360, 780), "Weather App") {
            user_input = false;
            scrollSpeed = -50.0f;
            scrollTop = 400;
            if (!font.loadFromFile("Fonts/basic.otf"))
                exit(84);
            if (!symbols_font.loadFromFile("Fonts/WeatherSymbols.ttf"))
                exit(84);
            if (!texture.loadFromFile("Assets/sunny.png"))
                exit(84);
            background.setTexture(texture);
            background.setScale(0.34, 0.34);
            background.setPosition(-50, 0);
            today.setFont(font);
            today.setCharacterSize(30);
            today.setString("Today");
            today.setPosition(130, 50);
            today.setFillColor(sf::Color::White);
            actualTemp.setFont(font);
            actualTemp.setCharacterSize(90);
            actualTemp.setString(" ");
            actualTemp.setPosition(80, 140);
            actualTemp.setFillColor(sf::Color::White);
            actualSymbol.setFont(symbols_font);
            actualSymbol.setCharacterSize(80);
            actualSymbol.setString(" ");
            actualSymbol.setPosition(160, 250);
            actualSymbol.setFillColor(sf::Color::White);
        };
        ~App() = default;
        void init_tab(int &_period);
        void update_values(int &_period);
        std::string get_symbol(double &temp);
        void update_background(double &temp);
        void draw(int &_period);
        void events_handler(int &_period);

        bool user_input;
        float scrollSpeed;
        int scrollTop;
        sf::Font font;
        sf::Font symbols_font;
        sf::RenderWindow window;
        sf::Texture texture;
        sf::Sprite background;
        sf::Text today;
        sf::Text actualTemp;
        sf::Text actualSymbol;
        std::vector<sf::Text> days;
        std::vector<sf::Text> temps;
        std::vector<sf::Text> symbols;
        std::vector<sf::RectangleShape> rectArray;
        std::vector<std::vector<double>> tab;
        std::string inputStr;
};

#endif /* !APP_HPP_ */
