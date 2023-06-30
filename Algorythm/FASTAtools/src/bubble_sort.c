/*
** EPITECH PROJECT, 2023
** B-SYN-200-NAN-2-1-FASTAtools-tibaud.le-maout
** File description:
** bubble_sort
*/
#include "../include/fastatools.h"

static void swap_strings(char **str1, char **str2)
{
    if (strcmp(*str1, *str2) > 0) {
        char *temp = *str1;
        *str1 = *str2;
        *str2 = temp;
    }
    return;
}

void bubble_sort_strings(char **arr, int size)
{
    for (int i = 0; i < size - 1; i++) {
        for (int j = 0; j < size - i - 1; j++) {
            swap_strings(&arr[j], &arr[j + 1]);
        }
    }
    return;
}
