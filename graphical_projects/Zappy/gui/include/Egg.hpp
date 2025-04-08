/*
** EPITECH PROJECT, 2024
** Appzy
** File description:
** Egg
*/

/**
 * @file Egg.hpp
 * @brief File containing functions that manages the egg
*/

#ifndef EGG_HPP_
    #define EGG_HPP_

    #include <iostream>

namespace Graphic {

    /**
     * @class Class with every function needed to manage the egg
    */
    class Egg {
        public:

            /**
             * @brief Constructor of the egg
             * @param id The id of the egg
             * @param idParentPlayer The id of the parent player
             * @param position The position of the egg
            */
            Egg(int id, int idParentPlayer, sf::Vector2i position) {
                _id = id;
                _idParentPlayer = idParentPlayer;
                _position = position;
                if (!_texture.loadFromFile("gui/Assets/Eggs.png")) {
                    std::cerr << "Error: loading texture" << std::endl;
                    exit(84);
                }
                _sprite.setTexture(_texture);
                _sprite.setTextureRect(sf::IntRect(0, 0, 144, 143));
                _sprite.setScale(0.15f, 0.15f);
                _sprite.setPosition(position.x, position.y);
            };
            ~Egg() = default;

            /**
             * @brief Set the Id object
             * 
             * @param id The id of the egg
             */
            inline void setId(int& id) { _id = id; };

            /**
             * @brief Set the Id Parent Player object
             * 
             * @param idParentPlayer The id of the parent player
             */
            inline void setIdParentPlayer(int& idParentPlayer) { _idParentPlayer = idParentPlayer; };

            /**
             * @brief Set the Position object
             * 
             * @param position The position of the egg
             */
            inline void setPosition(sf::Vector2i& position) { _position = position; };

            /**
             * @brief Get the Id object
             * 
             * @return int The id of the egg
             */
            inline int getId() { return _id; };

            /**
             * @brief Get the Id Parent Player object
             * 
             * @return int The id of the parent player
             */
            inline int getIdParentPlayer() { return _idParentPlayer; };

            /**
             * @brief Get the Position object
             * 
             * @return sf::Vector2i The position of the egg
             */
            inline sf::Vector2i getPosition() { return _position; };

            /**
             * @brief The id of the egg
             */
            int _id;

            /**
             * @brief The id of the parent player
             */
            int _idParentPlayer;

            /**
             * @brief The position of the egg
             */
            sf::Vector2i _position;

            /**
             * @brief The team name of the egg
             */
            std::string _teamName;

            /**
             * @brief The texture of the egg
             */
            sf::Texture _texture;

            /**
             * @brief The sprite of the egg
             */
            sf::Sprite _sprite;
    };
}

#endif /* !EGG_HPP_ */
