#include "main.h"

/**
 * itsExecutable - Checks if a given path is an executable
 * @path: Route of the file
 *
 * Return: If it is an executable file or not
 */
int itsExecutable(char *path)
{
	if (isDir(path) == 0)
	{
		if (path[0] == '/')
			perror(path);
		else
			perror(path);
		return (1);
	}
	if (access(path, X_OK))
		return (2);
	else
		return (0);
}

/**
 * isDir - Checks if the path is a directory
 * @path: Route of the file
 *
 * Return: If it is a directory or not
 */
int isDir(const char *path)
{
	struct stat st = {0};

	stat(path, &st);
	return (S_ISREG(st.st_mode));
}

/**
 * getReturnValue - Get exit value
 * @str: String to traverse
 *
 * Return: The exit value
 */
int getReturnValue(char *str)
{
	char *cpy = _strdup(str), *token;
	int exitValue = 0;

	token = _strtok(cpy, ' ');
	token = _strtok(NULL, ' ');
	if (token == NULL)
	{
		free(cpy);
		return (0);
	}
	if (_isdigit(token) == 0)
		exitValue = _atoi(token);
	else
	{
		free(cpy);
		write(STDERR_FILENO, "exit: Illegal number\n", 22);
		return (-1);
	}
	free(cpy);
	if (exitValue < 0)
	{
		write(STDERR_FILENO, "exit: Illegal number\n", 22);
		exitValue = (-1);
	}
	return (exitValue);
}

/**
 * _isdigit - Chekcs if there are only digits in a given string
 * @str: String to traverse
 *
 * Return: If it's only digits or not
 */
int _isdigit(char *str)
{
	int i = 0, flag = 0;

	while (str[i])
	{
		if (str[i] >= 48 && str[i] <= 57)
		{
			i++;
			continue;
		}
		else
		{
			flag++;
			break;
		}
	}
	return (flag);
}
/**
 * child_fork - Forks a process
 * @child_pid: Process ID of the child process
 * @name: Name of the program
 *
 * Return: The child process ID
 */
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
