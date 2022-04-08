#ifndef MAIN_H
#define MAIN_H

#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include <signal.h>
#include <sys/stat.h>

extern char **environ;

/**
 * struct list_s - singly linked list
 * @str: string
 * @next: pointer to the next node
 */

typedef struct list_s
{
	char *str;
	struct list_s *next;
} list_t;

/* MAIN FUNCTIONS */

char **tokenize(char *str, int builtIn);
char *_getenv(const char *name);
int _checkChars(char *str);
int _checkBuiltIn(char *str);
char *path(char *filename);
int args(char *str);
void sig_handler(int signo);
void free_array(char **array);
void free_and_exit(char *buffer);
int _setenv(char *name, char *value, int overwrite);
int _unsetenv(char *name);
char *create_variable(char *name, char *value);
void printenv(void);
void free_array_dup(char **array, char *dup);
int checkEnv(char *str);
int checkExit(char *str);
int checkDir(char *str);
void free_environ(char *var_name);

/* STRINGS */

char *_strcpy(char *dest, char *src);
int _strcmp(const char *s1, const char *s2);
char *_strdup(const char *str);
int _strlen(const char *s);
char *str_concat(char *s1, char *s2);

/* LISTS */

list_t *add_node_end(list_t **head, const char *str);
/* size_t print_list(const list_t *h); */

#endif
