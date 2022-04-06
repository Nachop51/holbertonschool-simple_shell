#ifndef MAIN_H
#define MAIN_H

#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>

/**
 * struct list_s - lista
 * @str: str
 * @next: next
 */

typedef struct list_s
{
	char *str;
	struct list_s *next;
} list_t;

/* String Functions */
int _strlen(const char *s);
char *_strdup(const char *str);

int _checkChars(char *str);
void sig_handler(int signo);
int args(char *str);
void free_list(list_t *head);
int _checkExit(char *str);
list_t *add_node_end(list_t **head, const char *str);
list_t tokenize(char *str);

#endif