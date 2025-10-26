<h1 align="center">
	📖 get_next_line
</h1>

<p align="center">
	<b><i>Reading a line on a fd is way too tedious</i></b><br>
</p>

<p align="center">
	<img alt="GitHub code size in bytes" src="https://img.shields.io/github/languages/code-size/handyman0/42-get_next_line?color=lightblue" />
	<img alt="Number of lines of code" src="https://img.shields.io/tokei/lines/github/handyman0/42-get_next_line?color=critical" />
	<img alt="Code language count" src="https://img.shields.io/github/languages/count/handyman0/42-get_next_line?color=yellow" />
	<img alt="GitHub top language" src="https://img.shields.io/github/languages/top/handyman0/42-get_next_line?color=blue" />
	<img alt="GitHub last commit" src="https://img.shields.io/github/last-commit/handyman0/42-get_next_line?color=green" />
</p>

<h3 align="center">
	<a href="#-about">About</a>
	<span> · </span>
	<a href="#-usage">Usage</a>
	<span> · </span>
	<a href="#-testing">Testing</a>
</h3>

---

## 💡 About the project

> _This project is about programming a function that returns a line read from a file descriptor._

This project will not only allow you to add a very convenient function to your collection,
but it will also make you learn a highly interesting new concept in C programming: static variables.

The goal is to create a function that reads a file descriptor line by line, handling multiple file descriptors simultaneously and managing memory efficiently.

## 🛠️ Usage

### Requirements

The function is written in C language and thus needs the **`gcc` compiler** and some standard **C libraries** to run.

### Instructions

**1. Compiling the library**

To compile, go to the library path and run:

For mandatory part:
```shell
$ make
```

For bonus part:
```shell
$ make bonus
```

**2. Using it in your code**

To use the function in your code, simply include the header:

For mandatory part:
```C
#include "get_next_line.h"
```

For bonus part:
```C
#include "get_next_line_bonus.h"
```

Example usage:
```C
#include <fcntl.h>
#include <stdio.h>
#include "get_next_line.h"

int main(void)
{
    int fd;
    char *line;

    fd = open("file.txt", O_RDONLY);
    while ((line = get_next_line(fd)) != NULL)
    {
        printf("%s", line);
        free(line);
    }
    close(fd);
    return (0);
}
```

## 📋 Testing

You can use this third party tester to fully test the project:

* [Tripouille/gnlTester](https://github.com/Tripouille/gnlTester)

### Project Structure

#### Mandatory part
- [`get_next_line.c`](https://github.com/handyman0/42-get_next_line/blob/main/get_next_line.c) - Main function implementation
- [`get_next_line.h`](https://github.com/handyman0/42-get_next_line/blob/main/get_next_line.h) - Header file for mandatory part
- [`get_next_line_utils.c`](https://github.com/handyman0/42-get_next_line/blob/main/get_next_line_utils.c) - Utility functions for mandatory part

#### Bonus part
- [`get_next_line_bonus.c`](https://github.com/handyman0/42-get_next_line/blob/main/get_next_line_bonus.c) - Main function implementation for bonus (multiple file descriptors)
- [`get_next_line_bonus.h`](https://github.com/handyman0/42-get_next_line/blob/main/get_next_line_bonus.h) - Header file for bonus part
- [`get_next_line_utils_bonus.c`](https://github.com/handyman0/42-get_next_line/blob/main/get_next_line_utils_bonus.c) - Utility functions for bonus part

#### Subject
- [`get_next_line.pdf`](https://github.com/handyman0/42-get_next_line/blob/main/get_next_line.pdf) - Project subject

### Features

- ✅ Reads from file descriptors line by line
- ✅ Handles multiple file descriptors (bonus)
- ✅ Efficient memory management
- ✅ Buffer size can be set at compile time
- ✅ Robust error handling
