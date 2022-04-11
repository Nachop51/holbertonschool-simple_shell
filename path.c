#include "main.h"

/**
 * path - Checks if a file exists
 * @filename: name of the file
 *
 * Return: Returns the absolute route of a file or NULL
 */
char *path(char *filename)
{
	char *PATH = _getenv("PATH");
	char *cpy = _strdup(PATH), *concatenated = NULL;
	char *token = NULL, *absolute = NULL;
	struct stat st;

	token = _strtok(cpy, ':');
	concatenated = str_concat("/", filename);
	while (token != NULL)
	{
		absolute = str_concat(token, concatenated);
		if (stat(absolute, &st) == 0)
		{
			free(PATH);
			free(cpy);
			free(concatenated);
			return (absolute);
		}
		token = _strtok(NULL, ':');
		free(absolute);
	}
	free(PATH);
	free(concatenated);
	free(cpy);
	return (NULL);
}
