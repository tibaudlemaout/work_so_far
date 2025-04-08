/*
** EPITECH PROJECT, 2024
** B-CCP-400-NAN-4-1-theplazza-tibaud-le.maout
** File description:
** Kitchen 
*/
#include <unistd.h>
#include <iostream>
#include <chrono>
#include <thread>
#include <vector>
#include "include/Kit.hpp"

Kitchen::Kitchen(Pizzeria *pizze)
{
    active = 0;
    pizzeria = pizze;
    state = Waiting;
    stock = new Ingredient();
}

Kitchen::~Kitchen(void)
{
    for (int i = 0; i < cooks.size(); i++) {
        if (cooks[i])
            free(cooks[i]);
    }
    cooks.clear();
    if (stock)
        free(stock);
}

void Kitchen::prepare_cooks(void)
{
    for (int i = 0; i < pizzeria->cooks; i++)
        cooks.push_back(new Cooks(this));
}

static void *task(void *restaurant)
{
    Kitchen *kitchen = (Kitchen *)restaurant;
    int stepRefresh = 0;
    int stepCook = 0;

    while (kitchen->running) {
        // Pizzas queue
        if (!kitchen->pizzasToCook.empty() && kitchen->pizzasToCook.at(0).second <= 0)
            kitchen->pizzasToCook.erase(kitchen->pizzasToCook.begin());
        if (!kitchen->pizzasToCook.empty() && kitchen->pizzasToCook.at(0).second > 0)
            kitchen->assign_if_empty();
        // Wait
        usleep(10000);
        stepCook += 10;
        stepRefresh += 10;
        // Manage time for pizzas ingredient
        if (kitchen->pizzeria->refresh <= stepRefresh) {
            kitchen->refresh_ingredients();
            stepRefresh = 0;
        }
        // Manage time for pizzas cook, step each 1s
        if (stepCook >= 1000) {
            if (kitchen->check_step())
                kitchen->active = 0;
            else if (kitchen->active <= 5)
                kitchen->active++;
            else
                kitchen->running = false;
                stepCook = 0;
        }
    }
    return (NULL);
}

order_t Kitchen::prepare_order(order_t order)
{
    std::pair<int, int> pair;
    int possiblePizzas = pizzeria->cooks * 2;

    for (int i = 0; i < 4 && possiblePizzas; i++) {
        if (!order.pizzaLeft[i].second)
            continue;
        if (possiblePizzas && possiblePizzas >= order.pizzaLeft[i].second) {
            pair = { order.pizzaLeft[i].first, order.pizzaLeft[i].second };
            possiblePizzas -= order.pizzaLeft[i].second;
            order.pizzaLeft[i].second -= order.pizzaLeft[i].second;
            pizzasToCook.insert(pizzasToCook.begin(), pair);
        } else if (possiblePizzas) {
            pair = { order.pizzaLeft[i].first, possiblePizzas };
            order.pizzaLeft[i].second -= possiblePizzas;
            possiblePizzas = 0;
            pizzasToCook.insert(pizzasToCook.begin(), pair);
        }
    }
    return (order);
}

void Kitchen::start_work(void)
{
    prepare_cooks();
    running = true;
    pthread_create(&this->thread, NULL, task, (void *)this);
    pthread_detach(this->thread);
    return;
}

void Kitchen::stop_work(void)
{
    running = false;
    return;
}

void Kitchen::assign_if_empty(void)
{
    if (!cooks.size())
        return;
    for (int i = 0; i < cooks.size() && pizzasToCook.size() && pizzasToCook.at(0).second; i++) {
        if (cooks[i]->state)
            continue;
        if (!stock->available_for_pizza(pizzasToCook.at(0).first))
            continue;
        pizzasToCook.at(0).second--;
        stock->get_stock_for_pizza(pizzasToCook.at(0).first);
        cooks[i]->assign_work(pizzasToCook.at(0).first);
    }
}

void Kitchen::refresh_ingredients(void)
{
    stock->update_ingredient();
}

int Kitchen::get_pizza_mult(int type)
{
    for (int i = 0; i < 4; i++) {
        if (type == PizzaRecipeList[i].Type)
            return (PizzaRecipeList[i].Time);
    }
    return (1);
}

void Kitchen::pizza_ready(int type)
{
    pizzasCoooked_mutex.lock();
    if (!pizzasCooked.empty() && pizzasCooked.at(0).first == type)
        pizzasCooked.at(0).second++;
    else
        pizzasCooked.insert(pizzasCooked.begin(), { type - 1, 1 } );
    pizzasCoooked_mutex.unlock();
}

bool Kitchen::check_step(void)
{
    int needSteps;
    bool doing = false;

    if (!cooks.size()) {
        active++;
        return (false);
    }
    for (int i = 0; i < cooks.size(); i++) {
        if (!cooks[i]->state)
            continue;
        doing = true;
        needSteps = pizzeria->multiplier * get_pizza_mult(cooks[i]->type);
        cooks[i]->next_step();
        if (cooks[i]->step == needSteps) {
            std::cout << "Cooks #" << i << " baked pizza " << cooks[i]->type << " in " << cooks[i]->step << " step(s)." << std::endl;
            cooks[i]->cook_ready(needSteps);
        }
    }
    return (doing);
}

void Kitchen::display_cooks(void)
{
    std::cout << "\tPizza queue:";
    for (int i = 0; i < pizzasToCook.size(); i++) {
        std::cout << "\n\t";
        std::cout << PizzaNames[pizzasToCook[i].first - 1].first;
        std::cout << " units=" << PizzaNames[pizzasToCook[i].first - 1].second;
    }
    std::cout << std::endl;
    std::cout << "\tCooks (#=" << cooks.size() << "):";
    for (int i = 0; i < cooks.size(); i++) {
        std::cout << "\n\t\tCook #" << i;
        cooks[i]->display_order();
    }
    std::cout << std::endl;
    return;
}
