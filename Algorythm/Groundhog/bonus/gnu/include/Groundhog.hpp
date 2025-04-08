/*
** EPITECH PROJECT, 2024
** Semester_3
** File description:
** Groundhog
*/

#ifndef GROUNDHOG_HPP_
    #define GROUNDHOG_HPP_
#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
#include <string>
#include <cmath>
#include <algorithm>

class Groundhog {
    public:
        Groundhog(int argc, char **argv);
        ~Groundhog();

        void calc_average(void);
        void standard_deviation(void);
        void start_finish(void);
        void calc_median(void);
        void get_highest(void);
        void get_lowest(void);
        void find_outliers(void);
        void find_jump(void);
        void segment_data(void);
        int main_loop(void);
        void calc_temp_inc_avg(void);
        void calc_relative_temp_evo(void);
        void find_weird_value(void);
        void result_display(void);

    protected:
    private:
        double _mean;
        double _median;
        double _lowest;
        double _highest;
        double _s_dev;
        double _temp;
        int _period;
        double _prev_evo;
        double _evo;
        int _switch;
        std::vector<std::string> _lines;
        std::vector<double> _values;
};

void writeDataToFile(const std::vector<double>& data, const std::string& filename);

#endif /* !GROUNDHOG_HPP_ */
