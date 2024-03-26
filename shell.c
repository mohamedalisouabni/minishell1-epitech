/*
** EPITECH PROJECT, 2023
** shell
** File description:
** lib
*/
#include <stdio.h>
#include "./include/my.h"
#include <stdlib.h>
#include <unistd.h>
#include <stddef.h>
#include <string.h>
#include <dirent.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <errno.h>
#include <sys/signal.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <errno.h>

const env_t *envList = NULL;

int error_handling(char *cmd, char **argv, char **env)
{
    if (cmd == NULL) {
        my_putstr(argv[0]);
        write(2, ": Command not found.\n", 22);
        exit(EXIT_FAILURE);
    }
    if (execve(cmd, argv, env) == -1) {
        perror("execve");
        free(cmd);
        exit(EXIT_FAILURE);
    }
}

int fonct_exe(char **argv, char **env)
{
    pid_t pid = fork();
    int status;
    char *cmd;

    if (pid == -1) {
        perror("fork");
        exit(EXIT_FAILURE);
    } else if (pid == 0) {
        cmd = ex_cmd(env, argv[0]);
        error_handling(cmd, argv, env);
    }
    waitpid(pid, &status, 0);
    return 0;
}

int bt_exec(char **line, char **argv, char **env)
{
    if (my_strcmp(line[0], "exit") == 0)
        exit(EXIT_SUCCESS);
    if (my_strcmp(line[0], "env") == 0)
        l_env(envList, env);
    else if (my_strcmp(line[0], "cd") == 0)
        cd_btins(line);
    else
        fonct_exe(line, env);
    return 0;
}

int shell_init(char **argv, char **env)
{
    size_t len = 0;
    ssize_t lineSize = 0;
    char *com = NULL;
    char *tokens[1024];
    int token_count;

    while (1) {
        my_putstr("$> ");
        lineSize = getline(&com, &len, stdin);
        token_count = index_found(len, com, tokens);
        if (lineSize == -1) {
            my_putstr("exit\n");
            exit(EXIT_SUCCESS);
        }
        if (token_count == 0)
            continue;
        bt_exec(tokens, argv, env);
    }
    free(com);
    return 0;
}

int main(int ac, char **av, char **env)
{
    if (ac == 1)
        shell_init(av, env);
    else
        return 84;
    return 0;
}
