/*
** EPITECH PROJECT, 2023
** B-SYN-200-NAN-2-1-calendar-tibaud.le-maout
** File description:
** employee
*/
#include "../include/calendar.h"

int set_new_employee(char **tab, employee_t **emp, meeting_t **meet)
{
    employee_t *new_emp = (employee_t*)malloc(sizeof(employee_t));
    employee_t *current;

    if (get_tab_layers(tab) != 6)
        return (0);
    new_emp->last_name = strdup(tab[2]);
    new_emp->first_name = strdup(tab[3]);
    new_emp->position = strdup(tab[4]);
    new_emp->zipcode = strdup(tab[5]);
    new_emp->ID = atoi(tab[6]);
    new_emp->next = NULL;
    if (*emp == NULL)
        *emp = new_emp;
    else {
        current = *emp;
        while (current->next != NULL)
            current = current->next;
        current->next = new_emp;
    }
    return 0;
}
