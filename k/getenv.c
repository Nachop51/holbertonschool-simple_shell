#include "main.h"

/**
 * _getenv - gets an enviroment variable
 * @name: the name of the variable
 *
 * Return: the enviroment
 */

char *_getenv(const char *name)
{
	extern char **environ;
	char *token, *value, *cpy;
	size_t i = 0;

	if (!name)
		return (NULL);
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
