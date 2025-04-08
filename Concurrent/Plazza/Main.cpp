/*
** EPITECH PROJECT, 2024
** B-CCP-400-NAN-4-1-theplazza-tibaud-le.maout
** File description:
** receptionist
*/
#include <iostream>
#include <cstdlib>
#include <cstring>
#include <unistd.h>
#include <sys/types.h> 
#include <sys/ipc.h> 
#include <sys/shm.h>
#include <sys/wait.h>

#include "include/Kit.hpp"

static bool usage(int argc, char **argv)
{
    if (argc == 2 && (!strcmp(argv[1], "-h") || !strcmp(argv[1], "-help"))) {
        std::cerr << "USAGE:\n";
        std::cerr << "\t" << argv[0] << " [multiplier] [cooks] [time]\n";
        std::cerr << "DESCRIPTION:\n";
        std::cerr << "\tmultiplier\tmultiplier for the cooking time of the pizzas\n";
        std::cerr << "\tcooks\tnumber of cooks per kitchen\n";
        std::cerr << "\ttime\tthe time in milliseconds used by the kitchen stock to replace ingredients\n";
        return (true);
    }
    return (false);
}

static bool check(int argc, char **argv)
{
    if (argc != 4) {
        std::cerr << "Bad usage.\n";
        return (false);
    }
    if (atoi(argv[1]) <= 0) {
        std::cerr << "Multiplier must be greater than 0.\n";
        return (false);
    }
    if (atoi(argv[2]) <= 0) {
        std::cerr << "Cooks must be greater than 0.\n";
        return (false);
    }
    if (atoi(argv[3]) <= 0) {
        std::cerr << "Refresh must be greater than 0.\n";
        return (false);
    }
    return (true);
}

int main(int argc, char **argv)
{
    Pizzeria *pizzeria = nullptr;
    commu_t *commu = nullptr;

    int pid = fork();
    if (pid < 0) 
        return (84);

    int memid = shmget(0x00042473, sizeof(commu_t), 0700 | IPC_CREAT);
    if (memid < 0)
        return (84);

    commu = static_cast<commu_t *>(shmat(memid, nullptr, 0));
    if (commu == reinterpret_cast<commu_t *>(-1))
        return (84);
    if (pid == 0) {
        if (!pizzeria)
            exit(84);
        pizzeria->check_kitchens();
        pizzeria->display_order();
        pizzeria->running = true;
        exit(0);
    } else {
        if (usage(argc, argv))
            return (0);
        if (!check(argc, argv))
            return (84);
        pizzeria = new Pizzeria(atoi(argv[1]), atoi(argv[2]), atoi(argv[3]));
        if (!pizzeria) return 84;
        pizzeria->commu = commu;
        pizzeria->run();
        delete pizzeria;
        wait(nullptr);
    }
    return (0);
}
