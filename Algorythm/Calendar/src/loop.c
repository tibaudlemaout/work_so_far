/*
** EPITECH PROJECT, 2023
** B-SYN-200-NAN-2-1-calendar-tibaud.le-maout
** File description:
** loop
*/
#include "../include/calendar.h"

static char **sort_input(char *buff)
{
    char **tab = NULL;
    char *c_buff = strdup(buff);
    char *token = strtok(c_buff, " \n");
    int count = 1;

    while (token) {
        count++;
        tab = realloc(tab, sizeof(char *) * (count));
        tab[count - 1] = strdup(token);
        token = strtok(NULL, " \n");
    }
    tab[count] = NULL;
    return (tab);
}

static int choose_option_cont(char **tab, employee_t **emp, meeting_t **meet)
{
    if (strcmp(tab[1], "info_employees") == 0) {
        info_employee(tab, emp, meet);
    }
    if (strcmp(tab[1], "info_meetings") == 0) {
        info_meeting(tab, emp, meet);
    }
    return (0);
}

static int choose_option(char **tab, employee_t **emp, meeting_t **meet)
{
    if (strcmp(tab[1], "new_employee") == 0) {
        set_new_employee(tab, emp, meet);
    }
    if (strcmp(tab[1], "new_meeting") == 0) {
        set_new_meeting(tab, emp, meet);
    }
    if (strcmp(tab[1], "invite") == 0) {
        set_invite(tab, emp, meet);
    }
    if (strcmp(tab[1], "exclude") == 0) {
        set_exclude(tab, emp, meet);
    }
    if (strcmp(tab[1], "cancel") == 0) {
        set_cancel(tab, emp, meet);
    }
    if (strcmp(tab[1], "fire") == 0) {
        set_fire(tab, emp, meet);
    }
    choose_option_cont(tab, emp, meet);
    return (0);
}

static void display_all(employee_t **emp, meeting_t **meet)
{
    employee_t *current = *emp;
    meeting_t *now = *meet;

    while (current) {
        printf("firstname = %s\n", current->first_name);
        printf("lastname = %s\n", current->last_name);
        printf("position = %s\n", current->position);
        printf("zipcode = %s\n", current->zipcode);
        printf("ID = %i\n", current->ID);
        current = current->next;
    }
    while (now) {
        printf("zipcode = %s\n", now->zipcode);
        printf("day = %s\n", now->day);
        printf("ID = %i\n", now->ID);
        for (int i = 0; i < now->emp_num; i++)
            printf("emp_id = %i\n", now->emp_ids[i]);
        now = now->next;
    }
    return;
}

int start_loop(void)
{
    employee_t *emp;
    meeting_t *meet;
    char *buff = NULL;
    size_t size = 0;
    char **tab = NULL;

    while (getline(&buff, &size, stdin) != -1) {
        tab = sort_input(buff);
        if (strcmp(tab[1], "END") == 0)
            break;
        if (tab)
            choose_option(tab, &emp, &meet);
    }
    for (int i = 1; tab[i]; i++)
        free(tab[i]);
    free(tab);
    if (buff)
        free(buff);
    return (0);
}
