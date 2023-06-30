/*
** EPITECH PROJECT, 2023
** B-SYN-200-NAN-2-1-calendar-tibaud.le-maout
** File description:
** cancel
*/
#include "../include/calendar.h"

void cancel_cont(int meetingID, meeting_t *current, meeting_t *prev,
meeting_t **meet)
{
    if (prev != NULL) {
        prev->next = current->next;
    } else {
        *meet = current->next;
    }
}

void cancel_meeting(int meetingID, meeting_t **meet)
{
    meeting_t *current = *meet;
    meeting_t *prev = NULL;

    while (current != NULL) {
        if (current->ID == meetingID) {
            cancel_cont(meetingID, current, prev, meet);
            free(current->day);
            free(current->zipcode);
            free(current->emp_ids);
            free(current);
            return;
        }
        prev = current;
        current = current->next;
    }
}

int set_cancel(char **tab, employee_t **emp, meeting_t **meet)
{
    int numMeetings = get_tab_layers(tab) - 1;

    if (get_tab_layers(tab) < 2)
        return (0);
    for (int i = 0; i < numMeetings; i++) {
        int meetingID = atoi(tab[i + 2]);
        cancel_meeting(meetingID, meet);
    }
    return (0);
}
