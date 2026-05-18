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
 * _getenv - gets the value of an environment variable
 * @name: name of the variable to look for
 *
 * Return: pointer to the value, or NULL if not found
 */
char *_getenv(const char *name)
{
	int i = 0;
	size_t len;

	if (name == NULL || environ == NULL)
		return (NULL);

	len = strlen(name);
	while (environ[i])
	{
		if (strncmp(environ[i], name, len) == 0 && environ[i][len] == '=')
			return (environ[i] + len + 1);
		i++;
	}
	return (NULL);
}

/**
 * get_location - finds the exact path of a command
 * @command: the command to find
 *
 * Return: full path of the command, or NULL
 */
char *get_location(char *command)
{
	char *path, *p_cpy, *tok, *f_path;
	struct stat buffer;

	if (command == NULL)
		return (NULL);
	if (strchr(command, '/'))
	{
		if (stat(command, &buffer) == 0)
			return (strdup(command));
		return (NULL);
	}
	path = _getenv("PATH");
	if (!path)
		return (NULL);
	p_cpy = strdup(path);
	tok = strtok(p_cpy, ":");
	while (tok)
	{
		f_path = malloc(strlen(command) + strlen(tok) + 2);
		if (!f_path)
		{
			free(p_cpy);
			return (NULL);
		}
		sprintf(f_path, "%s/%s", tok, command);
		if (stat(f_path, &buffer) == 0)
		{
			free(p_cpy);
			return (f_path);
		}
		free(f_path);
		tok = strtok(NULL, ":");
	}
	free(p_cpy);
	return (NULL);
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

