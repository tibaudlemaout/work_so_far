/*
** EPITECH PROJECT, 2023
** B-SYN-200-NAN-2-1-calendar-tibaud.le-maout
** File description:
** meeting
*/
#include "../include/calendar.h"

int fill_new_meet(char **tab, meeting_t *new_meet)
{
    new_meet->zipcode = strdup(tab[2]);
    new_meet->day = strdup(tab[3]);
    new_meet->ID = atoi(tab[4]);
    new_meet->emp_num = (get_tab_layers(tab) - 4);
    new_meet->emp_ids = (int*)malloc(sizeof(int) * (new_meet->emp_num + 1));
    for (int i = 0; i != new_meet->emp_num; i++)
        new_meet->emp_ids[i] = atoi(tab[5 + i]);
    new_meet->next = NULL;
    return (0);
}

int set_new_meeting(char **tab, employee_t **emp, meeting_t **meet)
{
    meeting_t *new_meet = (meeting_t*)malloc(sizeof(meeting_t));
    meeting_t *current;

    if (get_tab_layers(tab) < 6)
        return (0);
    fill_new_meet(tab, new_meet);
    if (*meet == NULL)
        *meet = new_meet;
    else {
        current = *meet;
        while (current->next != NULL)
            current = current->next;
        current->next = new_meet;
    }
    return (0);
}
