/*
** EPITECH PROJECT, 2024
** B-CCP-400-NAN-4-1-panoramix-tibaud.le-maout
** File description:
** druid
*/
#include "include/panoramix.h"

void initialize_pot(druid_t *pot, int pot_size, int nb_refills)
{
    sem_init(&(pot->pot_empty), 0, 0);
    sem_init(&(pot->pot_full), 0, pot_size);
    sem_init(&(pot->refill_completed), 0, 0);
    pthread_mutex_init(&(pot->pot_mutex), NULL);
    pot->pot_size = pot_size;
    pot->pot_servings = pot_size;
    pot->refills_left = nb_refills;
    return;
}

void refill_potion(druid_t *druid)
{
    sem_wait(&(druid->pot_empty));
    pthread_mutex_lock(&(druid->pot_mutex));
    druid->pot_servings = druid->pot_size;
    if (druid->active_villagers == 0) {
        pthread_mutex_unlock(&(druid->pot_mutex));
        return;
    }
    if (druid->refills_left >= 1) {
        printf("Druid: Ah! Yes, yes, I'm awake! Working on it! ");
        printf("Beware I can only make %d more refills after this one.\n",
            druid->refills_left - 1);
    }
    pthread_mutex_unlock(&(druid->pot_mutex));
    sem_post(&(druid->pot_full));
    druid->refills_left--;
    druid->pot_servings--;
}

void *druid_thread_func(void *arg)
{
    druid_t *druid = (druid_t *)arg;

    printf("Druid: I'm ready... but sleepy...\n");
    while (druid->refills_left > 0) {
        if (druid->active_villagers == 0)
            break;
        refill_potion(druid);
    }
    printf("Druid: I'm out of viscum. I'm going back to... zZz\n");
    return (NULL);
}
