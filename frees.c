#include "main.h"

/**
 * free_buff_and_env - Frees the buffer and an environ variable
 * @str: Buffer to free
 */
void free_buff_and_env(char *str)
{
	free(str);
}
/**
 * waitAndFree - Waits and frees things
 * @status: Status of the process
 * @argv: Array to free
 * @dup: Duplicated array to free
 *
 * Return: Returns the status of isatty
 */
void waitAndFree(int status, char **argv, char *dup)
{
	wait(&status);
	free_array_dup(argv, dup);
}
/**
 * free_and_exit - Frees a buffer and exits the function
 * @buffer: Buffer to free
 */
void free_and_exit(char *buffer)
{
	if (isatty(STDIN_FILENO) == 1)
		write(STDOUT_FILENO, "\n", 1);
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
 * free_environ - frees all the environ[i] used in the function _setenv
 * @var_name: the name of the variable
 *
 * Return: asd
 */
void free_environ(char *var_name)
{
	size_t len = 0;
	int i = 0;

	len = strlen(var_name);
	while (environ[i] != NULL)
	{
		if (strncmp(environ[i], var_name, len) == 0)
		{
			free(environ[i]);
		}
		i++;
	}
}
