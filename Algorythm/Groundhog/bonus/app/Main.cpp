/*
** EPITECH PROJECT, 2024
** Semester_3
** File description:
** Main
*/
#include "include/Groundhog.hpp"

void Groundhog::get_lowest(void)
{
    std::vector<double> tmp;

    for (int i = 0; i < (_values.size() - 1); i++) {
        tmp.push_back(_values[i]);
    }
    std::sort(tmp.begin(), tmp.end());
    _lowest = tmp[0];
    std::cout << "lowest = " << _lowest << std::endl;
}

void Groundhog::get_highest(void)
{
    std::vector<double> tmp;

    for (int i = 0; i < _values.size(); i++) {
        tmp.push_back(_values[i]);
    }
    std::sort(tmp.begin(), tmp.end());
    _highest = tmp[tmp.size() - 1];
    std::cout << "highest = " << _highest << std::endl;
}

void Groundhog::find_outliers(void)
{
    std::vector<double> outliers;

    for (int i = 0; i < _values.size(); i++) {
        if (_values[i] < (_mean - _s_dev) || _values[i] > (_mean + _s_dev))
            outliers.push_back(_values[i]);
    }
    for (const auto& v : outliers)
        std::cout << v << " is an outlier, (+/- standard deviation)" << std::endl;
    return;
}

void Groundhog::find_jump(void)
{
    std::vector<int> jumps;

    for (int i = 0; i < (_values.size() - 1); i++) {
        if (_values[i] > (_values[i + 1] + _s_dev) || _values[i] < (_values[i + 1] - _s_dev))
            jumps.push_back(i);
    }
    for (int i = 0; i < _values.size(); i++) {
        for (int j = 0; j < jumps.size(); j++) {
            if (jumps[j] == i )
                std::cout << "a jump occurs at [" << i << "] between " << _values[i] << " and " << _values[i + 1] << std::endl; 
        }
    }
    return;
}

void Groundhog::segment_data(void)
{
    return;
}

int main(int argc, char **argv)
{
    if (argc != 2)
        exit(84);
    else {
        Groundhog hog(argc, argv);
        hog.main_loop();
    }
    return (0);
}
