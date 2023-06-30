/*
** EPITECH PROJECT, 2022
** sokoban
** File description:
** main file
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

int count_lines(const char *buff)
{
    int lines = 0;
    int index = 0;

    while (buff[index] != '\0'){
        if (buff[index] == '\n')
            lines ++;
        index ++;
    }
    lines ++;
    return (lines);
}

int count_cols(const char *buff)
{
    int cols = 0;

    cols = my_strlen(buff);
    return (cols);
}

void empty_cpy(const char *buff, INIT_S *data)
{
    int layer = count_lines(buff);
    int length = count_cols(buff);
    int i = 0;
    int j = 0;

    E_TAB = malloc(sizeof(char*) * (layer + 1 ));
    for (int q = 0; q < layer; q ++)
        E_TAB[q] = malloc(sizeof(char) * (length + 1));
    for (int k = 0; buff[k] != '\0'; k ++){
        E_TAB[i][j] = buff[k];
        if (E_TAB[i][j] == 'P' || E_TAB[i][j] == 'X'){
            E_TAB[i][j] = ' ';
        }
        j ++;
        if (buff[k] == '\n'){
            i ++;
            j = 0;
        }
    }
    return;
}

void cpy(const char *buff, INIT_S *data)
{
    data->buff_layer = count_lines(buff);
    int length = count_cols(buff);
    int i = 0;
    int j = 0;

    C_TAB = malloc (sizeof(char*) * (data->buff_layer + 1));
    for (int q = 0; q < data->buff_layer; q ++)
        C_TAB[q] = malloc(sizeof(char) * (length + 1));
    for (int k = 0; buff[k] != '\0'; k ++){
        C_TAB[i][j] = buff[k];
        j ++;
        if (buff[k] == '\n'){
            i ++;
            j = 0;
        }
        if (buff[k] == 'P'){
            data->copy_tab.p_ypos = i;
            data->copy_tab.p_xpos = j - 1;
        }
    }
}

void rd_file(INIT_S *data)
{
    struct stat info;
    char *buff;
    stat(data->filepath, &info);
    buff = malloc(sizeof(char) * (info.st_size + 1));
    int file_desc = open(data->filepath, O_RDONLY);
    read (file_desc, buff, info.st_size);
    check_map(buff, data);
    possible_end(buff, data);
    cpy(buff, data);
    empty_cpy(buff, data);
    free(buff);
    close(file_desc);
    game(data);
    free_all(data);
    return;
}
