/*
** EPITECH PROJECT, 2023
** B-SYN-200-NAN-2-1-calendar-tibaud.le-maout
** File description:
** calendar
*/
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include "struct.h"

#ifndef CALENDAR_H_
    #define CALENDAR_H_

int error_handling(int argc, char **argv);
int start_loop(void);
int get_tab_layers(char **tab);
int set_new_employee(char **tab, employee_t **emp, meeting_t **meet);
int set_fire(char **tab, employee_t **emp, meeting_t **meet);
int set_invite(char **tab, employee_t **emp, meeting_t **meet);
int set_new_meeting(char **tab, employee_t **emp, meeting_t **meet);
int set_cancel(char **tab, employee_t **emp, meeting_t **meet);
int set_exclude(char **tab, employee_t **emp, meeting_t **meet);
int info_employee(char **tab, employee_t **emp, meeting_t **meet);
int info_meeting(char **tab, employee_t **emp, meeting_t **meet);
void sort_by_date(char **tab, employee_t **emp, meeting_t **meet);
int compare_by_date(const void *a, const void *b);
int compare_by_location(const void *a, const void *b);
int compare_by_id(const void *a, const void *b);
int compare_employees_by_name(const void *a, const void *b);
void sort_meeting_list_by_date(meeting_t **meet);
void sort_meeting_list_by_location(meeting_t **meet);
void sort_meeting_list_by_id(meeting_t **meet);
employee_t *get_employee_by_id(employee_t *emp, int id);
void sort_employee_array_by_name(employee_t **employees, int count);
void sort_emp_list_by_forename(employee_t **emp);
void sort_emp_list_by_id(employee_t **emp);
void sort_emp_list_by_name(employee_t **emp);
void sort_emp_list_by_zip(employee_t **emp);
void sort_emp_list_by_job(employee_t **emp);
int compare_by_id_emp(const void *a, const void *b);
int compare_by_location_emp(const void *a, const void *b);
int compare_by_name_emp(const void *a, const void *b);
int compare_by_forename_emp(const void *a, const void *b);
int compare_by_job_emp(const void *a, const void *b);

#endif /* !CALENDAR_H_ */
