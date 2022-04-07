#include "main.h"

/**
 * tokenize - tokenizer
 * @str: str
 *
 * Return: list_t
 */
char **tokenize(char *str, int builtIn)
{
	char *token = NULL, **array = NULL, *test = NULL;
	int size = 0, n = 0;

	size = args(str);
	array = malloc(sizeof(char *) * (size + 1));
	if (!array)
		return (NULL);
	token = strtok(str, " ");
	while (token != NULL)
	{
		array[n] = _strdup(token);
		token = strtok(NULL, " ");
		n++;
	}
	printf("%d\n", builtIn);
	if (builtIn == 0 && array[0][0] != '/')
	{
		test = _status(array[0]);
		if (test != NULL)
		{
			free(array[0]);
			array[0] = _strdup(test);
		}
		free(test);
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

/**
 * _strcpy - copy a string
 * @dest: dest
 * @src: source
 *
 * Return: a char
 */
char *_strcpy(char *dest, char *src)
{
	int i;

	for (i = 0; src[i]; i++)
	{
		dest[i] = src[i];
	}
	dest[i] = '\0';

	return (dest);
}
