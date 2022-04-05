#include "main.h"

int main(void)
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
		if (_checkChars(buffer) == -1)
			continue;
		buffer[c - 1] = '\0';
		dup = strdup(buffer);
		head = malloc(sizeof(list_t));
		*head = tokenize(dup);
		argv = malloc(sizeof(char *) * 10);
		argv[0] = malloc(sizeof(char) * head->len);
		argv[0] = head->str;
		_checkExit(argv[0]);
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
		}
	}
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

void _checkExit(char *str)
{
	char *Exit = "exit";

	if (strcmp(str, Exit) == 0)
		exit(0);
}

void handle_signal(int signal)
{
	if (signal == SIGINT)
		exit(0);
}
