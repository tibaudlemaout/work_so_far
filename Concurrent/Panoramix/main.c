/*
** EPITECH PROJECT, 2024
** B-CCP-400-NAN-4-1-panoramix-tibaud.le-maout
** File description:
** main
*/
#include "include/panoramix.h"

static void argument_is_num(char *argv, int j)
{
    if (!isdigit(argv[j])) {
        printf("Error: Argument %s must be a number.\n", argv);
        exit(84);
    }
}

static void error_handling(int argc, char **argv)
{
    if (argc != 5) {
        printf("USAGE: ./panoramix <nb_villagers> <pot_size> ");
        printf("<nb_fights> <nb_refills>\n");
        exit(84);
    }
    for (int i = 1; i < argc; ++i) {
        for (int j = 0; argv[i][j] != '\0'; ++j)
            argument_is_num(argv[i], j);
    }
}

void join_free_villagers(pthread_t *villagers, villager_t **villager_array,
    int nb_villagers)
{
    for (int i = 0; i < nb_villagers; i++) {
        pthread_join(villagers[i], NULL);
        free(villager_array[i]);
    }
}

void main_loop(druid_t *pot, int nb_villagers, int nb_fights)
{
    pthread_t druid_thread;
    pthread_t villagers[nb_villagers];
    villager_t *villager_array[nb_villagers];

    pot->active_villagers = nb_villagers;
    pthread_create(&druid_thread, NULL, druid_thread_func, pot);
    for (int i = 0; i < nb_villagers; ++i) {
        villager_array[i] = malloc(sizeof(villager_t));
        villager_array[i]->id = i;
        villager_array[i]->nb_fights = nb_fights;
        villager_array[i]->has_potion = false;
        villager_array[i]->druid = pot;
        pthread_create(&villagers[i], NULL, villager_thread,
            villager_array[i]);
    }
    join_free_villagers(villagers, villager_array, nb_villagers);
    pthread_join(druid_thread, NULL);
    sem_destroy(&(pot->pot_empty));
    sem_destroy(&(pot->pot_full));
    pthread_mutex_destroy(&(pot->pot_mutex));
}

int main(int argc, char **argv)
{
    int nb_villagers = 0;
    int pot_size = 0;
    int nb_fights = 0;
    int nb_refills = 0;
    druid_t pot;

    error_handling(argc, argv);
    nb_villagers = atoi(argv[1]);
    pot_size = atoi(argv[2]);
    nb_fights = atoi(argv[3]);
    nb_refills = atoi(argv[4]);
    initialize_pot(&pot, pot_size, nb_refills);
    main_loop(&pot, nb_villagers, nb_fights);
    return (0);
}
