/*
** EPITECH PROJECT, 2024
** Gomoku
** File description:
** Evaluation.cpp
*/
#include "../include/Gomoku.hpp"

void Game::evaluateAdjacentMoves(void)
{
    int directions[8][2] = {
        {1, 0}, {-1, 0}, {0, 1}, {0, -1},  // Horizontal and vertical
        {1, 1}, {1, -1}, {-1, 1}, {-1, -1} // Diagonal
    };

    for (int x = 0; x < boardSize; ++x) {
        for (int y = 0; y < boardSize; ++y) {
            if (boardArray[x][y] == 0) {
                // Check all 8 neighbors
                for (auto &dir : directions) {
                    int nx = x + dir[0];
                    int ny = y + dir[1];
                    // Ensure the neighbor is within bounds
                    if (nx >= 0 && nx < boardSize && ny >= 0 && ny < boardSize) {
                        if (boardArray[nx][ny] == 1) {
                            evalArray[x][y] += 2;
                        }
                        if (boardArray[nx][ny] == 2) {
                            evalArray[x][y] += 1;
                        }
                    }
                }
            }
        }
    }
}

void Game::evaluateForkCreationMoves(int player)
{
    // Directions: horizontal, vertical, diagonal, anti-diagonal
    int directions[4][2] = {{1, 0}, {0, 1}, {1, 1}, {1, -1}};
    int baseValue = (player == 1) ? 200 : 150;

    for (int x = 0; x < boardSize; ++x) {
        for (int y = 0; y < boardSize; ++y) {
            if (boardArray[x][y] == 0) {
                int potentialForkCount = 0;
                int maxLineLength = 0; // Track the longest line contributing to a fork

                for (int d = 0; d < 4; ++d) {
                    int dx = directions[d][0], dy = directions[d][1];
                    int forwardCount = 0;
                    int backwardCount = 0;
                    bool forwardOpen = false;
                    bool backwardOpen = false;
                    // Check in the forward direction
                    int nx = x + dx, ny = y + dy;
                    while (nx >= 0 && nx < boardSize && ny >= 0 && ny < boardSize) {
                        if (boardArray[nx][ny] == player) {
                            forwardCount++;
                        } else if (boardArray[nx][ny] == 0) {
                            forwardOpen = true; // Open space at the end of the sequence
                            break;
                        } else {
                            break; // Blocked by opponent stone
                        }
                        nx += dx;
                        ny += dy;
                    }
                    // Check in the backward direction
                    nx = x - dx, ny = y - dy;
                    while (nx >= 0 && nx < boardSize && ny >= 0 && ny < boardSize) {
                        if (boardArray[nx][ny] == player) {
                            backwardCount++;
                        } else if (boardArray[nx][ny] == 0) {
                            backwardOpen = true; // Open space at the end of the sequence
                            break;
                        } else {
                            break; // Blocked by opponent stone
                        }
                        nx -= dx;
                        ny -= dy;
                    }
                    // Total line length including the current empty space
                    int lineLength = forwardCount + backwardCount + 1;
                    if (lineLength >= 3 && (forwardOpen || backwardOpen)) {
                        potentialForkCount++;
                        maxLineLength = std::max(maxLineLength, lineLength);
                    }
                }
                // Calculate score based on the best fork potential
                if (potentialForkCount >= 2) {
                    int bonus = 0;
                    if (maxLineLength == 4) {
                        bonus = 50; // Bonus for a 4-stone line
                    } else if (maxLineLength >= 5) {
                        bonus = 100; // Bonus for a 5-stone line
                    }
                    evalArray[x][y] += baseValue + bonus;
                }
            }
        }
    }
}

void Game::evaluateThreeInARowMoves(int player)
{
    int baseValue = (player == 1) ? 100 : 75;

    // Directions for all possible lines: horizontal, vertical, and diagonal
    int directions[4][2] = {{1, 0}, {0, 1}, {1, 1}, {1, -1}};

    for (int x = 0; x < boardSize; ++x) {
        for (int y = 0; y < boardSize; ++y) {
            if (boardArray[x][y] == 0) {
                for (auto& dir : directions) {
                    int dx = dir[0], dy = dir[1];
                    int stoneCount = 0;
                    int openSpaces = 0;
                    // Check forward direction
                    for (int step = 1; step <= 2; ++step) {
                        int nx = x + step * dx;
                        int ny = y + step * dy;
                        if (nx >= 0 && nx < boardSize && ny >= 0 && ny < boardSize) {
                            if (boardArray[nx][ny] == player) {
                                stoneCount++;
                            } else if (boardArray[nx][ny] == 0) {
                                openSpaces++;
                                break;
                            } else {
                                break; // Blocked by opponent stone
                            }
                        }
                    }
                    // Check backward direction
                    for (int step = 1; step <= 2; ++step) {
                        int px = x - step * dx;
                        int py = y - step * dy;
                        if (px >= 0 && px < boardSize && py >= 0 && py < boardSize) {
                            if (boardArray[px][py] == player) {
                                stoneCount++;
                            } else if (boardArray[px][py] == 0) {
                                openSpaces++;
                                break;
                            } else {
                                break; // Blocked by opponent stone
                            }
                        }
                    }
                    if (stoneCount == 2 && openSpaces >= 2) {
                        evalArray[x][y] += baseValue;
                    }
                }
            }
        }
    }
}

void Game::evaluateBlockOpponentOpenThreeInARow(int player)
{
    int directions[8][2] = {
        {1, 0}, {-1, 0}, {0, 1}, {0, -1},  // Horizontal and vertical
        {1, 1}, {1, -1}, {-1, 1}, {-1, -1} // Diagonal
    };

    for (int x = 0; x < boardSize; ++x) {
        for (int y = 0; y < boardSize; ++y) {
            if (boardArray[x][y] == 0) {
                for (auto &dir : directions) {
                    int nx1 = x + dir[0];       // First neighbor
                    int ny1 = y + dir[1];
                    int nx2 = x + 2 * dir[0];   // Second neighbor
                    int ny2 = y + 2 * dir[1];
                    int nx3 = x + 3 * dir[0];   // Third neighbor
                    int ny3 = y + 3 * dir[1];
                    int nxAfter = x + 4 * dir[0]; // Position after the line
                    int nyAfter = y + 4 * dir[1];

                    // Check bounds and evaluate a potential open 3 line
                    if (nx1 >= 0 && nx1 < boardSize && ny1 >= 0 && ny1 < boardSize &&
                        nx2 >= 0 && nx2 < boardSize && ny2 >= 0 && ny2 < boardSize &&
                        nx3 >= 0 && nx3 < boardSize && ny3 >= 0 && ny3 < boardSize) {
                        if (boardArray[nx1][ny1] == player &&
                            boardArray[nx2][ny2] == player &&
                            boardArray[nx3][ny3] == player) {

                            // Check if the ends are open
                            bool leftOpen = (x - dir[0] >= 0 && y - dir[1] >= 0 && x - dir[0] < boardSize && y - dir[1] < boardSize &&
                                             boardArray[x - dir[0]][y - dir[1]] == 0);
                            bool rightOpen = (nxAfter >= 0 && nyAfter >= 0 && nxAfter < boardSize && nyAfter < boardSize &&
                                              boardArray[nxAfter][nyAfter] == 0);
                            if (leftOpen || rightOpen) {
                                evalArray[x][y] += 1000; // Use a high priority score
                            }
                        }
                    }
                }
            }
        }
    }
}

void Game::evaluateFourInARowMoves(int player)
{
    int baseValue = (player == 1) ? 200 : 150;

    // Directions for all possible lines: horizontal, vertical, and diagonal
    int directions[4][2] = {{1, 0}, {0, 1}, {1, 1}, {1, -1}};

    for (int x = 0; x < boardSize; ++x) {
        for (int y = 0; y < boardSize; ++y) {
            if (boardArray[x][y] == 0) {
                for (auto& dir : directions) {
                    int dx = dir[0], dy = dir[1];
                    int stoneCount = 0;
                    int openSpaces = 0;
                    // Check forward direction
                    for (int step = 1; step <= 3; ++step) {
                        int nx = x + step * dx;
                        int ny = y + step * dy;
                        if (nx >= 0 && nx < boardSize && ny >= 0 && ny < boardSize) {
                            if (boardArray[nx][ny] == player) {
                                stoneCount++;
                            } else if (boardArray[nx][ny] == 0) {
                                openSpaces++;
                                break;
                            } else {
                                break; // Blocked by opponent stone
                            }
                        }
                    }
                    // Check backward direction
                    for (int step = 1; step <= 3; ++step) {
                        int px = x - step * dx;
                        int py = y - step * dy;
                        if (px >= 0 && px < boardSize && py >= 0 && py < boardSize) {
                            if (boardArray[px][py] == player) {
                                stoneCount++;
                            } else if (boardArray[px][py] == 0) {
                                openSpaces++;
                                break;
                            } else {
                                break; // Blocked by opponent stone
                            }
                        }
                    }
                    if (stoneCount == 3 && openSpaces >= 2) { // Needs 3 stones and both ends open
                        evalArray[x][y] += baseValue;
                    }
                }
            }
        }
    }
}


int **Game::evaluationFunction(int **boardState)
{
    evaluateAdjacentMoves();
    evaluateForkCreationMoves(1);
    evaluateForkCreationMoves(2);
    evaluateThreeInARowMoves(1);
    evaluateThreeInARowMoves(2);
    evaluateFourInARowMoves(1);
    evaluateFourInARowMoves(2);
    evaluateBlockOpponentOpenThreeInARow(1);
    evaluateBlockOpponentOpenThreeInARow(2);
    evaluateWinningMoves(boardArray, evalArray, 1);
    evaluateLosingMoves(boardArray, evalArray, 2);
    return boardState;
}
