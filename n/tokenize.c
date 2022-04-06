#include "main.h"

/**
 * tokenize - tokenizer
 * @str: str
 *
 * Return: list_t
 */
char **tokenize(char *str)
{
	char *token = NULL, **array = NULL;
	int size = 0, n = 0;

	size = args(str);
	array = malloc(sizeof(char *) * (size + 1));
	if (!array)
		return (NULL);
	token = strtok(str, " ");
	while (token != NULL)
	{
		if (n == 0)
			if (token[0] != '/')
			{
				array[n] = malloc(sizeof(path(token) + 1));
				if (!array[n])
					return (NULL);
				array[n] = path(token);
				n++;
				token = strtok(NULL, " ");
				continue;
			}
		array[n] = malloc(sizeof(token) + 1);
		if (!array[n])
			return (NULL);
		array[n] = strcpy(array[n], token);
		token = strtok(NULL, " ");
		n++;
	}
	array[n] = NULL;
	return (array);
}

/**
 * _strlen - string length
 * @s: string
 *
 * Return: the length of a string
 */
int _strlen(const char *s)
{
	int i = 0;

	while (s[i])
		i++;
	return (i);
}

/**
 * _strdup - strdup C function
 * @str: string to duplicate
 *
 * Return: str
 */
char *_strdup(const char *str)
{
	int i, n = 0;
	char *strcopy;

	if (str == NULL)
		return (NULL);
	do {
		n++;
	} while (str[n - 1]);
	strcopy = malloc(sizeof(char) * n);
	if (strcopy == NULL)
		return (NULL);

	for (i = 0; i < n; i++)
	{
		strcopy[i] = str[i];
	}

	return (strcopy);
}
