#include "main.h"

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

	len = strlen(name);
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

	len = strlen(name);
	while (environ[i] != NULL)
	{
		if ((strncmp(environ[i], name, len) == 0) && overwrite != 0)
		{
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
 * free_environ - frees all the environ[i] used in the function _setenv
 * @var_name: the name of the variable
 *
 * Return: asd
 */
void free_environ(char *var_name)
{
	size_t len = 0;
	int i = 0;

	len = strlen(var_name);
	while (environ[i] != NULL)
	{
		if (strncmp(environ[i], var_name, len) == 0)
		{
			free(environ[i]);
		}
		i++;
	}
}
