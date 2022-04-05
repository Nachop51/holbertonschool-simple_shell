#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>

extern char **environ;
char *_getenv(const char *name);
int _strcmp(const char *s1, const char *s2);
char *_strdup(char *str);

int main(void)
{
	char *PATH = _getenv("PATH");

	printf("%s\n", PATH);
	free(PATH);
	return (0);
}

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
			value = malloc(sizeof(char) * strlen(token) + 1);
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

/**
 * _strdup - strdup C function
 * @str: string to duplicate
 *
 * Return: str
 */
char *_strdup(char *str)
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
