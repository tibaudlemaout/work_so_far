/*
** EPITECH PROJECT, 2024
** B-CNA-410-NAN-4-1-groundhog-thomas.cluseau
** File description:
** WeirdValues
*/

#include "include/Groundhog.hpp"

void Groundhog::find_weird_value(void)
{
    std::vector<std::pair<double, double>> absolute_differences;
    size_t num_values = 0;

    if (_values.size() < 5) {
        std::cout << "not enough values for weird values" << std::endl;
        return;
    }
    for (double value : _values) {
        double difference = std::abs(value - _mean);
        absolute_differences.push_back(std::make_pair(difference, value));
    }
    std::cout << std::fixed << std::setprecision(1);
    std::cout << "5 weirdest values are [";
    num_values = std::min<size_t>(5, absolute_differences.size());
    for (size_t i = 0; i < num_values - 1; i++)
        std::cout << absolute_differences[i].second << ", ";
    if (absolute_differences.size() > 4)
        std::cout << absolute_differences[4].second << "]" << std::endl;
    return;
}
