/*
** EPITECH PROJECT, 2024
** Gomoku
** File description:
** Main.cpp
*/
#include "../include/CommandProcessor.hpp"

int main() {
    CommandProcessor commandProcessor;

    std::thread listenerThread(&CommandProcessor::listener, &commandProcessor);
    std::thread senderThread(&CommandProcessor::sender, &commandProcessor);

    listenerThread.join();
    senderThread.join();
    return 0;
}
