# Lance Shell (Custom Shell Implementation in C)

Lance Shell is a custom shell implementation in the C programming language. This project aims to create a simple yet functional shell that provides basic command execution, input/output redirection, variable handling, and more. It is designed for educational purposes and serves as a platform for learning about Unix-like shells and systems programming in C.

## Features

Lance Shell offers the following features:

- Command execution: Execute system commands and display their output.
- Interactive and file modes: Run the shell interactively from the command line or provide a script file for execution.
- Input and output redirection: Redirect input and output using `<`, `>`, and `>>` operators.
- Basic built-in commands: Implement built-in commands like `cd`, `pwd`, `alias`, `setenv`, `unsetenv`, and more.
- Environment variable handling: Support for environment variable manipulation and expansion.
- Alias management: Define and list aliases for commonly used commands.
- Variable replacement: Replace special variables like `$$`, `$?`, and `$PATH` in command strings.
- Logical operators: Implement logical `&&` and `||` operators for command chaining.
- Comment handling: Ignore comments in script files starting with `#`.

## File Structure

The project is organized into several source files for modularity and maintainability:

- `_allocate_input_buffer.c`: Handles memory allocation for input.
- `_input_processor.c`: Reads and processes user input.
- `_prompt_processor.c`: Processes and executes prompt strings.
- `_handle_alias.c`: Handles alias management.
- `_handle_cd.c`: Implements the `cd` built-in command.
- `_handle_pwd.c`: Implements the `pwd` built-in command.
- `_handle_setenv.c` and `_handle_unsetenv.c`: Implement the `setenv` and `unsetenv` built-in commands.
- `_handle_dollar.c`: Handles variable replacement for `$?`, `$$`, and `$PATH`.
- `_handle_logical_and.c` and `_handle_logical_or.c`: Implement logical `&&` and `||` operators.
- `_handle_comments.c`: Handles comments in input.
- `helpers.c` and `helpers.h`: Contain various utility functions.
- `lance.c` and `lance.h`: The main Lance Shell program and header.

## Getting Started

To compile and run Lance Shell:

1. Clone the repository to your local machine.
2. Compile the source code using a C compiler (e.g., `gcc -o lance lance.c _allocate_input_buffer.c _input_processor.c ...`).
3. Run the compiled binary (`./lance`) to start the shell.

## Usage

Lance Shell supports both interactive and file execution modes:

### Interactive Mode

In interactive mode, Lance Shell provides a command prompt where you can enter and execute commands directly. Simply run the shell without any arguments:

```
$ ./lance
Lance-Shell$ ls
file1.txt  file2.txt  directory/
Lance-Shell$ pwd
/home/user/
Lance-Shell$ exit
```

### File Mode

In file mode, you can provide a script file with commands to be executed by Lance Shell. Provide the script file as an argument when running the shell:

```
$ ./lance script.txt
```

## Acknowledgments

Lance Shell was developed as an educational project to learn about Unix-like shells and C programming. It draws inspiration from various Unix shells and shell scripting concepts.
