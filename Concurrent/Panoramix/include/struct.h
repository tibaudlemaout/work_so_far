/*
** EPITECH PROJECT, 2024
** B-CCP-400-NAN-4-1-panoramix-tibaud.le-maout
** File description:
** struct
*/

#ifndef STRUCT_H_
    #define STRUCT_H_
    #include <stdio.h>
    #include <pthread.h>
    #include <semaphore.h>
    #include <unistd.h>
    #include <stdbool.h>

typedef struct druid {
    sem_t pot_empty;
    sem_t pot_full;
    sem_t refill_completed;
    pthread_mutex_t pot_mutex;
    int pot_size;
    int pot_servings;
    int refills_left;
    int active_villagers;
} druid_t;

typedef struct villager {
    int id;
    int nb_fights;
    bool has_potion;
    druid_t *druid;
} villager_t;

#endif /* !STRUCT_H_ */
