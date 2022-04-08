#include "main.h"

int main(void)
{
	int i = 0;
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
	char *var = NULL;
	size_t len = 0;
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
	free(var);
	environ[i + 1] = NULL;
	return (i);
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
	size_t len = 0;

	aux = str_concat(name, "=");
	var = str_concat(aux, value);
	free(aux);
	return (var);
}

/**
 * str_concat - Concatenates two strings
 * @s1: First string
 * @s2: Second string
 *
 * Return: Returns the concatenated string
 */
char *str_concat(char *s1, char *s2)
{
	int i = 0, j = 0, n = 0;
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
 * printenv - prints the enviroment
 *
 * Return: void
 */

void printenv(void)
{
	int i = 0;

	while (environ[i])
	{
		printf("%s\n", environ[i++]);
	}
}