#include "main.h"

/**
 * _status - checks if a file exists
 * @PATH: Environment variable PATH
 * @filename: name of the file
 *
 * Return: Absolute route of a file or NULL
 */
char *_status(char *filename)
{
	char *PATH = _getenv("PATH");
	char *cpy = _strdup(PATH), *concatenated;
	char *token, *absolute;
	struct stat st;

	token = strtok(cpy, ":");
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
		token = strtok(NULL, ":");
		free(absolute);
	}
	free(PATH);
	free(concatenated);
	free(cpy);
	return (NULL);
}
