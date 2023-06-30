/*
** EPITECH PROJECT, 2023
** Elementary
** File description:
** map_generation
*/
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/stat.h>
#include "struct.h"
#include "bsq.h"
#include "define.h"

void generate_display(GLOBAL_T *data, int size)
{
    int y = 0;
    int x = 0;

    while (y < size) {
        my_printf("%s", data->gen_map[y]);
        my_putchar ('\n');
        y ++;
    }
    return;
}

void set_gen_map_size(GLOBAL_T *data, int size)
{
    data->gen_map = malloc(sizeof(char *) * size);
    for (int q = 0; q <= size; q ++)
        data->gen_map[q] = malloc(sizeof(char) * size);
    return;
}

int reset_template_index(int tmplt_index, int tmplt_size)
{
    if (tmplt_index == tmplt_size)
        tmplt_index = 0;
    return (tmplt_index);
}

void create_template(GLOBAL_T *data, int size, char *template)
{
    int tmplt_index = 0;
    int tmplt_size = my_strlen(template);
    int index = 0;
    Y_P = 0;

    set_gen_map_size(data, size);
    while (Y_P < size) {
        while (X_P < size) {
            tmplt_index = reset_template_index(tmplt_index, tmplt_size);
            data->gen_map[Y_P][X_P] = template[tmplt_index];
            X_P ++;
            tmplt_index ++;
        }
        Y_P ++;
        X_P = 0;
    }
    generated_search(data, size);
    generated_drawing_square(data);
    generate_display(data, size);
    return;
}
