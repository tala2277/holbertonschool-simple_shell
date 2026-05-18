#include "shell.h"

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
	for (i = 0; environ[i]; i++)
	{
		if (strncmp(environ[i], name, len) == 0 && environ[i][len] == '=')
			return (environ[i] + len + 1);
	}
	return (NULL);
}

/**
 * get_location - finds the exact path of a command
 * @cmd: the command to find
 *
 * Return: full path of the command, or NULL
 */
char *get_location(char *cmd)
{
	char *path, *p_cpy, *tok, *f_path;
	struct stat st;

	if (cmd == NULL)
		return (NULL);
	if (strchr(cmd, '/'))
	{
		if (stat(cmd, &st) == 0)
			return (strdup(cmd));
		return (NULL);
	}
	path = _getenv("PATH");
	if (!path || *path == '\0')
		return (NULL);
	p_cpy = strdup(path);
	if (!p_cpy)
		return (NULL);
	tok = strtok(p_cpy, ":");
	while (tok)
	{
		f_path = malloc(strlen(tok) + strlen(cmd) + 2);
		if (!f_path)
		{
			free(p_cpy);
			return (NULL);
		}
		sprintf(f_path, "%s/%s", tok, cmd);
		if (stat(f_path, &st) == 0)
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
