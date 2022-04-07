#include "main.h"

/**
 * _checkBuiltIn - checks the built-ins
 * @str: string
 *
 * Return: return
 */
int _checkBuiltIn(char *str)
{
	if (strcmp(str, "exit") == 0)
		return (1);
	if (strcmp(str, "env") == 0)
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
int _checkChars(char *str)
{
	int i = 0, r = -1;

	while (str[i])
	{
		if (str[i] != 32 && str[i] != 10)
		{
			r = 0;
			break;
		}
		i++;
	}
	return (r);
}
