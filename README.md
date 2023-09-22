# Lance Shell (Custom Shell Implementation in C)

This is a simple shell program written in C that provides a basic command-line interface for executing commands and managing processes. It supports executing commands with or without absolute paths, handling the PATH environment variable, and gracefully exiting the shell.

## Features

- Command execution with or without specifying absolute paths.
- PATH environment variable lookup for command execution.
- Handling of CTRL+D signal for graceful exit.
- Interactive and non-interactive modes.
- Error handling and error messages.

## Usage

To compile the shell program, use the following command:

shell
gcc -o hsh *.c

You can then run the shell using:

shell
./hsh

The shell will display a prompt `hsh>`, where you can enter commands to be executed.

## Commands

- Supported shell commands, e.g., `ls`, `pwd`, `echo`, etc.
- The `exit` command to gracefully exit the shell.

## Examples

hsh> ls
hsh> pwd
hsh> echo Hello, World!
hsh> exit

## Requirements

- A C compiler (e.g., GCC) to compile the code.
- A UNIX-like operating system (Linux, macOS) for proper execution.

## License

## Acknowledgments
Lance Shell was developed as an educational project to learn about Unix-like shells and C programming. It draws inspiration from various Unix shells and shell scripting concepts.
