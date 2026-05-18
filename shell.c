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
 * execute_command - executes command safely
 * @args: command and arguments
 * @prog_name: name of the shell program
 */
void execute_command(char **args, char *prog_name)
{
	pid_t pid;
	char *actual_cmd;

	if (args == NULL || args[0] == NULL)
		return;

	actual_cmd = get_location(args[0]);
	if (actual_cmd == NULL)
	{
		fprintf(stderr, "%s: No such file or directory\n", prog_name);
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
		perror(prog_name);
		free(actual_cmd);
		exit(EXIT_FAILURE);
	}
	wait(NULL);
	free(actual_cmd);
}
