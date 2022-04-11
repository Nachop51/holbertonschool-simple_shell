#include "main.h"

/**
 * _checkChars - Looks for a character in the buffer
 * @str: The buffer
 * Return: If there's a char or not
 */
int _checkChars(char *str)
{
	int i = 0, r = -1;

	if (str[0] == '#')
		return (r);
	while (str[i])
	{
		if (str[i] != 32 && str[i] != 10 && str[i] != '\t' && str[i] != '#')
		{
			r = 0;
			if (str[0] == ' ' && str[1] != ' ')
			{
				str = _strtok(str, ' ');
			}
			break;
		}
		if (str[i] == '#')
			break;
		i++;
	}
	return (r);
}
/**
 * checkDir - Built-In checker for cd (cd function)
 * @str: String to compare
 *
 * Return: If there's a coincidence or not
 */
int checkDir(char *str)
{
	char *cpy = _strdup(str), *dir = NULL, *PWD = NULL, *buffer = NULL;
	int builtIn = 0, flag = 0;

	if (_strcmp(_strtok(cpy, ' '), "cd") == 0)
	{
		dir = _strtok(NULL, ' ');
		if (dir == NULL)
		{
			dir = _getenv("HOME");
			flag++;
		}
		if (_strcmp(dir, "-") == 0)
		{
			dir = _getenv("OLDPWD");
			flag++;
		}
		PWD = _getenv("PWD");
		_setenv("OLDPWD", PWD, 1);
		_setenv("PWD", dir, 1);
		if (chdir(dir) != 0)
			perror(dir);
		builtIn++;
	}
	if (flag > 0)
		free(dir);
	free(cpy);
	free(buffer);
	free(PWD);
	return (builtIn);
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
		return (2);
	if (checkExit(str) == 1)
		return (1);
	if (checkEnv(str) == 1)
		return (3);
	if (checkUnset(str) == 1)
		return (4);
	if (checkSetenv(str) == 1)
		return (5);
	if (checkHelp(str) == 1)
		return (6);
	return (0);
}

/**
 * checkHelp - Built-In checker for Help
 * @str: String to compare
 *
 * Return: If there's a coincidence or not
 */
int checkHelp(char *str)
{
	char *cpy = _strdup(str), *name = NULL;

	if (_strcmp(_strtok(cpy, ' '), "help") == 0)
	{
		name = _strtok(NULL, ' ');
		if (name == NULL)
		{
			write(1, "Usage: help [BUILTIN]\nList of Built-Ins\n", 41);
			write(1, "cd\nexit\nsetenv\nunsetenv\nenv\nhelp\n", 34);
			free(cpy);
			return (1);
		}
		else
		{
			while (name != NULL)
			{
				helpCase(name);
				name = _strtok(NULL, ' ');
			}
		}
		free(cpy);
		return (1);
	}
	free(cpy);
	return (0);
}
/**
 * helpCase - Prints out a shor help message
 * @name: Name of the Built-In
 */
void helpCase(char *name)
{
	if (_strcmp(name, "cd") == 0)
	{
		write(1, "cd [dir]\nChange the shell working directory.\n", 46);
	}
	else if (_strcmp(name, "exit") == 0)
	{
		write(1, "exit [n]\nExits the shell with a status of N.\n", 46);
	}
	else if (_strcmp(name, "setenv") == 0)
	{
		write(1, "setenv [var] [value]\nSet environment variables.\n", 49);
	}
	else if (_strcmp(name, "unsetenv") == 0)
	{
		write(1, "unsetenv [var]\nUnset environment variables.\n", 45);
	}
	else if (_strcmp(name, "help") == 0)
	{
		write(1, "help [BUILTIN]\nDisplays information for Buitlt-Ins.\n", 53);
	}
	else if (_strcmp(name, "env") == 0)
	{
		write(1, "env\nPrint all environment variables.\n", 38);
	}
	else
	{
		write(1, "Wrong Built-In, use help to list all Built-Ins\n", 48);
	}
}
