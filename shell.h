#ifndef SHELL_H
#define SHELL_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/wait.h>

extern char **environ;

void display_prompt(void);
void execute_command(char **args);
char *_getenv(const char *name);
char *get_location(char *command);


#endif
