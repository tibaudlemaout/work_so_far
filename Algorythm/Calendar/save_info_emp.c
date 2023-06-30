/*
** EPITECH PROJECT, 2023
** B-SYN-200-NAN-2-1-calendar-tibaud.le-maout
** File description:
** save_info_emp
*/
#include "include/calendar.h"

static void get_colleagues(meeting_t *meet, int ID, employee_t **emp)
{
    employee_t *current = *emp;

    for (int i = 0; i <= meet->emp_num; i++) {
        while (current) {
            if (current->ID == meet->emp_ids[i] && current->ID != ID) {
                printf(" %s %s", current->first_name, current->last_name);
                if (i + 1 < meet->emp_num)
                    printf(",");
                break;
            }
            current = current->next;
        }
    }
    return;
}

static void get_meetings(char **tab, employee_t *current, meeting_t **meet, employee_t **emp)
{
    meeting_t *meetings = *meet;

    while (meetings) {
        for (int i = 0; i <= meetings->emp_num; i++) {
            if (meetings->emp_ids[i] == current->ID) {
                printf("meetings on %s, %s, with", meetings->day, meetings->zipcode);
                get_colleagues(meetings, current->ID, emp);
                putchar('\n');
            }
        }
        meetings = meetings->next;
    }
    return;
}

static void sort_by_name(char **tab, employee_t **emp, meeting_t **meet)
{
    employee_t *current;

    for (int i = 3; tab[i]; i++) {
        current = *emp;
        while (current) {
            if (atoi(tab[i]) == current->ID) {
                printf("******************************\n");
                printf("%s %s\n", current->first_name, current->last_name);
                printf("position: %s\n", current->position);
                printf("city: %s\n", current->zipcode);
                get_meetings(tab, current, meet, emp);
            }
            current = current->next;
        }
    }
    return;
}
