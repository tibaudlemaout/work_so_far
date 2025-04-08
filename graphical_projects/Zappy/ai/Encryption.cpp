/* 
** EPITECH PROJECT, 2024
** Appzy
** File description:
** Encryption
*/

/**
 * @file Encryption.cpp
 * @brief Source file for Encryption.
 * In this file, we have all functions about the encryption of the AI
 * 
*/

#include "Encryption.hpp"

namespace AI {

    /**
     * @brief Encrypt a string
     * @param str The string to encrypt
     * 
     * @return std::string The encrypted string
     */
    std::string encrypt(std::string str) {
        for (int i = 0; i < str.size(); i++) {
            str[i] = str[i] + 1;
        }
        return str;
    }

    /**
     * @brief Decrypt a string
     * @param str The string to decrypt
     * 
     * @return std::string The decrypted string
     */
    std::string decrypt(std::string str) {
        for (int i = 0; i < str.size(); i++) {
            str[i] = str[i] - 1;
        }
        return str;
    }
}