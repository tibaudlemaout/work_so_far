/* 
** EPITECH PROJECT, 2024
** Appzy
** File description:
** Encryption
*/

/**
 * @file Encryption.hpp
 * @brief Source file for Encryption.
 * In this file, we have all functions about the encryption of the AI
 * 
*/

#ifndef ENCRYPTION_HPP_
    #define ENCRYPTION_HPP_

    #include <iostream>

namespace AI {
    
        /**
        * @brief Encrypt a string
        * @param str The string to encrypt
        * 
        * @return std::string The encrypted string
        */
        std::string encrypt(std::string str);
    
        /**
        * @brief Decrypt a string
        * @param str The string to decrypt
        * 
        * @return std::string The decrypted string
        */
        std::string decrypt(std::string str);
    }

#endif // ENCRYPTION_HPP_