#include "main.h"

/**
 * _strtok - strtok
 * @str: str
 * @delim: delim
 *
 * Return: ret
 */

char *_strtok(char *str, char delim)
{
	char *array;
	int i, j;

	for (i = 0; str[i]; i++)
	{
		if (str[i] == delim)
		{
			for (j = 0; j < i; j++)
			{
				array[j] = str[i];
			}
		}
	}
}
