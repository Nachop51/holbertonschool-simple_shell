#include "main.h"

int _setenv(const char *name, const char *value, int overwrite)
{
	char *var;
	size_t len;
	int i;

	len = strlen(name);
	while (environ[i] != NULL)
	{
		if ((strncmp(environ[i], name, len) == 0) && overwrite != 0)
		{
			var = create_variable(name, value);
			free(environ[i]);
			environ[i] = strdup(var);
			free(var);
			return (0);
		}
		i++;
	}
	var = create_variable(name, value);
	free(environ[i]);
	environ[i] = strdup(var);
	environ[i++] = NULL;
	free(var);
	return (0);
}
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
