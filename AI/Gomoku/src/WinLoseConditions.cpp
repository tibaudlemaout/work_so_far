/*
** EPITECH PROJECT, 2024
** Gomoku
** File description:
** Evaluation.cpp
*/
#include "../include/Gomoku.hpp"

bool Game::checkFinalMove(int **boardArray, int x, int y, int player)
{
    // Directions: horizontal, vertical, diagonal, anti-diagonal
    int directions[4][2] = {{1, 0}, {0, 1}, {1, 1}, {1, -1}};
    
    for (auto &dir : directions) {
        int count = 0;
        for (int i = -4; i <= 4; ++i) {
            int nx = x + i * dir[0];
            int ny = y + i * dir[1];
            if (nx >= 0 && nx < boardSize && ny >= 0 && ny < boardSize && boardArray[nx][ny] == player || (nx == x && ny == y)) {
                count++;
            } else {
                count = 0;
            }
            if (count == 5) {
                return true;
            }
        }
    }
    return false;
}

void Game::evaluateWinningMoves(int **boardArray, int **evalArray, int player)
{
    for (int x = 0; x < boardSize; ++x) {
        for (int y = 0; y < boardSize; ++y) {
            if (boardArray[x][y] == 0 && checkFinalMove(boardArray, x, y, player)) {
                evalArray[x][y] = INT_MAX;
            }
        }
    }
}

void Game::evaluateLosingMoves(int **boardArray, int **evalArray, int opponent)
{
    for (int x = 0; x < boardSize; ++x) {
        for (int y = 0; y < boardSize; ++y) {
            if (boardArray[x][y] == 0 && checkFinalMove(boardArray, x, y, opponent)) {
                evalArray[x][y] = INT_MAX - 1;
            }
        }
    }
}
