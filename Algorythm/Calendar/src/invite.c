/*
** EPITECH PROJECT, 2023
** B-SYN-200-NAN-2-1-calendar-tibaud.le-maout
** File description:
** invite
*/
#include "../include/calendar.h"

void add_employee_to_meeting(meeting_t *meeting, int employeeID)
{
    int *updated_emp_ids = NULL;
    int size = meeting->emp_num + 1;

    for (int i = 0; i < meeting->emp_num; i++) {
        if (meeting->emp_ids[i] == employeeID)
            return;
    }
    updated_emp_ids = realloc(meeting->emp_ids, (size) * sizeof(int));
    updated_emp_ids[meeting->emp_num] = employeeID;
    meeting->emp_ids = updated_emp_ids;
    meeting->emp_num++;
}

int set_invite(char **tab, employee_t **emp, meeting_t **meet)
{
    int employeeID = 0;
    int meetingID = atoi(tab[2]);
    meeting_t *current = *meet;

    while (current != NULL) {
        if (current->ID == meetingID) {
            break;
        }
        current = current->next;
    }
    for (int i = 3; i <= get_tab_layers(tab); i++) {
        employeeID = atoi(tab[i]);
        add_employee_to_meeting(current, employeeID);
    }

    return 0;
}
