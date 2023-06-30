/*
** EPITECH PROJECT, 2023
** B-SYN-200-NAN-2-1-calendar-tibaud.le-maout
** File description:
** requirement
*/
#include "requirement.h"
#include <unistd.h>
#include <stdio.h>

int my_revlist_synthesis(list_t **begin)
{
    list_t *tmp = NULL;
    list_t *tmp2 = (*begin);
    list_t *tmp3 = NULL;

    while (tmp2) {
        tmp3 = tmp2->next;
        tmp2->next = tmp;
        tmp = tmp2;
        tmp2 = tmp3;
    }
    (*begin) = tmp;
    return (0);
}

list_t *my_findnodeeqinlist_synthesis(list_t *begin, void *data_ref ,
    int(*cmp)(void *, void *))
{
    list_t *tmp = begin;

    while (tmp) {
        if (cmp(begin->data, data_ref) == 0)
            return (tmp);
        tmp = tmp->next;
    }
    return (NULL);
}
