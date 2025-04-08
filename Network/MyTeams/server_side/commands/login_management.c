/*
** EPITECH PROJECT, 2024
** B-NWP-400-NAN-4-1-myteams-thomas.cluseau
** File description:
** login_management
*/
#include "../../include/server.h"
#include "../../include/utils.h"
#include "../../libs/myteams/logging_server.h"

static command _command[11] = {&is_users, &is_user, &is_send, &is_messages,
&is_create, &is_sub, &is_unsub, &is_use, &is_info, &is_list, &is_subed};

static void command_management(client_serv_t client[MAX_CLIENT], int id,
int len)
{
    char *command_first[] = {"/users", "/user", "/send", "/messages",
    "/create", "/subscribe", "/unsubscribe", "/use", "/info", "/list",
    "/subscribed"};

    for (int i = 0; i != 11; i++) {
        if (!strcmp(client[id].command[0], command_first[i])) {
            _command[i](client, id, len);
            return;
        }
    }
}

void handling_command_client(client_serv_t client[MAX_CLIENT], int id,
int len)
{
    if (len == 1) {
        if (client[id].login == false
        && !strcmp(client[id].message, "/logout")) {
            clean_client(client, id);
            return;
        }
    } else if (len == 2) {
        if (!strcmp(client[id].command[0], "/login")) {
            login_client(client, id, len);
            return;
        }
    }
    if (client[id].login == true) {
        command_management(client, id, len);
    }
}

static void help_command_cont(client_serv_t client[MAX_CLIENT], int id)
{
    c_message(client[id].sockfd,
    "\t/create : based on context, create sub ressource\n");
    c_message(client[id].sockfd,
    "\t/list : based on context, list sub ressources\n");
    c_message(client[id].sockfd,
    "\t/info : based on context, display details of current ressources\n");
    return;
}

void help_command(client_serv_t client[MAX_CLIENT], int id)
{
    c_message(client[id].sockfd,
    "\t/login [username] : login with your id\n");
    c_message(client[id].sockfd,
    "\t/logout : disconnect from server and close client\n");
    c_message(client[id].sockfd,
    "\t/users : get the list of all users that exist on the domain\n");
    c_message(client[id].sockfd,
    "\t/user [user_uuid] : get details about the given user\n");
    c_message(client[id].sockfd,
    "\t/send [user_uuid] [message]  : send a message to that user\n");
    c_message(client[id].sockfd,
    "\t/message [user_uuid] : list all the messages with that user\n");
    c_message(client[id].sockfd,
    "\t/subscribe [team_uuid] : subscibe to the event of a team\n");
    c_message(client[id].sockfd,
    "\t/subscribed ?[team_uuid] : list all subscribed teams/users\n");
    c_message(client[id].sockfd,
    "\t/unsubscribe [team_uuid] : unsubscribe from a team\n");
    c_message(client[id].sockfd,
    "\t/use ?[team_uuid][channel_uuid][thread_uuid] : set command context to given uuid\n");
    help_command_cont(client, id);
}
