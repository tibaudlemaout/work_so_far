/*
** EPITECH PROJECT, 2022
** pushswap
** File description:
** functions to interact with the multiple strings pa pb
*/
#include "./pushswap.h"
#include "./struct.h"

void push_pa(global_t *data, int disp)
{
    int temp = 0;
    int index = 0;

    data->size_a ++;
    rotate_right_rra(data, 0);
    data->lista[0] = data->listb[0];
    rotate_left_rb(data, 0);
    data->size_b --;
    if (disp == 1)
        my_printf("pa");

    return;
}

void push_pb(global_t *data, int disp)
{
    int temp = 0;
    int index = 0;

    data->size_b ++;
    rotate_right_rrb(data, 0);
    data->listb[0] = data->lista[0];
    rotate_left_ra(data, 0);
    data->size_a --;
    if (disp == 1)
        my_printf("pb");
    return;
}
