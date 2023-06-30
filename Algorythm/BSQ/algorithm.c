/*
** EPITECH PROJECT, 2022
** bsq
** File description:
** algorithm
*/
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/stat.h>
#include "struct.h"
#include "bsq.h"
#include"define.h"

int count_size(GLOBAL_T *data, int i, int j, int count)
{
    if (C_TAB[Y_P + i][X_P + j] == '.') {
        count ++;
    }
    return (count);
}

int check_fill(GLOBAL_T *data)
{
    int i = 0;
    int j = 0;
    int count = 0;

    while (i <= data->check_value) {
        while (j <= data->check_value) {
            count = count_size(data, i, j, count);
            j ++;
        }
        i ++;
        j = 0;
    }
    if ((count == 1 && data->check_value == 0) ||
        (count == 4 && data->check_value == 1) ||
        count == (data->check_value + 1) * (data->check_value + 1)) {
        data->check_value ++;
        check_fill(data);
    }
    return (0);
}

void check_square(GLOBAL_T *data)
{
    check_fill(data);
    if (data->check_value > data->max_check_value ||
        (data->check_value == 0 && data->max_check_value == 0)) {
        data->r_x = X_P;
        data->r_y = Y_P;
        data->max_check_value = data->check_value;
    }
    return;
}

void search_cont(GLOBAL_T *data)
{
    if (C_TAB[Y_P][X_P] != '.')
        return;
    if (X_P + data->check_value >= data->columns)
        return;
    if (Y_P + data->check_value >= data->layers)
        return;
    if (C_TAB[Y_P][X_P] == '.'){
        check_square(data);
    }
    return;
}

void square_search(GLOBAL_T *data)
{
    while (C_TAB[Y_P][X_P] != '\0') {
        while (C_TAB[Y_P][X_P] != '\n') {
            search_cont(data);
            X_P ++;
        }
        Y_P ++;
        X_P = 0;
    }
    return;
}
