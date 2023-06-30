/*
** EPITECH PROJECT, 2023
** B-SYN-200-NAN-2-1-calendar-tibaud.le-maout
** File description:
** info_employee
*/
#include "../include/calendar.h"

void final_emp_display(employee_t *current, meeting_t **meet)
{
    printf("******************************\n");
    printf("%s %s\n", current->first_name, current->last_name);
    printf("position: %s\n", current->position);
    printf("city: %s\n", current->zipcode);
}

int find_id_emp(employee_t *current, int num_ids, int *ids)
{
    for (int i = 0; i < num_ids; i++) {
        if (current->ID == ids[i]) {
            return (1);
            break;
        }
    }
    return (0);
}

void display_employee(employee_t **emp, meeting_t **meet, int num_ids,
    int *ids)
{
    employee_t *current = *emp;
    int can_disp = 0;

    while (current) {
        if (num_ids == 0)
            can_disp = 1;
        else {
            can_disp = find_id_emp(current, num_ids, ids);
        }
        if (can_disp) {
            final_emp_display(current, meet);
        }
        current = current->next;
    }
}

int info_employee_cont(char **tab, employee_t **emp)
{
    if (strcmp(tab[2], "sortByZip") == 0)
        sort_emp_list_by_zip(emp);
    if (strcmp(tab[2], "sortById") == 0)
        sort_emp_list_by_id(emp);
    if (strcmp(tab[2], "sortByName") != 0 &&
        strcmp(tab[2], "sortByForename") != 0 &&
        strcmp(tab[2], "sortByJob") != 0 &&
        strcmp(tab[2], "sortByZip") != 0 &&
        strcmp(tab[2], "sortById") != 0)
        return (1);
    return (0);
}

int info_employee(char **tab, employee_t **emp, meeting_t **meet)
{
    int num_ids = get_tab_layers(tab) - 2;
    int ids[num_ids];

    if (get_tab_layers(tab) < 2)
        return (0);
    for (int i = 0; i < num_ids; i++)
        ids[i] = atoi(tab[i + 3]);
    if (strcmp(tab[2], "sortByName") == 0)
        sort_emp_list_by_name(emp);
    if (strcmp(tab[2], "sortByForename") == 0)
        sort_emp_list_by_forename(emp);
    if (strcmp(tab[2], "sortByJob") == 0)
        sort_emp_list_by_job(emp);
    if (info_employee_cont(tab, emp) == 1)
        return (0);
    display_employee(emp, meet, num_ids, ids);
    return (0);
}
