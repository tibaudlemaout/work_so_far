/*
** EPITECH PROJECT, 2023
** B-SYN-200-NAN-2-1-calendar-tibaud.le-maout
** File description:
** fire
*/
#include "../include/calendar.h"

void fire_emp_cont(int empID, employee_t *prev, employee_t *current,
employee_t **emp)
{
    if (prev != NULL) {
        prev->next = current->next;
    } else {
        *emp = current->next;
    }
}

void fire_employee(employee_t **emp, int employeeID)
{
    employee_t *current = *emp;
    employee_t *prev = NULL;

    while (current != NULL) {
        if (current->ID == employeeID) {
            fire_emp_cont(employeeID, prev, current, emp);
            free(current);
            return;
        }
        prev = current;
        current = current->next;
    }
}

int rmv_from_meet_cont(meeting_t *current, int j, int empID, int *upd_emp_ids)
{
    int len = 0;

    for (int i = 0; i < current->emp_num; i++) {
        if (current->emp_ids[i] != empID) {
            upd_emp_ids[j] = current->emp_ids[i];
            j++;
            len++;
        }
    }
    return (len);
}

void remove_from_meetings(meeting_t **meet, int employeeID)
{
    meeting_t *current = *meet;
    int *updated_emp_ids = NULL;
    int j = 0;
    int new_num = 0;

    while (current != NULL) {
        new_num = 0;
        updated_emp_ids = malloc((current->emp_num - 1) * sizeof(int));
        j = 0;
        new_num = rmv_from_meet_cont(current, j, employeeID, updated_emp_ids);
        free(current->emp_ids);
        current->emp_ids = updated_emp_ids;
        current->emp_num = new_num;
        current = current->next;
    }
}

int set_fire(char **tab, employee_t **emp, meeting_t **meet)
{
    int numEmps = get_tab_layers(tab) - 1;
    int empID = 0;

    if (get_tab_layers(tab) < 2)
        return (0);
    for (int i = 0; i < numEmps; i++) {
        empID = atoi(tab[i + 2]);
        fire_employee(emp, empID);
        remove_from_meetings(meet, empID);
    }
    return (0);
}
