/*
** EPITECH PROJECT, 2023
** B-SYN-200-NAN-2-1-calendar-tibaud.le-maout
** File description:
** get_emp_meeting
*/
#include "../include/calendar.h"

employee_t *get_employee_by_id(employee_t *emp, int id)
{
    while (emp) {
        if (emp->ID == id)
            return emp;
        emp = emp->next;
    }
    return NULL;
}

void sort_employee_array_by_name(employee_t **employees, int count)
{
    qsort(employees, count, sizeof(employee_t *), compare_employees_by_name);
}
