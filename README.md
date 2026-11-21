*This project has been created as part of the 42 curriculum by hsalahal.*

# get_next_line

## 1. Description

The aim of this project is to make you code a function that returns a line, read from a file descriptor._

This project will not only allow you to add a very convenient function to your collection, but it will also make you learn a highly interesting new concept in C programming: static variables.

You will understand how files are opened, read and closed in an OS, and how they are interpreted by a programming language for further analysis. This task is crucial to understand for a future programmer since much of the time is based on manipulating files for data management and persistence. This project consists of coding a function that returns one line at a time from a text file.

## 2. Requirements

The function is written in C language and thus needs the gcc/cc compiler and some standard C libraries to run.

## 3. Instructions

### 1. Using it in your code

To use the function in your code, simply include its header:

#include "get_next_line.h"
and, when compiling your code, add the source files and the required flag:

get_next_line.c get_next_line_utils.c -D BUFFER_SIZE=<size>

### 2. Testing
You can edit test.txt files to put another text if you wish to test out the cases. Then simply run this command (change "xx" with desired buffer size) :

gcc -Wall -Werror -Wextra -D BUFFER_SIZE=xx get_next_line.c get_next_line_utils.c && ./a.out

### 3. Testing with Standard Input (stdin)
You can also test get_next_line() using standard input (fd = 0) instead of reading from a file.

Compile your program:


bash
cc -Wall -Werror -Wextra -D BUFFER_SIZE=42 get_next_line.c get_next_line_utils.c main.c
Run it:


bash
./a.out
Then type some lines directly into the terminal. Press Ctrl + D to indicate EOF and stop the input.

Example:


text
Hello 42!
Testing get_next_line.
This is standard input.
^D
The function should return each line separately, including the newline character when present, until EOF is reached.

Note: Standard input uses file descriptor 0, so you can call:


line = get_next_line(0);

## 4. Resources
### 1. Man Pages

man read  – Reading data from file descriptors.

man open  – Opening files.

man close  – Closing file descriptors.

man malloc  – Dynamic memory allocation.

man free  – Releasing allocated memory.

man stat  – Getting file information.

C Reference – Static Variables  – Understanding static storage duration.

### 2. Concepts Studied
File descriptors and file handling.

The read() system call.

Static variables.

Dynamic memory allocation (malloc, free).

Linked lists.

Buffer management.

String manipulation.

Memory management and memory leaks.

EOF and error handling.

Multiple file descriptors (bonus).

### 3. AI Usage
AI tools (ChatGPT) were used for:

Understanding concepts related to static variables, file descriptors, buffers, and linked lists.

Clarifying the behavior of read(), EOF, and different BUFFER_SIZE values.

Getting assistance with identifying potential bugs and understanding memory management.

Organizing and writing the project documentation (README.md).