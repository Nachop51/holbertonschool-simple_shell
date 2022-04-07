#include "main.h"

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
	char *var = NULL;
	size_t len;
	int i = 0;

	len = strlen(name);
	while (environ[i] != NULL)
	{
		if ((strncmp(environ[i], name, len) == 0) && overwrite != 0)
		{
			var = create_variable(name, value);
			if (!var)
				return (-1);
			environ[i] = strdup(var);
			free(var);
			return (0);
		}
		i++;
	}
	var = create_variable(name, value);
	if (!var)
		return (-1);
	environ[i] = strdup(var);
	environ[i + 1] = NULL;
	free(var);
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
	char *var;
	size_t len;

	len = strlen(name) + strlen(value) + 1;
	var = malloc(len + 1);
	if (var == NULL)
		return (NULL);

	var = str_concat(var, name);
	var = str_concat(var, "=");
	var = str_concat(var, value);
	return (var);
}
