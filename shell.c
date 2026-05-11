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
	char *args[] = {command, NULL};

	pid = fork();

	if (pid == 0)
	{
		execve(command, args, NULL);
		perror("./hsh");
		exit(1);
	}
	else
	{
		wait(NULL);
	}
}
