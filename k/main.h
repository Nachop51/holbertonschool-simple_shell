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
#include "strings.c"
#include "lists.c"

extern char **environ;

/**
 * struct list_s - singly linked list
 * @str: string
 * @len: length of the string
 * @next: pointer to the next node
 */

typedef struct list_s
{
	char *str;
	unsigned int len;
	struct list_s *next;
} list_t;

/* MAIN FUNCTIONS*/

list_t tokenize(char *str);
char *_getenv(const char *name);
int _checkChars(char *str);
void handle_signal(int signal);
void _checkExit(char *str);
char *_status(char *PATH, char *filename);

/* STRINGS */

char *_strncpy(char *dest, char *src, int n);
int _strcmp(const char *s1, char *s2);
char *_strdup(const char *str);
int _strlen(const char *s);
char *str_concat(char *s1, char *s2);

/* LISTS */

list_t *add_node_end(list_t **head, const char *str);
/* size_t print_list(const list_t *h); */

#endif
