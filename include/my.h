/*
** EPITECH PROJECT, 2023
** my
** File description:
** h
*/
#include <stdarg.h>

#ifndef MY_H_
    #define MY_H_
    #include <stddef.h>

typedef struct env_s {
    char *data;
    char *value;
    struct env_s *next;
    struct env_s *prev;
} env_t;

void my_putchar(char c);
int my_put_nbr(int nb);
int my_putstr(char const *str);
int my_strlen(char const *str);
int my_strcmp(char const *s1, char const *s2);
int env_btins(char **env);
int cd_btins(char **av);
int pwd_btins(void);
char *my_strcpy(char *dest, char const *src);
char *my_strncpy(char *dest, char const *src, int n);
char *my_strcat(char *dest, char const *src);
int index_found(size_t len, char *com, char **tokens);
int lineform_inpt(char *com, char **tokens);
char *ex_cmd(char **env, char *argv);
int error_handling1(char *cmd);
char *find_var(char **env, char *var);
int find_env_egl(char **env, int i);

#endif /* MY_H_ */
