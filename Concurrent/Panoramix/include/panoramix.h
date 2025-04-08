/*
** EPITECH PROJECT, 2024
** B-CCP-400-NAN-4-1-panoramix-tibaud.le-maout
** File description:
** panoramix
*/

#ifndef PANORAMIX_H_
    #define PANORAMIX_H_
    #include <stdio.h>
    #include <pthread.h>
    #include <semaphore.h>
    #include <unistd.h>
    #include <stdlib.h>
    #include <ctype.h>
    #include "struct.h"

void *druid_thread_func(void *arg);
void *villager_thread(void *arg);
void initialize_pot(druid_t *pot, int pot_size, int nb_refills);

#endif /* !PANORAMIX_H_ */
