#ifndef MAIN_H
#define MAIN_H

#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include <signal.h>

/**
 * struct list_s - lista
 * @str: str
 * @len: len
 * @next: next
 */

typedef struct list_s
{
	char *str;
	unsigned int len;
	struct list_s *next;
} list_t;

// size_t print_list(const list_t *h);
int _strlen(const char *s);
list_t *add_node_end(list_t **head, const char *str);
list_t tokenize(char *str);
char *_strncpy(char *dest, char *src, int n);
int _strcmp(const char *s1, char *s2);
char *_strdup(const char *str);
char *_getenv(const char *name);
int _checkChars(char *str);
void handle_signal(int signal);
void _checkExit(char *str);

#endif
