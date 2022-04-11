#include "main.h"

/**
 * tokenize - Tokenizes a given string
 * @str: String to tokenize
 * @builtIn: Indicates if there's a built-in or not
 *
 * Return: An array of tokenized strings
 */
char **tokenize(char *str, int builtIn)
{
	char *token = NULL, **array = NULL, *test = NULL;
	int size = 0, n = 0;
	struct stat st = {0};

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
		{
			if ((stat(array[0], &st) == 0) || (isDir(array[0]) == 0))
				;
			else
				perror(array[0]);
		}
		free(test);
	}
	array[n] = NULL;
	return (array);
}
