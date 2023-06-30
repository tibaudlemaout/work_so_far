/*
** EPITECH PROJECT, 2023
** B-SYN-200-NAN-2-1-calendar-tibaud.le-maout
** File description:
** exclude
*/
#include "../include/calendar.h"

void remove_employee_from_meeting(meeting_t *meeting, int employeeID)
{
    int index = -1;
    int *updated_emp_ids = NULL;
    int size = meeting->emp_num;

    for (int i = 0; i < meeting->emp_num; i++) {
        if (meeting->emp_ids[i] == employeeID) {
            index = i;
            break;
        }
    }
    if (index != -1) {
        for (int i = index; i < meeting->emp_num - 1; i++)
            meeting->emp_ids[i] = meeting->emp_ids[i + 1];
        meeting->emp_num--;
        updated_emp_ids = realloc(meeting->emp_ids, size * sizeof(int));
        meeting->emp_ids = updated_emp_ids;
    }
}

void exclude_cont(char **tab, int empID, meeting_t *meeting)
{
    for (int i = 3; tab[i] != NULL; i++) {
        empID = atoi(tab[i]);
        remove_employee_from_meeting(meeting, empID);
    }
}

int set_exclude(char **tab, employee_t **emp, meeting_t **meet)
{
    meeting_t *meeting = *meet;
    int meetingID = atoi(tab[2]);
    int employeeID = 0;

    while (meeting != NULL) {
        if (meeting->ID == meetingID) {
            exclude_cont(tab, employeeID, meeting);
            break;
        }
        meeting = meeting->next;
    }

    return 0;
}
