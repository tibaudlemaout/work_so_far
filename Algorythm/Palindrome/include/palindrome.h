/*
** EPITECH PROJECT, 2023
** Synthesis
** File description:
** sbml
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

#ifndef PALINDROME_H_
    #define PALINDROME_H_

int is_palindrome(global_t *data);
int my_factrec_synthesis(int nb);
int my_squareroot_synthesis(int nb);
void search_for_all_palindromes(global_t *data);
int error_handling(int argc, char **argv, global_t *data);
int get_revbase_nb(int nb, int base);
void decimal_conv(global_t *data);
void display_h(void);

#endif /* !PALINDROME_H_ */
