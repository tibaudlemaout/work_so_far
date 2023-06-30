/*
** EPITECH PROJECT, 2022
** EPITECH
** File description:
** struct
*/

#ifndef STRUCT_H_
    #define STRUCT_H_

    typedef struct TAB{
        char ** copy;
        int y_pos;
        int x_pos;
    } TAB_T;

    typedef struct GLOBAL{
        TAB_T c_tab;
        char **gen_map;
        int r_x;
        int r_y;
        int layers;
        int columns;
        int check_value;
        int max_check_value;
    } GLOBAL_T;

#endif /* !STRUCT_H_ */
