/*
** EPITECH PROJECT, 2022
** sokoban
** File description:
** input_management
*/
#include <ncurses.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <string.h>
#include "sokoban.h"
#include "struct.h"
#include "define.h"

void move_input(INIT_S *data)
{
        switch (getch()) {
            case KEY_UP: move_up(data); break;
            case KEY_DOWN: move_down(data); break;
            case KEY_RIGHT: move_right(data); break;
            case KEY_LEFT: move_left(data); break;
            case 32: rd_file(data) ; break;
            case KEY_BACKSPACE: data->end_value = 1; break;
        }
    return;
}

void display_game (INIT_S *data)
{
    int index = 0;

    while (C_TAB[index] != '\0'){
            mvprintw(LINES / 2 + index, COLS / 2, "%s", C_TAB[index]);
            index ++;
        }
        return;
}

void game (INIT_S *data)
{
    initscr();
    noecho();
    keypad(stdscr, true);
    while (data->end_value != 1){
        clear();
        display_game (data);
        move_input(data);
        get_win(data);
        get_lose(data);
        check_end_cond(data);
        refresh();
    }
    endwin();
    return;
}
