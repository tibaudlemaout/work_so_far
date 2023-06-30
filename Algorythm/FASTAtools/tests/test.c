/*
** EPITECH PROJECT, 2023
** B-SYN-200-NAN-2-1-FASTAtools-tibaud.le-maout
** File description:
** test
*/
#include "../include/fastatools.h"
#include "criterion/criterion.h"
#include "criterion/redirect.h"

void redirect_all_std(void)
{
    cr_redirect_stdout();
    cr_redirect_stderr();
}

Test(my_strcapitalize_synthesis, Test01, .init = redirect_all_std)
{
    char str[] = "hello world";

    my_strcapitalize_synthesis(str);
    cr_assert_stdout_eq_str("Hello World");
}