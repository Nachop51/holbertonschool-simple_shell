#include "main.h"
#include <stddef.h>
#include <string.h>

/**
 * _strtok - strtok
 * @str: str
 * @delim: delim
 *
 * Return: ret
 */

char *_strtok(char *str, char delim)
{
	static char *tok1, *tok2;
	unsigned int i;

	if (str != NULL)
		tok2 = str;
	tok1 = tok2;
	if (tok1 == NULL)
		return (NULL);
	for (i = 0; tok1[i] != '\0'; i++)
	{
		if (tok1[i] != delim)
			break;
	}
	if (tok2[i] == '\0')
	{
		tok2 = NULL;
		return (NULL);
	}
	tok1 = tok2 + i;
	tok2 = tok1;
	for (i = 0; tok2[i] != '\0'; i++)
	{
		if (tok2[i] == delim)
			break;
	}
	if (tok2[i] == '\0')
		tok2 = NULL;
	else
	{
		tok2[i] = '\0';
		tok2 += i + 1;
		if (tok2[0] == '\0')
			tok2 = NULL;
	}
	return (tok1);
}
