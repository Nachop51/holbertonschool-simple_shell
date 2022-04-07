#include "main.h"

/**
 * _status - checks if a file exists
 * @PATH: Environment variable PATH
 * @filename: name of the file
 *
 * Return: Absolute route of a file or NULL
 */
char *_status(char *filename)
{
	char *PATH = _getenv("PATH");
	char *cpy = _strdup(PATH);
	char *token, *absolute;
	struct stat st;

	token = strtok(cpy, ":");
	filename = str_concat("/", filename);
	while (token != NULL)
	{
		absolute = str_concat(token, filename);
		if (stat(absolute, &st) == 0)
			return (absolute);
		token = strtok(NULL, ":");
	}
	free(cpy);
	return (NULL);
}

/**
 * str_concat - concatenates two strings
 * @s1: first string
 * @s2: second string
 *
 * Return: concatenated string
 */
char *str_concat(char *s1, char *s2)
{
	int i = 0, j = 0, n;
	char *str;

	if (s1 == NULL)
		s1 = "";
	if (s2 == NULL)
		s2 = "";
	do {
		i++;
	} while (s1[i - 1]);
	do {
		j++;
	} while (s2[j - 1]);
	str = malloc(sizeof(char) * (i + j - 1));
	if (str == NULL)
		return (NULL);

	for (n = 0; n < i; n++)
		str[n] = s1[n];
	for (n = 0; n < j; n++)
		str[n + i - 1] = s2[n];
	return (str);
}

/**
 * _getenv - uses the environ variable in order to get a variable
 * @name: name of the variable
 *
 * Return: value of the variable or NULL
 */
char *_getenv(const char *name)
{
	char *token, *value, *cpy;
	size_t i = 0;

	if (!name)
		exit(1);
	while (environ[i] != NULL)
	{
		cpy = _strdup(environ[i]);
		token = strtok(cpy, "=");
		if (_strcmp(name, token) == 0)
		{
			token = strtok(NULL, "=");
			value = malloc(sizeof(char) * _strlen(token) + 1);
			if (!value)
				return (NULL);
			strcpy(value, token);
			free(cpy);
			break;
		}
		i++;
		free(cpy);
	}
	return (value);
}

/**
 * _strcmp - strcmp function
 * @s1: string 1
 * @s2: string 2
 *
 * Return: the different values
 */
int _strcmp(const char *s1, const char *s2)
{
	int i, ss1 = 0, ss2 = 0, result = 0;

	for (i = 0; i > -1; i++)
	{
		if (s1[i] != s2[i])
		{
			ss1 = s1[i];
			ss2 = s2[i];
			break;
		}
		else
		{
			if (s1[i] == '\0' || s2[i] == '\0')
				break;
		}
	}
	result = ss1 - ss2;
	return (result);
}
