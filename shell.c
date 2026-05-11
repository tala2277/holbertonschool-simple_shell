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
 * @command: command entered by user
 */
void execute_command(char *command)
{
	pid_t pid;
	char *args[2];

	args[0] = command;
	args[1] = NULL;

	pid = fork();

	if (pid == -1)
	{
		perror("Error");
		return;
	}

	if (pid == 0)
	{
		execve(command, args, environ);
		perror("./hsh");
		exit(EXIT_FAILURE);
	}
	else
	{
		wait(NULL);
	}
}
