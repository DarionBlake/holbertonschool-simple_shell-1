<h1 align="center">
C - Simple Shell
</h1>

<p align="center">
  <strong>
   Description
  </strong>
</p>

<p align="center">
This project is an implementation of a simple shell that was developed as a Peer Programming project for C programming language. </br>
This first trimester project teaches students the more complex ideas underlying the shell program, including as processes, system calls, bit manipulation, file management, and error handling. </br>

Shell is a basic command interpreter for UNIX that mimics the features of the simple shell (sh). </br>

All of the programming for this program was done in the C programming language.
</p>

## COPYRIGHT
Copyright (C) 2022 by [**Junius Whitaker**](https://github.com/HolbertonFalcon) </br>
All rights reserved

 ## Description :
This is a shell written in [C](https://en.wikipedia.org/wiki/C_(programming_language)).
It is based on [the Thompson Shell](https://en.wikipedia.org/wiki/Thompson_shell).

## Environment :

Our shell was built and tested on  Ubuntu 20.04 LTS.

## Features
* Issue a prompt and watch for a command to be typed by the user. A new line appears at the end of every command line.
* In the event that an executable cannot be located, reprint the prompt along with an error message.
* Deal with mistakes.
* Using the Command Line with Arguments; * Handling the "end of file" condition (Ctrl+D);
* Handle the command separator {;} Handle the logical operators {&&{ and {||} Handle the variable replacements {$?{ and {$${ Handle the comments {#{ Support the history
* feature Handle the PATH Support the exit features and the exit status Handle the Ctrl-C to not terminate the shell

## Builtins
Our shell has support for the following built-in commands:

| Command             | Definition                                                                                |
| ------------------- | ----------------------------------------------------------------------------------------- |
| exit [n]            | Exit the shell, with an optional exit status, n.                                          |
| env                 | Print the environment.                                                                    |
| setenv [var][value] | Set an environment variable and value. If the variable exists, the value will be updated. |
| alias[name[='value]]| Reads aliases name                                                                        |
| unsetenv [var]      | Remove an environment variable.                                                           |
| cd [dir]            | Change the folder.                                                                     |
| help [built-in]     | Read documentation for a built-in.                                                        |


 ## Installation : Getting HSH
 
Clone the below repository and compile the files into an executable using the GCC compiler.
```
https://github.com/holbertonfalcon/simple_shell.git
```

### Basic usage :bulb:
- First, Fork this Repository [Learn how to fork repo](https://docs.github.com/en/github/getting-started-with-github/fork-a-repo).
- Then Clone [Learn how to clone ](https://docs.github.com/en/github/creating-cloning-and-archiving-repositories/cloning-a-repository).
- Create an executable by running the following command:
- `gcc -Wall -Werror -Wextra -pedantic *.c -o hsh`
- From there, type in the following command and press your enter button.
- `./hsh`
- Final step: ENJOY!


## Example :computer:
```
 $ ./simple_shell
           # /bin/ls
           hsh main.c shell.c
           #
           # exit
           $
```
!

## Contributors :
* [**Darion Woodard**](https://github.com/DarionBlake)



