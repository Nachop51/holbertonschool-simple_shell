#include "main.h"

/**
 * main - Recreation of a "sh"
 * 
 * Return: 0 If succeed, or the number of the error
 */
int main(void)
{
	size_t i = 0;
	int counter = 0, builtIn = 0, status = 0;
	char *buffer = NULL, **argv = NULL, *dup = NULL;
	pid_t child_pid;
	struct stat st;

	while (1)
	{
		_isatty();
		counter = getline(&buffer, &i, stdin);
		if (counter == -1)
			free_and_exit(buffer);
		if (_checkChars(buffer) == -1)
			continue;
		buffer = clearBuffer(buffer, counter);
		builtIn = _checkBuiltIn(buffer);
		if (builtIn == 1)
			break;
		dup = _strdup(buffer);
		argv = tokenize(dup, builtIn);
		if ((builtIn == 0 && (stat(argv[0], &st) == 0)))
			child_pid = child_fork(child_pid, argv[0]);
		else
			child_pid = 1;
		if (child_pid == 0 && execve(argv[0], argv, environ) == -1)
		{
			perror(argv[0]);
			break;
		}
		else
			if (waitIsatty(status, argv, dup) == 0)
				break;
	}
	if (builtIn != 1)
		free_array_dup(argv, dup);
	free(buffer);
	return (0);
}

int waitIsatty(int status, char **argv, char *dup)
{
	int i = 0;

	wait(&status);
	i = isatty(STDIN_FILENO);
	free_array_dup(argv, dup);
	return (i);
}

int child_fork(pid_t child_pid, char *name)
{
	child_pid = fork();
	if (child_pid == -1)
	{
		perror(name);
		exit(EXIT_FAILURE);
	}
	return (child_pid);
}

void _isatty(void)
{
	signal(SIGINT, sig_handler);
	if ((isatty(STDIN_FILENO) == 1))
		printf("$ ");
}

int _checkChars(char *str)
{
	int i = 0, r = -1;

	while (str[i])
	{
		if (str[i] != 32 && str[i] != 10 && str[i] != '\t')
		{
			r = 0;
			if (str[0] == ' ' && str[1] != ' ')
			{
				str = strtok(str, " ");
			}
			break;
		}
		i++;
	}
	return (r);
}

char *clearBuffer(char *str, int counter)
{
	str[counter - 1] = '\0';
	str = searchAndDestroy(str);
	return (str);
}

char *searchAndDestroy(char *str)
{
	int i = 0, tab = 0;

	while (str[i])
	{
		if (str[i] == '\t')
		{
			tab++;
		}
		i++;
	}
	i = 0;
	if (tab > 0)
	{
		while (str[i])
		{
			if (str[i] == '\t')
			{
				str[i] = ' ';
			}
			i++;
		}
	}
	return (str);
}

int _checkBuiltIn(char *str)
{
	if (checkDir(str) == 1)
		return (3);
	if (checkExit(str) == 1)
		return (1);
	if (checkEnv(str) == 1)
	{
		printenv();
		return (2);
	}
	return (0);
}

int checkDir(char *str)
{
	char *cpy = _strdup(str), *dir = NULL;
	int flag = 0;

	if (strcmp(strtok(cpy, " "), "cd") == 0)
	{
		dir = strtok(NULL, " ");
		if (dir == NULL)
			dir = _getenv("HOME");
		if (chdir(dir) == 1)
		{
			perror("cd");
			free(dir);
		}
		flag++;
	}
	free(cpy);
	return (flag);
}

int checkExit(char *str)
{
	char *cpy = _strdup(str);

	if (strcmp(strtok(cpy, " "), "exit") == 0)
	{
		free(cpy);
		return (1);
	}
	free(cpy);
	return (0);
}

int checkEnv(char *str)
{
	char *cpy = _strdup(str);

	if (strcmp(strtok(cpy, " "), "env") == 0)
	{
		free(cpy);
		return (1);
	}
	free(cpy);
	return (0);
}

void sig_handler(__attribute__((unused))int signo)
{
	dprintf(STDOUT_FILENO, "\n$ ");
}

int args(char *str)
{
	int i = 1, counter = 0;

	if (str[0] != ' ')
		counter++;
	if (str[0] == ' ' && (str[1] != ' ' && str[1] != '\0'))
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
	dprintf(STDOUT_FILENO, "\n");
	free(buffer);
	exit(0);
}

void free_array_dup(char **array, char *dup)
{
	int i = 0;

	while (array[i] != NULL)
	{
		free(array[i]);
		i++;
	}
	free(array[i]);
	free(array);
	free(dup);
}

void printenv(void)
{
	int i = 0;

	while (environ[i])
	{
		printf("%s\n", environ[i++]);
	}
}
