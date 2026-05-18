#include "shell.h"

void display_prompt(void)
{
	if (isatty(STDIN_FILENO))
		printf("($) ");
}

int execute_command(char **args, char *prog_name)
{
	pid_t pid;
	char *actual_cmd;
	int status;

	if (args == NULL || args[0] == NULL)
		return (0);

	actual_cmd = get_location(args[0]);
	if (actual_cmd == NULL)
	{
		fprintf(stderr, "%s: 1: %s: not found\n", prog_name, args[0]);
		return (127);
	}

	pid = fork();
	if (pid == -1)
	{
		perror("Error");
		free(actual_cmd);
		return (1);
	}
	if (pid == 0)
	{
		execve(actual_cmd, args, environ);
		perror(prog_name);
		free(actual_cmd);
		exit(127);
	}
	wait(&status);
	free(actual_cmd);
	if (WIFEXITED(status))
		return (WEXITSTATUS(status));
	return (0);
}
