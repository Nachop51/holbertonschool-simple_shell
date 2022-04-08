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
		_isattyAndSignal();
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

/**
 * waitIsatty - Looks for isatty and frees things
 * @status: Status of the process
 * @argv: Array to free
 * @dup: Duplicated array to free
 *
 * Return: Returns the status of isatty
 */
int waitIsatty(int status, char **argv, char *dup)
{
	int i = 0;

	wait(&status);
	i = isatty(STDIN_FILENO);
	free_array_dup(argv, dup);
	return (i);
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

/**
 * _isattyAndSignal - Looks for signals and checks the isatty function
 */
void _isattyAndSignal(void)
{
	signal(SIGINT, sig_handler);
	if ((isatty(STDIN_FILENO) == 1))
		printf("$ ");
}

/**
 * _checkChars - Looks for a character in the buffer
 * @str: The buffer
 * Return: If there's a char or not
 */
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

/**
 * clearBuffer - Removes the '\n' char, and looks for tabulations
 * @str: The buffer
 * @counter: Length of the string
 * Return: The clean buffer
 */
char *clearBuffer(char *str, int counter)
{
	str[counter - 1] = '\0';
	str = searchAndDestroy(str);
	str = searchAndReplace(str);
	return (str);
}

/**
 * searchAndReplace - Looks for a ~ and replaces it for the variable $HOME
 * ~/../home/shell/simple_shell/n/a.out
 * @str: String to traverse
 * Return: The modified string or just the string
 */
char *searchAndReplace(char *str)
{
	int i = 0, tilde = 0, j = 0, flag = 0;
	char *cpy = _strdup(str), *home = NULL, *concatenated = NULL, *new = NULL;

	while (str[i])
	{
		if (str[i] == '~')
			tilde++;
		i++;
	}
	i = 0;
	if (tilde > 0)
	{
		home = _getenv("HOME");
		free(str);
		while (cpy[j])
		{
			while (cpy[i])
			{
				if (cpy[i] == '~')
				{
					flag++;
					break;
				}
				else
					cpy[i] = str[i];
				i++;
			}
			if (flag == 1)
			{
				new = malloc(sizeof(i) + 1);
				strncpy(new, str, i);
				new[i + 1] = '\0';
				concatenated = str_concat(new, home);
			}
			j++;
		}
		free(home);
	}
	free(cpy);
	printf("str:%s\n", concatenated);
	return (str);
}

/**
 * searchAndDestroy - Looks for a tabulation and erases it
 * @str: String to traverse
 *
 * Return: The modified string or just the string
 */
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

/**
 * _checkBuiltIn - Checks if there's a Built-In in the buffer or not
 * @str: String to traverse
 *
 * Return: If there's a coincidence or not
 */
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

/**
 * checkDir - Built-In checker for cd (cd function)
 * @str: String to compare
 *
 * Return: If there's a coincidence or not
 */
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

/**
 * checkExit - Built-In checker for exit
 * @str: String to compare
 *
 * Return: If there's a coincidence or not
 */
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

/**
 * checkEnv - Built-In checker for env
 * @str: String to compare
 *
 * Return: If there's a coincidence or not
 */
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

/**
 * sig_handler - Signal handler for ^C
 * @signo: Signal number
 */
void sig_handler(__attribute__((unused))int signo)
{
	dprintf(STDOUT_FILENO, "\n$ ");
}

/**
 * args - Counts all the possibles arguments of a function
 * @str: String to traverse
 *
 * Return: The possibles arguments
 */
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

/**
 * free_and_exit - Frees a buffer and exits the function
 * @buffer: Buffer to free
 */
void free_and_exit(char *buffer)
{
	dprintf(STDOUT_FILENO, "\n");
	free(buffer);
	exit(0);
}

/**
 * free_array_dup - Frees an array and the duplicated string
 * @array: Array to free
 * @dup: Duplicated string to free
 */
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

/**
 * printenv - Prints out all the environment variables
 */
void printenv(void)
{
	int i = 0;

	while (environ[i])
	{
		printf("%s\n", environ[i++]);
	}
}

/**
 * string_nconcat - concatenates two strings in n bytes
 * @s1: String 1
 * @s2: String 2
 * @n: number of bytes
 *
 * Return: string concatenated
 */
char *string_nconcat(char *s1, char *s2, unsigned int n)
{
	unsigned int i = 0, j = 0, x = 0, a = 0;
	char *str;

	if (s1 == NULL)
		s1 = "";
	if (s2 == NULL)
		s2 = "";
	while (s1[i])
		i++;
	while (s2[j])
		j++;
	if (n >= j)
	{
		n = j;
	}
	str = malloc(sizeof(char) * (i + n + 1));
	if (str == NULL)
		return (NULL);

	for (x = 0; x < i; x++)
		str[x] = s1[x];
	for (; x < (n + i); x++, a++)
		str[x] = s2[a];
	str[x] = '\0';
	return (str);
}