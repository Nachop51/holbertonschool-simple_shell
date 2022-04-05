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
