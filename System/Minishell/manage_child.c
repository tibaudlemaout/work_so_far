/*
** EPITECH PROJECT, 2023
** Semester_2
** File description:
** manage_child
*/
#include "./include/minishell_1.h"
#include "./include/struct.h"

int signal_errors(int status)
{
if (WIFSIGNALED(status)) {
    int sig = WTERMSIG(status);
    if (sig == 11)
        my_putstr("Segmentation fault");
    if (__WCOREDUMP(status))
        my_putstr("core dumped\n");
    else
        my_putchar('\n');
    }
}

void handle_child(global_t *data, char *exec)
{
    int child_pid = 0;
    int status = 0;
    int err = 0;

    child_pid = fork();
    if (child_pid == -1)
        perror("Fork error");
    if (child_pid == 0) {
        err = execve(exec, data->tab, data->c_env);
        exit(1);
    }
    waitpid(child_pid, &status, 0);
    signal_errors(status);
    data->past_status = status;
    return;
}
