#include "main.h"

/**
 * _checkExit - checks the exit condition
 * @str: string
 *
 * Return: 1 if successful 0 if not
 */
int _checkExit(char *str)
{
	if (strcmp(str, "exit") == 0)
		return (1);
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
		if ((str[i] >= 65 && str[i] <= 90)
		|| (str[i] >= 97 && str[i] <= 122)
		|| str[i] == '/' || str[i] == '.')
		{
			r = 0;
			break;
		}
		i++;
	}
	return (r);
}
