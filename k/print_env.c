#include "main.h"

/**
 * printenv - prints the enviroment
 *
 * Return: void
 */
void main()
{
	printenv();
}
void printenv(void)
{
	int i = 0;

	while (environ[i])
	{
		printf("%s\n", environ[i++]);
	}
}
