#include <stdio.h>

/**
 * main - strtok
 *
 * Return: anose
 */

int main(int ac, char **av)
{
	char *str[10];
	char *ava;
	int a = 0, i = 0, j = 0, k = 0;

	while (a < ac)
	{
		ava = av[a];
		for (; ava[i]; i++, k++)
		{
			if (ava[i] != ' ')
			{
				str[j][k] = ava[i];
			}
			else
			{
				j++;
				k = 0;
			}
		}
		printf("%s", str[j]);
	}
	return (0);
}
