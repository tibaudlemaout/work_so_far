/*
** EPITECH PROJECT, 2022
** bsq
** File description:
** to display the x
*/
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/stat.h>
#include "struct.h"
#include "bsq.h"
#include"define.h"

int verif_drawing(GLOBAL_T *data, int i, int j)
{
    if (C_TAB[Y_P + i][X_P + j] == '.') {
        return (0);
    }
    if (C_TAB[Y_P + i][X_P + j] != '.') {
        return (1);
    }
    return (0);
}

void drawing_square(GLOBAL_T *data)
{
    int i = 0;
    int j = 0;

    while (i < data->max_check_value){
        while (j < data->max_check_value){
            C_TAB[data->r_y + i][data->r_x + j] = 'x';
            j ++;
        }
        i ++;
        j = 0;
    }
    return;
}
