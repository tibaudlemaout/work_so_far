/*
** EPITECH PROJECT, 2024
** Semester_3
** File description:
** MeanDevMedian
*/

#include "include/Groundhog.hpp"

void Groundhog::calc_average(void)
{
    double total = 0;
    int amount = 0;

    for (size_t i = _values.size() - _period; i < _values.size(); i++) {
        total += _values[i];
        amount++;
    }
    _mean = total / amount;
    return;
}

void Groundhog::standard_deviation(void)
{
    double deviation = 0;
    int amount = 0;
    _prev_dev = _s_dev;

    if (_values.size() < _period)
        return;
    for (size_t i = _values.size() - _period; i < _values.size(); i++) {
        deviation += pow((_values[i] - _mean), 2);
        amount++;
    }
    deviation /= amount;
    _s_dev = sqrt(deviation);
    return;
}

void Groundhog::calc_median(void)
{
    std::vector<double> tmp;
    int length = 0;

    for (int i = 0; i < _values.size(); i++) {
        tmp.push_back(_values[i]);
    }
    length = tmp.size();
    if (length % 2 == 0) {
        length /= 2;
        _median = (tmp[length] + tmp[length + 1]) / 2;
    } else {
        length /= 2;
        _median = tmp[length];
    }
    return;
}
