/*
** EPITECH PROJECT, 2024
** B-CNA-410-NAN-4-1-groundhog-thomas.cluseau
** File description:
** Loop
*/

#include "include/Groundhog.hpp"
#include "include/App.hpp"
#include <iomanip>
#include <SFML/Graphics.hpp>

void Groundhog::FillSwitch(void)
{
    _sd_values.push_back(_s_dev);
    _temp_values.push_back(_temp);
    _evo_values.push_back(_evo);
    if (_sd_values.size() > _period)
        _sd_values.erase(_sd_values.begin());
    if (_temp_values.size() > _period)
        _temp_values.erase(_temp_values.begin());
    if (_evo_values.size() > _period)
        _evo_values.erase(_evo_values.begin());
}

bool Groundhog::FindSwitch(void)
{
    double sd_avg = 0;
    double temp_avg = 0;
    double evo_avg = 0;
    double sd_var = 0;
    double temp_var = 0;
    double evo_var = 0;
    double sd_diff = 0;
    double temp_diff = 0;
    double evo_diff = 0;
    double tmp_sd = _s_dev;
    double tmp_temp = _temp;
    double tmp_evo = _evo;

    if (_values.size() <= _period)
        return (false);
    FillSwitch();
    sd_avg = StandardDeviationMean();
    temp_avg = TempMean();
    evo_avg = EvoMean();
    sd_var = sd_avg * 0.70;
    temp_var = temp_avg * 0.70;
    evo_var = evo_avg * 0.70;
    if (sd_var < 0)
        sd_var *= -1;
    if (temp_var < 0)
        temp_var *= -1;
    if (evo_var < 0)
        evo_var *= -1;
    if (tmp_sd > sd_avg)
        sd_diff = tmp_sd - sd_avg;
    else
        sd_diff = sd_avg - tmp_sd;
    if (tmp_temp > temp_avg)
        temp_diff = tmp_temp - temp_avg;
    else
        temp_diff = temp_avg - tmp_temp;
    if (tmp_evo > evo_avg)
        evo_diff = tmp_evo - evo_avg;
    else
        evo_diff = evo_avg - tmp_evo;
    if (sd_diff < 0)
        sd_diff *= -1;
    if (temp_diff < 0)
        temp_diff *= -1;
    if (evo_diff < 0)
        evo_diff *= -1;
    if (sd_diff > sd_var && TimeSinceSwitch() == true){
        _switches.push_back(1);
        return (true);
    }
    if (temp_diff > temp_var && TimeSinceSwitch() == true) {
        _switches.push_back(1);
        return (true);
    }
    if (evo_diff > evo_var && TimeSinceSwitch() == true) {
        _switches.push_back(1);
        return (true);
    }
    _switches.push_back(0);
    return (false);
}

static bool is_first_period_done(size_t cmp, int period, double s)
{
    if (cmp <= period) {
        std::cout << "g=nan\t\tr=nan%";
        if (cmp < period)
            std::cout << "\t\ts=nan" << std::endl;
        else
            std::cout << std::setprecision(3) << "\t\ts=" << s << std::endl;
        return false;
    }
    return true;
}

void Groundhog::result_display(size_t cmp)
{
    if (!is_first_period_done(cmp, (_period - 1), _s_dev))
        return;
    if (_temp < 1)
        std::cout << std::fixed << std::setprecision(2) << "g=" << _temp;
    else
        std::cout << std::fixed << std::setprecision(2) << "g=" << _temp;
    std::cout << std::fixed << std::setprecision(0) << "\t\tr=" << _evo;
    if (FindSwitch() == true) {
        _switch ++;
        std::cout << std::fixed << std::setprecision(2) << "%\t\ts=" << _s_dev << "\t\ta switch occurs" << std::endl;
    } else {
        std::cout << std::fixed << std::setprecision(2) << "%\t\ts=" << _s_dev << std::endl;
    }
}

int Groundhog::main_loop(void)
{
    App app;
    std::string tmp;
    size_t cmp = 0;

    app.init_tab(_period);
    while (app.window.isOpen()) {
        app.events_handler(_period);
        app.draw(_period);
        
        if (app.user_input) {
            std::ostringstream oss;
            oss << std::fixed << std::setprecision(1) << app.inputStr;
            std::string actualTmp = oss.str();
            size_t dotPosition = actualTmp.find('.');

            if (dotPosition == std::string::npos) {
                actualTmp += ".0";
            } else {
                if (actualTmp.find('.', dotPosition + 1) != std::string::npos)
                    actualTmp.erase(actualTmp.find('.', dotPosition + 1), 1);
            }
            app.actualTemp.setString(actualTmp);
            std::cout << actualTmp << std::endl;
            _lines.push_back(app.inputStr);
            _values.push_back(std::atof(app.inputStr.c_str()));
            _prev_evo = _evo;
            calc_average();
            double s = standard_deviation();
            double g = calc_temp_inc_avg();
            double r = calc_relative_temp_evo();
            result_display(cmp);
            double temp = std::atof(app.inputStr.c_str());
            app.update_background(temp);
            // app.tab.push_back(_values);
            std::vector<double> var;
            var.push_back(g);
            var.push_back(r);
            var.push_back(s);
            app.tab.push_back(var);
            cmp++;
            app.user_input = false;
            app.inputStr.clear();
        }

        app.draw(_period);
    }
    std::cout << "Global tendency switched " << _switch << " times" << std::endl;
    find_weird_value();
    return (0);
}