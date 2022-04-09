#include "main.h"

/**
 * tokenize - Tokenizes a given string
 * @str: String to tokenize
 * @builtIn: Indicates if there's a built-in or not
 *
 * Return: An array of tokenized strings
 */
char **tokenize(char *str, int builtIn)
{
	char *token = NULL, **array = NULL, *test = NULL;
	int size = 0, n = 0;
	struct stat st;

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
	if (builtIn == 0 && array[0][0] != '/')
	{
		test = path(array[0]);
		if (test != NULL)
		{
			free(array[0]);
			array[0] = _strdup(test);
		}
		else
			if (stat(array[0], &st) == 0)
				;
			else
				perror(array[0]);
		free(test);
	}
	array[n] = NULL;
	return (array);
}

/**
 * _strlen - Calculates the length of a string
 * @s: String
 *
 * Return: Returns the length of a string
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
 * @str: String to duplicate
 *
 * Return: A new copy of the given string
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
 * _strcpy - Takes a source string and copies it to the dest string
 * @dest: Dest string
 * @src: Source string
 *
 * Return: Returns a copy of the source string
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

/**
 * _atoi - converts string to an integer
 * @s: string
 *
 * Return: an integer
 */
int _atoi(char *s)
{
	char c;
	unsigned int i, n = 0, j = _strlen(s) - 1, null = -1;
	int flag = 0, sign = 1;

	for (i = 0; i <= j; i++)
	{
		c = s[i];
		if (c == '-')
			sign *= -1;
		if (c >= 48 && c <= 57)
		{
			n = n * 10 + (c - '0');
			flag = 1;
		}
		if (flag == 1)
		{
			if (!(c >= 48 && c <= 57))
				break;
		}
	}
	if (sign == -1)
	{
		n *= -1;
	}
	if (j == null)
		return (0);
	return (n);
}
