#include "main.h"

/**
 * checkSetenv - Built-In checker for setenv
 * @str: String to compare
 *
 * Return: If there's a coincidence or not
 */
int checkSetenv(char *str)
{
	char *cpy = _strdup(str), *name = NULL, *value = NULL;

	if (strcmp(_strtok(cpy, ' '), "setenv") == 0)
	{
		name = _strtok(NULL, ' ');
		value = _strtok(NULL, ' ');
		if (name == NULL || value == NULL)
		{
			write(STDERR_FILENO, "Usage: setenv [VARIABLE] [VALUE]\n", 34);
			free(cpy);
			return (1);
		}
		_setenv(name, value, 1);
		free(cpy);
		return (1);
	}
	free(cpy);
	return (0);
}

/**
 * checkUnset - Built-In checker for unsetenv
 * @str: String to compare
 *
 * Return: If there's a coincidence or not
 */
int checkUnset(char *str)
{
	char *cpy = _strdup(str), *token = NULL;

	if (strcmp(_strtok(cpy, ' '), "unsetenv") == 0)
	{
		token = _strtok(NULL, ' ');
		if (token == NULL)
		{
			write(STDERR_FILENO, "Usage: unsetenv [VARIABLE]\n", 28);
			free(cpy);
			return (1);
		}
		if (_unsetenv(token) == -1)
		{
			write(STDERR_FILENO, "can't unset non-existent variable\n", 35);
			free(cpy);
			return (1);
		}
		free(cpy);
		return (1);
	}
	free(cpy);
	return (0);
}

/**
 * checkExit - Built-In checker for exit
 * @str: String to compare
 *
 * Return: If there's a coincidence or not
 */
int checkExit(char *str)
{
	char *cpy = _strdup(str);

	if (strcmp(_strtok(cpy, ' '), "exit") == 0)
	{
		free(cpy);
		return (1);
	}
	free(cpy);
	return (0);
}

/**
 * checkEnv - Built-In checker for env
 * @str: String to compare
 *
 * Return: If there's a coincidence or not
 */
int checkEnv(char *str)
{
	char *cpy = _strdup(str);

	if (strcmp(_strtok(cpy, ' '), "env") == 0)
	{
		free(cpy);
		printenv();
		return (1);
	}
	free(cpy);
	return (0);
}
