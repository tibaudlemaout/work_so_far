/*
** EPITECH PROJECT, 2022
** bsq
** File description:
** main file
*/
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/stat.h>
#include "struct.h"
#include "bsq.h"
#include "define.h"

int count_lines(const char *buff)
{
    int lines = 0;
    int index = 0;

    while (buff[index] != '\0') {
        if (buff[index] == '\n') {
            lines ++;
        }
        index ++;
    }
    lines ++;
    return (lines);
}

int count_cols(const char *buff)
{
    int cols = 0;
    int index = 0;
    int lines = 0;

    while (lines != 2) {
        if (buff[index] == '\n') {
            lines ++;
        }
        if (lines == 1){
            buff[index];
            cols ++;
        }
        index ++;
    }
    cols --;
    return (cols);
}

void cpy(const char *buff, GLOBAL_T *data)
{
    data->layers = count_lines(buff);
    data->columns = count_cols(buff);
    int i = 0;
    int j = 0;

    C_TAB = malloc (sizeof(char *) * (data->layers + 1));
    for (int q = 0; q < data->layers; q ++)
        C_TAB[q] = malloc(sizeof(char) * (data->columns));
    for (int k = 0; buff[k] != '\0'; k ++) {
        C_TAB[i][j] = buff[k];
        j ++;
        if (buff[k] == '\n') {
            i ++;
            j = 0;
        }
    }
    return;
}

int display(GLOBAL_T *data)
{
    int layers = 1;
    int length = 0;

    while (C_TAB[layers][length] != '\0') {
        while (C_TAB[layers][length] != '\n') {
            my_printf("%c", C_TAB[layers][length]);
            length ++;
        }
        my_putchar('\n');
        layers ++;
        length = 0;
    }
    return (0);
}

int op_rd_file(const char *filepath, GLOBAL_T *data)
{
    struct stat info;
    char *buff;

    int fd = open(filepath, O_RDONLY);
    if (fd != -1){
        stat(filepath, &info);
        buff = malloc(sizeof(char) * (info.st_size + 1));
        read(fd, buff, info.st_size + 1);
        cpy(buff, data);
    } else {
        my_printf("could not open or read the given file\n");
        return (84);
    }
    square_search(data);
    drawing_square(data);
    display(data);
    close(fd);
    free (buff);
    free(C_TAB);
    return (0);
}
