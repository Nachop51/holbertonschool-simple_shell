#include "main.h"

/**
 * path - searches a route of a file
 * @name: name of the file
 *
 * Return: Absolute route of a file or NULL
 */
char *path(char *name)
{
	char *PATH = getenv("PATH"), *r = _status(PATH, name);

	if (r == NULL)
		return (NULL);
	return (r);
}
/**
 * _status - checks if a file exists
 * @PATH: Enviroment variable PATH
 * @filename: name of the file
 *
 * Return: Absolute route of a file or NULL
 */
char *_status(char *PATH, char *filename)
{
	char *cpy = strdup(PATH);
	char *token, *absolute;
	struct stat st;

	token = strtok(cpy, ":");
	filename = str_concat("/", filename);
	while (token != NULL)
	{
		absolute = str_concat(token, filename);
		if (stat(absolute, &st) == 0)
			return (absolute);
		token = strtok(NULL, ":");
	}
	return (NULL);
}
