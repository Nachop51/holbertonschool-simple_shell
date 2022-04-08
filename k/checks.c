#include "main.h"

/**
 * _checkBuiltIn - checks the built-ins
 * @str: the string
 *
 * Return: return
 */
int _checkBuiltIn(char *str)
{
	if (checkExit(str) == 1)
		return (1);
	if (checkEnv(str) == 1)
	{
		printenv();
		return (2);
	}
	return (0);
}
/**
 * _checkExit - checks for the exit built-in
 * @str: the string
 *
 * Return: 1 if it is the exit built-in, 0 if not
 */
int checkExit(char *str)
{
	char *cpy = _strdup(str);

	if (strcmp(strtok(cpy, " "), "exit") == 0)
	{
		free(cpy);
		return (1);
	}
	free(cpy);
	return (0);
}
/**
 * checkEnv - checks for the env built-in
 * @str: the string
 *
 * Return: 1 if it is the env built-in, 0 if not
 */
int checkEnv(char *str)
{
	char *cpy = _strdup(str);

	if (strcmp(strtok(cpy, " "), "env") == 0)
	{
		free(cpy);
		return (1);
	}
	free(cpy);
	return (0);
}
/**
 * _checkChars - checks the characters
 * @str: the string
 *
 * Return: -1 or 0
 */
int _checkChars(char *str)
{
	int i = 0, r = -1;

	while (str[i])
	{
		if (str[i] != 32 && str[i] != 10)
		{
			r = 0;
			if (str[0] == ' ' && str[1] != ' ')
			{
				str = strtok(str, " ");
			}
			break;
		}
		i++;
	}
	return (r);
}
int checkDir(char *str)
{
	char *cpy = _strdup(str), *dir = NULL;
	int flag = 0;

	if (strcmp(strtok(cpy, " "), "cd") == 0)
	{
		dir = strtok(NULL, " ");
		if (dir == NULL)
			dir = _getenv("HOME");
		if (chdir(dir) == 1)
		{
			perror("cd");
			free(dir);
		}
		flag++;
	}
	free(cpy);
	return (flag);
}
