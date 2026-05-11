#include "shell.h"

/**
 * main - simple shell main function
 *
 * Return: Always 0
 */
int main(void)
{
	char *line = NULL;
	char *token;
	char *args[64];
	size_t len = 0;
	int i;

	while (1)
	{
		display_prompt();

		if (getline(&line, &len, stdin) == -1)
		{
			free(line);
			exit(0);
		}

		line[strcspn(line, "\n")] = '\0';

		i = 0;
		token = strtok(line, " \t");
		while (token != NULL && i < 63)
		{
			args[i] = token;
			i++;
			token = strtok(NULL, " \t");
		}
		args[i] = NULL;

		if (args[0] == NULL)
			continue;

		if (strcmp(args[0], "exit") == 0)
		{
			free(line);
			exit(0);
		}

		execute_command(args);
	}

	return (0);
}
