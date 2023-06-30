/*
** EPITECH PROJECT, 2022
** pushswap
** File description:
** functions to interact with the multiple strings ra rb rr
*/
#include "./pushswap.h"
#include "./struct.h"

void rotate_left_ra(global_t *data, int disp)
{
    int temp;
    int index = 0;

    while (index != data->size_a) {
        if (index > 0 && index < data->size_a) {
            temp = data->lista[index];
            data->lista[index] = data->lista[ index - 1];
            data->lista[index - 1] = temp;
        }
        index ++;
    }
    if (disp == 1)
        my_printf("ra ");
    return;
}

void rotate_left_rb(global_t *data, int disp)
{
    int temp;
    int index = 0;

    while (index != data->size_b) {
        if (index > 0 && index < data->size_b) {
            temp = data->listb[index];
            data->listb[index] = data->listb[ index - 1];
            data->listb[index - 1] = temp;
        }
        index ++;
    }
    if (disp == 1)
        my_printf("rb ");
    return;
}
