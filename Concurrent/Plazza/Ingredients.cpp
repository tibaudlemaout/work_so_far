/*
** EPITECH PROJECT, 2024
** B-CCP-400-NAN-4-1-theplazza-tibaud-le.maout
** File description:
** receptionist
*/
#include "include/Kit.hpp"

Ingredient::Ingredient(void)
{
    for (int i = 0; i < 9; i++) {
        std::pair<int, int> pair = { i, 5};
        products[i] = pair;
    }
    return;
}

Ingredient::~Ingredient(void)
{
    return;
}

void Ingredient::display_ingredient(void)
{
    std::cout << "\tCurrent stock:\n";
    for (int i = DOE; i <= CHIEF_LOVE; i++) {
        std::cout << ElemsNames[i].first << ": " << products[i].second << " left\n";
        if (i != 0 && i % 5 == 0) {
            std::cout << std::endl;
        }
    }
    std::cout << std::endl;
    return;
}

void Ingredient::update_ingredient(void)
{
    for (int i = 0; i < 9; i++)
        add_ingredient(i, 1);
}

int Ingredient::check_ingredient(int elem)
{
    if (elem >= 0 && elem <= 8)
        return (products[elem].second);
    else
        return (-1);
}

bool Ingredient::get_stock_for_pizza(int type)
{
    bool can_cook = true;
    pizzaRecipe_t recipe = { Invalid_t };

    for (int i = 0; PizzaRecipeList[i].Type != Invalid_t; i++)
        if (PizzaRecipeList[i].Type == type) {
            recipe = PizzaRecipeList[i];
            break;
        }
    if (recipe.Type == Invalid_t)
        return (false);
    for (int i = 0; recipe.Elems[i] != EMPTY; i++)
        if (check_ingredient(recipe.Elems[i]) <= 0)
            can_cook = false;
    if (!can_cook)
        return (false);
    for (int i = 0; recipe.Elems[i] != EMPTY; i++)
        remove_ingredient(recipe.Elems[i], 1);
    return (true);
}

bool Ingredient::available_for_pizza(int type)
{
    bool can_cook = true;
    pizzaRecipe_t recipe = { Invalid_t };

    for (int i = 0; PizzaRecipeList[i].Type != Invalid_t; i++)
        if (PizzaRecipeList[i].Type == type) {
            recipe = PizzaRecipeList[i];
            break;
        }
    if (recipe.Type == Invalid_t)
        return (false);
    for (int i = 0; recipe.Elems[i] != EMPTY; i++)
        if (check_ingredient(recipe.Elems[i]) <= 0)
            can_cook = false;
    return (can_cook);
}

void Ingredient::add_ingredient(int elem, int qty)
{
    if (elem >= 0 && elem <= 8)
        products[elem].second += qty;
    return;
}

void Ingredient::remove_ingredient(int elem, int qty)
{
    if (elem >= 0 && elem <= 8)
        products[elem].second -= qty;
    return;
}