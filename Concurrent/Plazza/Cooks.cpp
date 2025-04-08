/*
** EPITECH PROJECT, 2024
** B-CCP-400-NAN-4-1-theplazza-tibaud-le.maout
** File description:
** Cooks
*/
#include "include/Kit.hpp"

Cooks::Cooks(Kitchen *restaurant)
{
    kitchen = restaurant;
    state = 0;
    type = -1;
    step = -1;
    return;
}

void Cooks::display_order(void)
{
    if (state == Sleeping) {
        std::cout << "Waiting";
    } else {
        int remain = kitchen->get_pizza_mult(type) - step;
        std::cout << "Cooking a " << PizzaNames[type - 1].first << ", Remain=" << remain << "s, Elapsed=" << step << "s";
    }
    return;
}

void Cooks::assign_work(int _type)
{
    type = _type;
    state = Cooking;
    step = 0;
    return;
}

void Cooks::next_step(void)
{
    step++;
    return;
}

void Cooks::cook_ready(int mult)
{
    kitchen->pizza_ready(type);
    step = 0;
    type = -1;
    state = 0;
    return;
}
