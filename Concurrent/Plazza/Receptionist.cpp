/*
** EPITECH PROJECT, 2024
** B-CCP-400-NAN-4-1-theplazza-tibaud-le.maout
** File description:
** receptionist
*/
#include <iostream>
#include <stack>
#include <string.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include "include/Kit.hpp"

// Function to read the quantity from a command
char *parse_amount(std::string command)
{
    char *num = (char *)malloc(sizeof(char) * (command.size() + 1));
    int pos = 0;

    // Extract digits from the command
    while (command[pos] && command[pos] >= '0' && command[pos] <= '9') {
        num[pos] = command[pos];
        pos++;
    }
    num[pos] = '\0';

    // Check if the quantity is valid
    if (strlen(num) <= 0 || atoi(num) <= 0)
        return NULL;
    return (num);
}

// Function to read the size of the pizza from a command
PizzaSize parse_size(std::string command)
{
    // Compare the command with known size names and return the corresponding size
    for (int i = 0; i < sizeLen; i++)
        if (!strncmp(command.c_str(), SizeNames[i].first, strlen(SizeNames[i].first)))
            return SizeNames[i].second;
    return (Invalid_s);
}

// Function to read the type of the pizza from a command
PizzaType parse_type(std::string command)
{
    // Compare the command with known pizza names and return the corresponding type
    for (int i = 0; i < pizzaLen; i++)
        if (!strncmp(command.c_str(), PizzaNames[i].first, strlen(PizzaNames[i].first)))
            return PizzaNames[i].second;
    return (Invalid_t);
}

// Function to check the syntax of a command
bool parse_check_command(char *command)
{
    pizzaOrder_t elem;
    std::string s(command);

    // Parse the command string
    while (s.length() != 0) {
        // Remove leading whitespace and semicolons
        while (s[0] == ';' || s[0] == ' ')
            s.erase(0, 1);
        if (!s.length())
            break;
        // Read pizza type from the command
        elem.type = parse_type(s);
        if (elem.type == Invalid_t || s.length() < strlen(PizzaNames[elem.type - 1].first) + 1)
            return (false);
        s.erase(0, strlen(PizzaNames[elem.type - 1].first) + 1);
        // Read pizza size from the command
        elem.size = parse_size(s);
        if (!elem.size || s.length() < strlen(SizeNames[elem.size - 1].first) + 1)
            return (false);
        s.erase(0, strlen(SizeNames[elem.size - 1].first) + 1);
        // Read pizza quantity from the command
        if (s[0] == 'x')
            s.erase(0, 1);
        char *qty = parse_amount(s);
        if (!qty || s.length() < strlen(qty)) {
            if (qty)
                free(qty);
            return (false);
        }
        s.erase(0, strlen(qty));
        elem.quantity = atoi(qty);
        free(qty);
    }
    return (true);
}

// Function to parse the command and create a stack of pizza orders
std::stack<pizzaOrder_t> parser(Pizzeria *pizze, char *command)
{
    std::stack<pizzaOrder_t> order;
    pizzaOrder_t elem;
    std::string s(command);

    // Check command syntax
    if (!parse_check_command(command))
        return order;

    // Parse the command string
    while (s.length() != 0) {
        // Remove leading whitespace and semicolons
        while (s[0] == ';' || s[0] == ' ')
            s.erase(0, 1);
        if (!s.length())
            break;
        // Read pizza type from the command
        elem.type = parse_type(s);
        s.erase(0, strlen(PizzaNames[elem.type - 1].first) + 1);
        // Read pizza size from the command
        elem.size = parse_size(s);
        s.erase(0, strlen(SizeNames[elem.size - 1].first) + 1);
        // Read pizza quantity from the command
        if (s[0] == 'x')
            s.erase(0, 1);
        char *qty = parse_amount(s);
        s.erase(0, strlen(qty));
        elem.quantity = atoi(qty);
        free(qty);
        order.push(elem);
    }
    return (order);
}

// Function to read a line from the shell
char *parse_command(void)
{
    char *buff = (char *)malloc(sizeof(char) * 1024);
    int size = 1024;
    char curr;
    int pos = 0;

    // Read characters from input until newline or EOF
    while (true) {
        curr = getchar();
        if (!curr || -1 == curr || curr == '\n') {
            buff[pos] = '\0';
            return buff;
        } else
            buff[pos] = curr;
        pos++;
        // Reallocate memory if buffer is full
        if (pos >= 1024) {
            size += 1024;
            buff = (char *)realloc(buff, size);
        }
    }
}

// Function to handle shell input and execute commands
void *parse_loop(void *pizze)
{
    const char *invalid = "Invalid command. Please check syntax.";
    const char *prompt = "> ";
    Pizzeria *pizzeria = (Pizzeria *)pizze;
    char *command = NULL;

    // Loop until the pizzeria stops running
    while (pizzeria->running) {
        std::cout << prompt;
        // Read a line from the shell
        command = parse_command();
        if (!command)
            break;
        // Check for built-in commands
        if (!strcmp(command, "status"))
            pizzeria->display_order();
        else if (!strcmp(command, "exit"))
            pizzeria->running = false;
        else {
            // Parse the command and load orders into the pizzeria
            std::stack<pizzaOrder_t> stack = parser(pizzeria, command);
            if (stack.empty())
                std::cerr << invalid << std::endl;
            else
                pizzeria->load_orders(stack);
        }
        if (command)
            free(command);
    }
    return (NULL);
}
