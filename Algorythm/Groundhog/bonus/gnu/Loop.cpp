/*
** EPITECH PROJECT, 2024
** B-CNA-410-NAN-4-1-groundhog-thomas.cluseau
** File description:
** Loop
*/

#include "include/Groundhog.hpp"

void Groundhog::result_display(void)
{
    if ((_prev_evo < 0 && _evo > 0) || (_prev_evo > 0 && _evo < 0)) {
        _switch ++;
        std::cout << std::setprecision(3) << "g=" << _temp;
        std::cout << std::setprecision(2) << "\t\tr=" << _evo;
        std::cout << std::setprecision(3) << "%\t\ts=" << _s_dev << "\t\ta switch occurs" <<std::endl;
    } else {
        std::cout << std::setprecision(3) << "g=" << _temp;
        std::cout << std::setprecision(2) << "\t\tr=" << _evo;
        std::cout << std::setprecision(3) << "%\t\ts=" << _s_dev << std::endl;
    }
}

int Groundhog::main_loop(void)
{
    std::string tmp;

    while (tmp != "STOP") {
        std::cin >> tmp;
        _lines.push_back(tmp);
        _values.push_back(std::atof(tmp.c_str()));
        _prev_evo = _evo;
        calc_average();
        standard_deviation();
        calc_temp_inc_avg();
        calc_relative_temp_evo();
        result_display();
    }
    std::cout << "Global tendency switched " << _switch << "times" << std::endl;
    find_weird_value();
    writeDataToFile(_values, "./plotfile");
    return (0);
}