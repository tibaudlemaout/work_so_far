/*
** EPITECH PROJECT, 2024
** ee
** File description:
** gui_string_manip
*/

/**
 * @file gui_string_manip.c
 * @brief Some functions for string manipulation
*/

#include <stdbool.h>
#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>

/**
 * @brief Function that assure if a string is only made of letters
 * @param str the string to be analyzed
*/
static bool is_char_present(char *str)
{
    if (!isalpha(str[0]) || !isalpha(str[1]) ||
        !isalpha(str[2]) || str[3] != ' ') {
            return false;
    }
    return true;
}

/**
 * @brief function that returns the first number of a given string (specific)
 * @param str the string on which is based the analysis
 * @param val1 pointer to an int
 * @param p char *to be found in
 * @param end end placement
 * @return if the first number is found or not
*/
static bool get_first_number(char *str, int *val1, char **p, char *end)
{
    *val1 = strtol(*p, &end, 10);
    if (*p == end) {
        return false;
    }
    *p = end;
    return true;
}

/**
 * @brief Function that gets the second number of a string (specific)
 * @param str the string on which is based the analysis
 * @param val2 pointer to an int
 * @param p char *to be found in
 * @param end end placement
 * @return if the second number is found or not
*/
static bool get_second_number(char *str, int *val2, char **p, char *end)
{
    if (**p == '\n' || **p == '\0') {
        *val2 = 0;
        return true;
    }
    *val2 = strtol(*p, &end, 10);
    if (*p == end) {
        return false;
    }
    *p = end;
    if (**p == '\n' || **p == '\0') {
        return true;
    }
    return false;
}

/**
 * @brief Function that gets the two values in a char*
 * @param str the string on which is based the analysis
 * @param val1 pointer to the first int
 * @param val2 pointer to the second int
 * @return if the numbers are found or not
*/
bool gui_str_two_values_getter(char *str, int *val1, int *val2)
{
    char *p = str + 3;
    char *end;

    while (*p == ' ') {
        p++;
    }
    if (!is_char_present(str))
        return false;
    if (!get_first_number(str, val1, &p, end))
        return false;
    while (*p == ' ') {
        p++;
    }
    if (!get_second_number(str, val2, &p, end))
        return false;
    return true;
}

/**
 * @brief Function that gets values in a string
 * @param str the string to be analyzed
 * @param val an int for the val
 * @return if it is found or not
*/
bool gui_str_value_getter(char *str, int *val)
{
    char *p = str + 3;
    char *end;

    while (*p == ' ') {
        p++;
    }
    if (!is_char_present(str))
        return false;
    if (*p == '#') {
        p++;
    } else {
        return false;
    }
    if (!get_first_number(str, val, &p, end))
        return false;
    if (*p == '\n' || *p == '\0')
        return true;
    return false;
}
