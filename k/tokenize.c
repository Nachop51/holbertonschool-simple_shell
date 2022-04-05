#include "main.h"

/**
 * tokenize - tokenize
 * @str: str
 *
 * Return: list_t
 */
list_t tokenize(char *str)
{
	char *token;
	list_t *head;

	head = NULL;
	token = strtok(str, " ");
	while (token != NULL)
	{
		add_node_end(&head, token);
		token = strtok(NULL, " ");
	}
	return (*head);
}
