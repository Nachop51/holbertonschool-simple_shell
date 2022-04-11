#include "main.h"

/**
 * printenv - Prints out all the environment variables
 */
void printenv(void)
{
	int i = 0;

	while (environ[i])
	{
		write(1, environ[i], _strlen(environ[i]));
		write(1, "\n", 1);
		i++;
	}
}
/**
 * _unsetenv - deletes the variable name from the environment
 * @name: the name of the variable
 *
 * Return: 0 on success or -1 on error
 */
int _unsetenv(char *name)
{
	size_t len = 0;
	int i = 0, flag = 0;

	len = _strlen(name);
	while (environ[i] != NULL)
	{
		if (strncmp(environ[i], name, len) == 0)
		{
			while (environ[i] != NULL)
			{
				environ[i] = environ[i + 1];
				i++;
			}
			flag++;
			break;
		}
		i++;
	}
	if (flag > 0)
		return (0);
	return (-1);
}

/**
 * _setenv - changes or adds an environment variable
 * @name: the name of the variable
 * @value: the value of the variable
 * @overwrite: if the variable most be overwrited or not
 *
 * Return: 0 on success or -1 on error
 */
int _setenv(char *name, char *value, int overwrite)
{
	size_t len;
	int i = 0;

	len = _strlen(name);
	while (environ[i] != NULL)
	{
		if ((strncmp(environ[i], name, len) == 0) && overwrite != 0)
		{
			if (overwrite == 2)
			{
				free(environ[i]);
			}
			environ[i] = create_variable(name, value);
			if (!environ[i])
				return (-1);
			return (0);
		}
		i++;
	}
	environ[i] = create_variable(name, value);
	if (!environ[i])
		return (-1);
	environ[i + 1] = NULL;
	return (0);
}

/**
 * create_variable - creates a variable
 * @name: the name of the variable
 * @value: the value of the variable
 *
 * Return: the new variable
 */
char *create_variable(char *name, char *value)
{
	char *var = NULL, *aux = NULL;

	aux = str_concat(name, "=");
	if (!aux)
		return (NULL);
	var = str_concat(aux, value);
	if (!var)
		return (NULL);
	free(aux);
	return (var);
}
/**
 * _getenv - Uses the environ variable in order to get a variable
 * @name: name of the variable
 *
 * Return: Returns the value of the variable or NULL
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
		token = _strtok(cpy, '=');
		if (_strcmp(name, token) == 0)
		{
			token = _strtok(NULL, '=');
			value = malloc(sizeof(char) * _strlen(token) + 1);
			if (!value)
			{
				free(cpy);
				return (NULL);
			}
			_strcpy(value, token);
			free(cpy);
			break;
		}
		i++;
		free(cpy);
	}
	return (value);
}
