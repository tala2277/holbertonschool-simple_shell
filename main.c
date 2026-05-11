#include "shell.h"

/**
 * main - simple shell main function
 *
 * Return: Always 0
 */
int main(void)
{
	char *line = NULL;
	char *command;
	size_t len = 0;

	while (1)
	{
		display_prompt();

		if (getline(&line, &len, stdin) == -1)
		{
			free(line);
			exit(0);
		}

		line[strcspn(line, "\n")] = '\0';

		command = strtok(line, " ");

		if (command == NULL)
			continue;

		if (strcmp(command, "exit") == 0)
		{
			free(line);
			exit(0);
		}

		execute_command(command);
	}

	free(line);

	return (0);
}
