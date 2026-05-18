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
	char *actual_cmd;

	if (args == NULL || args[0] == NULL)
		return;

	actual_cmd = get_location(args[0]);
	if (actual_cmd == NULL)
	{
		fprintf(stderr, "./hsh: 1: %s: not found\n", args[0]);
		return;
	}

	pid = fork();
	if (pid == -1)
	{
		perror("Error");
		free(actual_cmd);
		return;
	}
	if (pid == 0)
	{
		execve(actual_cmd, args, environ);
		perror("./hsh");
		free(actual_cmd);
		exit(EXIT_FAILURE);
	}
	wait(NULL);
	free(actual_cmd);
}
