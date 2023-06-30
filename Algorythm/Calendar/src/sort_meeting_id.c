/*
** EPITECH PROJECT, 2023
** B-SYN-200-NAN-2-1-calendar-tibaud.le-maout
** File description:
** sort_meeting
*/
#include "../include/calendar.h"

int sort_meeting_id_alloc(meeting_t *current, int count, meeting_t **meet)
{
    while (current) {
        count++;
        current = current->next;
    }
    current = *meet;
    return (count);
}

static void fill_meetings_list(int count, meeting_t **meetings,
    meeting_t *current)
{
    for (int i = 0; i < count; i++) {
        meetings[i] = current;
        current = current->next;
    }
    qsort(meetings, count, sizeof(meeting_t *), compare_by_id);
}

void sort_meeting_id_end(meeting_t *prev, meeting_t *sorted,
    meeting_t **meet, meeting_t **meetings)
{
    if (prev)
        prev->next = NULL;
    *meet = sorted;
    free(meetings);
}

void sort_meeting_list_by_id(meeting_t **meet)
{
    meeting_t *current = *meet;
    meeting_t *sorted = NULL;
    meeting_t *prev = NULL;
    meeting_t **meetings = NULL;
    int count = 0;

    count = sort_meeting_id_alloc(current, count, meet);
    meetings = malloc(count * sizeof(meeting_t *));
    fill_meetings_list(count, meetings, current);
    for (int i = 0; i < count; i++) {
        current = meetings[i];
        if (sorted == NULL) {
        sorted = current;
        prev = current;
        } else {
        prev->next = current;
        prev = current;
        }
    }
    sort_meeting_id_end(prev, sorted, meet, meetings);
}
