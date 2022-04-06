#include "main.h"

/**
 * print_path -  prints each directory contained in PATH
 * @ac: ac
 * @av: av
 * @ep: ep
 *
 * Return: 0
 */

int print_path(int ac, char **av, char **ep)
{
	char *PATH = getenv("PATH"), *r;

	if (ac != 2)
		return (1);
	r = _status(PATH, av[1]);
	if (r != NULL)
		printf("%s\n", r);
	return (0);
}

/**
 * _status - status
 * @PATH: PATH
 * @filename: filename
 *
 * Return: return
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
