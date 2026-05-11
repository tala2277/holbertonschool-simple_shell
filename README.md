# Simple Shell

## Description

Simple Shell is a simple UNIX command interpreter written in C.

This project recreates basic functionalities of the UNIX shell. It reads commands from standard input, executes them, and manages processes using system calls.

The shell supports both interactive and non-interactive modes and behaves similarly to `/bin/sh`.

This project was developed as part of the Holberton School curriculum to strengthen understanding of:
- Processes
- System calls
- PATH handling
- Command execution
- Process management

---

## Features

- Displays a command prompt
- Executes commands with arguments
- Supports interactive mode
- Supports non-interactive mode
- Handles EOF condition (`Ctrl+D`)
- Uses `fork`, `execve`, and `wait`
- Uses the `PATH` environment variable
- Handles execution errors
- Includes built-in `exit`

---

## Requirements

- Ubuntu 20.04 LTS
- gcc compiler
- Betty coding style
- No memory leaks
- Maximum of 5 functions per file
- Header files must be include guarded

---

## Compilation

Compile the shell using:

gcc -Wall -Werror -Wextra -pedantic -std=gnu89 *.c -o hsh

---

## Usage

### Interactive Mode

$ ./hsh
($) /bin/ls
AUTHORS README.md main.c shell.c shell.h
($) exit
$

### Non-Interactive Mode

$ echo "/bin/ls" | ./hsh
AUTHORS README.md main.c shell.c shell.h
$

---

## Project Files

| File | Description |
|------|-------------|
| README.md | Project documentation |
| AUTHORS | Project contributors |
| man_1_simple_shell | Manual page |
| main.c | Main shell loop |
| shell.c | Command execution functions |
| shell.h | Header file |

---

## Authors

- Tala Alhudhaibi
- Laila Alghamdi

