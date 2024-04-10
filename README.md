#pipex
!GitHub

pipex is a project from École 42 that delves into the intricacies of UNIX mechanisms, specifically the concept of pipes.

## Description
The purpose of this project is to replicate the behavior of the following shell command:

$ < file1 cmd1 | cmd2 > file2

In other words, pipex should execute two commands (cmd1 and cmd2) with input from file1 and direct the output to file2. The program should handle various scenarios, including incorrect commands, file permissions, and more.

## Mandatory Part
To use pipex, follow this format:

$ ./pipex file1 cmd1 cmd2 file2

## Installation

Clone the repository:
```
git clone https://github.com/rabatm/pipex_42.git
cd pipex_42
```

Compile the project:
```
make
```

## License
Minishell is licensed under MIT License. See LICENSE for full details.

## Authors
rabatm - https://github.com/rabatm

Please note that all functions are created in accordance with the Norm – a set of rules governing code formatting at École 42. \
Happy piping! 🚀
