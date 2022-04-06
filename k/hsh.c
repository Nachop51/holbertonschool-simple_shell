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
		dup = strdup(buffer);
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
				return (1);
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

int _checkChars(char *str)
{
	int i = 0, r = -1;

	while (str[i])
	{
		if ((str[i] >= 65 && str[i] <= 90)
		|| (str[i] >= 97 && str[i] <= 122)
		|| str[i] == '/' || str[i] == '.')
		{
			r = 0;
			break;
		}
		i++;
	}
	return (r);
}

int _checkExit(char *str)
{
	char *Exit = "exit";

	if (strcmp(str, Exit) == 0)
		return (1);
	return (0);
}

void sig_handler(int signo)
{
       write(STDOUT_FILENO, "\n$ ", 3);
}

int args(char *str)
{
	int i = 1, counter = 0;

	if (str[0] != ' ')
		counter++;
	while (str[i])
	{
		if (str[i] == ' ' && (str[i + 1] != ' ' && str[i + 1] != '\0'))
			counter++;
		i++;
	}
	return (counter);
}

void free_and_exit(char *buffer)
{
	free(buffer);
	exit(0);
}

void free_array(char **array)
{
	int i = 0;

	while(array[i] != NULL)
	{
		free(array[i]);
		i++;
	}
	free(array[i]);
}
