/*
** EPITECH PROJECT, 2023
** B-SYN-200-NAN-2-1-calendar-tibaud.le-maout
** File description:
** sort_employee_id
*/
#include "../include/calendar.h"

static int sort_meeting_id_alloc(employee_t *current, int count,
    employee_t **emp)
{
    while (current) {
        count++;
        current = current->next;
    }
    current = *emp;
    return (count);
}

static void fill_employees_list(int count, employee_t **employees,
    employee_t *current)
{
    for (int i = 0; i < count; i++) {
        employees[i] = current;
        current = current->next;
    }
    qsort(employees, count, sizeof(employee_t *), compare_by_id_emp);
}

static void sort_meeting_id_end(employee_t *prev, employee_t *sorted,
    employee_t **meet, employee_t **employees)
{
    if (prev)
        prev->next = NULL;
    *meet = sorted;
    free(employees);
}

void sort_emp_list_by_id(employee_t **emp)
{
    employee_t *current = *emp;
    employee_t *sorted = NULL;
    employee_t *prev = NULL;
    employee_t **employees = NULL;
    int count = 0;

    count = sort_meeting_id_alloc(current, count, emp);
    employees = malloc(count * sizeof(employee_t *));
    fill_employees_list(count, employees, current);
    for (int i = 0; i < count; i++) {
        current = employees[i];
        if (sorted == NULL) {
        sorted = current;
        prev = current;
        } else {
        prev->next = current;
        prev = current;
        }
    }
    sort_meeting_id_end(prev, sorted, emp, employees);
}