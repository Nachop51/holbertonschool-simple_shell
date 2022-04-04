#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include <string.h>

char **tokenize(char *s);
int _strlen(char *s);

int main(int ac, char **av)
{
	// char *str = av[1], *token;
	char **argv;
	int i = 0;

	if (ac == 1)
	{
	// 	token = strtok(str, " ");
	// 	while (token != NULL)
	// 	{
	// 		printf("%s\n", token);
	// 		token = strtok(NULL, " ");
	// 	}
		argv = tokenize("Hola como estas    puto sad sad sad sad  a");
		// while (argv[i] != NULL)
		// {
		// 	printf("argv[%i]: %s\n", i, argv[i]);
		// }

	}
	// return (0);
}

char **tokenize(char *s)
{
	char **av, *token;
	int i = 0, counter = 0, j = 0;

	while (s[i])
	{
		if (i == 0)
			if (s[i] != ' ')
				counter++;
		if (s[i] == ' ' && (s[i + 1] != ' ' && s[i + 1] != '\0'))
			counter++;
		i++;
	}
	av = malloc(sizeof(char *) * counter);
	i = 0;
	token = strtok(s, " ");
	while (i < counter)
	{
		av[i] = strtok(s, " ");
		token = strtok(NULL, " ");
	}
	printf("Counter: %d\n", counter);
	return (av);
}
