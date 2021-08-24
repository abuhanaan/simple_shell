ALX - Simple Unix Like Shell
===========================
     C programming with ALX School!
================================================================================

## Description:
    
This project is based on the implementation of a simple shell. The shell is an interactive interface that allows users to execute commands and utilities in Linux and other UNIX-based operating systems. Shells use either a command-line interface or graphical user interface, depending on a computer's role and particular operation.

## Installation:

- clone the repository

     https://github.com/abuhanaan/simple_shell.git

- compile with

     gcc -Wall -Werror -Wextra -pedantic *.c -o tsh


## Example:

     ubuntu@ubuntu$ ./hsh     
     $ pwd
     /home/ubuntu/simple_shell
     $ /bin/pwd
     /home/ubuntu/simple_shell
     $ ls -la
     -rw-rw-r-- 1 vagrant vagrant  bytes <date> builtins.c
     -rw-rw-r-- 1 vagrant vagrant   bytes <date> shell.h

## Builtins commands:

     exit: exits a shell
     
     env: show/displays environment variables
     
## Special Features:

     Ctrl + C: To prevent the killing of the simple-shell
     
     Ctrl + D: exit the simple-shell

## Files:

     AUTHORS: This file contains all the contributors to this repository.

     README.md: This file contains this readme text.

     man_1_simple_shell: The man page for our shell.
