#include "main.h"

/**
 * sig_handler - handle the Control+C signal
 * @signo: the signal
 *
 * Return: void
 */
void sig_handler(__attribute__((unused))int signo)
{
	write(STDOUT_FILENO, "\n$ ", 3);
}
/**
 * args - counts how many arguments are
 * @str: the string
 *
 * Return: the amount of arguments
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
	printf("%d\n", counter);
	return (counter);
}
