#include "main.h"

int main(void)
{
	size_t i = 0;
	int counter = 0, builtIn = 0, status = 0;
	char *buffer = NULL, **argv = NULL, *dup = NULL;
	pid_t child_pid;

	signal(SIGINT, sig_handler);
	while (1)
	{
		if((isatty(STDIN_FILENO) == 1))
			printf("$ ");
		counter = getline(&buffer, &i, stdin);
		if (counter == -1)
			free_and_exit(buffer);
		if (_checkChars(buffer) == -1)
			continue;
		buffer[counter - 1] = '\0';
		builtIn = _checkBuiltIn(buffer);
		if (builtIn == 1)
			break;
		dup = _strdup(buffer);
		argv = tokenize(dup, builtIn);
		if (builtIn == 0 && argv[0][0] == '/')
		{
			child_pid = fork();
			if (child_pid == -1)
			{
				perror(argv[0]);
				return (1);
			}
		}
		else
			child_pid = 1;
		if (child_pid == 0)
		{
			if (execve(argv[0], argv, environ) == -1)
			{
				perror(argv[0]);
				break;
			}
		}
		else
		{
			wait(&status);
			if((isatty(STDIN_FILENO) == 0))
				break;
			free_array_dup(argv, dup);
		}
	}
	if (builtIn != 1)
		free_array_dup(argv, dup);
	free(buffer);
	return (0);
}
