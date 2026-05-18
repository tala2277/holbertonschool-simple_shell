#include "shell.h"

/**
 * display_prompt - displays shell prompt
 */
void display_prompt(void)
{
	if (isatty(STDIN_FILENO))
		printf("($) ");
}

/**
 * execute_command - executes command
 * @args: command and arguments
 */
void execute_command(char **args)
{
	pid_t pid;

	pid = fork();
	if (pid == -1)
	{
		perror("Error");
		return;
	}
	if (pid == 0)
	{
		execve(args[0], args, environ);
		perror("./hsh");
		exit(EXIT_FAILURE);
	}
	wait(NULL);
}
