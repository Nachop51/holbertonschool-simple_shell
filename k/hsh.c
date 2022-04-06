#include "main.h"

int main(void)
{
	size_t i = 0;
	int c = 0;
	char *buffer = NULL, **argv = NULL, *dup = NULL;
	int status = 0;
	pid_t child_pid;

	signal(SIGINT, sig_handler);

	while (1)
	{
		printf("$ ");
		c = getline(&buffer, &i, stdin);
		if (c == -1)
			free_and_exit(buffer);
		if (_checkChars(buffer) == -1)
			continue;
		buffer[c - 1] = '\0';
		dup = _strdup(buffer);
		argv = tokenize(dup);
		if (_checkExit(argv[0]) == 1)
			break;
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
			free(argv);
		}
	}
	free(dup);
	free(buffer);
	free_array(argv);
	free(argv);
	return (0);
}
