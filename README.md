*This project has been created as part of the 42 curriculum by ooulahra*

# Get Next Line

## Description

**Get Next Line (GNL)** is a 42 School project written in C. The goal is to develop a function that reads and returns a line from a file descriptor, one line at a time.

The project introduces the concept of **static variables** and provides a deeper understanding of file descriptors, memory allocation, and buffer management.

The main function is:

```c
char *get_next_line(int fd);
```

Each call returns the next line from the specified file descriptor, including the newline character (`\n`) when present.

The function returns `NULL` when:
- There is nothing left to read (EOF).
- A reading or memory allocation error occurs.

The function must work with regular files and standard input.

## Instructions

### Compilation

Compile the mandatory files using:

```bash
cc -Wall -Wextra -Werror get_next_line.c get_next_line_utils.c main.c -o gnl
```

You can specify the buffer size at compilation:

```bash
cc -Wall -Wextra -Werror -D BUFFER_SIZE=42 get_next_line.c get_next_line_utils.c main.c -o gnl
```

You can change `BUFFER_SIZE` to test different buffer sizes.

### Execution

Run the executable with:

```bash
./gnl
```

To test a file, you can use a simple `main.c`:

```c
#include "get_next_line.h"
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    int     fd;
    char    *line;

    fd = open("test.txt", O_RDONLY);
    if (fd < 0)
        return (1);

    while ((line = get_next_line(fd)) != NULL)
    {
        printf("%s", line);
        free(line);
    }
    close(fd);
    return (0);
}
```

## Algorithm

### 1. Static Storage

The function uses a static variable to preserve unread data between successive calls.

Unlike a regular local variable, a static variable retains its value after the function returns.

This allows the function to remember data that was read from the file descriptor but has not yet been returned to the user.

### 2. Reading and Buffering

The function reads data using `read()` and stores it in a temporary buffer.

The amount of data read depends on `BUFFER_SIZE`.

Reading continues until one of the following conditions is reached:

- A newline character (`\n`) is found.
- The end of the file is reached.
- An error occurs.

The function does not need to read the entire file before returning a line.

### 3. Extracting a Line

Once a newline is found, the function extracts the first complete line from the stored data.

The extracted line is allocated dynamically using `malloc()`.

If the line ends with a newline character, that character must also be included in the returned string.

### 4. Preserving Remaining Data

After extracting the line, any remaining characters are preserved in the static storage.

This is important because the next call to `get_next_line()` must continue reading from where the previous call stopped.

The function uses this remaining data before requesting more data from `read()`.

### 5. End of File and Memory Management

When `read()` reaches EOF, the function checks whether any data remains.

- If data remains, it returns the final line, even if it does not end with `\n`.
- If no data remains, it returns `NULL`.

All dynamically allocated memory must be properly freed to prevent memory leaks.

### Algorithm Flow

```text
get_next_line(fd)
       |
       v
Check stored data
       |
       v
Is there a newline?
       |
   +---+---+
   |       |
  Yes      No
   |       |
   |    Read more data
   |       |
   |    EOF or error?
   |       |
   |    Append data
   |       |
   +---+---+
       |
       v
Extract the first line
       |
       v
Preserve remaining data
       |
       v
Return the line
```

## Technical Concepts

This project explores several important C programming concepts:

- **File Descriptors:** Understanding how files and standard input are accessed through file descriptors.
- **Static Variables:** Preserving information between function calls.
- **Dynamic Memory Allocation:** Using `malloc()` and `free()` to manage memory.
- **Buffer Management:** Reading data in fixed-size chunks.
- **String Manipulation:** Searching, extracting, and joining strings.
- **EOF Handling:** Understanding how `read()` behaves when the end of a file is reached.
- **Memory Management:** Avoiding memory leaks and invalid memory access.

## Resources

The following resources were useful for understanding the concepts behind this project:

- [read() — Linux Manual](https://man7.org/linux/man-pages/man2/read.2.html)
- [malloc() — Linux Manual](https://man7.org/linux/man-pages/man3/malloc.3.html)
- [free() — Linux Manual](https://man7.org/linux/man-pages/man3/free.3.html)
- [Static Variables in C](https://en.cppreference.com/w/c/language/static_storage_duration.html)
- [File Descriptors — Linux Manual](https://man7.org/linux/man-pages/man2/open.2.html)

### AI Usage

AI tools were used as learning support during this project.

They helped with:
- Understanding static variables and their lifetime.
- Understanding file descriptors and the behavior of `read()`.
- Exploring buffer management and line extraction.
- Understanding EOF handling and memory management.
- Investigating potential bugs and memory leaks.

The goal was to use AI as a learning resource to understand the underlying concepts and improve problem-solving skills rather than blindly copying solutions.

## Author

**ooulahra**

42 Network Student