/*
** EPITECH PROJECT, 2024
** B-CCP-400-NAN-4-1-theplazza-tibaud-le.maout
** File description:
** receptionist
*/
#include <thread>
#include <iostream>
#include <vector>
#include <fstream>
#include <ctime>
#include "include/Kit.hpp"

Pizzeria::Pizzeria(int _multiplier, int _cooks, int _refresh)
{
    // Constructor initialization
    multiplier = _multiplier;
    cooks = _cooks;
    refresh = _refresh;
    return;
}

Pizzeria::~Pizzeria(void)
{
    // Destroying kitchens and clearing tasks
    while (!kitchens.empty()) {
        if (!kitchens.at(0))
            break;
        delete kitchens.at(0);
        kitchens.erase(kitchens.begin());
    }
    tasks.clear();
    multiplier = 0;
    cooks = 0;
    refresh = 0;
    pthread_cancel(thread);
    return;
}

// Method to load orders
void Pizzeria::load_orders(std::stack<pizzaOrder_t> orders)
{
    order_t order;
    int oldLen = tasks.size();

    // Initializing order struct
    order.pizzaToCook = { { Regina, 0 }, { Margarita, 0 },
                        { Americana, 0 }, { Fantasia, 0 } };
    order.pizzaLeft = { { Regina, 0 }, { Margarita, 0 },
                        { Americana, 0 }, { Fantasia, 0 } };
    order.pizzaCooked = { { Regina, 0 }, { Margarita, 0 },
                        { Americana, 0 }, { Fantasia, 0 } };
    order.details = orders;

    // Updating order details
    while (!orders.empty()) {
        order.pizzaLeft[orders.top().type - 1].second += orders.top().quantity;
        order.pizzaToCook[orders.top().type - 1].second += orders.top().quantity;
        orders.pop();
    }
    tasks.push_back(order);
    return;
}

// Method to delete the current order
void Pizzeria::delete_current_order(void)
{
    if (tasks.empty())
        return;

    std::cout << "An order is ready:" << std::endl;
    // Displaying order details
    while (!tasks[0].details.empty()) {
        std::cout << "\t" << PizzaNames[tasks[0].details.top().type - 1].first << " x"
            << tasks[0].details.top().quantity << " Size = "
            << SizeNames[tasks[0].details.top().size - 1].first << std::endl;
        tasks[0].details.pop();
    }
    // Deleting the completed order
    tasks.erase(tasks.begin());
}

// Method to update order status
void Pizzeria::update_order(void)
{
    if (kitchens.empty())
        return;
    for (int i = 0; i < kitchens.size(); i++) {
        kitchens.at(i)->pizzasCoooked_mutex.lock();
        // Updating cooked pizzas
        while (!kitchens.at(i)->pizzasCooked.empty()) {
            std::pair<int, int> pair = kitchens.at(i)->pizzasCooked.at(0);
            tasks[0].pizzaCooked[pair.first].second += pair.second;
            kitchens.at(i)->pizzasCooked.erase(kitchens.at(i)->pizzasCooked.begin());
        }
        kitchens.at(i)->pizzasCoooked_mutex.unlock();
    }
    return;
}

// Check if an order is empty
static bool order_empty(order_t order)
{
    bool empty = false;
    for (int i = 0; i < 4; i++)
        if (!order.pizzaLeft[i].second)
            empty = true;
        else
            return (false);
    return (empty);
}

// Prepare kitchens for an order
order_t prepare_kitchens(Pizzeria *pizzeria, order_t order)
{
    for (int i = 0; i < pizzeria->kitchens.size(); i++)
        order = pizzeria->kitchens[i]->prepare_order(order);
    if (order_empty(order))
        return (order);
    while (!order_empty(order)) {
        Kitchen *restaurant = new Kitchen(pizzeria);
        order = restaurant->prepare_order(order);
        pizzeria->kitchens.push_back(restaurant);
        restaurant->start_work();
    }
    return (order);
}

// Check if an order is ready
bool Pizzeria::order_ready(void)
{
    if (!tasks.size())
        return (false);
    for (int i = 0; i < 4; i++) {
        if (tasks[0].pizzaCooked[i].second !=
            tasks[0].pizzaToCook[i].second)
            return (false);
    }
    return (true);
}

// Check kitchens' status
bool Pizzeria::check_kitchens(void)
{
    for (int i = 0; i < kitchens.size(); i++)
        if (kitchens[i] && !kitchens[i]->running) {
            Kitchen *tmp = kitchens[i];
            kitchens.erase(kitchens.begin() + i);
            tmp = NULL;
            delete (tmp);
            return (true);
        }
    return (false);
}

// Clean up kitchens
void Pizzeria::clean_kitchens(void)
{
    for (int i = 0; i < kitchens.size(); i++)
        if (kitchens[i])
            kitchens[i]->running = false;
    for (int i = 0; i < kitchens.size(); i++)
        if (kitchens[i]) {
            kitchens[i] = NULL;
            delete (kitchens[i]);
        }
    return;
}

// Display orders and kitchens status
void Pizzeria::display_order(void)
{
    std::cout << "Order(s) status (#" << tasks.size() << "):" << std::endl;
    for (int i = 0; i < tasks.size(); i++) {
        std::cout << "Order #" << i << " {" << std::endl;
        for (int p = 0; p < 4; p++) {
            if (!tasks[i].pizzaToCook[p].second)
                continue;
            std::cout << "\t" << PizzaNames[p].first;
            std::cout << " " << tasks[i].pizzaCooked[p].second << "/" << tasks[i].pizzaToCook[p].second;
            std::cout << std::endl;
        }
        std::cout << "}" << std::endl;
    }
    std::cout << "Kitchen(s) status (#" << kitchens.size() << "):" << std::endl;
    for (int i = 0; i < kitchens.size(); i++) {
        std::cout << "Kitchen #" << i << " {" << std::endl;
        kitchens[i]->stock->display_ingredient();
        kitchens[i]->display_cooks();
        std::cout << "}" << std::endl;
    }
    return;
}

// Task method for running pizzeria
void *task(void *pizze)
{
    Pizzeria *pizzeria = (Pizzeria *)pizze;
    order_t current;

    pizzeria->running = true;
    while (pizzeria->running) {
        while (pizzeria->check_kitchens());
        if (!pizzeria->tasks.size())
            continue;
        pizzeria->update_order();
        if (pizzeria->order_ready())
            pizzeria->delete_current_order();
        else if (!pizzeria->kitchens.size()) {
            current = pizzeria->tasks[0];
            if (!pizzeria->order_ready())
                current = prepare_kitchens(pizzeria, current);
        }
    }
    pizzeria->clean_kitchens();
    return (NULL);
}

// Start the kitchen process
void Pizzeria::run(void)
{
    running = true;

    pthread_create(&this->thread, NULL, parse_loop, (void *)this);
    task(this);
    running = false;
    return;
}
