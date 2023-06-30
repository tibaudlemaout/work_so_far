/*
** EPITECH PROJECT, 2022
** sokoban
** File description:
** move P pos
*/
#include <ncurses.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <string.h>
#include "sokoban.h"
#include "struct.h"
#include "define.h"

void move_up (INIT_S *data)
{
    if (C_TAB[P_YPOS - 1][P_XPOS] != '#'){
        if (C_TAB[P_YPOS - 1][P_XPOS] == 'X' &&
            C_TAB[P_YPOS - 2][P_XPOS] != '#' &&
            C_TAB[P_YPOS - 2][P_XPOS] != 'X'){
                C_TAB[P_YPOS - 2][P_XPOS] = 'X';
                C_TAB[P_YPOS][P_XPOS] = E_TAB[P_YPOS][P_XPOS];
                C_TAB[P_YPOS - 1][P_XPOS] = 'P';
                P_YPOS -= 1;
            }
        if (C_TAB[P_YPOS - 1][P_XPOS] == ' ' ||
            C_TAB[P_YPOS - 1][P_XPOS] == 'O'){
            C_TAB[P_YPOS][P_XPOS] = E_TAB[P_YPOS][P_XPOS];
            C_TAB[P_YPOS - 1][P_XPOS] = 'P';
            P_YPOS -= 1;
        }
    }
    return;
}

void move_down(INIT_S *data)
{
    if (C_TAB[P_YPOS + 1][P_XPOS] != '#'){
        if (C_TAB[P_YPOS + 1][P_XPOS] == 'X' &&
            C_TAB[P_YPOS + 2][P_XPOS] != '#' &&
            C_TAB[P_YPOS + 2][P_XPOS] != 'X'){
                C_TAB[P_YPOS + 2][P_XPOS] = 'X';
                C_TAB[P_YPOS][P_XPOS] = E_TAB[P_YPOS][P_XPOS];
                C_TAB[P_YPOS + 1][P_XPOS] = 'P';
                P_YPOS += 1;
            }
        if (C_TAB[P_YPOS + 1][P_XPOS] == ' ' ||
            C_TAB[P_YPOS + 1][P_XPOS] == 'O'){
            C_TAB[P_YPOS][P_XPOS] = E_TAB[P_YPOS][P_XPOS];
            C_TAB[P_YPOS + 1][P_XPOS] = 'P';
            P_YPOS += 1;
        }
    }
    return;
}

void move_left(INIT_S *data)
{
    if (C_TAB[P_YPOS][P_XPOS - 1] != '#'){
        if (C_TAB[P_YPOS][P_XPOS - 1] == 'X' &&
            C_TAB[P_YPOS][P_XPOS - 2] != '#' &&
            C_TAB[P_YPOS][P_XPOS - 2] != 'X'){
                C_TAB[P_YPOS][P_XPOS - 2] = 'X';
                C_TAB[P_YPOS][P_XPOS] = E_TAB[P_YPOS][P_XPOS];
                C_TAB[P_YPOS][P_XPOS - 1] = 'P';
                P_XPOS -= 1;
        }
        if (C_TAB[P_YPOS][P_XPOS - 1] == ' ' ||
            C_TAB[P_YPOS][P_XPOS - 1] == 'O'){
            C_TAB[P_YPOS][P_XPOS] = E_TAB[P_YPOS][P_XPOS];
            C_TAB[P_YPOS][P_XPOS - 1] = 'P';
            P_XPOS -= 1;
        }
    }
    return;
}

void move_right(INIT_S *data)
{
    if (C_TAB[P_YPOS][P_XPOS + 1] != '#'){
        if (C_TAB[P_YPOS][P_XPOS + 1] == 'X' &&
            C_TAB[P_YPOS][P_XPOS + 2] != '#' &&
            C_TAB[P_YPOS][P_XPOS + 2] != 'X'){
                C_TAB[P_YPOS][P_XPOS + 2] = 'X';
                C_TAB[P_YPOS][P_XPOS] = E_TAB[P_YPOS][P_XPOS];
                C_TAB[P_YPOS][P_XPOS + 1] = 'P';
                P_XPOS += 1;
        }
        if (C_TAB[P_YPOS][P_XPOS + 1] == ' ' ||
            C_TAB[P_YPOS][P_XPOS + 1] == 'O'){
            C_TAB[P_YPOS][P_XPOS] = E_TAB[P_YPOS][P_XPOS];
            C_TAB[P_YPOS][P_XPOS + 1] = 'P';
            P_XPOS += 1;
        }
    }
    return;
}
