#include "main.h"

/**
 * free_and_exit - frees the buffer and exit
 * @buffer: the buffer
 *
 * Return: void
 */
void free_and_exit(char *buffer)
{
	write(STDOUT_FILENO, "\n", 1);
	free(buffer);
	exit(0);
}
/**
 * free_array - frees an array
 * @array: the array
 *
 * Return: void
 */
void free_array(char **array)
{
	int i = 0;

	while (array[i] != NULL)
	{
		free(array[i]);
		i++;
	}
	free(array[i]);
	free(array);
}
/**
 * free_array_dup - to save space
 * @array: the array of arrays to release
 * @dup: the duplicated string to release
 *
 * Return: void
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
