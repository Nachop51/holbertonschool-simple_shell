#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(void)
{
	printf("Output:\n");
	system("echo ls | ./hsh");
	system("echo ls | ./hsh | wc -m");
	printf("Expected:\n");
	system("echo ls | sh");
	system("echo ls | sh | wc -m");
	printf("Output:\n");
	system("echo ls -l | ./hsh");
	system("echo ls -l | ./hsh | wc -m");
	printf("Expected:\n");
	system("echo ls -l | sh");
	system("echo ls -l | sh | wc -m");

	return (0);
}
