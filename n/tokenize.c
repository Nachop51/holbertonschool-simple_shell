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
	struct stat st = {0};

	size = args(str);
	array = malloc(sizeof(char *) * (size + 1));
	if (!array)
		return (NULL);
	token = _strtok(str, ' ');
	while (token != NULL)
	{
		array[n] = _strdup(token);
		token = _strtok(NULL, ' ');
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
		{
			if (stat(array[0], &st))
				;
			else
				perror(array[0]);
		}
		free(test);
	}
	array[n] = NULL;
	return (array);
}

/**
 * _strtok - strtok
 * @str: str
 * @delim: delim
 *
 * Return: ret
 */
char *_strtok(char *str, char delim)
{
	static char *tok1, *tok2;
	unsigned int i;

	if (str != NULL)
		tok2 = str;
	tok1 = tok2;
	if (tok1 == NULL)
		return (NULL);
	for (i = 0; tok1[i] != '\0'; i++)
	{
		if (tok1[i] != delim)
			break;
	}
	if (tok2[i] == '\0')
	{
		tok2 = NULL;
		return (NULL);
	}
	tok1 = tok2 + i;
	tok2 = tok1;
	for (i = 0; tok2[i] != '\0'; i++)
	{
		if (tok2[i] == delim)
			break;
	}
	if (tok2[i] == '\0')
		tok2 = NULL;
	else
	{
		tok2[i] = '\0';
		tok2 += i + 1;
		if (tok2[0] == '\0')
			tok2 = NULL;
	}
	return (tok1);
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
