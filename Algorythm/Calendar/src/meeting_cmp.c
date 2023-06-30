/*
** EPITECH PROJECT, 2023
** B-SYN-200-NAN-2-1-calendar-tibaud.le-maout
** File description:
** meeting_cmp
*/
#include "../include/calendar.h"

int compare_by_date(const void *a, const void *b)
{
    const meeting_t *meetingA = *(const meeting_t **)a;
    const meeting_t *meetingB = *(const meeting_t **)b;

    return strcmp(meetingA->day, meetingB->day);
}

int compare_by_location(const void *a, const void *b)
{
    const meeting_t *meetingA = *(const meeting_t **)a;
    const meeting_t *meetingB = *(const meeting_t **)b;

    return strcmp(meetingA->zipcode, meetingB->zipcode);
}

int compare_by_id(const void *a, const void *b)
{
    const meeting_t *meetingA = *(const meeting_t **)a;
    const meeting_t *meetingB = *(const meeting_t **)b;

    return (meetingA->ID - meetingB->ID);
}

int compare_employees_by_name(const void *a, const void *b)
{
    const employee_t *empA = *(const employee_t **)a;
    const employee_t *empB = *(const employee_t **)b;

    return strcmp(empA->last_name, empB->last_name);
}
