/*
** EPITECH PROJECT, 2024
** Gomoku
** File description:
** Main.cpp
*/
#include "../include/Gomoku.hpp"

int **Game::createBoardState(int size)
{
    int **emptyBoard = NULL;

    emptyBoard = (int **)malloc(size * sizeof(int *));
    if (emptyBoard == NULL)
        return NULL;

    for (int i = 0; i < size; i++) {
        emptyBoard[i] = (int *)malloc(size * sizeof(int));
        if (emptyBoard[i] == NULL) {
            for (int k = 0; k < i; k++) {
                free(emptyBoard[k]);
            }
            free(emptyBoard);
            return NULL;
        }
        for (int j = 0; j < size; j++)
            emptyBoard[i][j] = 0;
    }

    return (emptyBoard);
}

int **Game::cleanEvalState(int size)
{
    int **emptyBoard = NULL;

    emptyBoard = (int **)malloc(size * sizeof(int *));
    if (emptyBoard == NULL)
        return NULL;
    for (int i = 0; i < size; i++) {
        emptyBoard[i] = (int *)malloc(size * sizeof(int));
        if (emptyBoard[i] == NULL) {
            for (int k = 0; k < i; k++) {
                free(emptyBoard[k]);
            }
            free(emptyBoard);
            return NULL;
        }
        for (int j = 0; j < size; j++) {
            emptyBoard[i][j] = -2;
            if (i == 0 || i == size - 1 || j == 0 || j == size - 1) {
                emptyBoard[i][j] -= 5; // Penalty for edges
            }
            if ((i == 0 && j == 0) || (i == 0 && j == size - 1) ||
                (i == size - 1 && j == 0) || (i == size - 1 && j == size - 1)) {
                emptyBoard[i][j] -= 10; // Higher penalty for corners
            }
        }
    }
    return (emptyBoard);
}


void Game::updateEnemyTurn(int x, int y)
{
    if (x >= 0 && x < boardSize && y >= 0 && y < boardSize) {
        boardArray[x][y] = 2;
    } else {
        std::cout << "ERROR Position (" << x << ", " << y << ") is out of bounds." << std::endl;
    } 
    return;
}

void Game::insertBoardMove(int x, int y, int player)
{
    boardArray[x][y] = player;
    return;
}

std::pair<int, int> Game::findMaxValuePosition()
{
    std::vector<int> storedX;
    std::vector<int> storedY;
    int maxValue = -1;
    int maxX = -1;
    int maxY = -1;
    int random = 0;

    for (int i = 0; i < boardSize; ++i) {
        for (int j = 0; j < boardSize; ++j) {
            if (evalArray[i][j] >= maxValue) {
                if (evalArray[i][j] > maxValue) {
                    maxValue = evalArray[i][j];
                    storedX.clear();
                    storedY.clear();
                }
                storedX.push_back(i);
                storedY.push_back(j);
            }
        }
    }

    if (!storedX.empty()) {
        random = rand() % storedX.size();
        maxX =  storedX[random];
        maxY =  storedY[random];
    }

    return std::make_pair(maxX, maxY);
}

void Game::play(void)
{
    evalArray = cleanEvalState(boardSize);
    srand(time(0));
    evaluationFunction(boardArray);
    std::pair<int, int> playPosition = {-1, -1};
    playPosition = findMaxValuePosition();

    if (playPosition.first != -1 && playPosition.second != -1 &&
        boardArray[playPosition.first][playPosition.second] == 0) {
        std::cout << playPosition.first << "," << playPosition.second << std::endl;
        boardArray[playPosition.first][playPosition.second] = 1;
    } else {
        int x = rand() % boardSize;
        int y = rand() % boardSize;
        while (boardArray[x][y] != 0 || (x == 0 || y == 0 || x == boardSize - 1 || y == boardSize - 1)) {
            x = rand() % boardSize;
            y = rand() % boardSize;
        }

        boardArray[x][y] = 1;
        
        std::string coordinates = std::to_string(x) + "," + std::to_string(y);
        std::lock_guard<std::mutex> lock(_queueMutex);
        _messageQueue.push(coordinates);
        _queueCondVar.notify_all();
    }
    return;
}
