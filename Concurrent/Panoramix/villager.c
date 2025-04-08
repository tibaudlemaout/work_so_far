/*
** EPITECH PROJECT, 2024
** B-CCP-400-NAN-4-1-panoramix-tibaud.le-maout
** File description:
** villager
*/
#include "include/panoramix.h"

void wake_up_for_potion(villager_t *villager)
{
    printf("Villager %d: Hey Pano wake up! We need more potion.\n",
        villager->id);
    sem_post(&(villager->druid->pot_empty));
    sem_wait(&(villager->druid->pot_full));
    return;
}

void take_potion(villager_t *villager)
{
    printf("Villager %d: I need a drink... I see %d servings left.\n",
        villager->id, villager->druid->pot_servings);
    villager->druid->pot_servings--;
    villager->has_potion = true;
    return;
}

void battle(villager_t *villager, int remaining_fights)
{
    printf("Villager %d: Take that roman scum! Only %d left.\n",
        villager->id, remaining_fights);
    usleep(1000000);
    return;
}

void handle_potion_refill(villager_t *villager)
{
    pthread_mutex_lock(&(villager->druid->pot_mutex));
    if (!villager->has_potion && villager->druid->pot_servings == 0) {
        if (villager->druid->refills_left > 0) {
            wake_up_for_potion(villager);
        } else {
            printf("Villager %d: No more refills left.", villager->id);
            printf(" I'm going to sleep now.\n");
            pthread_mutex_unlock(&(villager->druid->pot_mutex));
            return;
        }
    }
    pthread_mutex_unlock(&(villager->druid->pot_mutex));
}

void *villager_thread(void *arg)
{
    villager_t *villager = (villager_t *)arg;
    druid_t *druid = villager->druid;

    printf("Villager %d: Going into battle!\n", villager->id);
    for (int i = 0; i < villager->nb_fights; ++i) {
        handle_potion_refill(villager);
        pthread_mutex_lock(&(druid->pot_mutex));
        if (!villager->has_potion) {
            take_potion(villager);
        }
        pthread_mutex_unlock(&(druid->pot_mutex));
        battle(villager, villager->nb_fights - i - 1);
        villager->has_potion = false;
    }
    printf("Villager %d: I'm going to sleep now.\n", villager->id);
    pthread_mutex_lock(&(druid->pot_mutex));
    druid->active_villagers--;
    pthread_mutex_unlock(&(druid->pot_mutex));
    sem_post(&(druid->pot_empty));
    return (NULL);
}
