/*
** EPITECH PROJECT, 2023
** B-SYN-200-NAN-2-1-palindrome-tibaud.le-maout
** File description:
** test
*/
#include "../include/palindrome.h"
#include <criterion/criterion.h>
#include <criterion/redirect.h>

void redirect_all_std(void)
{
    cr_redirect_stdout();
    cr_redirect_stderr();
}

Test(test1, exemple_1, .init = redirect_all_std)
{
}

