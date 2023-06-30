/*
** EPITECH PROJECT, 2023
** B-SYN-200-NAN-2-1-calendar-tibaud.le-maout
** File description:
** info_meeting
*/
#include "../include/calendar.h"

void comma_display(int i, meeting_t *current)
{
    if (i < current->emp_num - 1)
        printf(", ");
}

void final_meet_display(meeting_t *current, employee_t **emp)
{
    employee_t **employees = NULL;
    employee_t *employee = NULL;

    printf("******************************\nMEETING\n");
    printf("date: %s\nplace: %s\nwith ", current->day, current->zipcode);
    employees = malloc(current->emp_num * sizeof(employee_t *));
    for (int i = 0; i < current->emp_num; i++) {
        employees[i] = get_employee_by_id(*emp, current->emp_ids[i]);
    }
    sort_employee_array_by_name(employees, current->emp_num);
    for (int i = 0; i < current->emp_num; i++) {
        employee = employees[i];
        if (employee) {
            printf("%s %s", employee->first_name, employee->last_name);
            comma_display(i, current);
        }
    }
    printf("\n");
    free(employees);
}

int find_id_display(int num_ids, int *ids, meeting_t *current)
{
    for (int i = 0; i < num_ids; i++) {
        if (current->ID == ids[i]) {
            return (1);
        }
    }
    return (0);
}

void display_meeting(meeting_t **meet, employee_t **emp, int num_ids, int *ids)
{
    meeting_t *current = *meet;
    int can_disp = 0;

    while (current) {
        can_disp = 0;
        if (num_ids == 0)
            can_disp = 1;
        else  {
            can_disp = find_id_display(num_ids, ids, current);
        }
        if (can_disp && current->emp_num > 1) {
            final_meet_display(current, emp);
        }
        current = current->next;
    }
}

int info_meeting(char **tab, employee_t **emp, meeting_t **meet)
{
    int num_ids = get_tab_layers(tab) - 2;
    int ids[num_ids];

    if (get_tab_layers(tab) < 1)
        return (0);
    for (int i = 0; i < num_ids; i++)
        ids[i] = atoi(tab[i + 3]);
    if (strcmp(tab[2], "sortByDate") == 0)
        sort_meeting_list_by_date(meet);
    if (strcmp(tab[2], "sortByZip") == 0)
        sort_meeting_list_by_location(meet);
    if (strcmp(tab[2], "sortById") == 0)
        sort_meeting_list_by_id(meet);
    if (strcmp(tab[2], "sortByDate") != 0 && strcmp(tab[2], "sortByZip") != 0
        && strcmp(tab[2], "sortById") != 0)
        return (0);
    display_meeting(meet, emp, num_ids, ids);
    return (0);
}
