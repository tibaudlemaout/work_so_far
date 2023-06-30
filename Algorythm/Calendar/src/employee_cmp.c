/*
** EPITECH PROJECT, 2023
** B-SYN-200-NAN-2-1-calendar-tibaud.le-maout
** File description:
** employee_cmp
*/
#include "../include/calendar.h"

int compare_by_forename_emp(const void *a, const void *b)
{
    const employee_t *employeeA = *(const employee_t **)a;
    const employee_t *employeeB = *(const employee_t **)b;

    return strcmp(employeeA->first_name, employeeB->first_name);
}

int compare_by_name_emp(const void *a, const void *b)
{
    const employee_t *employeeA = *(const employee_t **)a;
    const employee_t *employeeB = *(const employee_t **)b;

    return strcmp(employeeA->last_name, employeeB->last_name);
}

int compare_by_job_emp(const void *a, const void *b)
{
    const employee_t *employeeA = *(const employee_t **)a;
    const employee_t *employeeB = *(const employee_t **)b;

    return strcmp(employeeA->position, employeeB->position);
}

int compare_by_location_emp(const void *a, const void *b)
{
    const employee_t *employeeA = *(const employee_t **)a;
    const employee_t *employeeB = *(const employee_t **)b;

    return strcmp(employeeA->zipcode, employeeB->zipcode);
}

int compare_by_id_emp(const void *a, const void *b)
{
    const employee_t *employeeA = *(const employee_t **)a;
    const employee_t *employeeB = *(const employee_t **)b;

    return (employeeA->ID - employeeB->ID);
}
