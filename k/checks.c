#include "main.h"

/**
 * _checkBuiltIn - checks the built-ins
 * @str: string
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
 * _checkChars - checks for special characters
 * @str: the string
 *
 * Return: 0 if there are no SC, -1 if there is
 */
int checkExit(char *str)
{
	char *cpy = _strdup(str);

	if (strcmp(strtok(cpy, " "), "exit") == 0)
	{
		free(cpy);
		return (1);
	}
	free (cpy);
	return (0);
}
int checkEnv(char *str)
{
	char *cpy = _strdup(str);

	if (strcmp(strtok(cpy, " "), "env") == 0)
	{
		free(cpy);
		return (1);
	}
	free (cpy);
	return (0);
}
int _checkChars(char *str)
{
	int i = 0, r = -1;

	while (str[i])
	{
		if (str[i] != 32 && str[i] != 10)
		{
			r = 0;
			if(str[0] == ' ' && str[1] != ' ')
			{
				str = strtok(str, " ");
			}
			break;
		}
		i++;
	}
	return (r);
}
