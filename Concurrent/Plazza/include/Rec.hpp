/*
** EPITECH PROJECT, 2024
** B-CCP-400-NAN-4-1-theplazza-tibaud-le.maout
** File description:
** receptionist
*/
#ifndef REC_HPP_
    #define REC_HPP_
    #include <iostream>
    #include <stack>

// Forward declaration of Pizzeria class
class Pizzeria;

typedef struct pizzaOrder_s
{
    int type;
    int size;
    int quantity;
} pizzaOrder_t;

bool parse_check_command(char *);
std::stack<pizzaOrder_t> parser(Pizzeria *, char *);
void *parse_loop(void *);
char *parse_command(void);

#endif /* !REC_HPP_ */
