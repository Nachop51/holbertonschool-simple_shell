#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int main(void)
{
	int i;
	pid_t child_pid;
	int status;
	char *argv[] = {"/bin/ls", "-l", "/tmp", NULL};

	for (i = 0; i < 5; i++)
	{
		child_pid = fork();
		if (child_pid == -1)
		{
			perror("Error:");
			return (1);
		}
		if (child_pid == 0)
		{
			execve(argv[0], argv, NULL);
		}
		else
		{
			wait(&status);
		}
	}
	return (0);
}
