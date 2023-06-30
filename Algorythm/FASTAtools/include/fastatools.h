/*
** EPITECH PROJECT, 2023
** base_layout
** File description:
** fastatools
*/
#include <stdarg.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>
#include <strings.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <fcntl.h>
#include "struct.h"

#ifndef FASTATOOLS_H_
    #define FASTATOOLS_H_

char *my_strcapitalize_synthesis(char *str);
int error_handling(global_t *data, int argc, char **argv);
void get_input(global_t *data);
void clean_sequence_name(char *str, global_t *data);
void bubble_sort_strings(char **arr, int size);
void option_1(global_t *data);
void option_2(global_t *data);
void option_3(global_t *data);
char *rev_str(char *str);
void option_4(global_t *data);
int find_k_mers(char *tab, global_t *data, int size);
void option_5(global_t *data);
int get_sequence(char *tab, global_t *data, int size);
char *get_rna(char *rna, global_t *data);
void sort_sequence(global_t *data);
void option_6(global_t *data);
void get_amino_acid(global_t *data, int count);
char identify_acid(char a, char b, char c);
void option_7(global_t *data);

#endif /* !FASTATOOLS_H_ */
