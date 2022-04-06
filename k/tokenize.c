#include "main.h"

/**
 * tokenize - tokenize
 * @str: str
 *
 * Return: array
 */

char **tokenize(char *str)
{
	char *token, **array;
	int size = 0, n = 0;

	size = args(str);
	array = malloc(sizeof(char *) * (size + 1));
	if (array == NULL)
		return (NULL);
	token = strtok(str, " ");
	while (token != NULL)
	{
		array[n] = _strdup(token);
		token = strtok(NULL, " ");
		n++;
	}
	array[n] = NULL;
	return (array);
}
