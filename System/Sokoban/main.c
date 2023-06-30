/*
** EPITECH PROJECT, 2022
** sokoban
** File description:
** main function only
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

void free_all(INIT_S *data)
{
    free(C_TAB);
    free(E_TAB);
    return;
}

int main(int argc, char **argv)
{
    INIT_S data;
    int index = 0;
    error(argc, &data);
    data.filepath = argv[1];
    rd_file(&data);
    return (0);
}
