/*
** EPITECH PROJECT, 2023
** EPITECH
** File description:
** generated_algo
*/
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/stat.h>
#include "struct.h"
#include "bsq.h"
#include "define.h"

int generated_count_size(GLOBAL_T *data, int i, int j, int count)
{
    if (data->gen_map[Y_P + i][X_P + j] == '.') {
        count ++;
    }
    return (count);
}

int generated_check_fill(GLOBAL_T *data)
{
    int i = 0;
    int j = 0;
    int count = 0;

    while (i <= data->check_value) {
        while (j <= data->check_value) {
            count = generated_count_size(data, i, j, count);
            j ++;
        }
        i ++;
        j = 0;
    }
    if ((count == 1 && data->check_value == 0) ||
        (count == 4 && data->check_value == 1) ||
        count == (data->check_value + 1) * (data->check_value + 1)) {
        data->check_value ++;
        generated_check_fill(data);
    }
    return (0);
}

void generated_check_square(GLOBAL_T *data)
{
    generated_check_fill(data);
    if (data->check_value > data->max_check_value ||
        (data->check_value == 0 && data->max_check_value == 0)) {
        data->r_x = X_P;
        data->r_y = Y_P;
        data->max_check_value = data->check_value;
    }
    return;
}

void generated_search_cont(GLOBAL_T *data, int size)
{
    if (data->gen_map[Y_P][X_P] != '.')
        return;
    if (X_P + data->check_value >= size)
        return;
    if (Y_P + data->check_value >= size)
        return;
    if (data->gen_map[Y_P][X_P] == '.'){
        generated_check_square(data);
    }
    return;
}

void generated_search(GLOBAL_T *data, int size)
{
    X_P = 0;
    Y_P = 0;
    while (Y_P < size) {
        while (X_P < size) {
            generated_search_cont(data, size);
            X_P ++;
        }
        Y_P ++;
        X_P = 0;
    }
    return;
}
