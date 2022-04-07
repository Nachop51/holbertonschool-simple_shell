#include "main.h"

int main(void)
{
	size_t i = 0;
	int counter = 0, builtIn = 0;
	char *buffer = NULL, **argv = NULL, *dup = NULL;
	int status = 0;
	pid_t child_pid;

	signal(SIGINT, sig_handler);
	while (1)
	{
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
		child_pid = fork();
		if (child_pid == -1)
		{
			perror("./hsh: 1");
			return (1);
		}
		if (child_pid == 0)
		{
			if (execve(argv[0], argv, NULL) == -1)
			{
				perror("./hsh: 1");
				break;
			}
		}
		else
		{
			wait(&status);
			free(dup);
			free_array(argv);
		}
	}
	if (builtIn != 1)
	{
		free_array(argv);
		free(dup);
	}
	free(buffer);
	return (0);
}
