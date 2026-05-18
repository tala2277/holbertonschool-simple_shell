#include "shell.h"

/**
 * tokenize_input - splits the input line into tokens
 * @line: the string to tokenize
 * @args: the array to store the tokens
 */
void tokenize_input(char *line, char **args)
{
	char *token;
	int i = 0;

	token = strtok(line, " \t");
	while (token != NULL && i < 63)
	{
		args[i] = token;
		i++;
		token = strtok(NULL, " \t");
	}
	args[i] = NULL;
}

/**
 * main - simple shell main function
 * @argc: argument count
 * @argv: argument vector
 *
 * Return: Always 0
 */
int main(int argc, char **argv)
{
	char *line = NULL;
	char *args[64];
	size_t len = 0;
	int status = 0;
	int e;

	(void)argc;

	while (1)
	{
		display_prompt();
		if (getline(&line, &len, stdin) == -1)
		{
			free(line);
			exit(status);
		}
		line[strcspn(line, "\n")] = '\0';
		tokenize_input(line, args);

		if (args[0] == NULL)
			continue;
		if (strcmp(args[0], "exit") == 0)
		{
			free(line);
			exit(status);
		}
		if (strcmp(args[0], "env") == 0)
		{
			e = 0;
			while (environ[e] != NULL)
			{
				printf("%s\n", environ[e]);
				e++;
			}
			continue;
		}
		status = execute_command(args, argv[0]);
	}
	return (status);
}
