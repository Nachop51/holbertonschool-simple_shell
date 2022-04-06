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
		if (signal(SIGINT, sig_handler) == SIG_ERR)
			continue;
		c = getline(&buffer, &i, stdin);
		if (_checkChars(buffer) == -1)
			continue;
		buffer[c - 1] = '\0';
		dup = strdup(buffer);
		head = malloc(sizeof(list_t));
		*head = tokenize(dup);
		_checkExit(head->str);
		argv = malloc(sizeof(char *) * args(buffer));
		argv[0] = head->str;
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
			free(argv[0]);
			free(argv);
		}
	}
	free(dup);
	free(buffer);
	free(head);
	free(argv[0]);
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
	if (signo == SIGINT)
		return;
}

int args(char *str)
{
	int i = 1, counter = 0;

	if(str[0] != ' ')
			counter++;
	while (str[i])
	{
		if (str[i] == ' ' && (str[i + 1] != ' ' && str[i + 1] != '\0'))
			counter++;
		i++;
	}
	return (counter);
}
