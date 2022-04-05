#include "main.h"

/**
 * _strlen - returns the length of a string
 * @s: the string
 *
 * Return: the length
 */

int _strlen(const char *s)
{
	int a = 0;

	while (*s != '\0')
	{
		a++;
		s++;
	}
	return (a);
}

/**
 * _strdup - returns a pointer to a newly allocated space in memory
 * @str: the string
 *
 * Return: pointer to the duplicated string or NULL
 */

char *_strdup(const char *str)
{
	int a = 0, b;
	char *s;

	if (str == NULL)
		return (NULL);

	while (str[a])
		a++;

	s = malloc(a * sizeof(char) + 1);

	if (s == NULL)
		return (NULL);

	for (b = 0; b < a; b++)
		s[b] = str[b];

	return (s);
}

/**
* _strcmp - compares two strings
* @s1: first string
* @s2: second string
*
* Return: negative if s1 is less, 0 if match, positive if greater
*/

int _strcmp( const char *s1, char *s2)
{
	int a;

	for (a = 0; s1[a] != '\0' || s2[a] != '\0'; a++)
	{
		if (s1[a] != s2[a])
		{
			return (s1[a] - s2[a]);
		}
	}
	return (0);
}

/**
* *_strncpy - copies a string
* @dest: first string
* @src: second string
* @n: number
*
* Return: dest
*/

char *_strncpy(char *dest, char *src, int n)
{
	int a, b = 0;

	while (src[b] != '\0')
	{
		b++;
	}
	if (b >= n)
	{
		for (a = 0; a < n; a++)
		{
			dest[a] = src[a];
		}
	}
	else
	{
		for (a = 0; a < b; a++)
		{
			dest[a] = src[a];
		}
		while (b < n)
		{
			dest[b] = '\0';
			b++;
		}
	}
	return (dest);
}
