/*
** EPITECH PROJECT, 2023
** EPITECH
** File description:
** struct
*/

#ifndef STRUCT_H_
    #define STRUCT_H_

    typedef struct global{
        char **tab;
        char **dead_end;
        int length;
        int layers;
        int cross_pos_x;
        int cross_pos_y;
        int pos_x;
        int pos_y;
        int stuck;
    } global_t;

#endif /* !STRUCT_H_ */
