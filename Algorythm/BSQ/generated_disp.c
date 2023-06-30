/*
** EPITECH PROJECT, 2023
** EPITECH
** File description:
** generated_disp
*/
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/stat.h>
#include "struct.h"
#include "bsq.h"
#include "define.h"

void generated_drawing_square(GLOBAL_T *data)
{
    int i = 0;
    int j = 0;

    while (i < data->max_check_value){
        while (j < data->max_check_value){
            data->gen_map[data->r_y + i][data->r_x + j] = 'x';
            j ++;
        }
        i ++;
        j = 0;
    }
    return;
}
