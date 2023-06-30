/*
** EPITECH PROJECT, 2022
** sokoban
** File description:
** display and handling of lose conditions
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

void get_lose_cont(INIT_S *data, int i, int j)
{
    if ((C_TAB[i + 1][j] == '#' || C_TAB[i + 1][j] == 'X') &&
        (C_TAB[i][j - 1] == '#' || C_TAB[i][j + 1] == '#' ||
        C_TAB[i][j - 1] == 'X' || C_TAB[i][j + 1] == 'X'))
        data->lose_value ++;
    if ((C_TAB[i - 1][j] == '#' || C_TAB[i - 1][j] == 'X') &&
        (C_TAB[i][j - 1] == '#' || C_TAB[i][j + 1] == '#' ||
        C_TAB[i][j - 1] == 'X' || C_TAB[i][j + 1] == 'X'))
        data->lose_value ++;
    return;
}

void get_lose(INIT_S *data)
{
    int i = 0;
    int j = 0;
    data->lose_value = 0;

    while (C_TAB[i][j] != '\0'){
        if (C_TAB[i][j] == 'X' && E_TAB[i][j] != 'O'){
            get_lose_cont(data, i, j);
        }
        j ++;
        if (C_TAB[i][j] == '\n'){
            i ++;
            j = 0;
        }
    }
    return;
}
