/*
** EPITECH PROJECT, 2023
** B-SYN-200-NAN-2-1-palindrome-tibaud.le-maout
** File description:
** display_h
*/
#include "../include/palindrome.h"

void display_h(void)
{
    printf("USAGE\n");
    printf("      ./palindrome -n number -p palindrome [-b base] [-imin i] ");
    printf("[-imax i]\n\n");
    printf("DESCRIPTION\n");
    printf("      -n n      integer to be transformed (>=0)\n");
    printf("      -p pal    palindromic number to be obtained (incompatible ");
    printf("with the -n\n                option) (>=0)\n                if ");
    printf("defined, all fitting values of n will be output\n");
    printf("      -b base   base in which the procedure will be executed ");
    printf("(1<b<=10) [def: 10]\n");
    printf("      -imin i   minimum number of iterations, included (>=0)");
    printf(" [def: 0]\n");
    printf("      -imax i   maximum number of iterations, included (>=0)");
    printf(" [def: 100]\n");
    exit(0);
}
