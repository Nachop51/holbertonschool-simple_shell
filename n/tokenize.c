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
	int i = 0;
	list_t *head;

	head = NULL;
	token = strtok(str, " ");
	while (token != NULL)
	{
		// printf("%s\n", token);
		add_node_end(&head, token);
		token = strtok(NULL, " ");
	}
	return (*head);
}

/**
  * add_node_end - adds a new node at the end of a list_t list
  * @head: head
  * @str: str
  *
  * Return: the address of the new list or NULL if it failed
  */

list_t *add_node_end(list_t **head, const char *str)
{
	char *strd = strdup(str);
	list_t *new_node;
	list_t *t;

	if (str)
	{
		new_node = malloc(sizeof(list_t));
		if (new_node == NULL)
			return (NULL);
		new_node->str = strd;
		new_node->len = _strlen(str);
		new_node->next = NULL;

		if (*head == NULL)
		{
			*head = new_node;
			return (*head);
		}
		else
		{
			t = *head;
			while (t->next)
				t = t->next;
			t->next = new_node;
			return (t);
		}
	}
	return (NULL);
}

/**
 * _strlen - returns the length of a string
 * @s: the string
 *
 * Return: the length
 */

int _strlen(const char *s)
{
	int a = 0;

	while (*s != '\0')
	{
		a++;
		s++;
	}
	return (a);
}

/**
  * print_list - prints all the elements of a list_t list
  * @h: h
  *
  * Return: the number of nodes
  */

// size_t print_list(const list_t *h)
// {
// 	size_t ret = 0;

// 	while (h != NULL)
// 	{
// 		if (h->str == NULL)
// 			printf("[0] (nil)\n");
// 		else
// 			printf("[%d] %s\n", h->len, h->str);

// 		h = h->next;
// 		ret++;
// 	}
// 	return (ret);
// }