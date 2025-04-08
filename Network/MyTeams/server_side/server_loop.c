/*
** EPITECH PROJECT, 2024
** Network_Programming
** File description:
** server_loop
*/
#include "../include/server.h"

static void handle_signal_action(int sig_number)
{
    run = 0;
}

static void loop_cont2(client_serv_t client_str[MAX_CLIENT], int i)
{
    if (check_client(client_str, i) == 0)
        start_client(client_str, i);
    return;
}

static void loop_cont(client_serv_t client_str[MAX_CLIENT], serv_t *serv)
{
    for (int i = 0; i < MAX_CLIENT; i++) {
        if (FD_ISSET(client_str[i].sockfd, &serv->readfds))
            loop_cont2(client_str, i);
    }
    return;
}

int loop_server(client_serv_t client_str[MAX_CLIENT], serv_t *serv)
{
    is_save_file();
    signal(SIGINT, handle_signal_action);
    load_user_infile();
    for (int id = 0; id < MAX_CLIENT; id++) {
        init_struct_client(client_str, id);
    }
    while (run != 0) {
        if (init_client(client_str, serv) != 0)
            continue;
        fill_client(client_str, serv);
        loop_cont(client_str, serv);
    }
    close_server(client_str, serv);
    return (0);
}
