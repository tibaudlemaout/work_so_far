/*
** EPITECH PROJECT, 2022
** pushswap
** File description:
** functions to interact with the multiple strings rra rrb rrr
*/
#include "./pushswap.h"
#include "./struct.h"

void rotate_right_rra(global_t *data, int disp)
{
    int temp;
    int index = data->size_a - 1;

    while (index > 0){
        temp = data->lista[index];
        data->lista[index] = data->lista[index - 1];
        data->lista[index - 1] = temp;
        index --;
    }
    if (disp == 1)
        my_printf("rra");
    return;
}

void rotate_right_rrb(global_t *data, int disp)
{
    int temp;
    int index = data->size_b - 1;

    while (index > 0){
        temp = data->listb[index];
        data->listb[index] = data->listb[index - 1];
        data->listb[index - 1] = temp;
        index --;
    }
    if (disp == 1)
        my_printf("rrb ");
    return;
}
