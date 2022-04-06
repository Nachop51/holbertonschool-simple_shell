#include "main.h"
#include <sys/types.h>
#include <sys/stat.h>

char *_status(char *PATH, char *filename);
char *str_concat(char *s1, char *s2);

int main(int ac, char **av, char **ep)
{
	char *PATH = getenv("PATH"), *r;

	r = _status(PATH, "PATH");
	if(r != NULL)
		printf("%s\n", r);
	return (0);
}

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

/**
 * str_concat - concatenates two strings
 * @s1: first string
 * @s2: second string
 *
 * Return: concatenated string
 */
char *str_concat(char *s1, char *s2)
{
	int i = 0, j = 0, n;
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


	// if (signal(SIGINT, sig_handler) == SIG_ERR || signal(SIGKILL, sig_handler) == SIG_ERR)
	// 		exit(0);