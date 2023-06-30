/*
** EPITECH PROJECT, 2022
** sokoban
** File description:
** to fill the struct with values needed to end the game
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

void count_storage(const char *buff, INIT_S *data)
{
    int storage = 0;

    for (int k = 0; buff[k] != '\0'; k ++){
        if (buff[k] == 'O')
            storage ++;
    }
    data->storage = storage;
    return;
}

void count_boxes(const char *buff, INIT_S *data)
{
    int boxes = 0;

    for (int k = 0; buff[k] != '\0'; k ++){
        if (buff[k] == 'X')
            boxes ++;
    }
    data->boxes = boxes;
    return;
}

void possible_end(const char *buff, INIT_S *data)
{
    count_storage(buff, data);
    count_boxes(buff, data);
    if (data->storage != data->boxes){
        my_printf("It is impossible to win on this map.\n");
        exit(84);
    }
    return;
}

void check_end_cond(INIT_S *data)
{
    if (data->win_value == data->storage){
        endwin();
        my_printf("Congratulations,\nYou won !\n");
        exit (0);
    }
    if (data->lose_value == data->boxes){
        endwin();
        my_printf("You lost,\nWant to try again ?\n");
        exit (1);
    }
    return;
}
