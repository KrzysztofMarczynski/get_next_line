# get_next_line

`get_next_line` is a C function that reads a file descriptor and returns one line at a time.

The main goal of this project is to understand how file reading works in C and how to manage memory efficiently when the size of the input is unknown.

This function can read from files, standard input, or other file descriptors and returns a single line on each call until the end of the file is reached.

---

# Function Prototype

```c
char *get_next_line(int fd);
```

Parameters:

* `fd` – file descriptor to read from

Return value:

* returns a line ending with `\n`
* returns the last line if the file does not end with newline
* returns `NULL` when the end of file is reached or an error occurs

---

# Features

* Reads files line by line
* Works with unknown file sizes
* Efficient memory management
* Handles partial reads
* Uses a configurable buffer size

---

# How It Works

The function reads the file in chunks defined by `BUFFER_SIZE`.

Key mechanisms used:

* **read()** to read file data
* **dynamic memory allocation** (`malloc`, `free`)
* **static variables** to store leftover data between function calls

A static buffer allows the function to remember what was left unread after the previous call.

Typical process:

1. Read data from the file descriptor.
2. Store the data in a buffer.
3. Search for a newline (`\n`).
4. Extract a line.
5. Save remaining data for the next function call.

---

# Example

```c
#include "get_next_line.h"
#include <fcntl.h>

int main()
{
    int fd = open("file.txt", O_RDONLY);
    char *line;

    while ((line = get_next_line(fd)) != NULL)
    {
        printf("%s", line);
        free(line);
    }

    close(fd);
}
```

---

# Compilation

Clone the repository:

```bash
git clone https://github.com/KrzysztofMarczynski/get_next_line.git
cd get_next_line
```

Compile the project:

```bash
gcc -Wall -Wextra -Werror -D BUFFER_SIZE=42 *.c
```

---

# Project Structure

```
get_next_line/
│
├── get_next_line.c
├── get_next_line_utils.c
├── get_next_line.h
└── README.md
```

---

# Concepts Practiced

This project focuses on:

* file descriptors
* static variables
* dynamic memory allocation
* string manipulation
* efficient buffer management
* low-level file reading
