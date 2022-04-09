#include "main.h"

/**
 * tokenize - tokenizer
 * @str: str
 * @builtIn: built-in
 *
 * Return: list_t
 */
char **tokenize(char *str, int builtIn)
{
	char *token = NULL, **array = NULL, *test = NULL;
	int size = 0, n = 0;

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
			perror(array[0]);
		free(test);
	}
	array[n] = NULL;
	return (array);
}
