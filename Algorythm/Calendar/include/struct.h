/*
** EPITECH PROJECT, 2023
** B-SYN-200-NAN-2-1-calendar-tibaud.le-maout
** File description:
** struct
*/

#ifndef STRUCT_H_
    #define STRUCT_H_

    typedef struct employee {
        int ID;
        char *last_name;
        char *first_name;
        char *position;
        char *zipcode;
        struct employee *next;
    } employee_t;

    typedef struct meeting {
        int ID;
        char *day;
        char *zipcode;
        int emp_num;
        int *emp_ids;
        struct meeting *next;
    } meeting_t;

#endif /* !STRUCT_H_ */
