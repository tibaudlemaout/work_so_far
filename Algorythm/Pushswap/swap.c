/*
** EPITECH PROJECT, 2022
** pushswap
** File description:
** functions to interact with the multiple strings sa sb sc
*/
#include "./pushswap.h"
#include "./struct.h"

void swap_sa(int *array)
{
    int temp;

    temp = array[0];
    array[0] = array[1];
    array[1] = temp;
    my_printf("sa ");
    return;
}
