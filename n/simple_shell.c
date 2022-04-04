#include "main.h"

/**
 * main - Executes a simple command
 * @ac: Argument Counter
 * @av: Argument Vector
 * Return: 1 If succeed, 0 on Error.
 */
int main(int ac, char **av)
{
	size_t i = 0, c = 0;
	char *buffer = NULL, **argv, *dup;
	int status;
	pid_t child_pid;
	list_t *head;

	while (1)
	{
		printf("$ ");
		c = getline(&buffer, &i, stdin);
		if (c == 1 || c == -1)
			continue;
		buffer[c - 1] = '\0';
		dup = strdup(buffer);
		head = malloc(sizeof(list_t));
		*head = tokenize(dup);
		argv = malloc(sizeof(char *) * 10);
		argv[0] = malloc(sizeof(char) * head->len);
		argv[0] = head->str;
		child_pid = fork();
		if (child_pid == -1)
		{
			perror("Error:");
			return (1);
		}
		if (child_pid == 0)
		{
			if (execve(argv[0], argv, NULL) == -1)
			{
				perror("Error:");
				return (1);
			}
		}
		else
		{
			wait(&status);
		}
	}
}
