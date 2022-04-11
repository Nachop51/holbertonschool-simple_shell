#include "main.h"
#include <sys/types.h>
#include <sys/stat.h>

char *_status(char *PATH, char *filename);
char *str_concat(char *s1, char *s2);

int main(int ac, char **av, char **ep)
{
	char *PATH = getenv("PATH"), *r;

	r = _status(PATH, "ls");
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

/*
 * expandTilde - Looks for a ~ and replaces it for the variable $HOME
 * ~/../home/shell/simple_shell/n/a.out
 * @str: String to traverse
 *
 * Return: The modified string or just the string
 *
char *expandTilde(char *str)
{
	int i = 0, tilde = 0, flag = 0;
	char *cpy = _strdup(str), *new = NULL, *rest = NULL, *token = NULL;
	char *concatenated = NULL;

	while (str[i])
	{
		if (str[i] == '~')
			tilde++;
		i++;
	}
	printf("Tilde:%d\n", tilde);
	if (tilde > 0)
	{
		free(str);
		while (tilde > 0)
		{
			i = 0;
			while (cpy[i])
			{
				printf("cpy[%d]:%c\n", i, cpy[i]);
				if (cpy[i] == '~')
				{
					if (flag == 0)
					{
						token = strtok(cpy, "~");
						flag++;
					}
					else
					{
						rest = strtok(NULL, "~");
						new = addTilde(token);
					}
				}
				i++;
			}
			tilde--;
			printf("Tilde:%d\n", tilde);
		}
	}
	printf("cpy:%s.\n", cpy);
	str = _strdup(cpy);
	free(cpy);
	return (str);
}
*/

/*
char *addTilde(char *path)
{
	char *home = NULL, *concatenated = NULL;

	printf("path:%s.\n", path);
	home = _getenv("HOME");
	concatenated = str_concat(path, home);
	free(home);
	printf("con:%s.\n", concatenated);
	return (concatenated);
}
*/
