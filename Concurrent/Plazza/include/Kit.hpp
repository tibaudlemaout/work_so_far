/*
** EPITECH PROJECT, 2024
** B-CCP-400-NAN-4-1-theplazza-tibaud-le.maout
** File description:
** receptionist
*/
#ifndef KIT_HPP_
    #define KIT_HPP_

    #include <iostream>
    #include <stack>
    #include <vector>
    #include <mutex>
    #include <unistd.h>
    #include <pthread.h>
    #include "Rec.hpp"

class Pizzeria;
class Cooks;
class Ingredient;
class Kitchen;

static const int pizzaLen = 4;
static const int sizeLen = 5;
static const int maxContentLen = 6;

typedef struct commu_s
{
    int instruction;
    int val;
    int type;
    int size;
    int delay;
} commu_t;

typedef struct order_s
{
    std::vector<std::pair<int, int>> pizzaToCook;
    std::vector<std::pair<int, int>> pizzaLeft;
    std::vector<std::pair<int, int>> pizzaCooked;
    std::stack<pizzaOrder_t> details;

} order_t;

enum CooksState {
    Sleeping = 0,
    Cooking
};

enum PizzaType
{
    Invalid_t = 0,
    Regina = 1,
    Margarita = 2,
    Americana = 3,
    Fantasia = 4
};

enum PizzaSize
{
    Invalid_s = 0,
    S = 1,
    M = 2,
    L = 3,
    XL = 4,
    XXL = 5
};

enum PizzaContent
{
    EMPTY = -1,
    DOE = 0,
    TOMATO = 1,
    GRUYERE = 2,
    HAM = 3,
    MUSHROOMS = 4,
    STEAK = 5,
    EGGPLANT = 6,
    GOAT_CHEESE = 7,
    CHIEF_LOVE = 8,
};

typedef struct pizzaRecipe_s {
    PizzaType Type;
    PizzaContent Elems[maxContentLen];
    int Time;
} pizzaRecipe_t;

static std::pair<const char *, PizzaSize> SizeNames[] =
{
    { "S", S },
    { "M", M },
    { "L", L },
    { "XL", XL },
    { "XXL", XXL },
    { "", Invalid_s }
};

static std::pair<const char *, PizzaType> PizzaNames[] =
{
    { "regina", Regina },
    { "margarita", Margarita },
    { "americana", Americana },
    { "fantasia", Fantasia },
    { "", Invalid_t }
};

static std::pair<const char *, PizzaContent> ElemsNames[] =
{
    { "doe", DOE },
    { "tomato", TOMATO },
    { "gruyere", GRUYERE },
    { "ham", HAM },
    { "mushrooms", MUSHROOMS },
    { "steak", STEAK },
    { "eggplant", EGGPLANT },
    { "goat cheese", GOAT_CHEESE },
    { "chief love", CHIEF_LOVE },
    { "", EMPTY }
};

static pizzaRecipe_t PizzaRecipeList[] =
{
    { Regina, { DOE, TOMATO, GRUYERE, HAM, MUSHROOMS, EMPTY }, 2 },
    { Margarita, { DOE, TOMATO, GRUYERE, EMPTY }, 1 },
    { Americana, { DOE, TOMATO, GRUYERE, STEAK, EMPTY }, 2},
    { Fantasia, { DOE, TOMATO, EGGPLANT, GOAT_CHEESE, CHIEF_LOVE, EMPTY}, 4},
    { Invalid_t, { EMPTY } }
};

class Pizzeria {
public:
    Pizzeria(int, int, int);
    ~Pizzeria(void);

    std::vector<Kitchen *> kitchens;
    std::vector<order_t> tasks;

    int multiplier;
    int cooks;
    int refresh;
    bool running;
    pthread_t thread;
    commu_t *commu;

    void display_order(void);
    void load_orders(std::stack<pizzaOrder_t>);
    void run(void);
    bool order_ready(void);
    void delete_current_order(void);
    bool check_kitchens(void);
    void clean_kitchens(void);
    void update_order(void);
};

class Pizza {
public:
    Pizza();
    ~Pizza();

    int type;
    int state;
};

class Cooks {
public:
    Cooks(Kitchen *);
    ~Cooks() = default;

    Pizza *pizza;

    void display_order(void);
    void assign_work(int);
    void next_step(void);
    void cook_ready(int);
    Kitchen *kitchen;
    int type;
    int step;
    int state;
};

enum KitchenState {
    Full,
    Work,
    Waiting
};

class Kitchen {
public:
    Kitchen(Pizzeria *);
    ~Kitchen();

    Pizzeria *pizzeria;
    std::vector<Cooks *> cooks;
    Ingredient *stock;
    int state;
    int active;
    bool running;
    pthread_t thread;

    std::vector<std::pair<int, int>> pizzasToCook;
    std::mutex pizzasCoooked_mutex;
    std::vector<std::pair<int, int>> pizzasCooked;

    void display_cooks(void);
    order_t prepare_order(order_t);
    void refresh_ingredients(void);
    void start_work(void);
    void stop_work(void);
    bool check_step(void);
    void assign_if_empty(void);
    void pizza_ready(int);
    int get_pizza_mult(int);
private:
    void prepare_cooks(void);
};

class Ingredient {
public:
    Ingredient();
    ~Ingredient();

    std::pair<int, int> products[9];

    void display_ingredient(void);
    void update_ingredient(void);
    int check_ingredient(int);
    bool get_stock_for_pizza(int);
    bool available_for_pizza(int);
    void add_ingredient(int, int);
    void remove_ingredient(int, int);
};

#endif /* !KIT_HPP_ */
