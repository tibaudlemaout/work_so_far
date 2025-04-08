/*
** EPITECH PROJECT, 2024
** Semester_3
** File description:
** ConstDestr
*/

#include "include/Groundhog.hpp"

Groundhog::Groundhog(int argc, char **argv)
{
    _period = atoi(argv[1]);
    _evo = 0;
    _s_dev = 0;
    _temp = 0;
    _switch = 0;

    return;
}

Groundhog::~Groundhog()
{
    return;
}
