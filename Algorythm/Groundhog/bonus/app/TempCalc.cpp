/*
** EPITECH PROJECT, 2024
** B-CNA-410-NAN-4-1-groundhog-thomas.cluseau
** File description:
** TempCalc
*/

#include "include/Groundhog.hpp"

double Groundhog::calc_temp_inc_avg(void) 
{
    double sum_increase = 0.0;
    int count_increase = 0;
    double increase = 0;
    _prev_temp = _temp;

    if (_values.size() <= _period)
        return 0.0;
    for (size_t i = _values.size() - _period; i < _values.size(); ++i) {
        increase = _values[i] - _values[i - 1];
        if (increase > 0) {
            sum_increase += increase;
        }
        count_increase ++;
    }
    _temp = sum_increase / count_increase;
    return _temp;
}

double Groundhog::calc_relative_temp_evo(void)
{
    if (_values.size() <= _period)
        return 0.0;
    double current_temp = _values.back();
    double previous_temp = _values[_values.size() - _period - 1];

    _evo = ((current_temp - previous_temp) / previous_temp) * 100;
    return _evo;
}
