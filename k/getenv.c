#include "main.h"
#include <unistd.h>

extern char **environ;

int main(void)
{
	char *PATH = _getenv("PATH");
	printf("%s\n", PATH);
	free(PATH);
}

char *_getenv(const char *name)
{
	char *token1, *token2, *cpy;
	size_t i = 0;

	if (!name)
		return(NULL);
	while (environ[i] != NULL)
	{
		cpy = _strdup(environ[i]);
		token1 = strtok(cpy, "=");
		token2 = _strdup(strtok(NULL, "="));
		if (_strcmp(name, token1) == 0)
			break;
		free(cpy);
		free(token2);
		i++;
	}
	return (token2);
}

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
