/*
** EPITECH PROJECT, 2022
** bs push swap
** File description:
** step 1
*/
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "./pushswap.h"
#include "./struct.h"

int find_smallest(global_t *data)
{
    int smallest = data->lista[0];
    int index = 0;

    while (index < data->size_a) {
        if (data->lista[index] < smallest)
            smallest = data->lista[index];
        index ++;
    }
    return (smallest);
}

void pushb_cond(global_t *data, int small)
{
    if (data->lista[0] != small)
        rotate_left_ra(data, 1);
    if (data->lista[0] == small) {
        push_pb(data, 1);
        my_putchar(' ');
    }
    return;
}

void pusha_cond(global_t *data)
{
    push_pa(data, 1);
    if (data->size_b >= 1)
        my_putchar(' ');
    return;
}

void bubble_push(global_t *data)
{
    int done = 0;
    int small = 0;

    while (done == 0) {
        while (data->size_a > 1) {
            small = find_smallest(data);
            pushb_cond(data, small);
        }
        while (data->size_b > 0) {
            pusha_cond(data);
        }
        done = 1;
    }
    my_putchar('\n');
    return;
}
