/*
** EPITECH PROJECT, 2024
** B-CNA-410-NAN-4-1-groundhog-thomas.cluseau
** File description:
** App
*/

#include "include/App.hpp"

void App::init_tab(int &_period)
{
    int vertical_offset = 50;

    days.clear();
    temps.clear();
    symbols.clear();
    rectArray.clear();

    for (int i = 0; i < _period; i++) {
        std::string textStr = "not enough data";
        sf::Text text(textStr, font, 20);
        text.setPosition(100, scrollTop + i * vertical_offset);
        text.setFillColor(sf::Color::White);
        days.push_back(text);

        std::string tempStr = " ";
        sf::Text temp(tempStr, font, 24);
        temp.setPosition(window.getSize().x - 80, scrollTop + i * vertical_offset);
        temp.setFillColor(sf::Color::White);
        temps.push_back(temp);

        std::string symbolStr = " ";
        sf::Text symbol(symbolStr, symbols_font, 50);
        symbol.setPosition(30, (scrollTop - 20) + i * vertical_offset);
        symbol.setFillColor(sf::Color::White);
        symbols.push_back(symbol);

        sf::RectangleShape rect;
        sf::FloatRect textBounds = text.getLocalBounds();
        rect.setSize(sf::Vector2f(window.getSize().x, textBounds.height + 32));
        rect.setPosition(0, text.getPosition().y - 10);
        rect.setFillColor(sf::Color::Transparent);
        rect.setOutlineColor(sf::Color::White);
        rect.setOutlineThickness(1.0f);
        rectArray.push_back(rect);
    }
}

void App::update_background(double &temp)
{
    if (temp < 0) {
        if (!texture.loadFromFile("Assets/tunder.png"))
            exit(84);
        actualSymbol.setString("a");
    }
    if (temp >= 0 && temp < 10) {
        if (!texture.loadFromFile("Assets/rainy.png"))
            exit(84);
        actualSymbol.setString("m");
    }
    if (temp >= 10 && temp < 20) {
        if (!texture.loadFromFile("Assets/cloudy.png"))
            exit(84);
        actualSymbol.setString("p");
    }
    if (temp > 20) {
        if (!texture.loadFromFile("Assets/sunny.png"))
            exit(84);
        actualSymbol.setString("n");
    }
    background.setTexture(texture);
}

std::string App::get_symbol(double &temp)
{
    if (temp < 0)
        return "a";
    if (temp >= 0 && temp < 10)
        return "m";
    if (temp >= 10 && temp < 20)
        return "p";
    if (temp > 20)
        return "n";
    return " ";
}

void App::update_values(int &_period)
{
    int vertical_offset = 50;
    double lastTemperature = 0;

    if (tab.size() > _period) {
        for (int i = 0; i < _period; i++) {
            // std::cout << "a " << temps[(_period - 1) - i] << std::endl;
            size_t index = (tab.size() - (_period - 1) + i) - 1;
            if (index < 0)
                index = 0;
            if (index >= tab.size()) {
                std::cerr << "Index out of bounds: " << index << " for tab size: " << tab.size() << std::endl;
                exit(84);
            }
            if (tab[index].size() < 3)
                break;
            double estimatedTemperature = tab.back() + (tab[index][0] * 1.0) + ((estimatedTemperature/ 100) * tab[index][1]);
            if (tab[index][1] < 0)
                estimatedTemperature -= tab[index][2] * 0.60;
            else
                estimatedTemperature += tab[index][2] * 0.60;
            lastTemperature = estimatedTemperature;
            std::string textStr = "+" + std::to_string(i + 1) + " days";
            if (i == 0)
                textStr = "+" + std::to_string(i + 1) + " day";
            days[i].setString(textStr);
            // for (int j = 0; j < 3; j++)
            //     std::cout << "tab[" << index <<"] " << tab[index][j] << std::endl;
            // std::cout<<std::endl;

            std::ostringstream oss;
            oss << std::fixed << std::setprecision(1) << estimatedTemperature;
            std::string tempStr = oss.str();
            size_t dotPosition = tempStr.find('.');

            if (dotPosition == std::string::npos) {
                tempStr += ".0";
            } else {
                if (tempStr.find('.', dotPosition + 1) != std::string::npos)
                    tempStr.erase(tempStr.find('.', dotPosition + 1), 1);
            }
            temps[i].setString(tempStr);

            std::string symbolStr = get_symbol(estimatedTemperature);
            symbols[i].setString(symbolStr);
        }
    }
}

void App::draw(int &_period)
{
    update_values(_period);
    window.clear();
    window.draw(background);
    for (size_t i = 0; i < _period; i++) {
        window.draw(today);
        window.draw(actualTemp);
        window.draw(actualSymbol);
        if (days[i].getPosition().y >= scrollTop) {
            window.draw(days[i]);
            window.draw(temps[i]);
            window.draw(symbols[i]);
            window.draw(rectArray[i]);
        }
    }
    window.display();
}

void App::events_handler(int &_period)
{
    sf::Event event;
    while (window.pollEvent(event)) {
        if (event.type == sf::Event::Closed)
            window.close();
        if (event.type == sf::Event::MouseWheelScrolled) {
            if (event.mouseWheelScroll.wheel == sf::Mouse::VerticalWheel && !user_input) {
                float currentPosition = days[0].getPosition().y;
                float newPosition = currentPosition + (event.mouseWheelScroll.delta * scrollSpeed);
                float currentPosition2 = days[days.size()].getPosition().y;
                float newPosition2 = currentPosition2 + (event.mouseWheelScroll.delta * scrollSpeed);

                if (newPosition > scrollTop || newPosition2 > scrollTop)
                    break;
                for (size_t i = 0; i < _period; i++) {
                    days[i].move(0, event.mouseWheelScroll.delta * scrollSpeed);
                    temps[i].move(0, event.mouseWheelScroll.delta * scrollSpeed);
                    symbols[i].move(0, event.mouseWheelScroll.delta * scrollSpeed);
                    rectArray[i].move(0, event.mouseWheelScroll.delta * scrollSpeed);
                }
            }
        }
        if (event.type == sf::Event::KeyReleased) {
            if (event.key.code == sf::Keyboard::Space)
                user_input = true;
        }
        if (event.type == sf::Event::TextEntered) {
            if (event.text.unicode == 13) { // enter key
                user_input = true;
            } else if (event.text.unicode == 8) { // delete key
                if (!inputStr.empty())
                    inputStr.pop_back();
            } else {
                if (inputStr.size() < 10)
                    inputStr += static_cast<char>(event.text.unicode);
            }
        }
    }
}
