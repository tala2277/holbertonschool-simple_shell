# Simple Shell

## Description

Simple Shell is a simple UNIX command interpreter written in C.

The program reads commands from standard input, executes them, and prints the result. It works in interactive mode and non-interactive mode, similar to /bin/sh.

This project is part of the Holberton School curriculum and helps practice processes, system calls, PATH handling, and command execution.

## Features

- Displays a prompt in interactive mode
- Reads user input from standard input
- Executes commands
- Works in interactive and non-interactive modes
- Handles end-of-file with Ctrl+D
- Uses fork, execve, and wait
- Includes a manual page
- Follows Betty style requirements

## Compilation

gcc -Wall -Werror -Wextra -pedantic -std=gnu89 *.c -o hsh

## Usage

Interactive mode:

./hsh

Non-interactive mode:

echo "/bin/ls" | ./hsh

## Authors

- Tala Alhudhaibi
- Laila Alghamdi
