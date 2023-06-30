/*
** EPITECH PROJECT, 2022
** sokoban
** File description:
** display and handling win conditions
*/
#include <ncurses.h>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <string.h>
#include "sokoban.h"
#include "struct.h"
#include "define.h"

void get_win(INIT_S *data)
{
    int i = 0;
    int j = 0;
    data->win_value = 0;

    while (C_TAB[i][j] != '\0'){
        if (E_TAB[i][j] == 'O' && C_TAB[i][j] == 'X'){
            data->win_value ++;
        }
        j ++;
        if (C_TAB[i][j] == '\n'){
            i ++;
            j = 0;
        }
    }
    return;
}
