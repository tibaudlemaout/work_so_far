/*
** EPITECH PROJECT, 2024
** B-CNA-410-NAN-4-1-groundhog-thomas.cluseau
** File description:
** Switch
*/
#include "include/Groundhog.hpp"

double Groundhog::TempMean(void)
{
    double total = 0;
    int amount = 0;

    for (size_t i = 0; i < _temp_values.size(); i++) {
        total += _temp_values[i];
        amount++;
    }
    return (total / amount);
}

double Groundhog::EvoMean(void)
{
    double total = 0;
    int amount = 0;

    for (size_t i = 0; i < _evo_values.size(); i++) {
        total += _evo_values[i];
        amount++;
    }
    return (total / amount);
}

double Groundhog::StandardDeviationMean(void)
{
    double total = 0;
    int amount = 0;

    for (size_t i = 0; i < _sd_values.size(); i++) {
        total += _sd_values[i];
        amount++;
    }
    return (total / amount);
}

bool Groundhog::TimeSinceSwitch(void)
{
    auto it = std::find(_switches.rbegin(), _switches.rend(), 1);
    if (it == _switches.rend())
        return (true);
    size_t recentIdx = _switches.size() - std::distance(_switches.rbegin(), it) - 1;
    size_t timeSinceLastSwitch = _switches.size() - recentIdx;
    if (timeSinceLastSwitch > _period)
        return (true);
    else
        return (false);
}
